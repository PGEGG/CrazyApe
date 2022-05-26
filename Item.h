#ifndef Item_h
#define Item_h

class Item
{
private:
    virtual int posX;
    virtual int posY;

public: 
    virtual void setField(int x, int y);
};




#endif