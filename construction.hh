#ifndef CONSTRUCTION_HH
#define CONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"
#include "G4GenericMessenger.hh"
#include "G4OpticalSurface.hh"
#include "G4LogicalBorderSurface.hh"
#include "G4LogicalSkinSurface.hh"
#include "G4UnionSolid.hh"
#include "G4SubtractionSolid.hh"

#include "detector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    G4LogicalVolume *GetScoringVolume() const { return fScoringVolume; }

    virtual G4VPhysicalVolume *Construct();
    void ConstructCherenkov();
    void ConstructScintillator();
    void ConstructTOF();
    void ConstructAtmosphere();
    void ConstructCell();

private:

       G4Material *SiO2, *H2O, *Aerogel, *worldMat, *NaI, *polystyrene, *PMMA, *TiO2;

    G4Material *WLS_Core;

    G4Element *C, *Na, *I;


    G4SubtractionSolid *Scin_Box, *TiO2Box_with_groove, *TiO2cover;

    G4Tubs *solidCore, *solidCladding;

    G4Box *solidWorld, *solidRadiator, *solidDetector, *solidScintillator, *solidCapDet, *Scin_FullBox, *scintilator_groove_box, *TiO2Box, *TiO2_groove;

    G4LogicalVolume *logicWorld, *logicRadiator, *logicDetector, *logicScintillator, *logicCapDet, *logicScin, *logicCore, *logicCladding, *TiO2_logic;

    G4VPhysicalVolume *physWorld, *physDetector, *physRadiator, *physScintillator, *physCapDet1, *physCapDet2, *physScin, *physCore, *physCladding, *TiO2_phys;

    G4LogicalSkinSurface *Core_Surface, *Cladding_Surface, *Scin_Surface, *DET_Surface, *TiO2_Surface;

    G4LogicalBorderSurface *TiO2_Scin, *Core_Cladding, *Cladding_Core, *Scin_TiO2, *Core_DET1, *Core_DET2, *Clad_World, *World_Clad, *Core_World, *World_Core, *Scin_World, *World_Scin;
   



    G4OpticalSurface *OpticalSurfaceScin;
    G4OpticalSurface *OpticalSurfaceCore;
    G4OpticalSurface *OpticalSurfaceTiO2;

   

    void DefineMaterials();
    virtual void ConstructSDandField();

    G4GenericMessenger *fMessenger;

    G4LogicalVolume *fScoringVolume;

    G4int nRows, nCols;

    G4double xWorld, yWorld, zWorld;

    G4bool isCherenkov, isScintillator, isCell;
};

#endif