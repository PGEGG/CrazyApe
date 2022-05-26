#ifndef Animal_h
#define Animal_h

class Animal
{
private:
    int posX = 0;
    int posY = 0;
public:
    virtual void move(int x, int y) = 0;
};


#endif