#include "practice.h"

//Implementation of future_study class(derived class) derived from practice
//Implementation of constructor
future_study :: future_study()
{
    concept = NULL;
}



//Implementation of copy constructor
future_study :: future_study(const future_study & source):practice(source)
{
    if(source.concept)
    {
        concept = new char[strlen(source.concept) + 1];
        strcpy(concept,source.concept);
    }
}


//Destructor
future_study :: ~future_study()
{
    delete_me();
}



//Virtual

//Implementation of set_info() method for future_study class to set the concept as its protected data member is concept
void future_study :: set_info()
{
    char temp[100];
    cout<< "What is the concept" <<endl;
    cin.get(temp,100,'\n');
    cin.ignore(100,'\n');

    concept = new char[strlen(temp) + 1];
    strcpy(concept,temp);
}



//Implementation of display() function for future_study class
void future_study :: display()
{
    cout<< "ID      : " << id <<endl;
    cout<< "Q       : " << question <<endl;
    cout<< "concept : " <<concept << "    ";
    cout<< "Progress: ";
    if(progress == 0)
        cout<< "Not completed" << "    ";
    else if(progress == 100)
        cout<< "Completed" << "    ";
    else
        cout<< progress << " percent(%) completed" << "    ";
    cout<< "Difficulty Level(1-5): " << level <<endl<<endl;
}




//Implementation of edit_question() function for future_study class
void future_study::edit_question()
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

    cout<< "Do you want to edit the concept? :  1-> yes   2-> no" <<endl;
    cin>> input_int;
    cin.ignore(100,'\n');

    if(input_int == 1)
    {
        cout<< "What is the concept: "<<endl;
        cin.get(input_char,100,'\n');
        cin.ignore(100,'\n');

        concept = new char[strlen(input_char)+1];
        strcpy(concept,input_char);
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




//Implementation of set_difficulty() function for future_study class
void future_study :: set_difficulty()
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


void future_study :: mark_complete()
{
    //prompting user for the input
    cout << "For future study,Please rate your progress in percentage in the range(0-100)" << endl;
    cin >> progress;
    cin.ignore(100,'\n');

    if(progress < 0 || progress > 100)//if the input is wrong
    {
        cout << "Wrong input!!! Please enter the right input " <<endl;
        mark_complete();//calling the same function recursively to prompt the user again to enter the right input
    }
}


void future_study :: delete_me()
{
    if (concept)
    {
        delete [] concept;
    }
    if(question)
    {
        delete [] question;
    }

}

int future_study :: who_am_i()
{
    return 2;
}






