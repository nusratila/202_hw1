// 01/18/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under each class.

#include "two_player.h"
using namespace std;



//base card methods
//constructor
base_card::base_card()
{
    card_id = NULL;
}

//destructor
base_card::~base_card()
{
    delete[] card_id;
    card_id = NULL;
}


//copy constructor
base_card::base_card(const base_card & source)
{
    if(source.card_id)
    {
        card_id = new char[strlen(source.card_id) + 1];
        strcpy(card_id,source.card_id);
    }
    else
        card_id = NULL;
}


//constructor with argument
base_card::base_card(char* unique_name)
{
    if(unique_name)
    {
        strcpy(card_id,unique_name);
    }
}




void base_card::display()
{
    printf("card unique id is: %s", card_id);
}




void base_card::return_to_deck(deck *gamedeck)
{
    gamedeck->add_card(this);
}








//action card methods
//constructor
action_card::action_card()
{
    //set attack level to a random number between 1~5;
    attack_level = rand()%4 +1;
}


//implimentation of change_strength method
void action_card::change_strength()
{
    attack_level = rand()%4 +1;
}

void action_card::do_attack(player &  p)
{
    p.got_attack(attack_level);

}












//spell_card methods
//constructor
spell_card::spell_card()
{
    spell = NULL;
}


//copy constructor
spell_card::spell_card(const spell_card & source)
{
    if(source.spell)
    {
        spell = new char[strlen(source.spell) + 1];
        strcpy(spell,source.spell);
    }
    else
        spell = NULL;
}


void spell_card::cast_spell(player &p)
{
    p.got_spell(spell);
}



//defence-card methods
//constructor
defense_card::defense_card()
{
    spell = NULL;
    strength = 0;
}


//copy constructor
defense_card::defense_card(const defense_card & source)
{
    if(source.spell)
    {
        spell = new char[strlen(source.spell) + 1];
        strcpy(spell,source.spell);
    }
    else
        spell = NULL;
}










//deck methods
//constructor
deck::deck()
{
    head = NULL;
    total_card = 0;

}

//copy constructor
deck :: deck(const deck & source)
{
}

//ilplimentation of add)card method of deck class
void deck::add_card(base_card* a_card)
{
}









//hand class methods
//constructor
hand :: hand()
{
    head = NULL;
    total_card_in_hand = 0;
}











//player class methods
//constructor
player :: player()
{
    name = NULL;
    my_hand = NULL;
    life_point = 0;
    counter_play_needed = false;
    spell_recieved = NULL;
}


player :: player(const player & source)
{
    if(source.name)
    {
        name = new char[strlen(source.name) + 1];
        strcpy(name,source.name);
    }
    else
        name = NULL;

}

void player::got_attack(int attack_level)
{
    attack_recieved = attack_level;
    counter_play_needed = true;
}
void player::got_spell(char* spell_rcvd)
{
    if(spell_rcvd)
    {
        strcpy(spell_recieved,spell_rcvd);
    }
    counter_play_needed =true;
}






