#include "generator.hh"
#include "Randomize.hh"
#include "G4OpticalPhoton.hh"
#include "G4Proton.hh"
#include <cmath>
MyPrimaryGenerator::MyPrimaryGenerator()
{
    G4long seed = time(0);
    CLHEP::HepRandom::setTheSeed(seed*G4UniformRand());



    fParticleGun = new G4ParticleGun(1);
    

    G4int OP;

    OP = 0;

    G4ParticleTable *particleTable = G4ParticleTable::GetParticleTable();
    G4ParticleDefinition *particleOP = G4OpticalPhoton::OpticalPhotonDefinition();
    G4ParticleDefinition *particle = particleTable->FindParticle("mu-");


   

       if(OP == 1)
    {fParticleGun->SetParticleDefinition(particleOP);
     G4ThreeVector mom(0.*cm,-1.*cm,0.*cm);
     fParticleGun->SetParticleMomentumDirection(mom);
     fParticleGun->SetParticlePosition(G4ThreeVector (0.*cm, 3.*cm, 0.3*cm));
    }
    else
    {fParticleGun->SetParticleDefinition(particle);}

    
    fParticleGun->SetParticleEnergy(1.*GeV);



  
}


///Sursa plana cu unghiul 0///




void Source1(G4ParticleGun *fParticleGun)
    {
    G4double xSource, ySource, zSource;

        xSource = 2.5*cm; //cm length on the x axis
        ySource = 2.5*cm; //cm height from the scintilator surface // CHANGE THE HEIGHT OF THE VERTEX OF THE PRIMARY PARTICLE //
        zSource = 100*cm; //cm length on the z axis



    G4double x, y, z;
    
    x = (G4UniformRand() - 0.5) * xSource;
    y = ySource;
    z = (G4UniformRand() - 0.5) * zSource;



    G4ThreeVector pos(x,y,z);

    fParticleGun->SetParticlePosition(pos);

    G4ThreeVector mom(0.*cm, -1.*cm, 0.*cm);

    fParticleGun->SetParticleMomentumDirection(mom);
}





    ///Sursa plana cu distributie unghiulara///



void Source2(G4ParticleGun *fParticleGun)
{

    G4double xSource, ySource, zSource;

    xSource = 500 * cm;
    ySource = 2.5 * cm;
    zSource = 20000 * cm;

    G4double x, y, z, x1, y1, z1;

    x1 = 0 * cm; // x coord '--' //The point all the particles go trough// It's also used for calculations of the angle of incidence
    y1 = 0 * cm; // y coord '--'
    z1 = 0 * cm; // z coord '--'


    x = (G4UniformRand() - 0.5) * xSource;
    y = ySource;
    z = (G4UniformRand() - 0.5) * zSource;

    G4ThreeVector mom(x1-x,y1-y,z1-z);

    G4ThreeVector pos(x, y, z);

    fParticleGun->SetParticlePosition(pos);

    fParticleGun->SetParticleMomentumDirection(mom);



}

//distributie unghiulara si distributie de energie

void Source3(G4ParticleGun *fParticleGun)
{

    #define PI 3.14159265
    G4double x, y, z, x1, y1, z1;
    G4double phi, theta;


    x1 = (G4UniformRand() - 0.5) * 2.5 * cm;
    y1 = 0.5 * cm;
    z1 = (G4UniformRand() - 0.5) * 100. *cm ; //coord. punctelor generate pe suprafata scintilatorului

    

    phi = G4UniformRand() * PI * 2;
    theta = G4UniformRand() * PI / 2;

    x= x1 + 10 * cm * sin(theta) * cos(phi);
    y= y1 + 10 * cm * cos(theta);
    z= z1 + 10 * cm * sin(phi) * sin(theta);

    G4double energy;

    energy = 3.0;

    fParticleGun->SetParticleEnergy(energy*GeV);

    G4ThreeVector mom(x1-x,y1-y,z1-z); //checked

    G4ThreeVector pos(x, y, z);

    fParticleGun->SetParticlePosition(pos);

    fParticleGun->SetParticleMomentumDirection(mom);
  
    G4AnalysisManager *man =  G4AnalysisManager::Instance();


    man->FillNtupleDColumn(0,8, phi);
    man->FillNtupleDColumn(0,9, theta);
    man->FillNtupleDColumn(0,5, x);
    man->FillNtupleDColumn(0,6, y);
    man->FillNtupleDColumn(0,7, z);
    man->FillNtupleDColumn(0,1, x1);
    man->FillNtupleDColumn(0,2, y1);
    man->FillNtupleDColumn(0,3, z1);

}




MyPrimaryGenerator::~MyPrimaryGenerator()
{
    delete fParticleGun;
}






void MyPrimaryGenerator::GeneratePrimaries(G4Event *anEvent)
{
    G4ParticleDefinition* particle = fParticleGun->GetParticleDefinition();



    ///Choosee the type of surce 1 or 2 or 3?///

    Source3(fParticleGun);


    ////////////////////polarization for photons//////////////////////////
    
  if(particle == G4OpticalPhoton::OpticalPhotonDefinition()) 
{ 
    G4double angle = G4UniformRand() * 360.0 * deg;

    G4ThreeVector normal(1., 0., 0.);

  G4ThreeVector kphoton = fParticleGun->GetParticleMomentumDirection();
  G4ThreeVector product = normal.cross(kphoton);
  G4double modul2       = product * product;

  G4ThreeVector e_perpend(0., 0., 1.);
  if(modul2 > 0.)
    e_perpend = (1. / std::sqrt(modul2)) * product;

  G4ThreeVector e_paralle = e_perpend.cross(kphoton);

  G4ThreeVector polar = std::cos(angle) * e_paralle + std::sin(angle) * e_perpend;
  fParticleGun->SetParticlePolarization(polar);
}





    fParticleGun->GeneratePrimaryVertex(anEvent);





}