// 01/31/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment main

#include <iostream>
#include "two_player.h"
using namespace std;

int main()
{
    cout<<"This is a simple two player card game."<<endl;
    game_controller gc(CARD_EACH_TYPE);
    gc.game_play();

    return 0;
}
