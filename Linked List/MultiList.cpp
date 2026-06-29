#include <iostream>
using namespace std;
#include <cstdlib>

struct SNode
{
    int SNo;
    SNode *Snext;
};

struct CNode
{
    int CNo;
    CNode *Cnext;
    SNode *Std_list;
};
CNode *C_list = NULL;

void Add_Course(int value)
{
    CNode *tmp = (CNode *)malloc(sizeof(CNode));
    tmp->CNo = value;
    tmp->Cnext = NULL;
    tmp->Std_list = NULL;
    if (C_list == NULL)
    {
        C_list = tmp;
    }
    else
    {
        CNode *Ccur = C_list;
        while (Ccur->Cnext != NULL)
        {
            Ccur = Ccur->Cnext;
        }
        Ccur->Cnext = tmp;
    }
};

void Add_Student(int C_No, int S_No)
{
    CNode *Ccur = C_list;
    while (Ccur != NULL)
    {
        if (Ccur->CNo == C_No)
        {
            SNode *tmp = (SNode *)malloc(sizeof(SNode));
            tmp->SNo = S_No;
            tmp->Snext = NULL;
            if (Ccur->Std_list == NULL)
            {
                Ccur->Std_list = tmp;
            }
            else
            {
                SNode *Scur = Ccur->Std_list;
                while (Scur->Snext != NULL)
                {
                    Scur = Scur->Snext;
                }
                Scur->Snext = tmp;
            }
            return;
        }
        Ccur = Ccur->Cnext;
    }
    cout << "Course not found" << endl;
}
void Display_All(int value)
{
    CNode *Ccur = C_list;
    if (Ccur == NULL)
        cout << "List is empty" << endl;
    while (Ccur != NULL)
    {
        cout << "Course:" << Ccur->CNo << "| Sudents: ";
        SNode *Scur = Ccur->Std_list;
        while (Scur != NULL)
        {
            cout << Scur->SNo << "->";
            Scur = Scur->Snext;
        }
        cout << "NULL" << endl;
        Ccur = Ccur->Cnext;
    }
}

void Delete_Course(int C_No)
{
    if (C_list == NULL)
    {
        cout << "No courses available" << endl;
        return;
    }

    CNode *cur = C_list;
    CNode *prev = NULL;

    /* Case 1: Delete first course */
    if (C_list->CNo == C_No)
    {

        /* delete all students of this course */
        SNode *Scur = C_list->Std_list;
        while (Scur != NULL)
        {
            SNode *tempS = Scur;
            Scur = Scur->Snext;
            free(tempS);
        }

        CNode *tempC = C_list;
        C_list = C_list->Cnext;
        free(tempC);

        cout << "Course deleted successfully" << endl;
        return;
    }

    /* Case 2: Delete middle or last course */
    prev = C_list;
    cur = C_list->Cnext;

    while (cur != NULL)
    {
        if (cur->CNo == C_No)
        {

            /* delete students of this course */
            SNode *Scur = cur->Std_list;
            while (Scur != NULL)
            {
                SNode *tempS = Scur;
                Scur = Scur->Snext;
                free(tempS);
            }

            prev->Cnext = cur->Cnext;
            free(cur);

            cout << "Course deleted successfully" << endl;
            return;
        }

        prev = cur;
        cur = cur->Cnext;
    }

    cout << "Course not found" << endl;
}

int main()
{
    int ch;
    int value;

    cout << "Press 1 to Add Course" << endl
         << "Press 2 to Add Student" << endl
         << "Press 3 to Display all" << endl
         << "Press 4 to delete Course" << endl;

    while (true)
    {
        cin >> ch;
        if (ch == 1)
        {
            cout << "Enter a Course No you want to add" << endl;
            cin >> value;
            Add_Course(value);
        }
        if (ch == 2)
        {
            cout << "Enter Seat number and course num you want to add" << endl;
            int S_No;
            int C_No;
            cin >> S_No >> C_No;

            Add_Student(C_No, S_No);
        }
        if (ch == 3)
        {
            // cout << "Display All" << endl;
            // cin >> value;
            Display_All(value);
        }

        if (ch == 4)
        {
            int C_No;
            cout << "Enter Course No to delete: ";
            cin >> C_No;
            Delete_Course(C_No);
        }

        if (ch == 10)
        {
            break;
        }
        cout << "Press number to execute function" << endl;
    };
}