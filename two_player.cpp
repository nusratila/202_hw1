
#include "two_player.h"
using namespace std;

////base card methods
base_card::base_card(char* unique_name)
{


}
base_card::base_card()
{

}
void base_card::display()
{
    printf("card unique id is: %s", card_id);
}

void base_card::return_to_deck(deck *gamedeck)
{
    gamedeck->addcard(this);
}

//action card methods
action_card::action_card()
{
    //set attack level to a random number between 1~5;
    attack_level = rand()%4 +1;
}
void action_card::change_strength()
{
    attack_level = rand()%4 +1;
}


void deck::addcard(base_card* a_card)
{

}
