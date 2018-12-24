#include <stdio.h>
#include <iostream>
using namespace std;

struct nodo
{
       int dato;
       struct nodo *sig;
};

struct nodo* crear_nodo(int x);
struct nodo* insertar_inicio(int x, nodo* cabeza);
void imprimri_lista(nodo* cabeza);

int main()
{
    nodo* cabeza =NULL;
    cabeza=insertar_inicio(8,cabeza);
    cabeza=insertar_inicio(10,cabeza);
    cabeza=insertar_inicio(20,cabeza);
    /*cout<<cabeza->dato<<endl;
    cabeza=cabeza->sig;
    cout<<cabeza->dato<<endl;;
    cabeza=cabeza->sig;
    cout<<cabeza->dato<<endl;*/
    imprimri_lista(cabeza);
    
    system("PAUSE");
    return 0;
}

struct nodo* crear_nodo(int x)
{
       nodo *np;
       np=(nodo*)malloc(sizeof(nodo));
       np->dato=x;
       np->sig=NULL;
       return np;
}

struct nodo* insertar_inicio(int x, nodo* cabeza)
{
       nodo *np;
       np=crear_nodo(x);
       if(cabeza == NULL)
       {
                 return np;
       }
       else
       {
           np->sig=cabeza;
           cabeza=np;
           return cabeza;
       }
}

//Paso de parametros por valor y por referencia
void imprimri_lista(nodo* cabeza)
{
     for(; cabeza!=NULL; cabeza=cabeza->sig)
     {
            cout<<cabeza->dato<<endl;
     }
}
