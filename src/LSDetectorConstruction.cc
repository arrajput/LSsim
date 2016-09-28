#include "LSDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Cons.hh"
#include "G4Orb.hh"
#include "G4Sphere.hh"
#include "G4Trd.hh"
#include "G4Tubs.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"


LSDetectorConstruction::LSDetectorConstruction()
  : G4VUserDetectorConstruction()
{ }

LSDetectorConstruction::~LSDetectorConstruction()
{ }


G4VPhysicalVolume* LSDetectorConstruction::Construct()
{
  G4NistManager* nist = G4NistManager::Instance();

  //check overlapping

  G4bool checkOverlaps = true;

  //dimensions of world volume

  G4double world_hx = 1.0*m;
  G4double world_hy = 1.0*m;
  G4double world_hz = 1.0*m;

  //material for World volume

  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");

  //create world volume
  G4Box* worldBox = new G4Box("World", world_hx, world_hy, world_hz);

  //create world logical volume
  G4LogicalVolume* worldLog = new G4LogicalVolume(worldBox, world_mat, "World");

  //create world physical volume centered at origin and unrotated
  G4VPhysicalVolume* physWorld = new G4PVPlacement(0,G4ThreeVector(),worldLog,"World",0,false,0,checkOverlaps);

  //define LS material
  G4double z, a, density;
  G4String name, symbol;
  G4int ncomponents, natoms;

  a = 1.01*g/mole;
  G4Element* elH = new G4Element(name="Hydrogen",symbol="H",z = 1., a);

  a = 12.01*g/mole;
  G4Element* elC = new G4Element(name="Carbon",symbol="C",z = 6., a);

  density = 0.874*g/cm3;

  G4Material* BC501A = new G4Material(name="BC-501A",density, ncomponents=2);
  BC501A->AddElement(elH,natoms=6);
  BC501A->AddElement(elC,natoms=5);

  //define cylinder parameters for LS volume
  G4double innerRadius = 0.*cm;
  G4double outerRadius = 2.55*cm;
  G4double hz = 5.1*cm;
  G4double startAngle = 0.*deg;
  G4double spanningAngle = 360.*deg;

  //create LS cylinder volume
  G4Tubs* LSvol = new G4Tubs("LSvol",innerRadius,outerRadius,hz,startAngle,spanningAngle);

  //create LS cylinder logical volume
  G4LogicalVolume* LSlogvol = new G4LogicalVolume(LSvol, BC501A, "LSvol");

  //place LS cylinder physical volume at origin and unrotated
  G4VPhysicalVolume* LSphysvol = new G4PVPlacement(0,G4ThreeVector(),LSlogvol,"LSvol",worldLog,false,0,checkOverlaps);


  return physWorld;


}
