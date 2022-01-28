// 01/18/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to create an object oriented program for a simple two-player game that allows players to use 'cards' which will be randomly picked to cast spells, attack opponent and defend themselves.
#include <algorithm>
#include <fstream>
#include <string>
#include<time.h>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
void get_shuffled_index(int*, int);
class deck;
class player;
class base_card
{
    public:
        base_card();
        base_card(char * );
        base_card(const base_card & source);

        ~base_card();
        void return_to_deck(deck &); // this method should put the card to the deck.
        void set_card_id(char * unique_name);
        char* get_card_id();
        virtual void display();
        virtual int which_card();

    protected:
        char * card_id;
};

//Three derived classes from base_card: class action_card, class spell_card and class defense_card
class action_card : public base_card
{
    public:
        action_card(char*);
        void do_attack(player &); // this is equivalent to play card to attack opponent.
        void change_strength(); // if a player want to change the cards strength instead of playing card player can try to change attack level and attack_level will set randomly.
        void display();
        //int compare_card();
        int which_card();
    protected:
        int attack_level;
};


class spell_card : public base_card
{
    public:
        spell_card(char *);
        spell_card(const spell_card & source);
        ~spell_card();
        void set_update_spell(char ** allspells, int num_spells); // from the pool of spell player can get the spell randomly for play.
        void cast_spell(player &); // playing spell over the oponents
        void display();

        int which_card();
    protected:
        char * spell;
};


class defense_card : public base_card  // this defense card can be played against both other card.it can be either a spell defence or attack defence card.
{
    public:
        defense_card(char *);
        defense_card(const defense_card & source);
        ~defense_card();
        int defend_spell(); // if a strenth is 0 but spell is not null this method will counter the spell card.
        void create_new_spell(); // player can try to get a new spell to play in future round
        int defend_attack(player &); //player can play this card to defend attack and based on the strength it will be decided who will loose the life point and how many.
        void display();
        int which_card();
    protected:
        char * spell;
        int strength;

};

struct node
{
    base_card * data;
    node * next;
};

class board
{
public:
    board();
    ~board();
    void discard_to_board(base_card * a_card);        //this is basically adding card to board
    void discard_to_board(node * & head,base_card *& a_card);
    base_card * get_random_card();                  // getting a random card and put back to deck will ensure shuffling.
    void display_board();
    void display(node*& head);
private:
    node * head;
    int total_card;
};




class deck // collection of cards will be put together for each player to draw
{
    public:

        deck();
        deck(const deck & source);
        ~deck();
        //void create_cards(); // at the begining all the cards will be generated and shuffled.
        void display();
        void display(node*& head);
        bool hascard();
        void add_card(base_card *& a_card );
        void add_card(node *& head,base_card* &a_card);
        base_card draw();// this will return a card to the player.
        base_card*& get_card();
        char * get_random_spell();


    private:
        node * head;
        int total_card;
        char ** allspells; // fire->water / spinach earthquaq->
        int num_spells;
};





/*
class hand
{
    public:
        hand();
        ~hand();
        void display_hand();
        void add_card();
        void remove_card(int index);

    private:
        node ** head;       //this will be  a array of link list. array
        int total_card_in_hand;
};

*/

class player
{
    public:
        player();
        player(const player & source);
        player(char *name);
        void update_info(char* pname,int life_point);
        void add_card(base_card *& a_card);                 // from the deal_card function player will get some random cards in hand.
        void add_card(node *& head,base_card* &a_card);
        void display_hand();                                // this will show all the cards in hand of a player.
        void display_hand(node*& head);
        void play_card(board *b, player *p);                  // this function will return a card selected by player and played against opponent p.
        void pick_card_from_deck(deck* &d);
        void got_attack(int );
        void got_spell(char*);

    private:
        char* name;
        node ** head;
        int cards_in_hand;
        int life_point;
        int attack_recieved;
        char * spell_recieved;
        bool counter_play_needed;  // this bool var will tell whether the player has to play any counter card like spell card or defense card.

};


class game_controller  //'has a' relationship with class "deck"
{
    public:
        game_controller(int num_of_card_each_type);
        ~game_controller();
        void game_initializer();    //initialize the game create two player.
        void deal_cards();
        bool evaluate_result();     //evaluate result after each turn.It will return a bool. If any players win, then it will return true , otherwise false.
        void generate_deck();       // this method will generate all cards.
        void game_play();           //run the game. It will continue till the game end. It will continuously call another function evaluate_result(). The game will be continued till evaluate_result() returns true.:w


    protected:
        int num_of_card_each_type;
        deck * a_deck;
        player * p[2];
        base_card ** all_cards;
        //player p2;
        /*

        char * p1_name;      //player 1
        char * p2_name;      //player 2
        base_card * p1_hand;    //hand of player one
        base_card * p2_hand;    //hand ofplayer 2
        */
};

