#include <stdio.h>
#include <iostream>
using namespace std;

struct nodo
{
       int dato;
       struct nodo *sig;
};


struct nodo* crear_nodo(int x);
struct nodo* insertar_final(int x, nodo* cabeza);
struct nodo* borrar(int x, nodo* cabeza);
void imprimri_lista(nodo* cabeza);
//insercion en medio
struct nodo* insertar_ordernad(int x, nodo* cabeza);


int main()
{
    int num=0;
    nodo* cabeza =NULL;
    cabeza=insertar_final(10, cabeza);
    cabeza=insertar_final(20, cabeza);
    cabeza=insertar_final(30, cabeza);
    cabeza=insertar_final(40, cabeza);
    cabeza=insertar_final(50, cabeza);
    
    cin>>num;
    //cabeza=borrar(num, cabeza);
    
    
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

struct nodo* insertar_final(int x, nodo* cabeza)
{
       nodo *np;
       np=crear_nodo(x);
       if(cabeza == NULL)
       {
                 return np;
       }
       else
       {
           nodo *aux;
           for(aux = cabeza; aux->sig != NULL; aux=aux->sig);
                   aux->sig=np;
           return cabeza;
       }
}


struct nodo* insertar_ordernad(int x, nodo* cabeza)
{
       //nuevo igual cabeza  poner for que rrecora la lista nelazada  parecidoi a borrar 
       nodo *nuevo;
       nuevo=crear_nuevo(x);
       nodo *aux;
       cabeza=aux:
       if((cabeza->dato>aux->sig) && (nuevo->dato<aux->sig->dato)
       {
                                  cout<<"holña";
       }
}

struct nodo* borrar(int x, nodo* cabeza)
{
     /*for(; cabeza!=NULL; cabeza=cabeza->sig)
     {*/
     nodo *aux;
     nodo *aux2;
    if(x == cabeza->dato)
    {
         //caso 1 Borrar primer dato
         aux=cabeza;
         cabeza=cabeza->sig;
         free(aux);
         return cabeza;
    }
    else
    {
        //Buscra y borrar datos
        if(cabeza->sig != NULL)
        {
         aux2=cabeza;
         for(aux=cabeza->sig; aux != NULL; aux=aux->sig)
         {
              if(aux->dato==x)
              {
                  aux2->sig=aux->sig;
                  free(aux);
                  return cabeza;
              }
              else
              {
                  aux2=aux;
              }
         }
        }
        aux=cabeza;
    }
     //}
}

//Paso de parametros por valor y por referencia
void imprimri_lista(nodo* cabeza)
{
     for(; cabeza!=NULL; cabeza=cabeza->sig)
     {
            cout<<cabeza->dato<<endl;
     }
}
