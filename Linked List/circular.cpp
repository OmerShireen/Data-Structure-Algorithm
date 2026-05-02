#include <iostream>
using namespace std;
#include <cstdlib>

struct llNode
{
    int data;
    llNode *next;
};
llNode *list = NULL;

void insert(int value)
{
    llNode *tmp = (llNode *)malloc(sizeof(llNode));
    tmp->data = value;
    tmp->next = NULL;
    if (list == NULL)
    {
        list = tmp;
        tmp->next = list;
        return;
    }
    else
    {
        llNode *cur = list;
        while (cur->next != list)
        {
            cur = cur->next;
        }
        cur->next = tmp;
        tmp->next = list;
    }
}
void display()
{
    if (list == NULL)
    {
        cout << " The list is empty!" << endl;
        return;
    }

    llNode *cur = list;
    cout << "List: ";
    do
    {
        cout << cur->data << "->";
        cur = cur->next;
    } while (cur != list);
    cout << endl;
}
void search(int toSearch)
{
    if (list == NULL)
    {
        cout << " The list is empty!" << endl;
        return;
    }
    bool found = false;
    llNode *cur = list;
    do
    {
        if (cur->data == toSearch)
        {
            cout << "Value found" << endl;
            found = true;
            break;
        }
        cur = cur->next;
    } while (cur != list);

    if (!found)
    {
        cout << "Value not found" << endl;
    }
}

void del(int value) {
    if (list == NULL) {
        cout << "The list is empty" << endl;
        return;
    }

    llNode* cur = list;
    llNode* prev = NULL;

    
    if (list->data == value) {
        if (list->next == list) {
            free(list);
            list = NULL;
            return;
        }

        
        llNode* last = list;
        while (last->next != list) {
            last = last->next;
        }

        last->next = list->next;
        llNode* temp = list;
        list = list->next;
        free(temp);
        return;
    }

    prev = list;
    cur = list->next;

    while (cur != list) {
        if (cur->data == value) {
            prev->next = cur->next;
            free(cur);
            cout << "Value deleted" << endl;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    cout << "Value not found" << endl;
}


int main()
{
    int ch;
    cout << "Press 1 for insert" << endl
         << "Press 2 for search" << endl
         << "Press 3 for display" << endl
         << "Press 4 for delete" << endl
         << "Press 5 for exit" << endl;
    while (true)
    {
        cin >> ch;
        if (ch == 1)
        {
            int value;
            cout << "Enter a value u want to insert" << endl;
            cin >> value;
            insert(value);
        }
        if (ch == 2)
        {
            int value;
            cout << "Enter a value u want to Seacrh" << endl;
            cin >> value;
            search(value);
        }
        if (ch == 3)
        {
            display();
        }
        if (ch == 4)
        {
            int value;
            cout << "Enter a value u want to delete" << endl;
            cin >> value;
            del(value);
        }
        if (ch == 5)
        {
            break;
        }

        cout << "Press number to execute function" << endl;
    }
}

// The delete function removes a node from a circular linked list by handling empty list, head deletion, single-node list, and middle-node deletion using pointer manipulation.