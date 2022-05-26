#ifndef Gamecontroller_h
#define Gamecontroller_h

#define FIELDSIZEX 50
#define FIELDSIZEY 40

class Gamecontroller
{
private:
    int runtime = 0;
    int field[FIELDSIZEY][FIELDSIZEX];

    bool checkDeath();
    bool freePosition(int x, int y);
public:
    Gamecontroller();
    ~Gamecontroller();

    void startGame();
    void reset();
    bool checkWon();
};

#endif