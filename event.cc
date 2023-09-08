#include "event.hh"
#include "detector.hh"


MyEventAction:: MyEventAction(MyRunAction*)
{
fEdep = 0.;


}
MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event* )
{
	fEdep = 0.;

	
}

void MyEventAction::EndOfEventAction(const G4Event* event)
{

	G4cout<<"Energy deposition: "<<fEdep << G4endl;

	G4AnalysisManager *man = G4AnalysisManager::Instance();


	G4int evt= G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();


	// G4HCofThisEvent* HCE = event->GetHCofThisEvent();

	// MyHitsCollection* hitsCollection = 0;

	// if (HCE) hitsCollection = (MyHitsCollection*)(HCE->GetHC(1));

	// int phot1, phot2;

	// if (hitsCollection)
	// {
	// int numberHits = hitsCollection->entries();

	// int j = numberHits - 1;

	// MyHit* hit = (*hitsCollection)[j];

	//  phot1 = hit->GetPhot1();
	//  phot2 = hit->GetPhot2();

	 //The hits collecton doesn't work


	// }

	// G4cout<<"Phot1 "<<phot1;

	man->FillNtupleIColumn(0,0, evt);
	// man->FillNtupleDColumn(0, 4, phot1);
	// man->FillNtupleDColumn(0, 10, phot2);
	   man->AddNtupleRow(0);



	man->FillNtupleDColumn(1, 0, fEdep);

	man->AddNtupleRow(1);

}