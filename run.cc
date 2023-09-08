
#include "run.hh"

MyRunAction:: MyRunAction()
{
	G4AnalysisManager *man = G4AnalysisManager::Instance();
	/*creating the tree(Ntuple)*/
	
	man->CreateNtuple("Photons","Photons");
	man->CreateNtupleIColumn("fEvent");//0
	man->CreateNtupleDColumn("fx");//1
	man->CreateNtupleDColumn("fy");//2
	man->CreateNtupleDColumn("fz");//3
	man->CreateNtupleDColumn("Photons2");//4
	man->CreateNtupleDColumn("PrX");//5
	man->CreateNtupleDColumn("PrY");//6
	man->CreateNtupleDColumn("PrZ");//7
	man->CreateNtupleDColumn("Phi");//8
	man->CreateNtupleDColumn("Theta");//9
	man->CreateNtupleDColumn("Photons1");//10
	man->FinishNtuple(0);

	man->CreateNtuple("Scoring","Scoring");
	man->CreateNtupleDColumn("fEDep");
	man->FinishNtuple(1);
}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run* run)
{

	G4AnalysisManager *man = G4AnalysisManager::Instance();

	G4int runID = run->GetRunID();

	std::stringstream strRunID;
	strRunID << runID;

	man->OpenFile("output.root");
	

	

}

void MyRunAction::EndOfRunAction(const G4Run*)
{

	G4AnalysisManager *man = G4AnalysisManager::Instance();


	man->Write();
	man->CloseFile();	
}
