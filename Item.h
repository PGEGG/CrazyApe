#ifndef Item_h
#define Item_h

class Item
{
private:
    int posX;
    int posY;

public: 
    virtual void setField(int x, int y) = 0;
};




#endif