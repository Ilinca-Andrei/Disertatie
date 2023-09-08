#include "hit.hh"

MyHit::MyHit():G4VHit()
{}
MyHit::~MyHit()
{}

G4ThreadLocal G4Allocator<MyHit>* MyHitAllocator = 0;