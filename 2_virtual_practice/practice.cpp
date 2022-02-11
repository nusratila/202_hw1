#include "practice.h"

//Implementation of preparation class(base class)
//Implementation of constructor
practice :: practice()
{
    question = NULL;
    progress = 0;
    level = 0;
    id = 0;
}




//Implementation of copy constructor
practice :: practice(const practice & source)
{
    if(source.question)
    {
        question = new char[strlen(source.question) + 1];
        strcpy(question,source.question);
    }
    else
        question = NULL;
}

//Destructor
practice :: ~practice()
{
    if(question)
        delete [] question;
}


void practice :: set_question()
{
    char temp[100];
    cout<< "Type your question and press enter when done" <<endl;
    cin.get(temp,100,'\n');
    cin.ignore(100,'\n');

    question = new char[strlen(temp) + 1];
    strcpy(question,temp);
}

void practice :: set_id(int id)
{
    this->id = id;
}

int practice :: get_id()
{
    return id;
}


//virtual
void practice :: display()
{
}


void practice :: edit_question()
{
}

void practice :: mark_complete()
{
}

void practice :: set_difficulty()
{
}
void practice :: delete_me()
{


}

int practice :: who_am_i()
{
    return 100;
}












