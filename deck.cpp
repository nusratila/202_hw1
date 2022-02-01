// 01/31/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under Decks.

#include "two_player.h"

using namespace std;
//deck methods
//constructor
deck::deck()
{

    deck_card = 0;
    head = NULL;
}


//copy constructor
deck :: deck(const deck & source)
{
    head = NULL;

}


//destructo
deck::~deck()
{
    delete_allcards();
    if(head)
    {
        delete head;
        head = NULL;
    }

}
//cleaning up the card objects
void deck::delete_allcards()
{
    if(!head)
        return ;
    delete_allcards(head);
}
void deck::delete_allcards(node*& h)
{
    if(!h)
        return;
    else
    {
        node* temp = h;
        delete temp->data;
        temp->data = NULL;
        delete temp;
        temp = NULL;
        delete_allcards(h->next);
        return;
    }
}
//ilplimentation of add)card method of deck class
void deck::add_card(base_card *a_card)
{

    if(!head)
    {
        head = new node;
        head->next = NULL;
        head->data = a_card;
        deck_card++;
        return;
    }
    add_card(head,a_card);


}
void deck::add_card(node *& h,base_card* a_card)
{
    if(!head)
        return;
    if(!h->next)
    {
        h->next = new node;
        h->next->data = a_card;
        h->next->next = NULL;
        deck_card++;
        return;
    }
    add_card(h->next,a_card);
    return;
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
int deck::get_card_count()                //checking if the deck has enough card to play one round if not used cards from board will be added to the play deck.
{
    return deck_card;
}

base_card* deck::get_card()
{
    base_card * bc = NULL;
    if(head)
    {
        node * temp = head;
        head = head->next;
        deck_card--;
        bc=temp->data;
        delete temp;
        //return (temp->data);
    }
    return bc;
}
