#include <iostream>
#include <stdio.h>
using namespace std;

void Simple();
void Doble();

/*Nodo Simple*/
struct nodoSimple
{
	int dato;
	nodoSimple *sig = NULL;
};

struct nodoSimple* crear_nodo_simple(int x);
struct nodoSimple* inserta_inicio(int x, nodoSimple* cabeza);
struct nodoSimple* insertar_final(int x, nodoSimple* cabeza);
struct nodoSimple* insertar_medio(int x, nodoSimple* cabeza);
struct nodoSimple* borrar(int x, nodoSimple* cabeza);
void buscar(int x, nodoSimple* cabeza);
void imprimri_lista(nodoSimple* cabeza);

/*Nodo Doble*/
struct nodoDoble
{
	int dato;
	int y;
	nodoDoble *ant = NULL;
	nodoDoble *sig = NULL;
};

struct nodoDoble* crear_nodo_doble(int x);
struct nodoDoble* inserta_inicioD(int x, nodoDoble* cabeza);
struct nodoDoble* insertar_finalD(int x, nodoDoble* cabeza);
struct nodoDoble* insertar_medioD(int x, nodoDoble* cabeza);
struct nodoDoble* borrarD(int x, nodoDoble* cabeza);
void buscarD(int x, nodoDoble* cabeza);
void imprimri_listaD(nodoDoble* cabeza);

int main()
{
	int opc = 0;
	do
	{
		cout << "Estructura de Datos: Practica 3 Metodos Listas" << endl;
		cout << "1. Listas Simplemente enlazadas" << endl;
		cout << "2. Listas Doblemnte enlzadas" << endl;
		cout << "3. Salir" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			Simple();
			break;
		case 2:
			Doble();
			break;
		default:
			cout << "Saliendo" << endl;
			break;
		}
	} while (opc < 3);
	return 0;
	system("PAUSE");
}

/*Nodo Simple*/
struct nodoSimple* crear_nodo_simple(int x)
{
	nodoSimple *np;
	np = (nodoSimple*)malloc(sizeof(nodoSimple));
	np->dato = x;
	np->sig = NULL;
	return np;
}

struct nodoSimple* inserta_inicio(int x, nodoSimple* cabeza)
{
	nodoSimple *np;
	np = crear_nodo_simple(x);
	if (cabeza == NULL)
	{
		return np;
	}
	else
	{
		np->sig = cabeza;
		cabeza = np;
		return cabeza;
	}
}

struct nodoSimple* insertar_final(int x, nodoSimple* cabeza)
{
	nodoSimple *np;
	np = crear_nodo_simple(x);
	if (cabeza == NULL)
	{
		return np;
	}
	else
	{
		nodoSimple *aux;
		for (aux = cabeza; aux->sig != NULL; aux = aux->sig);
		aux->sig = np;
		return cabeza;
	}
}

struct nodoSimple* borrar(int x, nodoSimple* cabeza)
{
	nodoSimple *aux, *aux2;
	if (cabeza == NULL)
	{
		cout << "Lista vacia" << endl;
		cabeza = NULL;
		return cabeza;
	}
	else if (cabeza != NULL)
	{
		if (x == cabeza->dato)
		{
			//caso 1 Borrar primer dato
			aux = cabeza;
			cabeza = cabeza->sig;
			free(aux);
			return cabeza;
		}
		else
		{
			//Buscra y borrar datos
			if (cabeza->sig != NULL)
			{
				aux2 = cabeza;
				for (aux = cabeza->sig; aux != NULL; aux = aux->sig)
				{
					if (aux->dato == x)
					{
						aux2->sig = aux->sig;
						free(aux);
						return cabeza;
					}
					else
					{
						aux2 = aux;
					}
				}
			}
			aux = cabeza;
		}
	}
}

void buscar(int x, nodoSimple* cabeza)
{
	bool flag = false;
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		if (cabeza->dato == x)
		{
			cout << "Dato encontrado" << endl;
			flag = true;
		}
	}
	if (flag == false)
	{
		cout << "Dato no encontrado" << endl;
	}
	cout << "termina" << endl;
}

void imprimri_lista(nodoSimple* cabeza)
{
	if (cabeza == NULL)
	{
		cout << "Lista vacia" << endl;
	}
	else
	{
		cout << "Lista" << endl;
		for (; cabeza != NULL; cabeza = cabeza->sig)
		{
			cout << cabeza->dato << endl;
		}
		cout << "termina" << endl;
	}
}

/*Nodo Doble*/
struct nodoDoble* crear_nodo_doble(int x)
{
	nodoDoble *np;
	np = (nodoDoble*)malloc(sizeof(nodoDoble));
	np->dato = x;
	np->sig = NULL;
	return np;
}

struct nodoDoble* inserta_inicioD(int x, nodoDoble *cabeza)
{
	nodoDoble *np;
	np = crear_nodo_doble(x);
	if (cabeza == NULL)
	{
		return np;
	}
	else
	{
		np->sig = cabeza;
		cabeza = np;
		return cabeza;
	}
}

struct nodoDoble* insertar_finalD(int x, nodoDoble* cabeza)
{
	nodoDoble *np;
	np = crear_nodo_doble(x);
	if (cabeza == NULL)
	{
		return np;
	}
	else
	{
		nodoDoble *aux;
		for (aux = cabeza; aux->sig != NULL; aux = aux->sig);
		aux->sig = np;
		return cabeza;
	}
}

struct nodoDoble* insertar_medioD(int x, nodoDoble* cabeza)
{
	nodoDoble *np;
	np = crear_nodo_doble(x);
	//caso0
	if (cabeza == NULL)
	{
		return np;
	}
	//caso 1
	if (np->dato < cabeza->dato)
	{
		np->sig = cabeza;
		cabeza->ant = np;
		cabeza = np;
		return cabeza;
	}
	//caso 2
	else
	{
		nodoDoble *aux;
		for (aux = cabeza; aux != NULL; aux = aux->sig)
		{
			if (aux->sig != NULL)
			{
				if ((aux->dato<np->dato) && (aux->sig->dato>np->dato))
				{
					np->ant = aux;
					np->sig = aux->sig;
					aux->sig->ant = np;
					aux->sig = np;
					return cabeza;
				}
			}
			else if (np->dato > aux->dato)
			{
				np->ant = aux;
				aux->sig = np;
				return cabeza;
			}
		}
	}
}

struct nodoDoble* borrarD(int x, nodoDoble* cabeza)
{
	nodoDoble *aux, *aux2;
	if (x == cabeza->dato)
	{
		//caso 1 Borrar primer dato
		aux = cabeza;
		cabeza = cabeza->sig;
		free(aux);
		return cabeza;
	}
	else
	{
		//Buscra y borrar datos
		if (cabeza->sig != NULL)
		{
			aux2 = cabeza;
			for (aux = cabeza->sig; aux != NULL; aux = aux->sig)
			{
				if (aux->dato == x)
				{
					aux2->sig = aux->sig;
					free(aux);
					return cabeza;
				}
				else
				{
					aux2 = aux;
				}
			}
		}
		aux = cabeza;
	}
}

void buscarD(int x, nodoDoble* cabeza)
{
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		if (cabeza->dato)
		{
			cout << "Dato encontrado" << endl;
		}
	}
	cout << "termina" << endl;
}

void imprimri_listaD(nodoDoble* cabeza)
{
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		cout << cabeza->dato << endl;
	}
	cout << "termina" << endl;
}

/*Menu*/
void Simple()
{
	nodoSimple *cabeza = NULL;
	int opc = 0, datos = 0, x = 0, bx = 0;
	do
	{
		cout << "Lista Simple" << endl;
		cout << "1. Insertar Inicio" << endl;
		cout << "2. Insertar Final" << endl;
		cout << "3. Borrar" << endl;
		cout << "4. Buscar dato en lista" << endl;
		cout << "5. Imprimir lista" << endl;
		cout << "6. Salir" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "Cuantos datos deseas insertar?" << endl;
			cin >> datos;
			for (int i = 0; i < datos; i++)
			{
				cin >> x;
				cabeza = inserta_inicio(x, cabeza);
			}

			break;
		case 2:
			cout << "Cuantos datos deseas insertar?" << endl;
			cin >> datos;
			for (int i = 0; i < datos; i++)
			{
				cin >> x;
				cabeza = insertar_final(x, cabeza);
			}
			break;
		case 3:
			imprimri_lista(cabeza);
			cout << "Que dato desear borra?" << endl;
			cin >> bx;
			cabeza = borrar(bx, cabeza);
			if (cabeza == NULL)
			{
				cout << "";
			}
			else
			{
				imprimri_lista(cabeza);
			}
			break;
		case 4:
			cout << "Introduzca el dato que desa buscar" << endl;
			cin >> bx;
			buscar(bx, cabeza);
			break;
		case 5:
			imprimri_lista(cabeza);
			break;
		default:
			cout << "Saliendo" << endl;
			break;
		}
	} while (opc < 6);
	free(cabeza);
	cout << endl;
}

void Doble()
{
	nodoDoble *cabeza;
	int opc = 0;
	do
	{
		cout << "Lista Doble" << endl;
		cout << "1. Insertar Inicio" << endl;
		cout << "2. Insertar Final" << endl;
		cout << "3. Borrar" << endl;
		cout << "4. Buscar dato en lista" << endl;
		cout << "5. Imprimir lista" << endl;
		cout << "Salir" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			cout << "Saliendo" << endl;
			break;
		}
	} while (opc < 5);
	cout << endl;
}
