#ifndef DETECTOR_HH
#define DETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4CollectionNameVector.hh"
#include "g4root.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"
#include "event.hh"
#include "G4HCofThisEvent.hh"
#include "hit.hh"
#include "G4SDManager.hh"
#include <vector>


class MySensitiveDetector: public G4VSensitiveDetector
{
public:
		MySensitiveDetector(G4String name);
		virtual ~MySensitiveDetector();

private:
	virtual void Initialize(G4HCofThisEvent* HitsCollection);
	virtual void EndOfEvent(G4HCofThisEvent* HitsCollection);
	virtual bool ProcessHits(G4Step*, G4TouchableHistory* history);


	MyHitsCollection* HitsCollection;
	
	int collectionID, k = 0;

protected:
	G4CollectionNameVector collectionName;
};
#endif