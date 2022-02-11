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
#include <unistd.h>
//this function is randomzi
void get_shuffled_index(int*, int);
class deck;
class player;
const int INPUT_SIZE = 100;
const int CARD_EACH_TYPE = 13;
class base_card
{
    public:
        base_card();
        base_card(char * );
        base_card(const base_card & source);
        void test()
        {
            //cout<<"hello";
            return;
        }
        ~base_card();
        void set_card_id(char * unique_name);
        char* get_card_id();
        virtual void change_card(char ** allspells, int num_spells);
        virtual void display()=0;
        virtual int which_card()=0;                 // this virtual function helps to identify the card type runtime.
        // Below functions implemented in derived class as needed
        virtual void do_attack(player &);
        virtual void cast_spell(player &);
        virtual char* get_spell();
        virtual int get_strength();

    protected:
        char * card_id;             //this is unique id for each card. each card should be assigned a id without a duplicate.
};

//Three derived classes from base_card: class action_card, class spell_card and class defense_card
class action_card : public base_card
{
    public:
        action_card();
        action_card(char*);
        void do_attack(player &); // this is equivalent to play card to attack opponent.
        void change_card(char ** allspells, int num_spells); // if a player want to change the cards strength instead of playing card player can try to change attack level and attack_level will set randomly.
        void display();
        action_card(const base_card &src);
        //int compare_card();
        int which_card();
    protected:
        int attack_level;           // this indicates the ability to attack opponent which can cause the opponent to loose life points.
};


class spell_card : public base_card
{
    public:
        spell_card();
        spell_card(char *);
        spell_card(const spell_card & source);
        ~spell_card();
        void change_card(char ** allspells, int num_spells); // from the pool of spell player can get the spell randomly for play.
        void cast_spell(player &); // playing spell over the oponents
        void display();

        int which_card();
    protected:
        char * spell;               // spell is different type of attack.
};

//defense card must be played as an answer to an attack which happened when other player plays an action / spell card.
//An instance of this card either can defend action card or defend against spell. can not be both together.
class defense_card : public base_card  // this defense card can be played against both other card.it can be either a spell defence or attack defence card.
{
    public:
        defense_card();
        defense_card(char *);
        defense_card(const defense_card & source);
        ~defense_card();
        int defend_spell(); // if a strenth is 0 but spell is not null this method will counter the spell card.
        void create_new_spell(); // player can try to get a new spell to play in future round
        int defend_attack(player &); //player can play this card to defend attack and based on the strength it will be decided who will loose the life point and how many.
        void display();
        char* get_spell();
        int get_strength();
        int which_card();
        void change_card(char ** allspells, int num_spells);
    protected:
        char * spell;
        int strength;

};

//node is for generating link list same data type is used by all link list used in this program.
struct node
{
    base_card * data;           // this data can store a card . to make it generic base_card is used instead of any derived card class.
    node * next;                //next pointer is used to chaining the linked list used.
};



class deck // collection of cards will be put together for each player to draw
{
    public:

        deck();
        deck(const deck & source);
        ~deck();
        void display();                         // display the whole deck of cards.
        void display(node*& head);
        int get_card_count();                   // it returns the whole cards in the list.
        void add_card(base_card *a_card );      // This method adds card to the deck.
        void add_card(node *& head,base_card* a_card);
        base_card* get_card();
        void delete_allcards();



    private:
        void delete_allcards(node*& head);
        node * head;
        int deck_card;

};



class player
{
    public:
        player();
        ~player();
        player(const player & source);
        void deep_copy_head (node* h,int index);
        player(char *name);
        void update_info(char* pname,int life_point,int card_capacity);
        void add_card(base_card * a_card);                 // from the deal_card function player will get some random cards in hand.
        void display_hand();                                // this will show all the cards in hand of a player.
        void display_hand(int card_type);                    // this will show specific types of the cards.
        void display_hand(node*& head);
        void play_attack(deck &b, player &p,int card_type,char * card_id);                  // this function will return a card selected by player and played against opponent p.
        int play_defense(deck &b,char * card_id);                  // this function will return a card selected by player and played against opponent p.
        void play_update_card(char** allspells,int num_spells,char* card_id,int card_type);
        void pick_card_from_deck(deck *&d);
        base_card * find_delete_card(node*&head, char*& id,bool do_delete);
        void got_attack(int );
        void got_spell(char*);
        int get_life_point();
        bool counter_play_needed();
        char * getname();
        void delete_allcards(int index);

    private:
        void delete_allcards(node*& head);
        void add_card(node *& head,base_card* &a_card);
        int max_card;
        char* name;
        node ** head;               //this array of link list head pointer stores all the cards a player has.
        int cards_in_hand;          //all the time each player will have the same number of cards in hand.
        int life_point;             //player life point is assigned during initialization
        int attack_recieved;        // one player can attack other player. this is updated when this player recieve attack
        char * spell_recieved;      // this stores the spell recieved from other player.
        //bool counter_play_needed;  // this bool var will tell whether the player has to play any counter card like spell card or defense card.

};


class game_controller  //'has a' relationship with class "deck" and "player" class
{
    public:
        game_controller();
        game_controller(int num_of_card_each_type);         // total card will be 3 times of each type. in the id file exact same card id should be given.
        ~game_controller();
        void game_play();           //run the game. It will continue till the game end. It will continuously call another function evaluate_result(). The game will be continued till evaluate_result() returns true.:w
        void show_deck();
        void generate_deck();       // this method will generate all cards.

    private:
        void deal_cards(int n);
        bool evaluate_result();     //evaluate result after each turn.It will return a bool. If any players win, then it will return true , otherwise false.
        int num_of_card_each_type;  //user has the option to choose how many cards to play with by setting this variable during object creation.
        deck * b_deck;              //one deck is used as board or discard pile
        deck * a_deck;              //other one for picking up card.
        player * p[2];
        base_card ** all_cards;     // array of all cards it instantiates with generate_deck() method call.
        char ** allspells;          // all the spells read from the file and stores here for use during game play.
        int num_spells;             // number of total spells that read from the file.
        int winner;                 //this is to track who is winner.

};

