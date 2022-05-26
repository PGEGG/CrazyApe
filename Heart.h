#ifndef Heart_h
#define Heart_h

class Heart: public Item
{
private:
    int lifetime;
public:
    heart();
    heart(int x, int y);
    ~heart();
};

#endif