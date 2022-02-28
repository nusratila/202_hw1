//Name: Nustrat Jahan Ila.
//Date: 2/18/22
//Assignemnt 3 : This file contain the menu class where all the user interaction and menu items are organized.
// this file contains implementation of the menu class which manages the user interaction and 3 different typeos data collection.



#include "olympic_competetion.h"
/*
hockey_athletes  ha;
ice_dancing_athletes  ida;
ski_jumping_athlete_tree  sja;
*/

//this menu gives user to interact the game of ski jump and the athlete involved with this game.
void user_class::ski_jump_menu()
{
    char option2;
    cout<<"Game # ski jump"<<endl;
    cout<<"choose 1=>add  2=>delete  3=>search 4=>displayall 5=>deleteall || any other key back to main menu"<<endl;
    cin>>option2;
    cin.ignore();
    if(option2=='1')
    {
        ski_jumping sj;
        cout<<"Enter ski jumping athlete details no space in name and no extra space"<<endl;
        cout<<"name[string no space] topscore[int] number_of_wins[int] height[int] distance[int]"<<endl;
        //exception handling while getting the input from user.
        try
        {
            cin>>sj;
            cout<<"Adding the athlete to collection"<<endl;
            sja.add_athlete(sj);
        }
        catch(invalid_argument &e)
        {
            cout<<e.what();
        }
        ski_jump_menu();
    }
    else if(option2== '2')
    {
        cout<<"delete"<<endl;
        char* t_name = new char[101];
        cout<<"Enter athlete name to remove from collection"<<endl;
        cin>>t_name;
        cin.ignore(101,'\n');
        sja.remove_athlete(t_name);
        delete [] t_name;
        ski_jump_menu();

    }
    else if (option2 =='3')
    {
        char * t_name = new char[101];
        cout<<"Enter athlete name to search"<<endl;
        cin>>t_name;
        cin.ignore();
        ski_jumping * t_sj = sja.find_athlete(t_name);
        if(t_sj)
            t_sj->display();
        else
            cout<<"no matching athlete found"<<endl;
        delete [] t_name;
        ski_jump_menu();
    }
    else if (option2 =='4')
    {
        cout<<"Displaying all the athletes in the collection:"<<endl;
        sja.display_tree();
        ski_jump_menu();
    }
    else if (option2 =='5')
    {
        cout<<"Deleting all the athletes in the collection:"<<endl;
        sja.delete_all();
        ski_jump_menu();
    }
    else
    {
        cin.ignore(101,'\n');
        main_menu();
    }

}
//this menu gives user to interact the game of Hockey and the athlete involved with this game.
void user_class::hockey_menu()
{
    char option2;
    cout<<"Game # Hockey"<<endl;
    cout<<"choose 1=>add  2=>delete  3=>search 4=>displayall 5=>deleteall || any other key back to main menu"<<endl;
    cin>>option2;
    cin.ignore();
    if(option2=='1')
    {
        hockey h;
        cout<<"Enter Hockey athlete details no space in name and no extra space"<<endl;
        cout<<"name[string no space] topscore[int] number_of_wins[int] foul[int] shot_on_target[int]"<<endl;
        //exception handling while getting the input from user.
        try
        {
            cin>>h;
            cout<<"Adding the athlete to collection"<<endl;
            ha.add_athlete(h);
        }
        catch(invalid_argument &e)
        {
            cout<<e.what();
        }
        hockey_menu();
    }
    else if(option2== '2')
    {
        char* t_name = new char[101];
        cout<<"Enter athlete name to remove from collection"<<endl;
        cin>>t_name;
        cin.ignore(101,'\n');
        ha.remove_athlete(t_name);
        delete [] t_name;
        hockey_menu();

    }
    else if (option2 =='3')
    {
        char*  t_name = new char[101];
        cout<<"Enter athlete name to search"<<endl;
        cin>>t_name;
        cin.ignore(101,'\n');
        hockey * t_ha = ha.find_athlete(t_name);
        cout<<"Do you want to add shot/foul for this athlete press y to update"<<endl;
        char t_option;
        cin>>t_option;
        t_option = toupper(t_option);
        if(t_option == 'Y')
        {
            int foul_shot;
            cout<<"how many foul to be added for this athlete: ";
            cin>>foul_shot;
            t_ha->add_foul(foul_shot);
            cout<<"how many shot on target to be added for this athlete: ";
            cin>>foul_shot;
            t_ha->add_shot(foul_shot);
        }
        t_ha->display();
        delete [] t_name;
        hockey_menu();
    }
    else if (option2 =='4')
    {
        cout<<"Displaying all the athletes in the collection:"<<endl;
        ha.display_all();
        hockey_menu();
    }
    else if (option2 =='5')
    {
        cout<<"Deleting all the athletes from the collection:"<<endl;
        ha.delete_all();
        hockey_menu();
    }
    else
    {
        cin.ignore(101,'\n');
        main_menu();
    }
}
//this menu gives user to interact the game of Ice dance and the athlete involved with this game.
void user_class::ice_dance_menu()
{
    char option2;
    cout<<"Game # Ice Dance"<<endl;
    cout<<"choose 1=>add  2=>delete  3=>search 4=>displayall 5=>deleteall|| any other key back to main menu"<<endl;
    cin>>option2;
    cin.ignore();
    if(option2=='1')
    {
        ice_dancing id;
        cout<<"Enter Ice Dance athlete details no space in name and no extra space"<<endl;
        cout<<"name[string no space] topscore[int] number_of_wins[int] style[string no space] perf_quality[option ABCD]"<<endl;
        //exception handling while getting the input from user.
        try
        {
            cin>>id;
            cout<<"Adding the athlete to collection"<<endl;
            ida.add_athlete(id);
        }
        catch(invalid_argument &e)
        {
            cout<<e.what();
        }
        ice_dance_menu();
    }
    else if(option2== '2')
    {
        char* t_name = new char[101];
        cout<<"Enter athlete name to remove from collection"<<endl;
        cin>>t_name;
        cin.ignore(101,'\n');
        ida.remove_athlete(t_name);
        delete [] t_name;
        ice_dance_menu();

    }
    else if (option2 =='3')
    {
        char * t_name = new char[101];
        cout<<"Enter athlete name to search"<<endl;
        cin>>t_name;
        cin.ignore();
        ice_dancing * t_id = ida.find_athlete(t_name);
        t_id->display();
        delete[] t_name;
        ice_dance_menu();
    }
    else if (option2 =='4')
    {
        cout<<"Displaying all the athletes in the collection:"<<endl;
        ida.display_all();
        ice_dance_menu();
    }
    else if (option2 =='5')
    {
        cout<<"Deleting all the athletes in the collection:"<<endl;
        ida.delete_all();
        ice_dance_menu();
    }
    else
    {
        cin.ignore(101,'\n');
        main_menu();
    }

}


//main menu to choose the different game options.
void user_class::main_menu()
{
    char option1;
    cout<<"MAIN MENU"<<endl;
    cout<<"choose an option. 1=> ski jump 2=> Hockey 3=> Ice dancing  0=>repeat main menu"<<endl;
    cin>>option1;
    cin.ignore();

    if(option1=='1')
    {
        ski_jump_menu();
    }
    else if(option1== '2')
    {
        hockey_menu();
    }
    else if (option1 =='3')
    {

        ice_dance_menu();
    }
    else if (option1 =='0')
    {
        main_menu();
    }
    else
    {
        return;
    }
}
