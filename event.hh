#ifndef EVENT_HH
#define EVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "g4root.hh"
#include "run.hh"
#include "G4HCofThisEvent.hh"


class MyEventAction : public G4UserEventAction
{
public:

	MyEventAction(MyRunAction*);
	~MyEventAction();

	virtual void BeginOfEventAction( const G4Event*);
	virtual void EndOfEventAction( const G4Event*);

	void AddEdep(G4double Edep) {fEdep+=Edep;}

private:
	G4double fEdep;
};
#endif