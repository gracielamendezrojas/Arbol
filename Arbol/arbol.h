#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdlib.h> 
#include <iostream> 
#include <stdio.h>

using namespace std; 

struct Nodo{

    double temperatura;
    double humedad;
    double presion;
    char tipoPieza;
    Nodo *der;
    Nodo *izq;

};

Nodo *CreateNode(double temperatura, double humedad, double presion, char tipoPieza){

    Nodo *nuevo=new Nodo();
    nuevo->humedad = humedad;
    nuevo->presion = presion;
    nuevo->temperatura = temperatura;
    nuevo->tipoPieza = tipoPieza;
    nuevo->der=NULL;
    nuevo->izq=NULL;

    return nuevo;
}


void insert_Node(Nodo*& arbol, double temperatura, double humedad, double presion, char tipoPieza){
    double raiz;
    if(arbol==nullptr){
        arbol=CreateNode(temperatura,humedad,presion,tipoPieza);
    }else{
        raiz=arbol->temperatura;
        if(temperatura< raiz){
            /* menor a la izquierda*/
            insert_Node(arbol->izq, temperatura, humedad,  presion, tipoPieza);
        }else{
            /* mayor a la derecha*/
            insert_Node(arbol->der,temperatura, humedad,  presion, tipoPieza);
        }
    }
}

void mostrarArbol(Nodo *arbol, int cont){
    if(arbol==NULL){
        return;
    }else{
        mostrarArbol(arbol->der, cont+1);
        for(int i=0; i< cont; i++){
                cout<<"  ";       
        }
        cout<< arbol-> temperatura <<endl; 

        mostrarArbol(arbol->izq, cont+1);
    }
}


bool search_node_tree(Nodo *arbol, double ptemperatura){
    if(arbol == NULL){
        return false;
    }else if(arbol -> temperatura == ptemperatura){
        return true;
    }else if (ptemperatura < arbol -> temperatura ){
        return search_node_tree(arbol -> izq, ptemperatura);
    }else{
        return search_node_tree(arbol -> der, ptemperatura);
    }
}

Nodo* search_return_node_tree(Nodo *arbol, double ptemperatura){
    if(arbol == nullptr){
        return nullptr;
    }else if(arbol -> temperatura == ptemperatura){
        return arbol;
    }else if (ptemperatura < arbol -> temperatura ){
        return search_return_node_tree(arbol -> izq, ptemperatura);
    }else{
        return search_return_node_tree(arbol -> der, ptemperatura);
    }
}


Nodo* find_smallest(Nodo* arbol){
    if(arbol->izq){
        return find_smallest(arbol->izq); 
    }
    return arbol; 
}


Nodo* delete_node(Nodo*& arbol, double temperatura){
    if (arbol == nullptr) {
        return arbol;
    }
    if (temperatura < arbol->temperatura) {
        arbol->izq = delete_node(arbol->izq, temperatura);
    }
    else if (temperatura > arbol->temperatura) {
        arbol->der = delete_node(arbol->der, temperatura);
    }
    else {
        if (arbol->izq == nullptr) {
            Nodo* aux = arbol->der;
            free(arbol);
            return aux;
        } else if (arbol->der == nullptr) {
            Nodo* aux = arbol->izq;
            free(arbol);
            return aux;
        }
        Nodo* aux = find_smallest(arbol->der);
        arbol->temperatura = aux->temperatura;
        arbol->humedad = aux->humedad;
        arbol->presion = aux->presion;
        arbol->tipoPieza = aux->tipoPieza;
        arbol->der = delete_node(arbol->der, aux->temperatura);
    }
    return arbol;
}

void menuCocido(){
    int opcion; 
    char tipoPieza;
    double temperatura, humedad, presion;
    int contador=0;
    Nodo *raizCocido=nullptr;
    do{

        cout << "\n Opciones del proceso cocido\n";
        cout << "1. Insertar pieza\n";
        cout << "2. Mostrar el árbol\n";
        cout << "3. Buscar pieza por temperatura\n";
        cout << "4. Eliminar pieza por temperatura\n";
        cout << "5. Conteo de piezas\n";
        cout << "6. Salir\n";
        cout << "Digite la opción::\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
            {
                cout << "\n Ingrese la temperatura de la pieza::\n";
                cin >> temperatura ;

                cout << "\n Ingrese la humedad de la pieza::\n";
                cin >> humedad ;

                cout << "\n Ingrese la presion de la pieza::\n";
                cin >> presion ;

                cout << "\n Ingrese el tipo pieza::\n";
                cin >> tipoPieza ;

                insert_Node(raizCocido, temperatura,humedad, presion, tipoPieza);
                system("pause");
                break;
            }
            case 2:
            {
                cout << "\n";
                cout << "\n Así se ve el árbol actualmente ...\n";
                cout << "\n";
                mostrarArbol(raizCocido, contador);
                cout << "\n";
                system("pause");
                break; 
            }  
            case 3:
            {
                cout << "\n Ingresa la temperatura de la pieza para buscarla:: \n";
                cin >> temperatura;
                Nodo *nodoBuscado= new Nodo(); 
                nodoBuscado= search_return_node_tree(raizCocido, temperatura); 

                cout << "\n Buscando pieza.... \n";
        
                if (nodoBuscado == NULL) {
                    cout << "\n No se encontró la pieza.\n";
                }
                else {
                    cout <<"La pieza encontrada tiene los siguientes datos: "<<endl; 
                    cout <<"-Temperatura:: " <<nodoBuscado->temperatura <<endl;
                    cout <<"-Presión:: " <<nodoBuscado->presion <<endl;
                    cout <<"-Humedad:: " <<nodoBuscado->humedad <<endl;
                    cout <<"-Tipo de pieza:: " <<nodoBuscado->tipoPieza <<endl;
                }
                break;
            }
            case 4:
            {
                cout << "\n Ingrese la temperatura de la pieza a eliminar::\n";
                cin >> temperatura ;
                raizCocido = delete_node(raizCocido, temperatura);
                
                cout << "\n Así se ve el árbol actualmente...\n" << endl;
                cout << "\n";
                mostrarArbol(raizCocido, contador);
                cout << "\n";
                system("pause");
                break;
            }

            default:
            {
            break;
            }
        }    
    }while(opcion != 6); 
}

void menuImpregnado(){
    
}

void Menu() {

    int opcionInicial;

    do{
        cout << "¿Qué proceso desea realizar?:" <<endl;
        cout << "1. cocido" <<endl;
        cout << "2. impregnado" <<endl;
        cout << "Digite una opción: " <<endl;
        cin >> opcionInicial;
        switch (opcionInicial)
        {
            case 1:
                menuCocido(); 
                break; 
            case 2 :
                menuImpregnado(); 
                break;
        } 
    }while(opcionInicial != 6);
}

#endif // ARBOL_H_INCLUDED
