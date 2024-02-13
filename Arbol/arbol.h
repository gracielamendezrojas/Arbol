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

Nodo *arbol=NULL;

void insert_Node(Nodo *&arbol, double temperatura, double humedad, double presion, char tipoPieza){
    double raiz;
    if(arbol==NULL){
        Nodo *nuevo=CreateNode(temperatura,humedad,presion,tipoPieza);
        arbol=nuevo;
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


void menuCocido(){
    int opcion; 
    char tipoPieza;
    double temperatura, humedad, presion;
    int contador=0;
    do{

        cout << "\n Opciones del proceso cocido\n";
        cout << "1. Insertar pieza\n";
        cout << "2. Mostrar el árbol\n";
        cout << "3. Buscar pieza por temperatura\n";
        cout << "4. Eliminar pieza por temperatura\n";
        cout << "5. Conteo de piezas\n";
        cout << "6. Salir\n";
        cout << "Digite la opción::";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n Ingrese la temperatura de la pieza::";
                cin >> temperatura ;

                cout << "\n Ingrese la humedad de la pieza::";
                cin >> humedad ;

                cout << "\n Ingrese la presion de la pieza::";
                cin >> presion ;

                cout << "\n Ingrese el tipo pieza::";
                cin >> tipoPieza ;

                insert_Node(arbol, temperatura,humedad, presion, tipoPieza);
                system("pause");
                break;

            case 2:
                cout << "\n";
                cout << "\n Mostrando el árbol completo\n";
                cout << "\n";
                mostrarArbol(arbol, contador);
                system("pause");
                break; 
                        
            case 3:
                cout << "\n Ingresa la temperatura de la pieza para buscarla";
                cin >> temperatura;

                cout << "\n Buscando pieza \n";
                        if (search_node_tree(arbol, temperatura) == true) {
                            cout << "\n Se encontró la pieza";
                        }
                        else {
                            cout << "\n No se encontró la pieza";
                        }
                break;
            default:
                break;
        }    
    }while(opcion != 6); 
}

void menuImpregnado(){
    int opcion; 
    char tipoPieza;
    double temperatura, humedad, presion;
    int contador=0;
    do{

        cout << "\n Opciones del proceso cocido\n";
        cout << "1. Insertar pieza\n";
        cout << "2. Mostrar el árbol\n";
        cout << "3. Buscar pieza por temperatura\n";
        cout << "4. Eliminar pieza por temperatura\n";
        cout << "5. Conteo de piezas\n";
        cout << "6. Salir\n";
        cout << "Digite la opción::";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n Ingrese la temperatura de la pieza::";
                cin >> temperatura ;

                cout << "\n Ingrese la humedad de la pieza::";
                cin >> humedad ;

                cout << "\n Ingrese la presion de la pieza::";
                cin >> presion ;

                cout << "\n Ingrese el tipo pieza::";
                cin >> tipoPieza ;

                insert_Node(arbol, temperatura,humedad, presion, tipoPieza);
                system("pause");
                break;

            case 2:
                cout << "\n";
                cout << "\n Mostrando el árbol completo\n";
                cout << "\n";
                mostrarArbol(arbol, contador);
                system("pause");
                break; 
                        
            case 3:
                cout << "\n Ingresa la temperatura de la pieza para buscarla";
                cin >> temperatura;

                cout << "\n Buscando pieza \n";
                        if (search_node_tree(arbol, temperatura) == true) {
                            cout << "\n Se encontró la pieza";
                        }
                        else {
                            cout << "\n No se encontró la pieza";
                        }
                break;
            default:
                break;
        }    
    }while(opcion != 6); 
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
