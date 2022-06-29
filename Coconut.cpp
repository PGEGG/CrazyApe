#include "Coconut.h"
#include <iostream>
using namespace std;


Coconut::Coconut()
{

}


Coconut::~Coconut()
{

}
Coconut::Coconut(int y, int dem)
{
    posY = y;
    demage=dem;
}
void Coconut::Fly()
{
    posX++;
}
