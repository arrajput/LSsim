#include "LSActionInitialization.hh"
#include "LSPrimaryGeneratorAction.hh"
#include "LSEventAction.hh"
#include "LSSteppingAction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LSActionInitialization::LSActionInitialization()
  : G4VUserActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

LSActionInitialization::~LSActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

/*void LSActionInitialization::BuildForMaster() const
{
  //LSRunAction* runAction = new LSRunAction;
  //SetUserAction(runAction);
}*/

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void LSActionInitialization::Build() const
{
  SetUserAction(new LSPrimaryGeneratorAction);

  //LSRunAction* runAction = new LSRunAction;
  //SetUserAction(runAction);

  //LSEventAction* eventAction = new LSEventAction(runAction);
  //SetUserAction(eventAction);

  //SetUserAction(new LSSteppingAction(eventAction));
}
