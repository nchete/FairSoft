/********************************************************************
* _ROOT_DICT_Ntuple.h
* CAUTION: DON'T CHANGE THIS FILE. THIS FILE IS AUTOMATICALLY GENERATED
*          FROM HEADER FILES LISTED IN G__setup_cpp_environmentXXX().
*          CHANGE THOSE HEADER FILES AND REGENERATE THIS FILE.
********************************************************************/
#ifdef __CINT__
#error _ROOT_DICT_Ntuple.h/C is only for compilation. Abort cint.
#endif
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define G__ANSIHEADER
#define G__DICTIONARY
#define G__PRIVATE_GVALUE
#include "G__ci.h"
#include "FastAllocString.h"
extern "C" {
extern void G__cpp_setup_tagtable_ROOT_DICT_Ntuple();
extern void G__cpp_setup_inheritance_ROOT_DICT_Ntuple();
extern void G__cpp_setup_typetable_ROOT_DICT_Ntuple();
extern void G__cpp_setup_memvar_ROOT_DICT_Ntuple();
extern void G__cpp_setup_global_ROOT_DICT_Ntuple();
extern void G__cpp_setup_memfunc_ROOT_DICT_Ntuple();
extern void G__cpp_setup_func_ROOT_DICT_Ntuple();
extern void G__set_cpp_environment_ROOT_DICT_Ntuple();
}


#include "TObject.h"
#include "TMemberInspector.h"
#include "NtpMCJobConfig.h"
#include "NtpMCRecordI.h"
#include "NtpWriter.h"
#include "NtpMCDTime.h"
#include "NtpMCTreeHeader.h"
#include "NtpMCJobEnv.h"
#include "NtpMCEventRecord.h"
#include "NtpMCRecHeader.h"
#include <algorithm>
namespace std { }
using namespace std;

#ifndef G__MEMFUNCBODY
#endif

extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TClass;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TBuffer;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMemberInspector;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TObject;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TNamed;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_basic_ostreamlEcharcOchar_traitslEchargRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_string;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_vectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_reverse_iteratorlEvectorlEROOTcLcLTSchemaHelpercOallocatorlEROOTcLcLTSchemaHelpergRsPgRcLcLiteratorgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_vectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_reverse_iteratorlEvectorlETVirtualArraymUcOallocatorlETVirtualArraymUgRsPgRcLcLiteratorgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TFolder;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_genie;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLNtpMCJobConfig;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLNtpMCRecHeader;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLEventRecord;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLNtpMCRecordI;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLENtpMCFormat;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TFile;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TTree;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TBranch;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLNtpMCEventRecord;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLNtpMCTreeHeader;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLNtpWriter;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLNtpMCDTime;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TObjString;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLNtpMCJobEnv;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_iteratorlEbidirectional_iterator_tagcOTObjectmUcOlongcOconstsPTObjectmUmUcOconstsPTObjectmUaNgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLEGEvGenMode;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLEKinePhaseSpace;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLERefFrame;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTBaselEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTBaselEdoublegR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TVectorTlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TVectorTlEdoublegR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TElementActionTlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TElementPosActionTlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTRow_constlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTRowlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTDiag_constlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTColumn_constlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTFlat_constlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTSub_constlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTSparseRow_constlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTSparseDiag_constlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTColumnlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTDiaglEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTFlatlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTSublEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTSparseRowlEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_TMatrixTSparseDiaglEfloatgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLTarget;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLInitialState;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLEInteractionType;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLEScatteringType;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLProcessInfo;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLEKineVar;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLKinematics;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_maplEgeniecLcLEKineVarcOdoublecOlesslEgeniecLcLEKineVargRcOallocatorlEpairlEconstsPgeniecLcLEKineVarcOdoublegRsPgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLEResonance;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLXclsTag;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLInteraction;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLEGHepStatus;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_geniecLcLGHepRecord;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_vectorlEintcOallocatorlEintgRsPgR;
extern G__linked_taginfo G___ROOT_DICT_NtupleLN_reverse_iteratorlEvectorlEintcOallocatorlEintgRsPgRcLcLiteratorgR;

/* STUB derived class for protected member access */
