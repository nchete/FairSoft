//____________________________________________________________________________
/*!

\class    genie::AMNuGammaGenerator

\brief    

\author   Costas Andreopoulos <costas.andreopoulos \at stfc.ac.uk>
          STFC, Rutherford Appleton Laboratory

\created  Feb 15, 2008

\cpright  Copyright (c) 2003-2013, GENIE Neutrino MC Generator Collaboration
          For the full text of the license visit http://copyright.genie-mc.org
          or see $GENIE/LICENSE
*/
//____________________________________________________________________________

#ifndef _AMNUGAMMA_GENERATOR_H_
#define _AMNUGAMMA_GENERATOR_H_

#include "EVGCore/EventRecordVisitorI.h"

namespace genie {

class AMNuGammaGenerator : public EventRecordVisitorI {

public :
  AMNuGammaGenerator();
  AMNuGammaGenerator(string config);
 ~AMNuGammaGenerator();

  //-- implement the EventRecordVisitorI interface
  void ProcessEventRecord (GHepRecord * event_rec) const;

private:
  void AddPhoton             (GHepRecord * event_rec) const;
  void AddFinalStateNeutrino (GHepRecord * event_rec) const;
  void AddTargetRemnant      (GHepRecord * event_rec) const;
  void AddRecoilNucleon      (GHepRecord * event_rec) const;
};

}      // genie namespace
#endif // _AMNUGAMMA_GENERATOR_H_
