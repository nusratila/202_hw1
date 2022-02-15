// 01/31/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under players.

#include "two_player.h"

using namespace std;

void get_shuffled_index(int *arr, int n)
{

    for(int i = 0 ; i<n; i++)
    {
        arr[i]=i;
    }
    random_shuffle(arr,arr+n);
    //return arr;
}










//player class methods
//constructor
player :: player()
{
    cards_in_hand = 0;
    max_card = 6;
    name = NULL;
    spell_recieved = NULL;
    head = new node*[3];             // array of link list 3 different cards stored in 3 different linked list.
    head[0] = NULL;
    head[1] = NULL;
    head[2] = NULL;
    attack_recieved =0;
}


//copy constructor
player :: player(const player & source)
{
    if(source.name)
    {
        name = new char[strlen(source.name) + 1];
        strcpy(name,source.name);
    }
    else
        name = NULL;
    if(source.spell_recieved)
    {
        spell_recieved = new char[strlen(source.spell_recieved) + 1];
        strcpy(spell_recieved,source.spell_recieved);
    }
    else
        spell_recieved = NULL;
    head = new node*[3];
    deep_copy_head(head[0],0);
    deep_copy_head(head[1],1);
    deep_copy_head(head[2],2);

}
void player::deep_copy_head (node* h,int index)
{
    if(!h)
        return;
    else
    {
        head[index]->data = h->data;
        head[index]->next = h->next;
        deep_copy_head(h->next,index);
        return;
    }

}
//destructor
player::~player()
{
    delete_allcards(0);
    delete_allcards(1);
    delete_allcards(2);
    if(head)
        delete[] head;
    if(name)
        delete[] name;
    if(spell_recieved)
        delete[] spell_recieved;


}
void player::delete_allcards(int index)
{
    cout<<"deleting cards from player"<<index<<endl;
   if(head[index])
        return;
   delete_allcards(head[index]);
   return;

}
void player::delete_allcards(node *& head)
{
    if(head)
        return;
    else
    {
        node* temp = head;
        delete temp->data;
        temp->data = NULL;
        delete temp;
        temp = NULL;
        delete_allcards(head->next);
        return;
    }
}
void player::update_info(char* pname,int life_point,int card_capacity)
{
    max_card = card_capacity;
    name = new char[strlen(pname)+1];
    strcpy(name,pname);
    this->life_point = life_point;

}

void player::got_attack(int attack_level)
{
    attack_recieved = attack_level;

}
void player::got_spell(char* spell_rcvd)
{
    if(spell_rcvd)
    {
        if(spell_recieved)
            delete[] spell_recieved;
        else
            spell_recieved = new char(strlen(spell_rcvd)+1);
        strcpy(spell_recieved,spell_rcvd);
    }

}
void player::add_card(base_card * a_card)
{
    int cardgroup = a_card->which_card();
    add_card(head[cardgroup],a_card);
}
void player::add_card(node *& h,base_card* &a_card)
{
    if(!h)
    {
        h = new node;
        h->data = a_card;
        h->next = NULL;
        cards_in_hand++;
        return;
    }
    add_card(h->next,a_card);
}
int player::get_life_point()
{
    return life_point;
}
bool player::counter_play_needed()
{
    bool counter_play_needed = false;
    if((spell_recieved)||(attack_recieved>0))
    {
        counter_play_needed = true;
    }
    return counter_play_needed;
}
void player::display_hand()
{

    cout<<endl;

    cout<<"============ALL the action card in hand============"<<endl;
    display_hand(head[0]);
    cout<<endl;
    cout<<"============ALL the spell card in hand============="<<endl;
    display_hand(head[1]);
    cout<<endl;
    cout<<"============ALL the defense card in hand============"<<endl;
    display_hand(head[2]);
    cout<<endl<<endl;

}
void player::display_hand(int card_type)
{
    cout<<"============ALL the defense card in hand============"<<endl;
    display_hand(head[card_type]);
    cout<<endl<<endl;
}
void player::display_hand(node*& head)
{
    if(!head)
        return;
    head->data->display();
    display_hand(head->next);
}


base_card * player::find_delete_card(node* &head, char*& id,bool do_delete)
{
    base_card * ret=NULL;
    bool delete_node = false;           // This is to identify if the node is getting deleted.
    if(!head)
        return NULL;
    bool match = strcmp(id,head->data->get_card_id());     // matching the id from the link list nodes.
    if(!match)
    {
        node * temp = head;
        ret = head->data;
        if(do_delete)
        {
            head=head->next;
            cards_in_hand--;
            delete temp;
            delete_node = true;
        }
        return ret;
    }
    if(delete_node)
        ret=find_delete_card(head,id,do_delete);
    else
        ret=find_delete_card(head->next,id,do_delete);

    return ret;
}

void player::play_attack(deck & discard_deck, player & p,int card_type,char * card_id)
{

    base_card * bc = find_delete_card(head[card_type],card_id,true);
    if(bc)
    {
        discard_deck.add_card(bc);
        if(bc->which_card()==0)
            bc->do_attack(p);

        if(bc->which_card()==1)
            bc->cast_spell(p);
    }


}
int player::play_defense(deck &discard_deck,char* card_id)
{
    int lost_life = 0;
    if(attack_recieved>0)
    {
        lost_life = attack_recieved;
    }
    if(spell_recieved)
    {
        lost_life = 1;
    }
    base_card * dc = find_delete_card(head[2],card_id,true);
    if(dc)
    {
        discard_deck.add_card(dc);
        char * card_spell = dc->get_spell();
        int card_strength = dc->get_strength();
        if(card_strength>0 && attack_recieved>0)
        {
            if(card_strength<lost_life)
                lost_life -=card_strength;

        }
        if(card_spell && spell_recieved)
        {
            if(strcmp(card_spell,spell_recieved))
                lost_life = 0;
        }
    }
    attack_recieved = 0;
    if(spell_recieved)
        delete[] spell_recieved;
    spell_recieved = NULL;

    // checking if the lost life is greater than the current life point if so then set to 0.
    if(life_point>lost_life)
        life_point-=lost_life;
    else
        life_point = 0 ;
    return lost_life;


}
char * player::getname()
{
    return name;
}
void player::pick_card_from_deck(deck *&d)
{
    if(cards_in_hand<max_card)
    {
        add_card(d->get_card());

    }
}
void player::play_update_card(char ** allspells,int num_spells,char* card_id,int card_type)
{
    base_card * bc = find_delete_card(head[card_type],card_id,false);
    if(bc)
        bc->change_card( allspells, num_spells);
}


//wrapper for remove_card method. based on the provided id this will remove the card from hand of player.
int player::remove_card(char * id)
{
    int index = 0 ;
    node * thead = *head;
    return remove_card(id, thead,index);
}
//recursive method for remove_card method. returns 0 on failure to find and delete and 1 for delete.
int player::remove_card(char *id , node * &head, int &index)
{
    int res = 0 ;
    if(index==3)
        return res;
    if(!head)
    {
        remove_card( id, *(this->head + index),++index);
    }
    else
    {
        res = remove_card(id,head->next,index);
        if(!strcmp(id,head->data->get_card_id()))
            {
                node * temp = head;
                head = head->next;
                delete temp->data;
                delete temp;
                res = 1;
            }
    }
    return res;
}


base_card * player::retrieve_card(char * id)
{
    int index = 0 ;
    node * thead = *head;
    return retrieve_card(id, thead,index);
}


base_card * player::retrieve_card(char *id , node * &head, int &index)
{
    base_card * bc = NULL;
    if(index==3)
        return bc;
    if(!head)
    {
        remove_card( id, *(this->head + index),++index);
    }
    else
    {
        if(!strcmp(id,head->data->get_card_id()))
            bc = head->data;
        bc = retrieve_card(id,head->next,index);
    }
    return bc;
}
