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

template <class T>
struct node
{
    T data;
    node<T> *next;
    node<T> *prev;
};

template <class T>
class jp_list
{
         
    public:
        //constructs a new empty jp_list
        jp_list()
        {
            head = new node<T>;
            head->next = head;
            head->prev = head;
        };
        
        //constructs a new jp_list that is a copy of an existing list
        jp_list(const jp_list<T>& rt_side)
        {
            head = new node<T>;
            head->next = head;
            head->prev = head;

            node<T> *crt_ptr = rt_side.head->next;
            while(crt_ptr != rt_side.head)
            {
                push_back(crt_ptr->data);
                crt_ptr = crt_ptr->next;
            }
        };
        
        //adds a data node to the front of the list 
        void push_front(T nw_data)
        {
            node<T> *temp = new node<T>;
            temp->data = nw_data;
        
            temp->next = head->next;
            head->next->prev = temp;
        
            temp->prev = head;
            head->next = temp;
        };
         
        //adds a data node to the end of the list 
        void push_back(T nw_data)
        {
            node<T> *temp = new node<T>;
            temp->data = nw_data;

            head->prev->next = temp;
            temp->prev = head->prev;

            temp->next = head;
            head->prev = temp;
        };
        
        //removes the first node and returns the data
        T pop_front()
        {
            node<T> *temp = head->next;
            T temp_data = head->next->data;

            head->next = temp->next;
            temp->next->prev = head;

            delete temp;

            return temp_data;
        };
        
        //removes the last node and returns the data
        T pop_back()
        {
            node<T> *temp = head->prev;
            T temp_data = head->prev->data;

            head->prev = temp->prev;
            temp->prev->next = head;

            delete temp;

            return temp_data;
        };
        
        //resturns the size of the list
        int size()
        {
            int size = 0;
            node<T> *crt_ptr; //pointer to current node

            crt_ptr = head->next;
            while(crt_ptr != head)
            {
                size += 1;
                crt_ptr = crt_ptr->next; //advance to the next node then loop        
            }

            return size;
        };

        //prints out all the data in the list
        void display_all()
        {
            node<T> *crt_ptr = head->next;

            for(int i = 0; crt_ptr != head; i++)
            {
                cout << "Node " << (i+1) << ": " << crt_ptr->data << endl;

                crt_ptr = crt_ptr->next;
            }
        };

        jp_list& operator= (const jp_list& rt_side)
        {
            if(this == &rt_side)
                return *this;
            node<T> *crt_ptr = head->next;

            //empty this list so the rt_side can be coppied in
            while(crt_ptr != head)
            {
                crt_ptr = crt_ptr->next;
                pop_front();
            }

            crt_ptr = rt_side.head->next;
    
            while(crt_ptr != rt_side.head)
            {
                push_back(crt_ptr->data);
                crt_ptr = crt_ptr->next;
            }
    
            return *this;
        };         
        
        virtual ~jp_list()
        {
            int list_size = size();

            for(int i = 0; i < list_size; i++)
            {
                pop_front();
            } 

            delete head;
        }; 

    private:
        node<T> *head;
};

/*
jp_list<T>::jp_list()
{
    head = new node<T>;
    head->next = head;
    head->prev = head;
}

jp_list(const jp_list& rt_side)
{
    head = new node<T>;
    head->next = head;
    head->prev = head;

    node<T> *crt_ptr = rt_side.head->next;
    while(crt_ptr != rt_side.head)
    {
       push_tail(crt_ptr->data);
       crt_ptr = crt_ptr->next;
    }        
}

~jp_list()
{
    int list_size = size();

    for(int i = 0; i < list_size; i++)
    {
        pop_head();
    }
    
    delete head;
}

jp_list& operator=(const jp_list<T>& rt_side)
{
    if(this == &rt_side)
        return *this;

    node<T> *crt_ptr = head->next;

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

void push_front(T nw_data)
{ 
    node<T> *temp = new node<T>;
    temp->data = nw_data;

    temp->next = head->next;
    head->next->prev = temp;

    temp->prev = head;
    head->next = temp;
}

void push_back(T nw_data)
{
    node<T> *temp = new node<T>;
    temp->data = nw_data;

    head->prev->next = temp;
    temp->prev = head->prev;

    temp->next = head;
    head->prev = temp;
}

T pop_front()
{
    node<T> *temp = head->next;
    T temp_data = head->next->data;

    head->next = temp->next;
    temp->next->prev = head;

    delete temp;

    return temp_data;
}

T pop_back()
{
    node<T> *temp = head->prev;
    T temp_data = head->prev->data;

    head->prev = temp->prev;
    temp->prev->next = head;

    delete temp;
    
    return temp_data;
}

int size()
{
    int size = 0;
    node<T> *crt_ptr; //pointer to current node

    crt_ptr = head->next;
    while(crt_ptr != head)
    {
        size += 1;
        crt_ptr = crt_ptr->next; //advance to the next node then loop        
    }

    return size;
}

void display_all()
{
    node<T> *crt_ptr = head->next;

    for(int i = 0; crt_ptr != head; i++)
    {
        cout << "Node " << (i+1) << ": " << crt_ptr->data << endl;

        crt_ptr = crt_ptr->next;
    }
}
};
*/
#endif 
