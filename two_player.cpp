// 01/18/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under each class.

#include "two_player.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void get_shuffled_index(int *arr, int n)
{
    //int arr[n];
    for(int i = 0 ; i<n; i++)
    {
        arr[i]=i+1;
    }
    random_shuffle(arr,arr+n);
    for (int i = 0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    cout<<arr<<endl;
    //return arr;
}

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


void base_card::set_card_id(char * unique_name)
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




void base_card::return_to_deck(deck &gamedeck)
{
    gamedeck.add_card(this);
}

char * base_card::get_card_id()
{
    return card_id;
}







//action card methods
//constructor
action_card::action_card(char * unique_name):base_card(unique_name)
{
    //base_card(unique_name);
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
spell_card::spell_card(char * unique_name)
{
    //base_card(unique_name);
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

}
void spell_card::cast_spell(player &p)
{
    p.got_spell(spell);
}



//defence-card methods
//constructor
defense_card::defense_card(char * unique_name)
{
    spell = NULL;
    strength = 0;
    //base_card(NULL);
}
defense_card::~defense_card()
{

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
    cout<< "deck called";
    num_spells =0;
    head = NULL;
    total_card = 0;
    //reading the spell file for list of spells
    string line;
    ifstream spellfile("spell.txt");

    if(spellfile.is_open())
    {
        while(getline(spellfile,line))
            num_spells++;
        spellfile.close();
    }
    else
        cout<<"can not open spell file"<<endl;

    cout<< "t c :"<< num_spells<<endl;
    allspells = new char* [num_spells];
    spellfile.open("spell.txt");
    if(spellfile.is_open())
    {
        int i = 0;
        while(getline(spellfile,line))
        {
            cout<<line<<line.length()<<  endl;
            allspells[i] = new char[line.length()];
            strcpy(allspells[i],line.c_str());
            i++;
        }
        spellfile.close();

    }
    else
    {
        cout<<"can not open spell file"<<endl;
    }
    for(int i = 0; i<num_spells;i++)
    {
        cout<<allspells[i]<<endl;
    }

}
void deck::create_cards()
{

}

//copy constructor
deck :: deck(const deck & source)
{

}

deck::~deck()
{
    if(allspells)
        delete [] allspells;

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
game_controller::game_controller(int num_card )
{
    num_of_card_each_type = num_card;
    a_deck = new deck();
    p[0] = new player();
    p[1] = new player();
}
game_controller::~game_controller()
{

}

void game_controller::generate_deck()
{
    int totalcards = 3*num_of_card_each_type;
    int  index[totalcards];
    get_shuffled_index(index,totalcards);
    base_card all_cards[totalcards];
    int temp_index=0;
    for(int i = 0 ; i<num_of_card_each_type;i++)
    {
        action_card ac();
        //all_cards[temp_index] = ac;
        //delete ac
        temp_index++;
    }
    for(int i = 0 ; i<num_of_card_each_type;i++)
    {
        defense_card dc("o");
        all_cards[temp_index] = dc;
        //delete dc
        temp_index++;
    }
    for(int i = 0 ; i<num_of_card_each_type;i++)
    {
        spell_card sc("d");
        all_cards[temp_index] = sc;
        //delete sc
        temp_index++;
    }

}
//this will intialize the game
//shuffle cards and distribute few cards.
void game_controller::game_initializer()
{

}

