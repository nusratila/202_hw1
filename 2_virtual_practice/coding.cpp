#include "practice.h"

//Implementation of coding class(derived class) derived from practice
//Implementation of constructor
coding :: coding()
{
    language = NULL;
}


//Implementation of copy constructor
coding :: coding(const coding & source):practice(source)
{
    if(source.language)
    {
        language = new char[strlen(source.language) + 1];
        strcpy(language,source.language);
    }
}


//Destructor
coding :: ~coding()
{
    delete_me();
}


//virtual

//Implementation of set_info() method for coding class to set the language as its protected data member is language
void coding :: set_info()
{
    char temp[100];
    cout<< "Which Language" <<endl;
    cin.get(temp,100,'\n');
    cin.ignore(100,'\n');

    language = new char[strlen(temp) + 1];
    strcpy(language,temp);
}



void coding :: display()
{
    cout<< "ID      : " << id <<endl;
    cout<< "Q       : " << question <<endl;
    cout<< "Language: " << language << "    " ;
    cout<< "Progress: " ;
    if(progress == 0)
        cout<< "Not completed" << "    ";
    else
        cout<< "Completed" << "    ";
    cout<< "Difficulty Level(1-10): " << level <<endl<<endl;
}



void coding :: edit_question()
{
/*    if(question)
        delete[] question;
    if(language)
        delete[] language;
        */
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

    cout<< "Do you want to edit the language? :  1-> yes   2-> no" <<endl;
    cin>> input_int;
    cin.ignore(100,'\n');

    if(input_int == 1)
    {
        cout<< "What language: "<<endl;
        cin.get(input_char,100,'\n');
        cin.ignore(100,'\n');

        language = new char[strlen(input_char)+1];
        strcpy(language,input_char);
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




void coding:: mark_complete()
{
    //prompting user for the input
    cout << "Please enter 1 to mark it complete and 0 to mark it incomplete" << endl;
    cin >> progress;
    cin.ignore(100,'\n');

    if(progress < 0 || progress > 1)//if the input is wrong
    {
        cout << "Wrong input!!! Please enter the right input " <<endl;
        mark_complete();//calling the same function recursively to prompt the user again to enter the right input
    }
}




void coding :: set_difficulty()
{
    cout<< "Difficulty level range is from 1-10.Enter a number from 1-10 to set the difficulty level of the question" <<endl;
    cin >> level;
    cin.ignore(100,'\n');
    if(level < 1 || level > 10)
    {
        cout<< "Difficulty Level can not be set as it is not in the expected range(1-10).";
        cout<< "Please enter a valid input" <<endl;
        set_difficulty();//calling the same function recursively for a valid input
    }
}


void coding :: delete_me()
{

    if (language)
    {
        delete [] language;
    }
    if(question)
    {
        delete [] question;
    }
}

int coding :: who_am_i()
{
    return 1;
}
