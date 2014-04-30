/*
 * John Pigott
 * CS219
 * List Homework
 * Last Modifed: 4/18/14
 */
#include <iostream>
#include <cstdlib>
#include "jp_list.h"
using namespace std;

int main()
{
    jp_list<int> my_list1;
    jp_list<int> my_list2;

    my_list1.push_front(10);
    my_list1.push_front(20);
    my_list1.display_all();
    cout << endl;

    my_list2.push_front(30);
    my_list2.push_front(40);
    my_list2.push_front(50);

    my_list1 = my_list2;
    my_list1.display_all();
    cout << endl;

    jp_list<int> my_list3(my_list1);
    my_list3.display_all();
    cout << endl;

    srand(time(0));

    jp_list<int> my_list4;
    cout << "Size: " <<  my_list4.size() << endl << endl;
    for(int i = 0; i < 100; i++)
    {
        my_list4.push_front(rand() % 100);
    }

    my_list4.display_all();

    cout << "\nSize: " << my_list4.size() << endl;
}
