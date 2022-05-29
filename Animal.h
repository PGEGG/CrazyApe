#ifndef Animal_h
#define Animal_h

class Animal
{
protected:
    int posX = 0;
    int posY = 0;
public:
    Animal();
    virtual ~Animal() = 0;
    virtual void move(int x, int y) = 0;
};


#endif