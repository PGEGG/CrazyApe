#include <iostream>
#define FIELDSIZEX 20
#define FIELDSIZEY 10

int main(int argc, char* argv[]){

    int field[FIELDSIZEX][FIELDSIZEY];
    
    int ape = 1;
    int banana = 3;
    int tree = 4;
    int coconut = 5;

    for (int i = 0; i < FIELDSIZEX; i++)
    {
        for (int j = 0; j < FIELDSIZEY; j++)
        {
            field[i][j] = 0;
            printf("%d", field[i][j]);
        }
        printf("\n");
    }
    

}//end main