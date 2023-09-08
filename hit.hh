#ifndef HIT_HH
#define HIT_HH

#include "G4VHit.hh"
#include "G4Allocator.hh"
#include "G4ThreeVector.hh"
#include "G4THitsCollection.hh"
#include "tls.hh"



class MyHit : public G4VHit
{
public:

	MyHit();
	virtual ~MyHit();

	MyHit(const MyHit &right);

	const MyHit& operator = (const MyHit &right);

	int operator == (const MyHit &right) const;

	void Draw(){;};

	void Print(){;};


	inline void* operator new(size_t);

	inline void operator delete(void *);

public:

	inline void SetPhot1(double no) { phot1 = no;}
	inline double GetPhot1() { return phot1;}

	inline void SetPhot2(double no) { phot2 = no;}
	inline double GetPhot2() { return phot2;}

	inline void AddPhot1() { phot1++;}
	inline void AddPhot2() { phot2++;}

private:
	int phot1 = 0, phot2= 0;

};

	typedef G4THitsCollection<MyHit> MyHitsCollection;

	extern G4ThreadLocal G4Allocator<MyHit> *MyHitAllocator;
	


	inline void* MyHit::operator new(size_t)

{

	if(!MyHitAllocator) MyHitAllocator = new G4Allocator<MyHit>;

	return (void*) MyHitAllocator->MallocSingle();

}


	inline void MyHit::operator delete(void *aHit)

{
	if(!MyHitAllocator)

		MyHitAllocator = new G4Allocator<MyHit>;


	MyHitAllocator->FreeSingle((MyHit*) aHit);

}


#endif