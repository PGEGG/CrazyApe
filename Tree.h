#ifndef Tree_h
#define Tree_h
#include "Item.h"
#include "Player.h"

class Tree: public Item
{

public:
    Tree();
    //Tree(float x, float y);

    void treeCollision(Player *player, Tree *tree);

    ~Tree();
    
};



#endif