#include <iostream>
#include <stdio.h>
#include <string>
#include <Windows.h>
#include <stdlib.h> 
using namespace std;

struct canciones
{
	int id;
	string nombre;
	string ruta;
	canciones *ant = NULL;
	canciones *sig = NULL;
};

canciones *disponibles = NULL;
canciones *lista = NULL;

struct canciones* crear_lista(string nombre, string ruta, int id);
struct canciones* insertar_final(string nombre, string ruta, canciones* cabeza, int id);
struct canciones* borra_cancion(int x, canciones* cabeza);
void imprimri_lista(canciones* cabeza);
int regresaUltimoId(canciones *cabeza);
void insertar_final_lista(int id, canciones *cabeza);
void ver_lista(canciones* cabeza);
void Reproducir(int pista, canciones* cabeza);

int main()
{
	int opc = 0, numec = 0, id = 0;
	string nombre = "", ruta = "";
	char opcm = 'n';
	do
	{
		cout << "Estructura de Datos Practica 5: Reproductor" << endl;
		cout << "1. Ver Canciones Disponibles" << endl;
		cout << "2. Agregra Canciones" << endl;
		cout << "3. Crear Lista" << endl;
		cout << "4. Ver Lista" << endl;
		cout << "5. Escuchar Lista" << endl;
		cout << "6. Modificar Lista" << endl;
		cout << "7. Salir" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			imprimri_lista(disponibles);
			break;
		case 2:
			if (disponibles == NULL)
			{
				cout << "Lista vacia" << endl;
				cout << "Cuantas canciones deseas agregar?" << endl;
				cin >> numec;
				for (int i = 0; i < numec; i++)
				{
					id++;
					cout << "Nombre: ";
					cin >> nombre;
					cout << "Ruta: ";
					cin >> ruta;
					disponibles = insertar_final(nombre, ruta, disponibles, id);
				}
			}
			else if (disponibles != NULL)
			{
				cout << "Canciones Disponibles" << endl;
				imprimri_lista(disponibles);
				cout << "Cuantas canciones deseas agregar?" << endl;
				cin >> numec;
				id = regresaUltimoId(disponibles);
				for (int i = 0; i < numec; i++)
				{
					id++;
					cout << "Nombre: ";
					cin >> nombre;
					cout << "Ruta: ";
					cin >> ruta;
					disponibles = insertar_final(nombre, ruta, disponibles, id);
				}
			}
			cout << "Terminado" << endl;
			break;
		case 3:
			cout << "Canciones Disponibles" << endl;
			imprimri_lista(disponibles);
			cout << "Cuantas canciones deseas agregar?" << endl;
			cin >> numec;
			for (int i = 0; i < numec; i++)
			{
				cout << "Introduce el id de la cancion que deseas agregar a la lista: ";
				cin >> id;
				insertar_final_lista(id, disponibles);
			}
			break;
		case 4:
			ver_lista(lista);
			break;
		case 5:
			ver_lista(lista);
			do
			{
				cout << "Introduzca el id de la cancion: ";
				cin >> id;
				Reproducir(id, lista);
				cout << "Desea reproducir otra cancion?(s/n) ";
				cin >> opcm;
			} while (opcm != 'n');
			break;
		case 6:
			ver_lista(lista);
			do
			{
				cout << "Introduzca el id de la cancion que desea eliminar: ";
				cin >> id;
				lista = borra_cancion(id, lista);
				ver_lista(lista);
				cout << "Desea eliminar otra cancion?(s/n) ";
				cin >> opcm;
			} while (opcm != 'n');
			break;
		default:
			cout << "Saliendo" << endl;
			break;
		}
	} while (opc < 7);
	return 0;
	system("PAUSE");
}

struct canciones* crear_lista(string nombre, string ruta, int id)
{
	canciones *np;
	np = (canciones*)malloc(sizeof(canciones));
	np = new canciones();
	np->id = id;
	np->nombre = nombre;
	np->ruta = ruta;
	np->ant = NULL;
	np->sig = NULL;
	return np;
}

struct canciones* insertar_final(string nombre, string ruta, canciones* cabeza, int id)
{
	canciones *np;
	np = crear_lista(nombre, ruta, id);
	if (cabeza == NULL)
	{
		return np;
	}
	else
	{
		canciones *aux;
		for (aux = cabeza; aux->sig != NULL; aux = aux->sig);
		aux->sig = np;
		return cabeza;
	}
}

struct canciones* borra_cancion(int x, canciones* cabeza)
{
	canciones *aux, *aux2;
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

void imprimri_lista(canciones* cabeza)
{
	if (cabeza == NULL)
	{
		cout << "Lista vacia, agrega elementos" << endl;
	}
	else
	{
		cout << "Lista" << endl;
		for (; cabeza != NULL; cabeza = cabeza->sig)
		{
			cout << cabeza->id << " " << cabeza->nombre << endl;
		}
		cout << "termina" << endl;
	}
}

void ver_lista(canciones* cabeza)
{
	if (cabeza == NULL)
	{
		cout << "Lista vacia, agrega elementos" << endl;
	}
	else
	{
		cout << "Lista" << endl;
		for (; cabeza != NULL; cabeza = cabeza->sig)
		{
			cout << cabeza->id << " " << cabeza->nombre << endl;
		}
		cout << "termina" << endl;
	}
}

int regresaUltimoId(canciones *cabeza)
{
	int uID = 0;
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		uID = cabeza->id;
	}
	return uID++;
}

void insertar_final_lista(int id, canciones *cabeza)
{
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		if (cabeza->id == id)
		{
			lista = insertar_final(cabeza->nombre, cabeza->ruta, lista, cabeza->id);
		}
	}
	cout << "Cancion Agregada" << endl;
}

void Reproducir(int pista, canciones* cabeza)
{
	string nombre = "", ruta = "";
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		if (pista == cabeza->id)
		{
			nombre = cabeza->nombre;
			ruta = cabeza->ruta;
			break;
		}
	}
	if (nombre == "")
	{
		cout << "Cancion no encontrada" << endl;
	}
	else
	{
		char tab2[1024];
		strcpy(tab2, ruta.c_str());
		LPCTSTR file;
		file = LPCTSTR(tab2);
		cout << "Reproduciendo: " << nombre << endl;
		PlaySound(file, NULL, SND_FILENAME | SND_ASYNC);
		cout << "Fin de la cancion" << endl;
	}
}
