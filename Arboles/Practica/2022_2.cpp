#include <iostream>
#include <cmath>
using namespace std;

struct Nodo
{
    int camp1;
    int camp2;
    int camp3;
    Nodo *left;
    Nodo *right;
};

struct Tree{
    Nodo *root;
};

Nodo *createNodo(int camp1, int camp2, int camp3, Nodo *left, Nodo *right){
    Nodo *newNodo = new struct Nodo;

    newNodo->camp1 = camp1;
    newNodo->camp2 = camp2;
    newNodo->camp3 = camp3;
    newNodo->left = left;
    newNodo->right = right;

    return newNodo;
}

void buildTree(Tree &tree){
    //Nodo *newNodo = createNodo(0, 0, 0, nullptr , nullptr);
    tree.root = nullptr;
}

void insert(Nodo *&root, int camp1, int camp2, int camp3){

    if(root == nullptr){
        Nodo *newNodo = createNodo(camp1, camp2, camp3, nullptr, nullptr);
        root = newNodo;
    }
    else{
        if(camp1 > root->camp1){
            insert(root->right,  camp1,  camp2,  camp3);
        }
        else if(camp1 == root->camp1 and camp2 > root->camp2){
            insert(root->right,  camp1,  camp2,  camp3);
        }
        else if(camp1 == root->camp1 and camp2 < root->camp2){
            insert(root->left,  camp1,  camp2,  camp3);
        }
        else{
            insert(root->left,  camp1,  camp2,  camp3);
        }
    }        
}

void printPreOrder(Nodo *root){

    if(root != nullptr){
        cout<<root->camp1<<","<<root->camp2<<","<<root->camp3<<" ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }

}

void searchElement(Nodo *root, int camp1, int camp2, int camp3, bool &condition){

    if(root == nullptr){
        condition = false;
        return;
    }

    if(root->camp1 == camp1 and root->camp2 == camp2 and root->camp3 == camp3){
        condition = true;
        return ;
    }

    if(camp1 > root->camp1){
        searchElement(root->right,  camp1,  camp2,  camp3, condition);
    }
    else if(camp1 == root->camp1 and camp2 > root->camp2){
        searchElement(root->right,  camp1,  camp2,  camp3, condition);
    }
    else if(camp1 == root->camp1 and camp2 < root->camp2){
        searchElement(root->left,  camp1,  camp2,  camp3, condition);
    }
    else{
        searchElement(root->left,  camp1,  camp2,  camp3, condition);
    }
}

int main(){

    Tree tree;
    bool condition = false;

    buildTree(tree);
    insert(tree.root, 10, 8, 5);
    insert(tree.root, 8, 20, 6);
    insert(tree.root, 15, 10, 3);
    insert(tree.root, 5, 10, 3);
    insert(tree.root, 16, 7, 8);
    insert(tree.root, 10, 1, 7);

    printPreOrder(tree.root);
    cout<<endl;
    searchElement(tree.root, 15, 10, 3, condition);
    cout<<condition<<endl;


    return 0;
}