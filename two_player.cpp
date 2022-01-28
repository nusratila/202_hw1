// 01/18/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under each class.

#include "two_player.h"

using namespace std;

void get_shuffled_index(int *arr, int n)
{
    //int arr[n];
    for(int i = 0 ; i<n; i++)
    {
        arr[i]=i;
    }
    random_shuffle(arr,arr+n);

    //cout<<arr<<endl;
    //return arr;
}




/*
//hand class methods
//constructor
hand :: hand()
{
    head = NULL;
    total_card_in_hand = 0;
}



*/







//player class methods
//constructor
player :: player()
{
    name = NULL;
    counter_play_needed = false;
    spell_recieved = NULL;
    head = new node*[3];             // array of link list 3 different cards stored in 3 different linked list.
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
void player::update_info(char* pname,int life_point)
{
    name = new char[strlen(pname)+1];
    strcpy(name,pname);
    life_point = life_point;

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
void player::add_card(base_card *& a_card)
{
    int cardgroup = a_card->which_card();
    add_card(head[cardgroup],a_card);
}
void player::add_card(node *& head,base_card* &a_card)
{
    if(!head)
    {
        head = new node;
        head->data = a_card;
        head->next = NULL;
        return;
    }
    add_card(head->next,a_card);
}
void player::display_hand()
{
    cout<<endl<<endl;    cout<<"============ALL the action card in hand============"<<endl;
    display_hand(head[0]);
    cout<<endl<<endl;
    cout<<"============ALL the action card in hand============"<<endl;    display_hand(head[1]);
    cout<<endl<<endl;
    cout<<"============ALL the action card in hand============"<<endl;
    display_hand(head[2]);

}
void player::display_hand(node*& head)
{
    if(!head)
        return;
    head->data->display();
    display_hand(head->next);
}
void player::play_card(board * b, player *p)
{

}
void player::pick_card_from_deck(deck *&d)
{

}
