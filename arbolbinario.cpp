#include <iostream>

struct Nodo{
    int valor;
    Nodo* izquierda;
    Nodo* derecha;

    Nodo(int val):valor(val),izquierda(nullptr), derecha(nullptr) {}
};

void insertarNodo(Nodo*& raiz, Nodo* nodo) {
    if(raiz == nullptr){
        raiz = nodo;
    } else{
        if(nodo->valor < raiz->valor){
            if(raiz->izquierda == nullptr) {
                raiz->izquierda = nodo;
            } else{
                insertarNodo(raiz->izquierda, nodo);
            }
        } else if(nodo->valor > raiz->valor) {
            if(raiz->derecha == nullptr) {
                raiz->derecha = nodo;
            } else {
                insertarNodo(raiz->derecha, nodo);
            }
        } else{
            // El nodo ya existe en el árbol, no se inserta
            delete nodo;
        }
    }
}


void mostrarArbol(Nodo* raiz, int nivel = 0) {
    if (raiz != nullptr) {
        mostrarArbol(raiz->derecha, nivel + 1);
        for (int i = 0; i < nivel; i++) {
            std::cout << "   ";
        }
        std::cout << raiz->valor << std::endl;
        mostrarArbol(raiz->izquierda, nivel + 1);
    }
}

int main() {
	std::cout<<"ARBOL BINARIO (DERECHA A IZQUIERDA): "<<std::endl;
	std::cout<<"-------------------------------------------------------- "<<std::endl;
	std::cout<<std::endl<<std::endl;
    Nodo* arbol = nullptr;

    
    insertarNodo(arbol, new Nodo(8));
    insertarNodo(arbol, new Nodo(3));
    insertarNodo(arbol, new Nodo(10));
    insertarNodo(arbol, new Nodo(1));
    insertarNodo(arbol, new Nodo(6));
    insertarNodo(arbol, new Nodo(14));
    insertarNodo(arbol, new Nodo(4));
    insertarNodo(arbol, new Nodo(7));
    insertarNodo(arbol, new Nodo(13));
    

    std::cout << "Arbol binario:" << std::endl;
    mostrarArbol(arbol);
    
    std::cout<<std::endl<<std::endl;
    
    std::cout << "Arbol binario actualizado:" << std::endl;
    mostrarArbol(arbol);

    return 0;
}

