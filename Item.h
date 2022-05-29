#ifndef Item_h
#define Item_h

class Item
{
protected:
    int posX;
    int posY;

public: 
    Item();
    virtual ~Item()=0;
    //virtual void setField(int x, int y) = 0;
};




#endif