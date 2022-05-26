#ifndef Coconut_h
#define Coconut_h

class Coconut: public Item
{
private:
    int damage;
public:
    Coconut();
    Coconut(int y);
    ~Coconut();
    void Fly();
};



#endif