#include "LSPrimaryGeneratorAction.hh"

#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4RunManager.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"


LSPrimaryGeneratorAction::LSPrimaryGeneratorAction()
  : G4VUserPrimaryGeneratorAction(),
    fParticleGun(0)
 {

   G4int n_particle = 1;
   fParticleGun = new G4ParticleGun(n_particle);

   G4ParticleTable* particleTable = G4ParticleTable::GetParticleTable();
   G4String particleName;
   G4ParticleDefinition* particle = particleTable->FindParticle(particleName="neutron");
   fParticleGun->SetParticleDefinition(particle);
   fParticleGun->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
   fParticleGun->SetParticleEnergy(10.*MeV);

 }


LSPrimaryGeneratorAction::~LSPrimaryGeneratorAction()
 {

   delete fParticleGun;

 }

void LSPrimaryGeneratorAction::GeneratePrimaries(G4Event* anEvent)
 {
   G4double x0 = -0.45*m;
   G4double y0 = 0;
   G4double z0 = 0;

   fParticleGun->SetParticlePosition(G4ThreeVector(x0,y0,z0));

   fParticleGun->GeneratePrimaryVertex(anEvent);

 }
