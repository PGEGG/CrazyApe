#ifndef Coconut_h
#define Coconut_h
#include "Item.h"

class Coconut : public Item {
private:
    int demage;
public:
    Coconut();
    Coconut(int y, int dem);
    ~Coconut();
    void Fly();


};
#endif