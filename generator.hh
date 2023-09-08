#ifndef GENERATOR_HH
#define GENERATOR_HH

#include "G4VUserPrimaryGeneratorAction.hh"

#include "G4ParticleGun.hh"
#include "G4SystemOfUnits.hh"
#include "G4ParticleTable.hh"
#include "G4IonTable.hh"
#include "G4ChargedGeantino.hh"
#include "G4Gamma.hh"
#include "globals.hh"
#include "G4GeneralParticleSource.hh"
#include "G4UImanager.hh"
#include "g4root.hh"
#include "G4RunManager.hh"
#include <stdlib.h>
#include <time.h>
#include <random>
#include "Randomize.hh"


class G4Event;
class MyPrimaryGenerator : public G4VUserPrimaryGeneratorAction
{
	public:

	MyPrimaryGenerator();
	~MyPrimaryGenerator();

	void SetOptPhotonPolar();
  	void SetOptPhotonPolar(G4double);

	void GeneratePrimaries(G4Event*);

	private:

	G4ParticleGun *fParticleGun;
	

};

#endif
