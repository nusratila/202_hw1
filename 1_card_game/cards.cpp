// 01/31/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under all cards.


#include "two_player.h"

using namespace std;
const int ATTACK_LEVEL=4;
//base card methods

//constructor with argument
base_card::base_card(char* unique_name)
{
    card_id = new char[strlen(unique_name)+1];
    if(unique_name)
    {
       strcpy(card_id,unique_name);
    }
}
base_card::base_card()
{
   card_id = NULL;
}
//destructor
base_card::~base_card()
{
    if(card_id)
    {
        delete[] card_id;
        card_id = NULL;
    }
}


void base_card::do_attack(player &)
{
    return;
}
void base_card::cast_spell(player &)
{
    return;
}
char* base_card::get_spell()
{
    return NULL;
}
int base_card::get_strength()
{
    return -1;
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


//virtual function and its implementation in the derived class

int action_card::which_card()
{
    return 0;
}
int spell_card::which_card()
{
    return 1;
}
int defense_card::which_card()
{
    return 2;
}

void base_card::set_card_id(char * unique_name)
{
if(unique_name)
    {
        if(card_id)
            delete[] card_id;
        card_id = new char[strlen(unique_name)+1];
        strcpy(card_id,unique_name);
    }

}
char* base_card::get_card_id()
{
    return card_id;
}


void base_card::change_card(char ** allspells, int num_spells)
{

}


void base_card::display()
{
    printf("card unique id is: %s\n", card_id);
}



void action_card::display()
{
    cout<<"Action#    ID: "<<card_id<<"     Strength: "<<attack_level<<endl;
}
void spell_card::display()
{
    cout<<"Spell#     ID: "<<card_id;
    if(spell)
        cout<<"     Spell: "<<spell;
    cout<<endl;
}
void defense_card::display()
{
    cout<<"Defense#   ID: "<<card_id;
    if(spell)
        cout<<"     Spell: "<<spell;
    if(strength)
        cout<<"     Defense: "<<strength;
    cout<<endl;
}






/*
action_card::action_card(const action_card &src)
{

}
*/






//action card methods
//constructor
action_card::action_card()
{

}
action_card::action_card(char * unique_name):base_card(unique_name)
{
    //base_card(unique_name);
    //set attack level to a random number between 1~5;
    attack_level = rand()%ATTACK_LEVEL +1;
}


//implimentation of change_strength method
void action_card::change_card(char ** allspells, int num_spells)
{
    attack_level = rand()%ATTACK_LEVEL +1;
}

void action_card::do_attack(player &  p)
{
    p.got_attack(attack_level);

}










//spell_card methods
//constructor
spell_card::spell_card()
{

}
spell_card::spell_card(char * unique_name):base_card(unique_name)
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

spell_card::~spell_card()
{
    if(spell)
        delete[] spell;
}
void spell_card::cast_spell(player &p)
{
    p.got_spell(spell);
}

void spell_card::change_card(char ** allspells, int num_spells)
{
    if(spell)
        delete[] spell;
    sleep(1);
    srand(time(0));
    int select = rand()%num_spells;
    char * newspell = *(allspells+select);
    spell = new char[strlen(newspell)+1];
    strcpy(spell,newspell);


}

//defence-card methods
//constructor
defense_card::defense_card()
{
}
defense_card::defense_card(char * unique_name):base_card(unique_name)
{
    spell = NULL;
    strength = 0;
    //base_card(NULL);
}
defense_card::~defense_card()
{

}
int defense_card::get_strength()
{
    return strength;
}
char * defense_card::get_spell()
{
    return spell;
}
void defense_card::change_card(char ** allspells, int num_spells)
{
    strength =0;
    if(spell)
        delete[] spell;
    srand(time(0));
    sleep(1);
    int ss=rand()%2;
    if(ss==0)
    {
        int select = rand()%num_spells;
        char * newspell = *(allspells+select);
        spell = new char[strlen(newspell)+1];
        strcpy(spell,newspell);
    }
    else
    {
        strength = rand()%ATTACK_LEVEL +1;
    }
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



