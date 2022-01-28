// 01/18/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under each class.

#include "two_player.h"

using namespace std;
//deck methods
//constructor
deck::deck()
{
    cout<< "deck called\n";
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


    allspells = new char* [num_spells];
    spellfile.open("spell.txt");
    if(spellfile.is_open())
    {
        int i = 0;
        while(getline(spellfile,line))
        {
            //cout<<line<<line.length()<<  endl;
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


}


//copy constructor
deck :: deck(const deck & source)
{
    head = NULL;

}

deck::~deck()
{
    if(allspells)
        delete [] allspells;

}
//ilplimentation of add)card method of deck class
void deck::add_card(base_card *&a_card)
{
    if(!head)
    {
        head = new node;
        head->next = NULL;
        head->data = a_card;
        total_card++;
        return;
    }
    add_card(head,a_card);
}
void deck::add_card(node *& temp_head,base_card* &a_card)
{
    if(!temp_head->next)
    {
        temp_head->next = new node;
        temp_head->next->data = a_card;
        temp_head->next->next = NULL;
        total_card++;
        return;
    }
    add_card(head->next,a_card);

}

void deck::display()
{
    if(!head)
        return;
    display(head);
}
void deck::display(node*& head)
{
    if(head)
    {
       head->data->display();
       display(head->next);
    }
}
bool deck::hascard()                //checking if the deck has enough card to play one round if not used cards from board will be added to the play deck.
{
    if(total_card-2>0)
        return true;
    else
        return false;
}


base_card*& deck::get_card()
{
    base_card * bc = NULL;
    if(head)
    {
        node * temp = head;
        head = head->next;
        total_card--;
        return (temp->data);
    }
    return bc;
}
