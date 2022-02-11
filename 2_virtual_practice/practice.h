//Name: Nustrat Jahan Ila.
//Date: 2/4/22
//Assignemnt 2 : OOP  program to helping on prepare and practice.

//The purpose of this header file is to declare all the prototype of the function, creating OOP by providing derivation list
//and making dynamic binding

#include <iostream>
#include <cstring>
#include <cctype>
#include <cstdlib>

using namespace std;


void * operator new (size_t size);

void  operator delete (void * memory, size_t size);


class practice    //base class
{
public:
    practice();
    ~practice();
    practice(const practice & source);
    void set_question();
    void set_id(int id);
    int get_id();

    //all virtual function should be implemented in one or all of the derived class
    virtual void display()=0;
    virtual void edit_question()=0;           // answer to the question will be returned.
    virtual void mark_complete()=0;               //it will change the task status
    virtual void set_difficulty()=0;       //it will set the difficulty level ;
    virtual int who_am_i() = 0;                     //if need to identify the object type in runtime. =0 will enforce implementation in all derived class;
    virtual void set_info() = 0;            //It will set the appropiate info for each class
    virtual void delete_me();
protected:
    char * question;
    int progress;
    int level;
    int id;

};


//derived classes:

class exam : public practice //exam class is derived from preparation
{
public:
    exam();
    ~exam();
    void display();
    void set_info();    //set question_type
    void edit_question();
    void mark_complete();
    void set_difficulty();
    int who_am_i();
    void delete_me();
protected:
    int question_type;
};




class coding : public practice
{
public:
    coding();
    ~coding();
    coding(const coding & source);
    void display();
    void set_info();    //set language
    void edit_question();
    void mark_complete();
    void set_difficulty();
    int who_am_i();
    void delete_me();
protected:
    char * language;
};


class future_study : public practice
{
public:
    future_study();
    ~future_study();
    future_study(const future_study & source);
    void display();
    void set_info();    //set concept
    void edit_question();
    void set_difficulty();
    void mark_complete();
    void delete_me();
    int who_am_i();
protected:
    char * concept;
};


struct node
{
    practice * data;
    node * next;
    node * previous;
};


//this class is my abstruct data type
// this will have an array of doubly link list.
class practice_list
{
public:
    practice_list();
    ~practice_list();
    practice_list(const practice_list & source);
    void add_practice(practice * prac_ptr);
    void delete_practice(int id);
    void display_practice();
    void edit_practice(int id);
    void deleteall();

protected:
    void delete_practice(node * & head, int & index,int id); // this will traverse throw the array to find out the question to delete.
    void display_practice(node * head,int & index); // recursive call for displaying all question.
    void edit_practice(node * & head, int & index,int id);
    void deleteall(node* head, int &index);
    node ** head_array;           // this will store a bidirectional linked list of preparation
    int counter;                    //This will track the number of questions(number of nodes)
};



