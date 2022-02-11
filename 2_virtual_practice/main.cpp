#include "practice.h"
void user_prompt(int option, practice_list & my_list)
{
    if(option == 1)         // ADD
    {
        int user_input = 0;
        cout<< "Adding an object to the practice list" << endl;
        cout<< "What type of question do you want to add?" << endl;
        cout<< "press 1 ->for exam question" <<endl;
        cout<< "press 2 ->for coding question" <<endl;
        cout<< "press 3 ->for future_study question" <<endl;
        cin>> user_input;
        cin.ignore(100,'\n');

        practice * prac_ptr = NULL;//making a pointer of practice class(base class)

        if(user_input == 1)
        {
            prac_ptr = new exam();//upcasting
            prac_ptr->set_question();
            prac_ptr->set_info();
            prac_ptr->set_difficulty();
            prac_ptr->mark_complete();
        }

        else if(user_input == 2)
        {
            prac_ptr = new coding();//upcasting
            prac_ptr->set_question();
            prac_ptr->set_info();
            prac_ptr->set_difficulty();
            prac_ptr->mark_complete();
        }

        else if(user_input == 3)
        {
            prac_ptr = new future_study();//upcasting
            prac_ptr->set_question();
            prac_ptr->set_info();
            prac_ptr->set_difficulty();
            prac_ptr->mark_complete();
        }
        else
            cout<< "INVALID INPUT!!!" <<endl;

        if(user_input > 0 && user_input < 4)
        {
            my_list.add_practice(prac_ptr); //adding the object to practice list
            cout<< "           <<< Question is added to the list >>>" <<endl;
        }

    }

    else if(option == 2)    //Display
    {
        cout<< "" <<endl; cout<<"              <<< Displaying objects of the practice list >>>" <<endl<<endl;
        my_list.display_practice();
    }

    else if(option == 3)    //Delete
    {
        int user_input;
        cout<< "Please enter the Id number of the question to edit the question" <<endl;
        cin>> user_input;
        cin.ignore(100,'\n');
        my_list.delete_practice(user_input);
        cout<< "Item is deleted" << endl;
    }
    else if(option == 4)    //Edit a question
    {
        int user_input;
        cout<< "Please enter the Id number of the question to edit the question" <<endl;
        cin>> user_input;
        cin.ignore(100,'\n');
        my_list.edit_practice(user_input);
        cout<< "question edited" << endl;
    }
    else if(option == 5)    //exit : call all destructor or clean up here.
    {
        cout<<"cleaning up" <<endl;
        my_list.deleteall();
        return;

    }
    cout<< "Select options: 1-> Add , 2-> Display, 3-> Delete ,  4-> Edit question , 5-> exit"<<endl;
    cin >> option;
    cin.ignore(100,'\n');
    user_prompt(option,my_list);

}
int main()
{
    practice_list my_list;
    int option = -1;
    user_prompt(option,my_list);
    int t;
    cin>>t;
    return 0;
}
