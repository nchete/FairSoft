      subroutine HERAevolve(x,Q,pdf)
      implicit double precision (a-h,o-z)
      include 'parmsetup.inc'
      character*64 gridname
      character*16 name(nmxset)
      integer nmem(nmxset),ndef(nmxset),mem
      common/NAME/name,nmem,ndef,mem
      integer nset,iset,isetlast
      data isetlast/-1/
      integer Eorder
      real*8 mc,mc2,mb,mb2,mt,mt2
      real*8 f(-6:6),pdf(-6:6)
      integer qnerr
      parameter(nstartp=7)
      DIMENSION QSP(NSTARTP)
      DATA QSP/10.,20.,30.,40.,50.,80.,100./
      real*8 xval(45)
      logical HEAVY,VFN
      real*8 pwgt(20)
      save
!
      call getnset(iset)
!      print *,'iset=',iset,' now calling get_pdfqcd'
      if(iset.ne.isetlast) then
        call get_pdfqcd(iset)
        isetlast = iset
      endif
!
      Q2=Q*Q
      UCENT=QPDFXQ('UPVAL',X,Q2,IFAIL)
      DCENT=QPDFXQ('DNVAL',X,Q2,IFAIL)
      GCENT=QPDFXQ('GLUON',X,Q2,IFAIL)
      UBCEN=QPDFXQ('UB',X,Q2,IFAIL)
      DBCEN=QPDFXQ('DB',X,Q2,IFAIL)
      STCEN=QPDFXQ('SB',X,Q2,IFAIL)
      IF(Q2.GE.Q2C)THEN
        CHCEN=QPDFXQ('CB',X,Q2,IFAIL)
      ELSE
        CHCEN=0.0
      ENDIF
      IF(Q2.GE.Q2B)THEN
        BTCEN=QPDFXQ('BB',X,Q2,IFAIL)
      ELSE
        BTCEN=0.0
      ENDIF
      pdf(1)=dcent+dbcen
      pdf(2)=ucent+ubcen
      pdf(3)=stcen
      pdf(4)=chcen
      pdf(5)=btcen
      pdf(6)=0d0
      pdf(0)=gcent
      pdf(-1)=dbcen
      pdf(-2)=ubcen
      pdf(-3)=stcen
      pdf(-4)=chcen
      pdf(-5)=btcen
      pdf(-6)=0d0
!
      return
!
!===========================================================================
      entry HERAalfa(alfas,Q)
      Q2=Q*Q
      nf=6
      if (Q2.lt.mt2) nf=5
      if (Q2.lt.mb2) nf=4
      if (Q2.lt.mc2) nf=3
      alfas=QALFAS(Q2,Qlam,nf,iflag)
!      print *,q2,alfas,qlam,nf,iflag
      return
!
!===========================================================================
      entry HERAread(nset)
         read(1,*) gridname,nx,xmin,xmax,nq,qmin,qmax
!	 print *,gridname,nx,xmin,xmax,nq,qmin,qmax,' from HERAread'
      return
!
!===========================================================================
      entry HERAinit(nset,Eorder,Q2fit)
!      print *,name(nset), ' from HERAinit'
      if(name(nset).eq.'QCDNUM_HERA_TR') then
         HEAVY = .FALSE.
	 VFN = .TRUE.
      else if(name(nset).eq.'QCDNUM_HERA_FF') then
         HEAVY = .TRUE.
	 VFN = .FALSE.
      else if(name(nset).eq.'QCDNUM_HERA_ZM') then
         HEAVY = .FALSE.
	 VFN = .FALSE.
      else
        print *,'name/scheme not recognized'
	stop 1
      endif
!--try 3 way logic ffn/zm-vfn/rt-vfn
      IF(HEAVY)THEN
      IVFN=1
      ELSE
      IVFN=0
      ENDIF
      IF(VFN)THEN
      IVFN=IVFN+2
      ELSE
      IVFN=IVFN
      ENDIF
! IVFN=0 IS ZM-VFN, 1 IS FFN,2 IS RT-VFN, 3 IS NOT ALLOWED  

      IF(IVFN.EQ.3)THEN
      WRITE(*,*)'IVFN=3 SO STOP',IVFN
      STOP
      ENDIF    

      
      
!--qcdnum initialisation
      CALL QNINIT
!--se thresholds
      Q0=Q2fit
      ZM=91.187D0
      ZM2=ZM*ZM
      ALPHAS=QNALFA(ZM2)

      call getQmassM(nset,4,mc)
      mc2=mc*mc
      call getQmassM(nset,5,mb)
      mb2=mb*mb
      call getQmassM(nset,6,mt)
      mt2=mt*mt
    
!      Q2C=1.8225
      Q2C=mc2
!      Q2B=18.49
      Q2B=mb2 
!      print  *,q2c,q2b    
      q2t=mt2

      IF (Q0.LT.Q2C) THEN
        NACT=3
      ELSE
        NACT=4
      ENDIF
!--this merely defines nact where we startevolution
!--namely at q0
      IF (HEAVY) NACT=3

      CALL QNRSET('MCSTF',SQRT(Q2C))
      CALL QNRSET('MBSTF',SQRT(Q2B))
      CALL QNRSET('MCALF',SQRT(Q2C))
      CALL QNRSET('MBALF',SQRT(Q2B))
      CALL QNRSET('MTALF',SQRT(Q2T))
    
      IF (HEAVY) THEN
        CALL QTHRES(1D10,2D10)
!        CALL QTHRES(1D6,2D6)
      ELSE
        CALL QTHRES(Q2C,Q2B)
      ENDIF
 
      DO I=1,NSTARTP
        CALL GRQINP(QSP(I),1)
      ENDDO
      CALL GRQINP(Q0,1)
      CALL GRQINP(Q2C,1)
      CALL GRQINP(Q2B,1)
!      qcdnum grid not my grid

!      CALL GRXLIM(120,97D-8)
!      print *,'nx = ',nx
      CALL GRXLIM(nx,xmin)

!      CALL GRQLIM(61,29D-2,200D3) 
!      print *,'nq = ',nq
      CALL GRQLIM(nq,qmin,qmax) 

!--   Get final grid definitions and grid indices of Q0, Q2C and Q2B

      CALL GRGIVE(NXGRI,XMI,XMA,NQGRI,QMI,QMA)
!      WRITE(*,*)'NX,XL,XH,NQ,QL,QH',NXGRI,XMI,XMA,NQGRI,QMI,QMA
      IQ0 = IQFROMQ(Q0)
      IQC = IQFROMQ(Q2C)
      IQB = IQFROMQ(Q2B)
!--   Allow for heavy weights

      IF (HEAVY) THEN
        CALL QNLSET('WTF2C',.TRUE.)
        CALL QNLSET('WTF2B',.TRUE.)
        CALL QNLSET('CLOWQ',.FALSE.)
        CALL QNLSET('WTFLC',.TRUE.)
        CALL QNLSET('WTFLB',.TRUE.)
      ENDIF

!--   Compute weights and dump, or read in
!
!      IF (READIN) THEN 
!        OPEN(UNIT=24,FILE='weights.dat',FORM='UNFORMATTED',
!     .                                  STATUS='UNKNOWN')
!        CALL QNREAD(24,ISTOP,IERR)
!      ELSE
!        CALL QNFILW(0,0)
!        IF (HEAVY) THEN
!          OPEN(UNIT=24,FILE='weights.dat',FORM='UNFORMATTED',
!     .                                    STATUS='UNKNOWN')
!          CALL QNDUMP(24)
!        ENDIF
!      ENDIF


      if (index(gridname,'none').eq.1) then
         call qnfilw(0,0)
      else
         qnerr=-1
         open(unit=2,status='old',file=gridname, &
     &        form='unformatted',err=1)
         call QNREAD(2,1,qnerr)
 1       close(2)
         if (qnerr.ne.0) then
            write(*,*) 'Grid file problem: ',gridname
            if (qnerr.lt.0) then 
               write(*,*) 'Grid file does not exist'
               write(*,*) 'Calculating and creating grid file'
               call qnfilw(0,0)
               open(unit=2,status='unknown',file=gridname, &
     &              form='unformatted')
               call QNDUMP(2)
               close(2)
            else
               write(*,*) 'Existing grid file is inconsistent'
               if (qnerr.eq.1) &
     &              write(*,*) 'Defined grid different'
               if (qnerr.eq.2) &
     &              write(*,*) 'Heavy quark weight table different'
               if (qnerr.eq.3) &
     &              write(*,*) 'Charm mass different'
               if (qnerr.eq.4) &
     &              write(*,*) 'Bottom mass different'
               stop
            endif
         endif
      endif

!--   Apply cuts to grid
!--taking away the s cut at 600d0
      CALL GRCUTS(-1D0,-1D0,-1D0,-1D0)




!--   Choose renormalisation and factorisation scales

      CALL QNRSET('AAAR2',1D0)  ! renormalisation
      CALL QNRSET('BBBR2',0D0)
      CALL QNRSET('AAM2L',1D0)  ! factorisation (light)
      CALL QNRSET('BBM2L',0D0)
      CALL QNRSET('AAM2H',1D0)  ! factorisation (heavy)
      CALL QNRSET('BBM2H',0D0)
 
!       ZM=91.187D0
      imem=0
!      print *,imem
! -- only need call to listPDF here to get alphas
      call listPDF(nset,imem,xval)
!      print *,xval
        AS=XVAL(13)
!        AS=0.118d0
      CALL QNRSET('ALFQ0',ZM*ZM)
      CALL QNRSET('ALFAS',AS)

!      ZM2=ZM*ZM
      ALPHAS=QNALFA(ZM2)
      WRITE(*,*)'ALPHAS AT Mz2',ALPHAS

!--   Book non-singlet distributions

      CALL QNBOOK(2,'UPLUS')
      CALL QNBOOK(3,'DPLUS')
      CALL QNBOOK(4,'SPLUS')
      CALL QNBOOK(5,'CPLUS')
      CALL QNBOOK(6,'BPLUS')
      CALL QNBOOK(7,'UPVAL')
      CALL QNBOOK(8,'DNVAL')
 
!--   Book linear combinations for proton for f = 3,4,5 flavours

!--define some quark pdfs
         CALL dVZERO(PWGT,20)        
        PWGT(2) = 0.5

        PWGT(7) = -0.5

        PWGT(1) = 0.5/3.
        CALL QNLINC(17,'UB',3,PWGT)
        PWGT(1) = 0.5/4.
        CALL QNLINC(17,'UB',4,PWGT)
        PWGT(1) = 0.5/5.
        CALL QNLINC(17,'UB',5,PWGT) 
        CALL dVZERO(PWGT,20) 

        PWGT(4) = 0.5
        PWGT(1) = 0.5/3.
        CALL QNLINC(18,'SB',3,PWGT)
        PWGT(1) = 0.5/4.
        CALL QNLINC(18,'SB',4,PWGT)
        PWGT(1) = 0.5/5.
        CALL QNLINC(18,'SB',5,PWGT)
         CALL dVZERO(PWGT,20)        
        CALL QNLINC(19,'CB',3,PWGT)
        PWGT(5) = 0.5
        PWGT(1) = 0.5/4.

        CALL QNLINC(19,'CB',4,PWGT)
        PWGT(1) = 0.5/5.
        CALL QNLINC(19,'CB',5,PWGT) 
        CALL dVZERO(PWGT,20) 
        PWGT(3) = 0.5

        PWGT(8) = -0.5

        PWGT(1) = 0.5/3.
        CALL QNLINC(20,'DB',3,PWGT)
        PWGT(1) = 0.5/4.
        CALL QNLINC(20,'DB',4,PWGT)
        PWGT(1) = 0.5/5.
        CALL QNLINC(20,'DB',5,PWGT)
         CALL dVZERO(PWGT,20)        
        CALL QNLINC(21,'BB',3,PWGT)
       CALL QNLINC(21,'BB',4,PWGT)  
        PWGT(6) = 0.5
  
        PWGT(1) = 0.5/5.
        CALL QNLINC(21,'BB',5,PWGT) 
!---

      return
!
!==========================================================================
      entry HERApdf(nset)
!      print *,'calling HERApdf ',nset
!      ZM = 91.187d0
!      zm2 = zm*zm

!      ALPHAS=QNALFA(ZM2)
      
      
!      imem=mem
      call getnmem(nset,imem)    
      call listPDF(nset,imem,xval)
!      print *,xval
!      print *,imem,xval

        FS=XVAL(14)
        FC=XVAL(15)
!-- iremeber to change fs and fc with choices of Q20, and fc with =
!-- choices of mc.
!
!-- the free parameters are XVAL(1),2,3,4,6,9,10,11,12,13,14 which are :

!- 1,2,3,4 the parameters of the u_valence quark
!--ignore the names UA,Ub in the code, in the write-up these are called
!--x^B(1-x)^C (1+D x+E x^2) where 1=B,2=C,3=E,4=D.. you can see =
!--this from reading the code, but i thought it c--best to spell it out, =
!--normalisation comes from number sum-rule and is done in the code


      UA=XVAL(1)
      UB=XVAL(2)
      UE=XVAL(3)
      UC=XVAL(4)
!... 6 is the only free parameter for the d-valence: 6=C, where x^B =
!(1-x)^C, the B parameter is set equal to c--that of the u-valence, where =
!-- DA=UA means that B=1 again. normalisation comes from number sum-rule =
!c-- and is done in the code
      DA=UA
      DB=XVAL(5)
      DE=0.0
      DC=0.0
!------sea is in two bits Ubar and Dbar: parameter XVAL(9) gives an =
!overall sea normalisation, which is split up
!-- into Ubar (UBN)and Dbar(DBN) using the fractions fc and fs in the =
!-- code below
      SN=XVAL(6)
!-- Ubar and Dbar share a common low -x slope parameter XVAL(10), so =
!-- both Ubar and Dbar take the form
!--  X^B(1-x)C, B=10 is the same for both C=11 for Ubar and C=12 =
!--for Dbar
      SA=XVAL(7)
      SB=XVAL(8)
      SC=XVAL(9)
      SE=0.
!--- make sea more complex
      UBA=SA
      DBA=SA
      UBB=SB
      DBB=SC
      UBC=0.
      DBC=0.
      UBE=0.
      DBE=0.
!      UBN=SN/4.
!      DBN=SN/4.
       UBN=SN/2.*(1.-FS)/(2.-FS-FC)
       DBN=SN/2.*(1.-FC)/(2.-FS-FC)
!-- now for a simple gluon param. x^B(1-x)^C, where B=13 and C=14, =
!-- and norm comes from the momentum sum-rule c--below.
      GA=XVAL(10)
      GB=XVAL(11)
      GC=XVAL(12)
      GE=0.0d0
      
      AS=XVAL(13)
!-- alphas is 0.1176 and parameter 17 is not free in the fit
       CALL QNRSET('ALFAS',AS)

!--   Input quark distributions at Q2 = Q02 GeV2
       UN=2./AREA(UA-1,UB,UE,UC)
       DN=1./AREA(DA-1,DB,DE,DC)
        GN=(1-UN*AREA(UA,UB,UE,UC)- &
     &        DN*AREA(DA,DB,DE,DC)-2.*UBN*AREA(UBA,UBB,UBE,UBC) &
     &       -2.*DBN*AREA(DBA,DBB,DBE,DBC))/AREA(GA,GB,GE,GC)

      nxgri = nx
      DO IX = 1,NXGRI
        xX = XFROMIX(IX)
        UPVAL=UN*FF_LHA2(xX,UA,UB,UE,UC)
        DNVAL=DN*FF_LHA2(xX,DA,DB,DE,DC)
        UBAR=UBN*FF_LHA2(xX,UBA,UBB,UBE,UBC)
        DBAR=DBN*FF_LHA2(xX,DBA,DBB,DBE,DBC)
        SEA=2.*(UBAR+DBAR)

        SINGL=UPVAL+DNVAL+SEA  
!
        GLUON=GN*FF_LHA2(xX,GA,GB,GE,GC)

        UBQ=(1.-FC)*UBAR
        CBQ=FC*UBAR
        DBQ=(1.-FS)*DBAR
        SBQ=FS*DBAR
        USEA=2*UBQ
        DSEA=2*DBQ
        SSEA=2*SBQ
        CSEA=2*CBQ
!
        UPLUS=UPVAL+USEA-1./NACT*SINGL
        DPLUS=DNVAL+DSEA-1./NACT*SINGL
        SPLUS=SSEA-1./NACT*SINGL
        CPLUS=CSEA-1./NACT*SINGL
!-- the fraction of charm is simply imposed- not dynamically generated
        CALL QNPSET('GLUON',IX,IQ0,GLUON)
        CALL QNPSET('SINGL',IX,IQ0,SINGL)
        CALL QNPSET('UPLUS',IX,IQ0,UPLUS)
        CALL QNPSET('DPLUS',IX,IQ0,DPLUS)
        CALL QNPSET('SPLUS',IX,IQ0,SPLUS)
        CALL QNPSET('CPLUS',IX,IQ0,CPLUS)
        CALL QNPSET('UPVAL',IX,IQ0,UPVAL)
        CALL QNPSET('DNVAL',IX,IQ0,DNVAL)
      ENDDO
!--THINGS ARE FINE FOR HEAVY SO DO IT
!       print *, 'HEAVY is: ',heavy, 'NACT is: ',nact
       IF (HEAVY) THEN

!--     Evolve over whole grid

        CALL EVOLSG(IQ0,1,NQGRI)
        CALL EVPLUS('UPLUS',IQ0,1,NQGRI)
        CALL EVPLUS('DPLUS',IQ0,1,NQGRI)
        CALL EVPLUS('SPLUS',IQ0,1,NQGRI)
        CALL EVOLNM('UPVAL',IQ0,1,NQGRI)
        CALL EVOLNM('DNVAL',IQ0,1,NQGRI)

      ELSE

!--     Evolve gluon, singlet and valence over whole grid
        CALL EVOLSG(IQ0,1,NQGRI)
        CALL EVOLNM('UPVAL',IQ0,1,NQGRI)
        CALL EVOLNM('DNVAL',IQ0,1,NQGRI)
!--     Be more careful with plus distributions
        IF (NACT.EQ.3) THEN
!--THINGS ARE ALSO FINE IF 1Q0 IS BELOW 1QC THEN CLEARLY CSEA=0. IS OK
!--SITUATION CD BE 1<Q0<Q2C<Q2B ETC
!--GO DOWN QO TO 1 UP Q0 TO  Q2C
          CALL EVPLUS('UPLUS',IQ0,1,IQC)
          CALL EVPLUS('DPLUS',IQ0,1,IQC)
          CALL EVPLUS('SPLUS',IQ0,1,IQC)
!--DEAL WITH CHARM THRESH
          FACTOR=1./3.-1./4.
          CALL QADDSI('UPLUS',IQC,FACTOR)
          CALL QADDSI('DPLUS',IQC,FACTOR)
          CALL QADDSI('SPLUS',IQC,FACTOR)
          CALL QNPNUL('CPLUS')
          FACTOR=-1/4.
          CALL QADDSI('CPLUS',IQC,FACTOR)
!--GO UP Q2C TO Q2B
          CALL EVPLUS('UPLUS',IQC,IQC,IQB)
          CALL EVPLUS('DPLUS',IQC,IQC,IQB)
          CALL EVPLUS('SPLUS',IQC,IQC,IQB)
          CALL EVPLUS('CPLUS',IQC,IQC,IQB)


        ELSEIF(NACT.EQ.4)THEN

!-NOW DO MIDDLE FOR UPLUS,DPLUS,SPLUS,CPLUS
          CALL EVPLUS('UPLUS',IQ0,IQC,IQB)
          CALL EVPLUS('DPLUS',IQ0,IQC,IQB)
          CALL EVPLUS('SPLUS',IQ0,IQC,IQB)
          CALL EVPLUS('CPLUS',IQ0,IQC,IQB)
!--THEN GO DOWN IQC TO 1
             IF(IQC.GT.1)THEN
             FACTOR=1./4.-1./3.
             CALL QADDSI('UPLUS',IQC,FACTOR)
             CALL QADDSI('DPLUS',IQC,FACTOR)
             CALL QADDSI('SPLUS',IQC,FACTOR)
             CALL EVPLUS('UPLUS',IQC,1,IQC)
             CALL EVPLUS('DPLUS',IQC,1,IQC)
             CALL EVPLUS('SPLUS',IQC,1,IQC)
             ENDIF

        ENDIF
!--THEN DEAL WITH B THRESHOLD FOR ALL4
        FACTOR=1./4.-1./5.
        CALL QADDSI('UPLUS',IQB,FACTOR)
        CALL QADDSI('DPLUS',IQB,FACTOR)
        CALL QADDSI('SPLUS',IQB,FACTOR)
        CALL QADDSI('CPLUS',IQB,FACTOR)
!--THEN GO UP
        IF(IQB.LT.NQGRI)THEN
       CALL EVPLUS('UPLUS',IQB,IQB,NQGRI)
        CALL EVPLUS('DPLUS',IQB,IQB,NQGRI)
        CALL EVPLUS('SPLUS',IQB,IQB,NQGRI)
        CALL EVPLUS('CPLUS',IQB,IQB,NQGRI)
        ENDIF
!C--THEN DEAL WITH B TURNING ON AT IQB AND GO UP
        CALL QNPNUL('BPLUS')
        FACTOR=-1./5.
       CALL QADDSI('BPLUS',IQB,FACTOR)
        CALL EVPLUS('BPLUS',IQB,IQB,NQGRI)
      ENDIF 
      AMSR= GN*AREA(GA,GB,GE,GC)+UN*AREA(UA,UB,UE,UC) &
     &      +  DN*AREA(DA,DB,DE,DC)+2.*UBN*AREA(UBA,UBB,UBE,UBC) &
     &      +  2.*DBN*AREA(DBA,DBB,DBE,DBC)   

      call getnset(iset)
      call save_pdfqcd(iset)

      RETURN
  
      END

!------------------------------------------------------------------------=
      DOUBLE PRECISION FUNCTION AREA(A,B,E,C)
!------------------------------------------------------------------------=

      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
      IF (A.LE.-0.99.OR.B.LE.-0.99) THEN
        AREA=1D6
        RETURN
      ENDIF

      AR1=(DGAMMA_LHA(A+1)*DGAMMA_LHA(B+1))/DGAMMA_LHA(A+B+2)
!      AR2=E*(DGAMMA(A+1.5)*DGAMMA(B+1))/DGAMMA(A+B+2.5)
      AR2=E*(DGAMMA_LHA(A+3)*DGAMMA_LHA(B+1))/DGAMMA_LHA(A+B+4)
      AR3=C*(DGAMMA_LHA(A+2)*DGAMMA_LHA(B+1))/DGAMMA_LHA(A+B+3)
      AREA=AR1+AR2+AR3
      IF (AREA.LE.1D-6) AREA=1D-6

      RETURN
      END

!------------------------------------------------------------------------=
      DOUBLE PRECISION FUNCTION FF_LHA2(X,A,B,E,C)
!------------------------------------------------------------------------=

      IMPLICIT DOUBLE PRECISION (A-H,O-Z)
!      FF=X**A*(1D0-X)**B*(1+E*SQRT(X)+C*X)
      FF_LHA2=X**A*(1D0-X)**B*(1+C*X + E*X*X)
      RETURN
      END

!------------------------------------------------------------------------ 
      



