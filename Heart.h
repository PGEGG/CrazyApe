#ifndef Heart_h
#define Heart_h

class Heart: public Item
{
private:
    int lifetime;
public:
    Heart();
    Heart(int x, int y);
    ~Heart();
};

#endif