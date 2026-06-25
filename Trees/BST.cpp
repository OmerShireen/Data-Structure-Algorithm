#include <iostream>
using namespace std;

struct BSTNode{
    int data;
    BSTNode* left;
    BSTNode* right;
};
BSTNode* Root = NULL;

BSTNode* insertBST(BSTNode* cur, int value ){
    if( cur ==  NULL){
        BSTNode* temp = new BSTNode;
        temp->data = value;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(value < cur-> data){
        cur->left = insertBST(cur->left, value);
    }
    else{
        cur->right = insertBST(cur->right, value);
    }
    return cur;
}

void inOrder(BSTNode* cur){
    if(cur == NULL)
        return;

    inOrder(cur->left);
    cout<< cur-> data << " ";
    inOrder(cur->right);

}
void preOrder(BSTNode* cur){
    if(cur == NULL)
        return;

    cout<< cur-> data << " ";
    preOrder(cur->left);
    preOrder(cur->right);

}
void postOrder(BSTNode* cur){
    if(cur == NULL)
        return;

    postOrder(cur->left);
    postOrder(cur->right);
    cout<< cur-> data << " ";

}
bool searchBst(BSTNode* cur, int value){
    if (cur == NULL){
        return false;
    }
    else if (cur-> data == value){
        return true;
    }
    else if(value < cur->data){
        return searchBst(cur->left,  value);
    }
    else{
        return searchBst(cur->right, value);
    }
}