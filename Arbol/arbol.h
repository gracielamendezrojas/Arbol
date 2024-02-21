#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include <stdlib.h>
#include <iostream>
#include <stdio.h>

using namespace std;

//***************************//
//********ARBOL COCIDO*******//
//***************************//

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

int contarPiezas(Nodo *arbol) {
    if (arbol == nullptr) {
        return 0;
    } else {
        return 1 + contarPiezas(arbol->izq) + contarPiezas(arbol->der);
    }
}

int contarPiezasValidas(Nodo *arbol) {
   if (arbol == nullptr) {
        return 0;
    }

    if (arbol->temperatura < 30.8) {
        return 1 + contarPiezasValidas(arbol->izq) + contarPiezasValidas(arbol->der);
    } else {
        return contarPiezasValidas(arbol->izq) + contarPiezasValidas(arbol->der);
    }
}

int contarCajas(Nodo *arbol) {
    return contarPiezasValidas(arbol) / 5;
}


//*******************************//
//********ARBOL IMPREGNADO*******//
//*******************************//

struct NodoImpregnado {
    double resistencia;
    double voltaje;
    double campoMagnetico;
    char tipoSensor;
    NodoImpregnado *der;
    NodoImpregnado *izq;
};

NodoImpregnado *CreateNodeImpregnado(double resistencia, double voltaje, double campoMagnetico, char tipoSensor){

    NodoImpregnado *nuevo=new NodoImpregnado();
    nuevo->resistencia = resistencia;
    nuevo->voltaje = voltaje;
    nuevo->campoMagnetico = campoMagnetico;
    nuevo->tipoSensor = tipoSensor;
    nuevo->der=NULL;
    nuevo->izq=NULL;

    return nuevo;
}

void insert_NodeImpregnado(NodoImpregnado*& arbol, double resistencia, double voltaje, double campoMagnetico, char tipoSensor){
    double raiz;
    if(arbol==nullptr){
        arbol=CreateNodeImpregnado(resistencia,voltaje,campoMagnetico,tipoSensor);
    }else{
        raiz=arbol->resistencia;
        if(resistencia< raiz){
            /* menor a la izquierda*/
            insert_NodeImpregnado(arbol->izq, resistencia, voltaje,  campoMagnetico, tipoSensor);
        }else{
            /* mayor a la derecha*/
            insert_NodeImpregnado(arbol->der,resistencia, voltaje,  campoMagnetico, tipoSensor);
        }
    }
}

void mostrarArbolImpregnado(NodoImpregnado *arbol, int cont){
    if(arbol==NULL){
        return;
    }else{
        mostrarArbolImpregnado(arbol->der, cont+1);
        for(int i=0; i< cont; i++){
                cout<<"  ";
        }
        cout<< arbol-> resistencia <<endl;

        mostrarArbolImpregnado(arbol->izq, cont+1);
    }
}

bool search_node_treeImpregnado(NodoImpregnado *arbol, double presistencia){
    if(arbol == NULL){
        return false;
    }else if(arbol -> resistencia == presistencia){
        return true;
    }else if (presistencia < arbol -> resistencia ){
        return search_node_treeImpregnado(arbol -> izq, presistencia);
    }else{
        return search_node_treeImpregnado(arbol -> der, presistencia);
    }
}

NodoImpregnado* search_return_node_treeImpregnado(NodoImpregnado *arbol, double presistencia){
    if(arbol == nullptr){
        return nullptr;
    }else if(arbol -> resistencia == presistencia){
        return arbol;
    }else if (presistencia < arbol -> resistencia ){
        return search_return_node_treeImpregnado(arbol -> izq, presistencia);
    }else{
        return search_return_node_treeImpregnado(arbol -> der, presistencia);
    }
}

NodoImpregnado* find_smallestImpregnado(NodoImpregnado* arbol){
    if(arbol->izq){
        return find_smallestImpregnado(arbol->izq);
    }
    return arbol;
}

NodoImpregnado* delete_nodeImpregnado(NodoImpregnado*& arbol, double resistencia){
    if (arbol == nullptr) {
        return arbol;
    }
    if (resistencia < arbol->resistencia) {
        arbol->izq = delete_nodeImpregnado(arbol->izq, resistencia);
    }
    else if (resistencia > arbol->resistencia) {
        arbol->der = delete_nodeImpregnado(arbol->der, resistencia);
    }
    else {
        if (arbol->izq == nullptr) {
            NodoImpregnado* aux = arbol->der;
            free(arbol);
            return aux;
        } else if (arbol->der == nullptr) {
            NodoImpregnado* aux = arbol->izq;
            free(arbol);
            return aux;
        }
        NodoImpregnado* aux = find_smallestImpregnado(arbol->der);
        arbol->resistencia = aux->resistencia;
        arbol->voltaje = aux->voltaje;
        arbol->campoMagnetico = aux->campoMagnetico;
        arbol->tipoSensor = aux->tipoSensor;
        arbol->der = delete_nodeImpregnado(arbol->der, aux->resistencia);
    }
    return arbol;
}

int contarPiezasImpregnado(NodoImpregnado *arbol) {
    if (arbol == nullptr) {
        return 0;
    } else {
        return 1 + contarPiezasImpregnado(arbol->izq) + contarPiezasImpregnado(arbol->der);
    }
}

int contarPiezasValidasImpregnado(NodoImpregnado *arbol) {
   if (arbol == nullptr) {
        return 0;
    }

    if (arbol->resistencia < 30.8) {
        return 1 + contarPiezasValidasImpregnado(arbol->izq) + contarPiezasValidasImpregnado(arbol->der);
    } else {
        return contarPiezasValidasImpregnado(arbol->izq) + contarPiezasValidasImpregnado(arbol->der);
    }
}

int contarCajasImpregnado(NodoImpregnado *arbol) {
    return contarPiezasValidasImpregnado(arbol) / 5;
}

//********************//
//*******MENUS********//
//********************//
Nodo *raizCocido=nullptr;


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
        cout << "6. Conteo de cajas\n";
        cout << "7. Salir\n";
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
            case 5 :
            {
                cout << "\nCantidad de piezas en proceso cocido: " << contarPiezas(raizCocido) << endl;
                system("pause");
                break;
            }
            case 6 :
            {
                cout << "\nCantidad de cajas en proceso cocido: " << contarCajas(raizCocido) << endl;
                break;
            }
            default:
            {
            break;
            }
        }
    }while(opcion != 6);
}

NodoImpregnado *raizImpregnado=nullptr;

void menuImpregnado(){
    int opcion;
    char tipoSensor;
    double resistencia, voltaje, campoMagnetico;
    int contador=0;
    do{

        cout << "\n Opciones del proceso impregnado\n";
        cout << "1. Insertar pieza\n";
        cout << "2. Mostrar el árbol\n";
        cout << "3. Buscar pieza por resistencia\n";
        cout << "4. Eliminar pieza por resistencia\n";
        cout << "5. Conteo de piezas\n";
        cout << "6. Conteo de cajas\n";
        cout << "7. Salir\n";
        cout << "Digite la opción::\n";
        cin >> opcion;

        switch (opcion) {
            case 1:
            {
                cout << "\n Ingrese la resistencia de la pieza::\n";
                cin >> resistencia ;

                cout << "\n Ingrese el voltaje de la pieza::\n";
                cin >> voltaje ;

                cout << "\n Ingrese el campo magnetico de la pieza::\n";
                cin >> campoMagnetico ;

                cout << "\n Ingrese el tipo de sensor::\n";
                cin >> tipoSensor ;

                insert_NodeImpregnado(raizImpregnado, resistencia, voltaje, campoMagnetico, tipoSensor);
                system("pause");
                break;
            }
            case 2:
            {
                cout << "\n";
                cout << "\n Así se ve el árbol actualmente ...\n";
                cout << "\n";
                mostrarArbolImpregnado(raizImpregnado, contador);
                cout << "\n";
                system("pause");
                break;
            }
            case 3:
            {
                cout << "\n Ingresa la resistencia de la pieza para buscarla:: \n";
                cin >> resistencia;
                NodoImpregnado *nodoImpregnadoBuscado= new NodoImpregnado();
                nodoImpregnadoBuscado= search_return_node_treeImpregnado(raizImpregnado, resistencia);

                cout << "\n Buscando pieza.... \n";

                if (nodoImpregnadoBuscado == NULL) {
                    cout << "\n No se encontró la pieza.\n";
                }
                else {
                    cout <<"La pieza encontrada tiene los siguientes datos: "<<endl;
                    cout <<"-Resistencia:: " <<nodoImpregnadoBuscado->resistencia <<endl;
                    cout <<"-Voltaje:: " <<nodoImpregnadoBuscado->voltaje <<endl;
                    cout <<"-Campo magnetico:: " <<nodoImpregnadoBuscado->campoMagnetico <<endl;
                    cout <<"-Tipo de sensor:: " <<nodoImpregnadoBuscado->tipoSensor <<endl;
                }
                break;
            }
            case 4:
            {
                cout << "\n Ingrese la resistencia de la pieza a eliminar::\n";
                cin >> resistencia ;
                raizImpregnado = delete_nodeImpregnado(raizImpregnado, resistencia);

                cout << "\n Así se ve el árbol actualmente...\n" << endl;
                cout << "\n";
                mostrarArbolImpregnado(raizImpregnado, contador);
                cout << "\n";
                system("pause");
                break;
            }
            case 5 :
            {
                cout << "Cantidad de piezas en proceso impregnado: " << contarPiezasImpregnado(raizImpregnado) << endl;
                system("pause");
                break;
            }
            case 6 :
            {
                cout << "Cantidad de cajas en proceso impregnado: " << contarCajasImpregnado(raizImpregnado) << endl;
                break;
            }
            default:
            {
                break;
            }
        }
    }while(opcion != 7);
}

void Menu() {
    int opcionInicial;

    do {
        cout << "¿Qué proceso desea realizar?:" << endl;
        cout << "1. Cocido" << endl;
        cout << "2. Impregnado" << endl;
        cout << "3. Mostrar total de piezas en ambos procesos" << endl;
        cout << "4. Mostrar total de cajas producidas" << endl;
        cout << "5. Salir" << endl;
        cout << "Digite una opción: " << endl;
        cin >> opcionInicial;

        switch (opcionInicial) {
            case 1: {
                menuCocido();
                break;
            }
            case 2: {
                menuImpregnado();
                break;
            }
            case 3: {
                int piezasCocido = contarPiezas(raizCocido);
                int piezasImpregnado = contarPiezasImpregnado(raizImpregnado);
                int totalPiezas = piezasCocido + piezasImpregnado;
                cout << "Total de piezas en proceso cocido: " << piezasCocido << endl;
                cout << "Total de piezas en proceso impregnado: " << piezasImpregnado << endl;
                cout << "Total de piezas en ambos procesos: " << totalPiezas << endl;
                break;
            }
            case 4: {
                int cajasCocido = contarCajas(raizCocido);
                int cajasImpregnado = contarCajasImpregnado(raizImpregnado);
                int totalCajas = cajasCocido + cajasImpregnado;
                cout << "Total de cajas en proceso cocido: " << cajasCocido << endl;
                cout << "Total de cajas en proceso impregnado: " << cajasImpregnado << endl;
                cout << "Total de cajas producidas: " << totalCajas << endl;
                break;
            }
        }
    } while (opcionInicial != 5);
}

#endif // ARBOL_H_INCLUDED
