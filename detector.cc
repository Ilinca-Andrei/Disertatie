#include "detector.hh"
#include <math.h> 
#include "event.hh"
#include "construction.hh"


MyHit *hit = new MyHit();

MySensitiveDetector::MySensitiveDetector(G4String SDet) :G4VSensitiveDetector("SDet"), collectionID(1)
{
	collectionName.insert("MyHitsCollection");
}
MySensitiveDetector::~MySensitiveDetector()
{}

void MySensitiveDetector::Initialize(G4HCofThisEvent* HCE)
{


	// HitsCollection = new MyHitsCollection(GetName(), collectionName[0]);


	// collectionID = -1;

	// if(collectionID < 0)
	// 	collectionID = G4SDManager::GetSDMpointer()->GetCollectionID(collectionName[0]);;

	
	// HCE->AddHitsCollection(collectionID, HitsCollection);

	// hit->SetPhot1(0);
	// hit->SetPhot2(0);


	// G4cout<<"New Event";

}



bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{

	G4AnalysisManager *man = G4AnalysisManager::Instance();

	G4Track *track = aStep->GetTrack();

	track->SetTrackStatus(fStopAndKill);


	G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
	// G4StepPoint *postStepPoint = aStep->GetPostStepPoint();


	// G4ThreeVector posPhoton = preStepPoint->GetPosition();

	// G4ThreeVector momPhoton = preStepPoint->GetMomentum();


	// G4double Wlen = 1.239841939*eV/momPhoton.mag()*1E+03;

	// G4cout<<"Photon Position: " <<posPhoton<< G4endl;


	const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

	G4int copyNo = touchable->GetCopyNumber();

	G4int evt= G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();


		if (k != evt)
	{
		man->FillNtupleDColumn(0, 4, hit->GetPhot2());
		man->FillNtupleDColumn(0, 10, hit->GetPhot1());

		hit->SetPhot1(0);
		hit->SetPhot2(0);

		k++;

		// G4cout<<"AfterSetting to 0 "<<"Phot1 = "<<hit->GetPhot1()<<" Phot2 = "<<hit->GetPhot2()<<G4endl;
	}
	



	// G4cout << "Copy number: " <<copyNo <<G4endl;


	// G4VPhysicalVolume *physvol = touchable->GetVolume();
	// G4ThreeVector posDet = physvol->GetTranslation();



	


	
	
	if (copyNo == 1)
		hit->AddPhot1();
	else
		hit->AddPhot2();



	
	// HitsCollection ->insert(hit);
	// G4cout<<"HIT"<<G4endl;
	// G4cout<<"Phot1 = "<<hit->GetPhot1()<<G4endl;
	// G4cout<<"Phot2 = "<<hit->GetPhot2()<<G4endl;
	// G4cout<<"k = "<<k<<G4endl;
	// G4cout<<"EventID = "<<evt<<G4endl<<G4endl;

	// hit->Print();
	




return true;
}

void MySensitiveDetector::EndOfEvent(G4HCofThisEvent* HCE)
{

	// G4cout<<"PHOT1= "<<hit->GetPhot1()<<G4endl;
	// G4cout<<"PHOT2= "<<hit->GetPhot2()<<G4endl;

}


