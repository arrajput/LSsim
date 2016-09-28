#ifndef LSSteppingAction_h
#define LSSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"

class LSEventAction;

class G4LogicalVolume;

/// Stepping action class
///

class LSSteppingAction : public G4UserSteppingAction
{
public:
  LSSteppingAction(LSEventAction* eventAction);
  virtual ~LSSteppingAction();

  // method from the base class
  virtual void UserSteppingAction(const G4Step*);

private:
  LSEventAction*  fEventAction;
  G4LogicalVolume* fScoringVolume;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
