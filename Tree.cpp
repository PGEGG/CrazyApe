#include "Tree.h"
#include <iostream>

Tree::Tree()
{

}


Tree::~Tree()
{

}
Tree::Tree(float x, float y)
{
    
    if (!(image.loadFromFile("images\\BANANATREE.png")));
    {
        std::cerr << "Can`t load image!";
    }

    itemWidth = 80.f;
    itemHeight = 80.f;

    /// Smooths the pixels (Sharpen the image)
    texture.setSmooth(true);
    /// Give Image to texture
    texture.loadFromImage(image);

    // declarate Sprite
    sprite.setPosition(x, y);

    // Texture to Sprite
    sprite.setTexture(texture);
    sprite.setScale(sf::Vector2f(scaleWidth, scaleHeight));
 
}

void Tree::treeCollision(Player *player, Tree *tree)
{
    /*if (myPlayer->sprite.getPosition().x <= myTree->sprite.getPosition().x ||
                myPlayer->sprite.getPosition().x <= myTree2->sprite.getPosition().x ||
                myPlayer->sprite.getPosition().x <= myTree3->sprite.getPosition().x)
        {
            myPlayer->sprite.setPosition(myPlayer->sprite.getPosition().x -5.f, myPlayer->sprite.getPosition().y);
        }else if (myPlayer->sprite.getPosition().x >= myTree->sprite.getPosition().x ||
                    myPlayer->sprite.getPosition().x >= myTree2->sprite.getPosition().x ||
                    myPlayer->sprite.getPosition().x >= myTree3->sprite.getPosition().x)
        {
            myPlayer->sprite.setPosition(myPlayer->sprite.getPosition().x +5.f, myPlayer->sprite.getPosition().y);
        }else if (myPlayer->sprite.getPosition().y >= myTree->sprite.getPosition().y ||
                    myPlayer->sprite.getPosition().y >= myTree2->sprite.getPosition().y ||
                    myPlayer->sprite.getPosition().y >= myTree3->sprite.getPosition().y)
        {
            myPlayer->sprite.setPosition(myPlayer->sprite.getPosition().x, myPlayer->sprite.getPosition().y -5.f);
        }else if (myPlayer->sprite.getPosition().y <= myTree->sprite.getPosition().y ||
                    myPlayer->sprite.getPosition().y <= myTree2->sprite.getPosition().y ||
                    myPlayer->sprite.getPosition().y <= myTree3->sprite.getPosition().y)
        {
            myPlayer->sprite.setPosition(myPlayer->sprite.getPosition().x, myPlayer->sprite.getPosition().y +5.f);
        }*/
        if (player->sprite.getPosition().x <= tree->sprite.getPosition().x)
        {
            player->sprite.setPosition(player->sprite.getPosition().x -5.f, player->sprite.getPosition().y);
        }else if (player->sprite.getPosition().x >= tree->sprite.getPosition().x)
        {
            player->sprite.setPosition(player->sprite.getPosition().x +5.f, player->sprite.getPosition().y);
        }else if (player->sprite.getPosition().y >= tree->sprite.getPosition().y)
        {
            player->sprite.setPosition(player->sprite.getPosition().x, player->sprite.getPosition().y -5.f);
        }else if (player->sprite.getPosition().y <= tree->sprite.getPosition().y)
        {
            player->sprite.setPosition(player->sprite.getPosition().x, player->sprite.getPosition().y +5.f);
        }
}