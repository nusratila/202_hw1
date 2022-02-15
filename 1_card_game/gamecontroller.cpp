// 01/31/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under game controller class.

#include "two_player.h"

using namespace std;

game_controller::game_controller()
{

}
game_controller::game_controller(const game_controller & source)
{
        b_deck;              //one deck is used as board or discard pile
        deck * a_deck;              //other one for picking up card.
    /*
        player * p[2];
        base_card ** all_cards;     // array of all cards it instantiates with generate_deck() method call.
        char ** allspells;
        */

}
game_controller::game_controller(int num_card )
{
    num_of_card_each_type = num_card;   //constructor initialized the number of card each type
    a_deck = new deck();        // discard deck
    b_deck = new deck();        //draw deck
    p[0] = new player();        //player 1
    p[1] = new player();        //player 2
    num_spells =0;              //keep track of total number of spell available.

    //reading the spell file for list of spells
    string line;
    ifstream spellfile("spell.txt");       //spell.txt contains all the spells.


    //read the file to get the count.
    if(spellfile.is_open())
    {
        while(getline(spellfile,line))
            num_spells++;
        spellfile.close();
    }
    else
        cout<<"can not open spell file"<<endl;


    allspells = new char* [num_spells];

    //read the file again to read the spell.
    spellfile.open("spell.txt");
    if(spellfile.is_open())
    {
        int i = 0;
        while(getline(spellfile,line))
        {
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
    winner = 0 ;
}
game_controller::~game_controller()
{
    //destructor to destroy all the decks and players
    delete a_deck;
    delete b_deck;
    delete p[0];
    delete p[1];
    if(allspells)
        delete [] allspells;
}


// this method is for generating deck of cards. it will randomize the cards
// card id to be read from the id.txt file.
int game_controller::generate_deck()
{

    cout<<"Generating deck of cards. the delay of generation is added to ensure better randomization.  "<<endl;

    int totalcards = 3*num_of_card_each_type;
    char ** allids = new char* [totalcards];

    //reading the id.txt file fro all the card ids.
    ifstream idfile("id.txt");
    string line;
    if(idfile.is_open())
    {
        int i = 0;
        while(getline(idfile,line))
        {
            allids[i] = new char[line.length()];
            strcpy(allids[i],line.c_str());
            i++;
        }
        idfile.close();


    }
    else
    {
        cout<<"can not open id file"<<endl;
        return 0;
    }

    // generating a list of index.
    int  index[totalcards];
    //shuffle those index using a function call.
    get_shuffled_index(index,totalcards);

    // creating the list of pointers equal to the cards.
    all_cards = new base_card*[totalcards];
    int temp_index=0;
    for(int i = 0 ; i<num_of_card_each_type;i++)
    {
        cout<<"action card: "<<index[temp_index]<<endl;
        // creating action cards
        all_cards[index[temp_index]] =new action_card(*(allids+i));
        temp_index++;
    }

    for(int i = 0 ; i<num_of_card_each_type;i++)
    {
        cout<<"defense card: "<<index[temp_index]<<endl;
        //creating defense card
        all_cards[index[temp_index]] =new defense_card(*(allids+i+num_of_card_each_type));
       all_cards[index[temp_index]]->change_card(allspells,num_spells);
        temp_index++;
    }
    for(int i = 0 ; i<num_of_card_each_type;i++)
    {
        cout<<"spell card: "<<index[temp_index]<<endl;
        // creating spell card object.
        all_cards[index[temp_index]] =new spell_card(*(allids+i+2*num_of_card_each_type));
        all_cards[index[temp_index]]->change_card(allspells,num_spells);
        temp_index++;
    }

    for (int i =0; i<totalcards;i++)
    {
        base_card * bc = all_cards[i];
        bc->display();

    }

    //delete allcards

    for (int i =0; i<totalcards;i++)
    {
       // delete[] *(allids+i);
        a_deck->add_card (*(all_cards+i));


    }

    delete allids;
    return totalcards;
}
void game_controller::show_deck()
{
    a_deck->display();

}
//this will intialize the game
//shuffle cards and distribute few cards.
void game_controller::deal_cards(int n)
{
    cout<<"Dealing cards to player1"<<endl;
    for(int i = 0 ;i <n ; i++)
    {
        //base_card * t_card = a_deck->get_card();
        p[0]->add_card(a_deck->get_card());
        p[1]->add_card(a_deck->get_card());
    }

    show_deck();
    cout<<"PLAYER1: "<<endl;
    p[0]->display_hand();
    cout<<"PLAYER2: "<<endl;
    p[1]->display_hand();

}


bool game_controller::evaluate_result()
{
    bool res = true;
    if(p[0]->get_life_point() == 0)
    {
        winner = 2;
        res = false;
    }

    if(p[1]->get_life_point() == 0)
    {
        winner = 1;
        res = false;
    }
    return res;
}
void game_controller::game_play()
{
    char userinput[INPUT_SIZE];
    char charinput;
    int number_of_cards;
    int lifepoint;
    cout<< "This is a two player card game. Each turn gives the opportunity to the player to play a attack card and opponent might have to play a response/ defense card. ";
    cout<< "player can choose to get a new card of the same type too but in that case player will not be able to play any card against the opponent. ";
    cout<<endl;
    cout<< "INITIALIZING the Game now... "<<endl;
    //generate_deck();
    cout<<"\nGathering Game information"<<endl;
    cout<<"Enter the number of cards each player can hold: ";
    cin.get(userinput,INPUT_SIZE,'\n');
    cin.ignore(INPUT_SIZE,'\n');
    sscanf(userinput, "%d", &number_of_cards);
    cout<<"Enter lifepoint for each player: ";
    cin.get(userinput,INPUT_SIZE,'\n');
    cin.ignore(INPUT_SIZE,'\n');
    sscanf(userinput, "%d", &lifepoint);
    cout<<"\nGathering Player information"<<endl;
    cout<<"Player 1:"<<endl;
    cout<<"Enter Player 1 name: "<<endl;
    cin.get(userinput,INPUT_SIZE,'\n');
    cin.ignore(INPUT_SIZE,'\n');
    p[0]->update_info(userinput,lifepoint,number_of_cards);
    cout<<"Player 2:"<<endl;
    cout<<"Enter Player 2 name: "<<endl;
    cin.get(userinput,INPUT_SIZE,'\n');
    cin.ignore(INPUT_SIZE,'\n');
    p[1]->update_info(userinput,lifepoint,number_of_cards);
    deal_cards(number_of_cards);
    int ind =0;             // this will ensure swapping of the players.
    int card_type=-1;
    while(evaluate_result())
    {
        int player_idx = ind%2;
        int opponent_idx =0;
        if(player_idx ==0)
            opponent_idx = 1;
        cout<<"################################### ROUND   ** "<< ind  <<"  **   #########################################"<<endl;
        cout<<"\n\n\nNow its your turn Player "<<player_idx+1<<": ["<<p[player_idx]->getname()<<"]"<<endl;
        cout<<"Here is your hand: "<<endl;
        p[player_idx]->display_hand();
        cout<<"Do you want to change a card or play a card? "<<endl;
        cout<<"Enter c to change a card [keep same id but properties changes].\n Any other key to play a card to board:   ";
        cin>>charinput;
        cin.ignore();
        if(charinput == 'c' || charinput == 'C')
        {
            card_type=-1;
            while(card_type>3 || card_type<0)
            {
                cout<<"Type of card to play. 0: for action, 1: for spell, 2: for defense:: ";
                cin.get(userinput,INPUT_SIZE,'\n');
                cin.ignore(INPUT_SIZE,'\n');
                sscanf(userinput, "%d", &card_type);
            }
            cout<<"Enter card ID to update: " ;
            cin.get(userinput,INPUT_SIZE,'\n');
            cin.ignore(INPUT_SIZE,'\n');
            p[player_idx]->play_update_card(allspells,num_spells,userinput,card_type);
            cout<<"now you have in your hand"<<endl;
            p[player_idx]->display_hand();
        }
        else
        {
            card_type=-1;
            while(card_type>1 || card_type<0)
            {
                cout<<"Type of card to play. 0: for action, 1: for spell ";
                cin.get(userinput,INPUT_SIZE,'\n');
                cin.ignore(INPUT_SIZE,'\n');
                sscanf(userinput, "%d", &card_type);
            }
            cout<<"Enter card ID to play: ";
            cin.get(userinput,INPUT_SIZE,'\n');
            cin.ignore(INPUT_SIZE,'\n');

            p[player_idx]->play_attack(*b_deck,*p[opponent_idx],card_type,userinput);
            // swapping discard deck and collection deck.
            if(a_deck->get_card_count()==0)
            {
                deck * temp = a_deck;
                a_deck = b_deck;
                b_deck = temp ;
            }

            // Player 1 now will get a card from shuffled deck.
            p[player_idx]->pick_card_from_deck(a_deck);
            cout<< "card count# discard deck:  " <<b_deck->get_card_count()<< "   Main deck: "<<a_deck->get_card_count()<< "  P1 Life:"<<p[0]->get_life_point()<<"  P2 Life: "<<p[1]->get_life_point()<<endl;
            if(p[opponent_idx]->counter_play_needed())
            {
                cout<< "\n\nPlayer "<<opponent_idx+1<<" : [" <<p[opponent_idx]->getname() << "] to play a defense card. choose a card from below."<<endl<<endl;
                p[opponent_idx]->display_hand(2);
                cout<<"Enter card ID to play: [non existant any ID will be considered as not playing any card]";
                cin.get(userinput,INPUT_SIZE,'\n');
                cin.ignore(INPUT_SIZE,'\n');
                int lostlife = p[opponent_idx]->play_defense(*b_deck,userinput);
                cout<<"Player "<<opponent_idx+1 <<": [" <<p[opponent_idx]->getname() << "] Lost (" <<lostlife<<") points"<<endl<<endl;
                // swapping discard deck and collection deck.
                if(a_deck->get_card_count()==0)
                {
                    deck * temp = a_deck;
                    a_deck = b_deck;
                    b_deck = temp ;
                }
                p[opponent_idx]->pick_card_from_deck(a_deck);
                cout<< "card count# discard deck:  " <<b_deck->get_card_count()<< "   Main deck: "<<a_deck->get_card_count()<< "  P1 Life:"<<p[0]->get_life_point()<<"  P2 Life: "<<p[1]->get_life_point()<<endl;


            }

        }
        ind++;
    }


    if(p[0]->get_life_point()==0)
        cout<<"Congratulations !!! Player 2 [ "<<p[1]->getname() <<" ] wins the game."<< endl;
    if(p[1]->get_life_point()==0)
        cout<<"Congratulations !!! Player 1 [ "<<p[0]->getname() <<" ] wins the game."<< endl;

}

