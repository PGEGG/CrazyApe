# CrazyApe

array:
0: -empty
1: -player(ape)     mooves around the field according WASD
2: -red_coconut     ape loose 2 lifes, moves from left to right, flies further if they touch
3: -brown_coconut    ape loose 1 lifes, moves from left to rigth, flies further if they touch
4: -banana      collect banana, banana removes if they touch
5: -heart       increases live of ape, heart removes if they touch
6: -Tree        only blocks the field
7: -Tiger       moves random around the field,  ape dies if the touch
8: -Scorpion    moves random around the field,  ape loses 1 life if the touch


rules: 
winnig: if 3(all) bananas are collected and reahes sporning point

death: -lives empty(0)
       -touch the tiger