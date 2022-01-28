// 01/18/2022
// Nusrat Jahan Ila
// Assignment 1 : Two player game
// The purpose of the file  is to impliment all the methods under all cards.

#include "two_player.h"

using namespace std;

game_controller::game_controller(int num_card )
{
    num_of_card_each_type = num_card;
    a_deck = new deck();
    p[0] = new player();
    p[1] = new player();
}
game_controller::~game_controller()
{

}

void game_controller::generate_deck()
{

    int totalcards = 3*num_of_card_each_type;
    char ** allids = new char* [totalcards];
    ifstream idfile("id.txt");
    bool file_open = false;
    string line;
    if(idfile.is_open())
    {
        file_open = true;

        int i = 0;
        while(getline(idfile,line))
        {
            //cout<<line<<line.length()<<  endl;
            allids[i] = new char[line.length()];
            strcpy(allids[i],line.c_str());
            i++;
        }
        idfile.close();


    }
    else
    {
        cout<<"can not open id file"<<endl;
        return;
    }


    int  index[totalcards];
    get_shuffled_index(index,totalcards);
    for( int i =0; i<totalcards; i++)
    {
        cout<<index[i] <<"-";
    }


    all_cards = new base_card*[totalcards];
    int temp_index=0;
    for(int i = 0 ; i<num_of_card_each_type;i++)
    {

        char* temp = new char[strlen(*(allids+i))];
        strcpy(temp,*(allids+i));

        cout<<"action card: "<<index[temp_index]<<endl;
        all_cards[index[temp_index]] =new action_card(temp);
        if(temp)
        {
            delete [] temp;
            temp = NULL;
        }
        //delete ac
        temp_index++;
    }

    for(int i = 0 ; i<num_of_card_each_type;i++)
    {
        char* temp = new char[strlen(*(allids+i))];
        strcpy(temp,*(allids+i));
        cout<<"defense card: "<<index[temp_index]<<endl;
        all_cards[index[temp_index]] =new defense_card(temp);
        if(temp)
        {
            delete [] temp;
            temp = NULL;
        }
        //delete dc
        temp_index++;
    }
    for(int i = 0 ; i<num_of_card_each_type;i++)
    {
        char* temp = new char[strlen(*(allids+i))];
        strcpy(temp,*(allids+i));


        cout<<"spell card: "<<index[temp_index]<<endl;
        all_cards[index[temp_index]] =new spell_card(temp);
        if(temp)
        {
            delete [] temp;
            temp = NULL;
        }
        //delete sc
        temp_index++;
    }

    for (int i =0; i<totalcards;i++)
    {
        base_card * bc = all_cards[i];
        cout<<"index: "<<i<<" card: "<<bc->which_card()<<endl;
    }

    //delete allcards

    for (int i =0; i<totalcards;i++)
    {
        delete[] *(allids+i);
    }
    delete allids;
}
//this will intialize the game
//shuffle cards and distribute few cards.
void game_controller::game_initializer()
{

}
