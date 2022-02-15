// 01/31/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment main

#include <iostream>
#include "two_player.h"
using namespace std;

int main()
{
    char charinput;
    game_controller gc(CARD_EACH_TYPE);
    cout << "Generating deck for game play.. "<<endl;
    //gc.generate_deck();
    cout<<"Deck of cards generated. "<< gc.generate_deck()<<" cards generated to the deck. "<<endl;
    cout<<"Enter the option  [0] -> game play  [1] -> testing ADT";
    //cin.get(userinput,INPUT_SIZE,'\n');
    //cin.ignore(INPUT_SIZE,'\n');
    //sscanf(userinput, "%d", &number_of_cards);
    cin>>charinput;
    if(charinput == '0')
    {

        cout<<"0 input given"<<endl;
    }
    else if (charinput =='1')
    {

        cout<<"1 input given"<<endl;
        //gc.game_play();
    }

    else
    {
        cout<<"invalid input given"<<endl;
    }

    return 0;
}
