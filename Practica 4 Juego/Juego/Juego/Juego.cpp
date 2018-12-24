#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
using namespace std;

void Jugador();
void Juego();

struct jugador
{
	int id;
	string nombre;
	jugador *ant = NULL;
	jugador *sig = NULL;
};

struct jugador* crear_nodo_jugador(int x, string nom);
struct jugador* insertar_final_jugador(int x, string nom, jugador* cabeza);
struct jugador* borrar_jugador(int x, jugador* cabeza);
void imprimri_lista_jugador(jugador* cabeza);
struct jugador* buscar_jugador(int x, jugador* cabeza);

struct numero
{
	int dato;
	numero *sig = NULL;
	numero *ant = NULL;
};
struct numero* crear_nodo_numero(int x);
struct numero* insertar_final_numero(int x, numero* cabeza);
void imprimri_lista_numero(numero* cabeza);

struct numero* turno(numero* cabeza, jugador* enturno);

jugador *jugadores = NULL;
numero *lista = NULL;
/*static*/ jugador *jconta;


int main()
{
	int opc = 0;
	do
	{
		cout << "Practica 4: Juego" << endl;
		cout << "1. Jugadores" << endl;
		cout << "2. Empezar Juego" << endl;
		cout << "3. Salir" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			Jugador();
			break;
		case 2:
			Juego();
			break;
		default:
			break;
		}
	} while (opc < 3);
	return 0;
	system("PAUSE");
}

void Jugador()
{
	if (jugadores == NULL)
	{
		cin.ignore();
		int opc, id = 1;
		string nombre;
		cout << "Jugadores" << endl;
		cout << "Cuantos jugadores quieres agregar?" << endl;
		cin >> opc;
		for (int i = 0; i < opc; i++)
		{
			cout << "Nombre: ";
			cin >> nombre;
			jugadores = insertar_final_jugador(id, nombre, jugadores);
			id++;
		}
		cout << endl;
		cout << "Jugadores" << endl;
		imprimri_lista_jugador(jugadores);
	}
	else
	{
		free(jugadores);
		free(lista);
		free(jconta);
	}
}

void Juego()
{
	cout << "Empezando juego" << endl;
	do
	{
		if (jugadores != NULL)
		{
			jconta = jugadores;
			int jua = 0;
			for (jugadores = jconta; jconta != NULL; jconta = jconta->sig)
			{
				cout << "Turno de: ";
				jua = jconta->id;
				jugador *jugador = NULL;
				jugador = buscar_jugador(jua, jugadores);
				lista = turno(lista, jugador);
				system("cls");
				if (jconta == NULL || jugadores == NULL)
				{
					cout << "Juego terminado" << endl;
					break;
				}

			}
		}
		else
		{
			cout << "Juego Terminado" << endl;
			free(jugadores);
			free(lista);
			free(jconta);
		}
	} while (jugadores != NULL);
}

struct numero* turno(numero* cabeza, jugador* jugador)
{
	int var = 0;
	if (cabeza == NULL)
	{
		int numero;
		cout << "Introduce un numero para empezar: ";
		cin >> numero;
		cabeza = insertar_final_numero(numero, cabeza);
		return cabeza;
	}
	else if (cabeza != NULL)
	{
		bool pasa = true;
		numero *aux;
		for (aux = cabeza; aux != NULL; aux = aux->sig)
		{
			cout << "Escribe un numero a comparar" << endl;
			cin >> var;
			if (var != aux->dato)
			{
				system("cls");
				cout << "Perdiste" << endl;
				jugadores = borrar_jugador(jugador->id, jugadores);
				cout << "Jugadores Restantes" << endl;
				imprimri_lista_jugador(jugadores);
				jconta = jugadores;
				pasa = false;
				Sleep(3000);
				return cabeza;
				break;
			}
		}

		if (pasa == true)
		{
			int dato_nuevo;
			cout << "Introduce un numero nuevo" << endl;
			cin >> dato_nuevo;
			cabeza = insertar_final_numero(dato_nuevo, cabeza);
		}
		return cabeza;
	}

}

struct jugador* crear_nodo_jugador(int x, string nom)
{
	jugador *np;
	np = (jugador*)malloc(sizeof(jugador));
	np = new jugador();
	np->id = x;
	np->nombre = nom;
	np->sig = NULL;
	return np;
}

struct jugador* insertar_final_jugador(int x, string nom, jugador* cabeza)
{
	jugador *np;
	np = crear_nodo_jugador(x, nom);
	if (cabeza == NULL)
	{
		return np;
	}
	else
	{
		jugador *aux;
		for (aux = cabeza; aux->sig != NULL; aux = aux->sig);
		aux->sig = np;
		return cabeza;
	}
}

struct jugador* borrar_jugador(int x, jugador* cabeza)
{
	jugador *aux, *aux2;
	if (cabeza == NULL)
	{
		cout << "Lista vacia" << endl;
		cabeza = NULL;
		return cabeza;
	}
	else if (cabeza != NULL)
	{
		if (x == cabeza->id)
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
					if (aux->id == x)
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

void imprimri_lista_jugador(jugador* cabeza)
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
			cout << cabeza->id << " " << cabeza->nombre << endl;
		}
	}
}

struct jugador* buscar_jugador(int x, jugador* cabeza)
{
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		if (cabeza->id == x)
		{
			cout << cabeza->nombre << endl;
			return cabeza;
		}
	}
}

struct numero* crear_nodo_numero(int x)
{
	numero *np;
	np = (numero*)malloc(sizeof(numero));
	np->dato = x;
	np->sig = NULL;
	return np;
}

struct numero* insertar_final_numero(int x, numero* cabeza)
{
	numero *np;
	np = crear_nodo_numero(x);
	if (cabeza == NULL)
	{
		return np;
	}
	else
	{
		numero *aux;
		for (aux = cabeza; aux->sig != NULL; aux = aux->sig);
		aux->sig = np;
		return cabeza;
	}
}

void imprimri_lista_numero(numero* cabeza)
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