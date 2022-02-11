#include "practice.h"

//Implementation of exam class(derived class) derived from practice
//Implementation of constructor
exam :: exam()
{
    question_type = 0;
}

exam::~exam()
{

    //delete_me();
}

//Virtual

//Implementation of set_info() method for exam  class to set the question_type as its protected data member is question_type
void exam :: set_info()
{
    cout<< "what is the Question type?" <<endl;
    cout<< "press 1 ->for multiple choice" <<endl;
    cout<< "press 2 ->for descriptive " <<endl;
    cin>> question_type;
    cin.ignore(100,'\n');
}


//Implementation of display() function for exam class
void exam :: display()
{
    cout<< "ID      : " << id <<endl;
    cout<< "Q       : " << question <<endl;
    cout<< "Q type  : ";
    if(question_type == 1)
        cout<< "Multiple_choice" << "    ";
    else
        cout<< "Descriptive" << "    ";
    cout<< "Progress: ";
    if(progress == 0)
        cout<< "Not completed" << "    ";
    else if(progress == 1)
        cout<< "Completed" << "    ";
    else
        cout<< "In progress" << "    ";
    cout<< "Difficulty Level(1-5): " << level <<endl<<endl;
}


//Implementation of edit_question() function for exam class
void exam::edit_question()
{
    cout<< " Displaying the question " <<endl;
    display();

    char input_char[100];
    int input_int;

    cout<< "Do you want to edit the question? :  1-> yes   2-> no" <<endl;
    cin>> input_int;
    cin.ignore(100,'\n');

    if(input_int == 1)
    {
        cout<< "Enter the new question: "<<endl;
        cin.get(input_char,100,'\n');
        cin.ignore(100,'\n');

        question = new char[strlen(input_char)+1];
        strcpy(question,input_char);
    }

    cout<< "Do you want to edit the question type? :  1-> yes   2-> no" <<endl;
    cin>> input_int;
    cin.ignore(100,'\n');

    if(input_int == 1)
    {
        cout<< "What is the question type? "<<endl;
        cout<< "press 1 for multiple choice and 2 for short answer" <<endl;
        cin>> question_type;
        cin.ignore(100,'\n');
    }

    cout<< "Do you want to edit the difficulty level? :  1-> yes   2-> no" <<endl;
    cin>> input_int;
    cin.ignore(100,'\n');

    if(input_int == 1)
        set_difficulty();//calling set_difficulty() to set the difficulty level

    cout<< "Do you want to edit the progress(completed/not completed) level? :  1-> yes   2-> no" <<endl;
    cin>> input_int;
    cin.ignore(100,'\n');

    if(input_int == 1)
        mark_complete();//calling mark_complete() to set the progress level
}







//Implementation of set_difficulty() function for exam class
void exam :: set_difficulty()
{
    cout<< "Difficulty level range is from 1-5.Enter a number from 1-5 to set the difficulty level of the question" <<endl;
    cin >> level;
    cin.ignore(100,'\n');
    if(level < 1 || level > 5)
    {
        cout<< "Difficulty Level can not be set as it is not in the expected range(1-5).";
        cout<< "Please enter a valid input" <<endl;
        set_difficulty();//calling the same function recursively for a valid input
    }
}


void exam :: mark_complete()
{
    //prompting user for the input
    cout << "Please enter 1 to mark it complete,0 to mark it incomplete and 2 to mark it in progress" << endl;
    cin >> progress;
    cin.ignore(100,'\n');

    if(progress < 0 || progress > 2)//if the input is wrong
    {
        cout << "Wrong input!!! Please enter the right input " <<endl;
        mark_complete();//calling the same function recursively to prompt the user again to enter the right input
    }
}

void exam :: delete_me()
{
    if(question)
    {
        delete [] question;
    }
}
int exam :: who_am_i()
{
    return 0;
}
