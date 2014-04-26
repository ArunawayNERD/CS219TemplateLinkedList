#ifndef JP_LIST_H //JP is incase there already is LIST_H somewhere 
#define JP_LIST_H

/*
 * John Pigott
 * CS219
 * List Homework
 * Last Modified: 4/18/14 
 */
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};

class jp_list
{
         
    public:
        jp_list();
        jp_list(const jp_list&);
        void push_head(int);
        void push_tail(int);
        int pop_head(); //removes the head node and returns it
        int pop_tail(); //removes the tail node and returns it
        int size();
        void display_all();

        jp_list& operator= (const jp_list&);
        virtual ~jp_list(); 

    private:
        node *head;
};

jp_list::jp_list()
{
    head = new node;
    head->next = head;
    head->prev = head;
}

jp_list::jp_list(const jp_list& rt_side)
{
    head = new node;
    head->next = head;
    head->prev = head;

    node *crt_ptr = rt_side.head->next;
    while(crt_ptr != rt_side.head)
    {
       push_tail(crt_ptr->data);
       crt_ptr = crt_ptr->next;
    }        
}

jp_list::~jp_list()
{
    int list_size = size();

    for(int i = 0; i < list_size; i++)
    {
        pop_head();
    }
    
    delete head;
}

jp_list& jp_list::operator=(const jp_list& rt_side)
{
    if(this == &rt_side)
        return *this;

    int list_size = size();
    node *crt_ptr = head->next;

    //empty this list so the rt_side can be coppied in
    while(crt_ptr != head) 
    {
        crt_ptr = crt_ptr->next;
        pop_head();    
    }

    crt_ptr = rt_side.head->next;
    
    while(crt_ptr != rt_side.head)
    {
        push_tail(crt_ptr->data);
        crt_ptr = crt_ptr->next;
    }

   return *this;
}

void jp_list::push_head(int nw_data)
{ 
    node *temp = new node;
    temp->data = nw_data;

    temp->next = head->next;
    head->next->prev = temp;

    temp->prev = head;
    head->next = temp;
}

void jp_list::push_tail(int nw_data)
{
    node *temp = new node;
    temp->data = nw_data;

    head->prev->next = temp;
    temp->prev = head->prev;

    temp->next = head;
    head->prev = temp;
}

int jp_list::pop_head()
{
    node *temp = head->next;
    int temp_data = head->next->data;

    head->next = temp->next;
    temp->next->prev = head;

    delete temp;
    temp = 0;

    return temp_data;
}

int jp_list::pop_tail()
{
    node *temp = head->prev;
    int temp_data = head->prev->data;

    head->prev = temp->prev;
    temp->prev->next = head;

    delete temp;
    temp = 0;

    return temp_data;
}

int jp_list::size()
{
    int size = 0;
    node *crt_ptr; //pointer to current node

    crt_ptr = head->next;
    while(crt_ptr != head)
    {
        size += 1;
        crt_ptr = crt_ptr->next; //advance to the next node then loop        
    }

    return size;
}

void jp_list::display_all()
{
    node *crt_ptr = head->next;

    for(int i = 0; crt_ptr != head; i++)
    {
        cout << "Node " << (i+1) << ": " << crt_ptr->data << endl;

        crt_ptr = crt_ptr->next;
    }
}


#endif 
