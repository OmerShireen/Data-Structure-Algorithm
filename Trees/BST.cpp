#include <iostream>
using namespace std;

struct BSTNode
{
    int data;
    BSTNode *left;
    BSTNode *right;
};
BSTNode *Root = NULL;

BSTNode *insertBST(BSTNode *cur, int value)
{
    if (cur == NULL)
    {
        BSTNode *temp = new BSTNode;
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (value < cur->data)
    {
        cur->left = insertBST(cur->left, value);
    }
    else
    {
        cur->right = insertBST(cur->right, value);
    }
    return cur;
}

void inOrder(BSTNode *cur)
{
    if (cur == NULL)
        return;

    inOrder(cur->left);
    cout << cur->data << " ";
    inOrder(cur->right);
}
void preOrder(BSTNode *cur)
{
    if (cur == NULL)
        return;

    cout << cur->data << " ";
    preOrder(cur->left);
    preOrder(cur->right);
}
void postOrder(BSTNode *cur)
{
    if (cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    cout << cur->data << " ";
}
bool searchBst(BSTNode *cur, int value)
{
    if (cur == NULL)
    {
        return false;
    }
    else if (cur->data == value)
    {
        return true;
    }
    else if (value < cur->data)
    {
        return searchBst(cur->left, value);
    }
    else
    {
        return searchBst(cur->right, value);
    }
}
BSTNode *findMin(BSTNode *cur)
{
    if (cur == NULL){
        cout << " Root is empty" << endl;
        return NULL;
    }
    while (cur->left != NULL)
    {
        cur = cur->left;
    }
        return cur;
}

BSTNode *deleteBST(BSTNode *cur, int value)
{
    if (cur == NULL)
        return NULL;

    else if (value < cur->data)
    {
        cur->left = deleteBST(cur->left, value);
    }
    else if (value > cur->data)
    {
        cur->right = deleteBST(cur->right, value);
    }
    else
    {
        if (cur->left == NULL && cur->right == NULL)
        {
            delete cur;
            return NULL;
        }
        else if (cur->right == NULL)
        {
            BSTNode *temp = cur->left;
            delete cur;
            return temp;
        }
        else if (cur->left == NULL)
        {
            BSTNode *temp = cur->right;
            delete cur;
            return temp;
        }
        else
        {
            BSTNode *temp = cur->right;
            while (temp->left != NULL)
            {
                temp = temp->left;
            }
            cur->data = temp->data;

            cur->right = deleteBST(cur->right, temp->data);
        }
    }
    return cur;
}
int main()
{
    int ch;
    cout << "Press 1 for insert" << endl
         << "Press 2 for PreOrder" << endl
         << "Press 3 for PostOrder" << endl
         << "Press 4 for InOrder" << endl
         << "Press 5 for search" << endl
         << "Press 6 for Finding Min" << endl
         << "Press 7 for Delete" << endl
         << "Press 8 for exit" << endl;
    while (true)
    {
        cin >> ch;
        if (ch == 1)
        {
            int value;
            cout << "Enter a value u want to insert" << endl;
            cin >> value;
            Root = insertBST(Root, value);
        }
        else if (ch == 2)
        {
            cout << "PreOrder: ";
            preOrder(Root);
            cout << endl;
        }
        else if (ch == 3)
        {
            cout << "PostOrder: ";
            postOrder(Root);
            cout << endl;
        }
        else if (ch == 4)
        {
            cout << "Inorder: ";
            inOrder(Root);
            cout << endl;
        }
        else if (ch == 5)
        {
            int value;
            cout << "Enter a value you want to search: ";
            cin >> value;
            if (searchBst(Root, value))
                cout << "Value Found!\n";
            else
                cout << "Value not Found!\n";
        }
        if (ch == 6)
        {
            BSTNode *minNode = findMin(Root);
            if (minNode != NULL)
                cout << "Minimum value: " << minNode->data << endl;
        }
        if (ch == 7)
        {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            Root = deleteBST(Root, value);
        }
        else if (ch == 8)
        {
            break;
        }
        cout << "Press number to execute function: ";
    }
}
