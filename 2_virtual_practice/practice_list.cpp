#include "practice.h"
void * operator new (size_t size)
{
    cout<<"allocating: "<<size<<endl;
    return malloc(size);
};
void  operator delete (void * memory, size_t size)
{
    cout<<"freeing: "<<size<<endl;
    free(memory);
};

//constructor
practice_list :: practice_list()
{
    head_array = new nogit gde*[3];
    head_array[0] = NULL;
    head_array[1] = NULL;
    head_array[2] = NULL;

    counter = 0;
}


//copy constructor
practice_list :: practice_list(const practice_list & source)
{
    if(head_array)


}



//Destructor
practice_list :: ~practice_list()
{
    deleteall();
    delete [] head_array;
}



void practice_list :: display_practice()
{
    if(!head_array)
        return;
    int index = 0;
    display_practice(*head_array,index);
}

void practice_list ::display_practice(node * head,int & index)
{
    if(index == 3)
        return;
    if(!head)
        display_practice(*(head_array + index),++index);
    else
    {
        //displaying
        head->data->display();
        display_practice(head->next,index);
    }
}




//Implementation of add_practice() method to add a practice
void practice_list :: add_practice(practice * prac_ptr)
{
    ++counter;
    prac_ptr->set_id(counter);//setting the id with the value of pointer
    int index = prac_ptr->who_am_i();

    node *& head = *(head_array + index);

    node * hold = head;
    head = new node;
    head->data = prac_ptr;
    head->next = hold;
    if(hold)
        hold->previous = head;
    else
        head->previous = NULL;

    //delete hold;
    //hold = NULL;
}


void practice_list::deleteall()
{

    if(!head_array)
        return;
    int index = 0;
    deleteall(*head_array,index);

}
void practice_list::deleteall(node* head, int &index)
{
    if(index == 3)
        return;
    if(!head)
        deleteall(*(head_array + index),++index);
    else
    {
        //displaying
        //head->data->display();
        //deleteall(head->next,index);
        node* temp = head;
        head= head->next;
        //temp->data->delete_me();
        delete temp->data;
        delete temp;
    }
}

//Implementation of delete_practice() method to add a practice
void practice_list :: delete_practice(int id)
{
    if(!head_array)
        return;
    int index = 0;
    delete_practice(*head_array,index,id);//recursive func call
}


void practice_list :: delete_practice(node * & head, int & index,int id)
{
    if(index == 3)
        return ;

    if(!head)
        delete_practice(*(head_array + index),++index,id);

    if(head->data->get_id() == id)
    {
        node * temp = head;
        head=head->next;
        temp->data->delete_me();
        delete temp;
    }
    else
        delete_practice(head->next,index,id);
}

//Implementation of edit_practice() method to find  and edit a practice
//wrapper
void practice_list :: edit_practice(int id)
{
    if(!head_array)
        return;
    int index = 0;
    edit_practice(*head_array,index,id);//recursive func call
}

//recursive
void practice_list :: edit_practice(node * & head, int & index,int id)
{
    if(index == 3)
        return;

    if(!head)
        edit_practice(*(head_array + index),++index,id);

    if(head->data->get_id() == id)
        head->data->edit_question();
    else
        edit_practice(head->next,index,id);
}


