#include <stdio.h>
#include <iostream>
using namespace std;

struct nodo
{
       int coeficiente;
       int exponente;
       struct nodo *sig;
};

struct nodo* crear_nodo(int x, int y);
struct nodo* insertar_final(int x, int y, nodo* cabeza);
//void imprimri_lista(nodo* cabeza);
void MultiNumPol(int num, nodo* cabeza);
void MultiMonPol(nodo* mono, nodo* cabeza);


void imprimir_lista(nodo *cabeza){
     for(;cabeza!=NULL;cabeza=cabeza->sig){
       if(cabeza->coeficiente>0)
       cout<<"+";
       cout<<cabeza->coeficiente<<"x^"<<cabeza->exponente<<" ";
       }
}





int main()
{
    int x=0, y=0;
    int opc=0;
    int num=0;
    int coe=0;
    int exp=0;
    int coeM=0;
    int expM=0;
    char op;
    nodo* cabeza =NULL;
    nodo* mono = NULL;
    nodo* cabeza2=NULL;
    nodo* cabeza3=NULL;
    
    
    cout<<"Practica 1 Plinomios"<<endl;
    cout<<"1. Multiplicacion de un numero por un plinomio"<<endl;
    cout<<"2. Multiplicacion de un monomio por un polinomio"<<endl;
    cin>>opc;
    switch(opc)
    {
               case 1:
                    cout<<"Introduzca un numero"<<endl;
                    cin>>num;
                    cout<<"Introduzca un polinomio"<<endl;
                    do
                    {
                     cout<<"Coeficiente: ";
                     cin>>coe;
                     cout<<"Exponente: ";
                     cin>>exp;
                     cabeza=insertar_final(coe, exp, cabeza);
                    }
                    while(exp!=0);
                    MultiNumPol(num, cabeza);
                    break;
               case 2:
                    /*cout<<"Introduce un monomio"<<endl;
                    cin*/
                    /*cout<<"Introsuzca unmonomio"<<endl;
                    cout<<"Coeficiente: ";
                    cin>>coeM;
                    cout<<"Exponente: ";
                    cin>>expM;
                    mono=insertar_final(coeM, expM, mono);
                     
                     
                    cout<<"Introduzca un polinomio"<<endl;
                    do
                    {
                     cout<<"Coeficiente: ";
                     cin>>coe;
                     cout<<"Exponente: ";
                     cin>>exp;
                     cabeza=insertar_final(coe, exp, cabeza);
                    }
                    while(exp!=0);
                    
                    MultiMonPol(mono, cabeza);*/
                    cout<<"\tPOLINOMIO"<<endl;
                    do{
                    cout<<"Coeficiente del polinomio: "<<endl;
                    cin>>x;
                    cout<<"Exponente del polinomio: "<<endl;
                    cin>>y;
                    cabeza2=insertar_final(x,y,cabeza2);
                    cout<<"Quieres ingresar otro termino al polinomio?  (s/n)"<<endl;
                    cin>>op;
                    }while(op=='s');
                    
                    cout<<"\tMONONOMIO"<<endl;
                    cout<<"Coeficiente del mononomio: "<<endl;
                    cin>>x;
                    cout<<"Exponente del mononomio: "<<endl;
                    cin>>y;
                    cabeza3=insertar_final(x,y,cabeza3);
                    
                    MultiMonPol(cabeza3, cabeza2);
                    
                    
                    
                    /*imprimir_lista(cabeza2);
                    cout<<" x ";
                    imprimir_lista(cabeza3);
                    cout<<" = ";*/
                    
                    break;  
    }

    //imprimri_lista(cabeza);
    
    
    
    system("PAUSE");
    return 0;
}

struct nodo* crear_nodo(int x, int y)
{
       nodo *np;
       np=(nodo*)malloc(sizeof(nodo));
       np->coeficiente=x;
       np->exponente=y;
       np->sig=NULL;
       return np;
}

struct nodo* insertar_final(int x, int y, nodo* cabeza)
{
       nodo *np;
       np=crear_nodo(x,y);
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

void MultiNumPol(int num, nodo* cabeza)
{
     for(; cabeza!=NULL; cabeza=cabeza->sig)
     {
            cout<<(cabeza->coeficiente)*num<<"x"<<cabeza->exponente<<endl;
     }
}

void MultiMonPol(nodo* mono, nodo* cabeza)
{                     
     for(; cabeza!=NULL; cabeza=cabeza->sig)
     {
            cout<<(cabeza->coeficiente)*(mono->coeficiente)<<"x"<<(cabeza->exponente)+(mono->exponente)<<endl;
     }
}


//Paso de parametros por valor y por referencia
/*void imprimri_lista(nodo* cabeza)
{
     for(; cabeza!=NULL; cabeza=cabeza->sig)
     {
            cout<<cabeza->coeficiente<<"x"<<cabeza->exponente<<endl;
     }
}*/
