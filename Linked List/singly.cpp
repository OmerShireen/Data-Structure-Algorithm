#include <iostream>
using namespace std;
#include <cstdlib>

struct llNode{
    int data;
    llNode* next;
};
llNode* list = NULL;

void insert(int value){
   llNode* tmp = (llNode*) malloc(sizeof(llNode));
    tmp-> data = value;
    tmp-> next = NULL;
    if (list == NULL){
        list = tmp;
    } else{
        llNode * cur = list;
        while(cur->next != NULL)
    {
        cur = cur->next;
    }
    cur-> next = tmp;
    }   
}
void display() {
    if(list == NULL){
        cout << " The list is empty!" << endl;
        return;
    }

    llNode* cur = list;
    cout << "List: ";
    while(cur != NULL){
        cout <<cur->data <<"->";
        cur = cur->next;
    }
    cout <<endl;
}
void search (int toSearch){
    if(list == NULL){
        cout << " The list is empty!" << endl;
        return;
    }
    bool found;
    llNode * cur = list;
    while (cur != NULL)
    {
        if (cur ->data == toSearch)
        {
            cout << "Value found" << endl;
            found = true;
        }
        cur = cur -> next;
    }
    if(!found){
         cout<<"Value not found" << endl;
    }
}
void del(int value){
    if(list == NULL){
        cout << "The list is empty" << endl;
        return;
    }
    llNode * cur = list;
    if(value == list ->data){
        list = list->next;
        free(cur);
        return;
    }
    llNode * prev = list;
    cur = list -> next;
    bool found = false;
    while (cur != NULL){
        if(value == cur-> data){
            prev -> next = cur->next;
            free(cur);
            found = true;
            break;
        }
        cur = cur -> next;
        prev = prev -> next;
    }
    if(!found){
        cout << "Value not found" << endl;
    }
    
}

int main() {
    int ch;
    cout << "Press 1 for insert" << endl << "Press 21 for search" << endl  << "Press 3 for display" << endl << "Press 4 for delete" << endl << "Press 5 for exit" << endl;
    while (true)
    {
        cin >> ch;
        if(ch==1){
            int value;
            cout << "Enter a value u want to insert" << endl;
            cin >> value;
            insert(value);
        }
         if(ch==2){
            int value;
            cout << "Enter a value u want to Seacrh" << endl;
            cin >> value;
            search(value);
        }
        if(ch==3){
            display();
        }
        if(ch==4){
            int value;
            cout << "Enter a value u want to delete" << endl;
            cin >> value;
            del(value);
        }
        if(ch==5){
            break;
        }
        cout << "Press number to execute function" << endl;
    }
}