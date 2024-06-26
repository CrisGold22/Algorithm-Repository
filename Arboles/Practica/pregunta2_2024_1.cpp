#include <iostream>
using namespace std;

struct Nodo{
    int element;
    Nodo *left;
    Nodo *right;
};

struct Tree{
    Nodo *root;
};

void buildTree(Tree &tree){
    tree.root = nullptr;
}

Nodo *createNodo(int element, Nodo *left, Nodo *right){
    Nodo *nodo = new struct Nodo;

    nodo->element = element;
    nodo->left = left;
    nodo->right = right;

    return nodo;
}

void insert(Nodo *&root, int element){
    if(root == nullptr){
        Nodo *newNodo = createNodo(element, nullptr, nullptr);
        root = newNodo;
    }
    else{
        if(element > root->element){
            insert(root->right, element);
        }
        else{
            insert(root->left, element);
        }
    }
}

void printInOrder(Nodo *root){
    
    if(root != nullptr){
        printInOrder(root->left);
        cout<<root->element<<" ";
        printInOrder(root->right);
    }
}

void plantarArbolBinario(struct Tree & arbol, struct Nodo * arbolIzquierdo,
                         int elemento, struct Nodo * arbolDerecho){
    
    struct Nodo * nuevoNodo = createNodo(elemento, arbolIzquierdo, arbolDerecho);
    arbol.root = nuevoNodo;
}

void plantarArbolBinario(struct Tree & arbol, struct Tree arbolIzquierdo,
                         int elemento, struct Tree arbolDerecho){
    
    struct Nodo * nuevoNodo = createNodo(elemento, arbolIzquierdo.root, arbolDerecho.root);
    arbol.root = nuevoNodo;
}

int leafsTree(Nodo *root){
    if(root == nullptr){
        return 0;
    }
    else if (root->left == nullptr and root->right == nullptr){
        return 1;
    }
    else{
        return leafsTree(root->left) + leafsTree(root->right);
    }
}

int nodosCounter(Nodo *root){
    if(root == nullptr){
        return 0;
    }
    return 1 + nodosCounter(root->left) + nodosCounter(root->right);
}

int main(){

    Tree arbol1, arbol2, arbol3;
    


    return 0;
}
