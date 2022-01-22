// 01/18/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to create an object oriented program for a simple two-player game that allows players to use 'cards' which will be randomly picked to cast spells, attack opponent and defend themselves.

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
class deck;
class player;
class base_card
{
    public:
        base_card(char * );
        base_card(const base_card & source);
        base_card();
        ~base_card();
        void return_to_deck(deck *); // this method should put the card to the deck.
        char* get_card_id();
        void display();


    protected:
        char * card_id;
};

//Three derived classes from base_card: class action_card, class spell_card and class defense_card
class action_card : public base_card
{
    public:
        action_card();
        void do_attack(player p1); // this is equivalent to play card to attack opponent.
        void change_strength(); // if a player want to change the cards strength instead of playing card player can try to change attack level and attack_level will set randomly.
        void display();
        int comparecard();

    protected:
        int attack_level;
};


class spell_card : public base_card
{
    public:
        spell_card();
        spell_card(const spell_card & source);
        ~spell_card();
        void generate_spell(); // from the pool of spell player can get the spell randomly for play.
        void cast_spell(); // playing spell over the oponents
        void display();

    protected:
        char * spell;
};


class defense_card : public base_card  // this defense card can be played against both other card.it can be either a spell defence or attack defence card.
{
    public:
        defense_card();
        defense_card(const defense_card & source);
        ~defense_card();
        int defend_spell(); // if a strenth is 0 but spell is not null this method will counter the spell card.
        void create_new_spell(); // player can try to get a new spell to play in future round
        int defend_attack(); //player can play this card to defend attack and based on the strength it will be decided who will loose the life point and how many.

    protected:
        char * spell;
        int strength;

};

class node
{
    public:
        node();
        ~node();

    protected:
        base_card a_card;
        node * next;
};

class deck // collection of cards will be put together for each player to draw
{
    public:
        deck();
        deck(const deck & source);
        ~deck();
        void initiate(); // at the begining all the cards will be generated and shuffled.
        void display();
        void addcard(base_card* );
        base_card draw();// this will return a card to the player.
        void remove_card();


    private:
        node * head;
        int totalcard;
};
class hand
{
    public:
        hand();
        ~hand();
        void displayhand();
        void addcard();
        void removecard(int index);

    private:
        node* head;
        int totalcardinhand;
};
class player
{
    public:
        player(char *name);
        void add_card(base_card a_card);
        void display_hand();
    private:
        char* name;
        hand * my_hand;
        int life_point;

};


class game_controller  //'has a' relationship with class "deck"
{
    public:
        void game_initializer();    //initialize the game
        bool evaluate_result();     //evaluate result after each turn.It will return a bool. If any players win, then it will return true , otherwise false.

        void game_play();           //run the game. It will continue till the game end. It will continuously call another function evaluate_result(). The game will be continued till evaluate_result() returns true.:w


    protected:
        deck a_deck;
        player p1;
        player p2;
        /*

        char * p1_name;      //player 1
        char * p2_name;      //player 2
        base_card * p1_hand;    //hand of player one
        base_card * p2_hand;    //hand ofplayer 2
        */
};

