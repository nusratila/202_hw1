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


}
board::~board()
{

}

void board::discard_to_board(base_card*& a_card)
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
void board::discard_to_board(node*& temp_head,base_card*& a_card)
{
    if(!temp_head->next)
    {
        temp_head->next = new node;
        temp_head->next->data = a_card;
        temp_head->next->next = NULL;
        total_card++;
        return;
    }
    discard_to_board(head->next,a_card);
}
base_card * board::get_random_card()
{

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
