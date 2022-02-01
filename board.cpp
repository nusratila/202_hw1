// 01/18/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under each class.

#include "two_player.h"

using namespace std;

//board methods
//constructor

board::board()
{
    total_card=0;
    head = NULL;

}
board::~board()
{

}
//this is basically discarding a card to board.
void board::discard_to_board(base_card* a_card)
{
    if(!head)
    {
        head = new node;
        head->next = NULL;
        head->data = a_card;
        total_card++;
        return;
    }
    discard_to_board(head,a_card);
}
void board::discard_to_board(node*& head,base_card*& a_card)
{
    if(!head->next)
    {
        head->next = new node;
        head->next->data = a_card;
        head->next->next = NULL;
        total_card++;
        return;
    }
    discard_to_board(head->next,a_card);
}
base_card * board::get_random_card()
{
    base_card * ret ;
    // if there is only one card return the card and set head to NULL
    if(total_card==1)
    {
        ret = head->data;
        delete head;
        head = NULL;
        return ret;
    }
    else if(total_card==0)      // if there is 0 card returning NULL.
    {
        return NULL;
    }

    srand(time(0));             //This seed ensures a true random number generation it is using current time as seed.
    int select = rand()%total_card;
    node * temp = head;
    for(int i = 0 ; i<select-1 ; i++)
        temp = temp->next;
    node * hold = temp->next;
    ret = hold->data;
    if(!temp->next)
    {
        delete hold;
        temp->next = NULL;
    }
    else
    {
        temp->next = temp->next->next;
        delete hold;
    }
    total_card--;
    return ret;
}
void board::display_board()
{
    if(!head)
        return;
    display(head);
}
void board::display(node*& head)
{
    if(head)
    {
       head->data->display();
       display(head->next);
    }
}
