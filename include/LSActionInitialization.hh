#ifndef LSActionInitialization_h
#define LSActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class LSActionInitialization : public G4VUserActionInitialization
{
public:
  LSActionInitialization();
  virtual ~LSActionInitialization();

  //virtual void BuildForMaster() const;
  virtual void Build() const;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
