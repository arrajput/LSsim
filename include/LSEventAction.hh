#ifndef LSEventAction_h
#define LSEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class LSRunAction;

/// Event action class
///

class LSEventAction : public G4UserEventAction
{
public:
  LSEventAction(LSRunAction* runAction);
  virtual ~LSEventAction();

  virtual void BeginOfEventAction(const G4Event* event);
  virtual void EndOfEventAction(const G4Event* event);

private:
  LSRunAction* fRunAction;
  
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
