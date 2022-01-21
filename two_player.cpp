
#include "two_player.h"
using namespace std;

base_card::(char* unique_name)
{

}
base_card::base_card()
{

}
action_card::action_card()
{
    //set attack level to a random number between 1~5;
    attack_level = rand()%4 +1;
}
void action_card::change_strength()
{
    attack_level = rand()%4 +1;
}
