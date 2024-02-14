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

Nodo* search_return_node_tree(Nodo *arbol, double ptemperatura){
    if(arbol == NULL){
        return NULL;
    }else if(arbol -> temperatura == ptemperatura){
        return arbol;
    }else if (ptemperatura < arbol -> temperatura ){
        return search_return_node_tree(arbol -> izq, ptemperatura);
    }else{
        return search_return_node_tree(arbol -> der, ptemperatura);
    }
}


Nodo* find_smallest(Nodo *arbol){
    if(arbol->izq){
        return find_smallest(arbol->izq); 
    }
    return arbol; 
}


bool delete_node(Nodo *arbol, double ptemperatura){
    Nodo *nodoEvaluado = new Nodo(); 
    Nodo *aux = new Nodo(); 
    nodoEvaluado = search_return_node_tree(arbol,  ptemperatura); 
    if(nodoEvaluado == NULL){
        return false; 
    }else{
        if(nodoEvaluado->der ==NULL && nodoEvaluado->izq ==NULL){
            aux = nodoEvaluado; 
            nodoEvaluado = NULL; 
            free(aux); 
        }else if(nodoEvaluado->der == NULL && nodoEvaluado->izq != NULL){
            aux = nodoEvaluado -> izq; 
            nodoEvaluado->humedad = aux ->humedad; 
            nodoEvaluado->temperatura = aux ->temperatura; 
            nodoEvaluado->presion = aux ->presion; 
            nodoEvaluado->tipoPieza = aux -> tipoPieza; 

            nodoEvaluado ->der = aux ->der;  
            nodoEvaluado ->izq = aux ->izq;  
            free(aux); 

        }else if(nodoEvaluado->der != NULL && nodoEvaluado->izq == NULL){
            aux = nodoEvaluado -> der; 
            nodoEvaluado->humedad = aux ->humedad; 
            nodoEvaluado->temperatura = aux ->temperatura; 
            nodoEvaluado->presion = aux ->presion; 
            nodoEvaluado->tipoPieza = aux -> tipoPieza; 

            nodoEvaluado ->der = aux ->der;  
            nodoEvaluado ->izq = aux ->izq;  
            free(aux); 
        }else{
            aux = find_smallest(nodoEvaluado->der); 
            nodoEvaluado->humedad = aux ->humedad; 
            nodoEvaluado->temperatura = aux ->temperatura; 
            nodoEvaluado->presion = aux ->presion; 
            nodoEvaluado->tipoPieza = aux -> tipoPieza; 
            
            Nodo *aux2 = new Nodo(); 
            aux2 = aux->der; 
            aux = aux2; 
            free(aux2); 
        }
        return true; 
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

                insert_Node(arbol, temperatura,humedad, presion, tipoPieza);
                system("pause");
                break;
            }
            case 2:
            {
                cout << "\n";
                cout << "\n Mostrando el árbol completo\n";
                cout << "\n";
                mostrarArbol(arbol, contador);
                system("pause");
                break; 
            }  
            case 3:
            {
                cout << "\n Ingresa la temperatura de la pieza para buscarla:: \n";
                cin >> temperatura;
                Nodo *nodoBuscado= new Nodo(); 
                nodoBuscado= search_return_node_tree(arbol, temperatura); 

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
                if (delete_node(arbol, temperatura)) {
                    cout << "\n La pieza fue eliminada exitosamente.\n";
                }else {
                    cout << "\n La pieza NO fue eliminada.\n";
                }
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
        cout << "Digite la opción::\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\n Ingrese la temperatura de la pieza::\n";
                cin >> temperatura ;

                cout << "\n Ingrese la humedad de la pieza::\n";
                cin >> humedad ;

                cout << "\n Ingrese la presión de la pieza::\n";
                cin >> presion ;

                cout << "\n Ingrese el tipo pieza::\n";
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
                cout << "\n Ingresa la temperatura de la pieza para buscarla::\n";
                cin >> temperatura;

                cout << "\n Buscando pieza... \n";
                        if (search_node_tree(arbol, temperatura) == true) {
                            cout << "\n Se encontró la pieza. \n";
                        }
                        else {
                            cout << "\n No se encontró la pieza. \n";
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
