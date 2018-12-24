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
void imprimri_lista(nodo* cabeza);
void MultiNumPol(int num, nodo* cabeza);
void MultiMonPol(nodo* mono, nodo* cabeza);

int main()
{
	int opc = 0;
	int num = 0;
	int coe = 0;
	int exp = 0;
	int coeM = 0;
	int expM = 0;
	nodo* cabeza = NULL;
	nodo* mono = NULL;
	do
	{
		cout << "Estructuras de datos: Practica 2 Plinomios" << endl;
		cout << "1. Multiplicacion de un numero por un plinomio" << endl;
		cout << "2. Multiplicacion de un monomio por un polinomio" << endl;
		cout << "3. Salir" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			cout << "Introduzca un numero" << endl;
			cin >> num;
			cout << "Introduzca un polinomio" << endl;
			do
			{
				cout << "Coeficiente: ";
				cin >> coe;
				cout << "Exponente: ";
				cin >> exp;
				cabeza = insertar_final(coe, exp, cabeza);
			} while (exp != 0);
			MultiNumPol(num, cabeza);
			break;
		case 2:
			cout << "Introsuzca unmonomio" << endl;
			cout << "Coeficiente: ";
			cin >> coeM;
			cout << "Exponente: ";
			cin >> expM;
			mono = insertar_final(coeM, expM, mono);
			cout << "Introduzca un polinomio" << endl;
			do
			{
				cout << "Coeficiente: ";
				cin >> coe;
				cout << "Exponente: ";
				cin >> exp;
				cabeza = insertar_final(coe, exp, cabeza);
			} while (exp != 0);
			MultiMonPol(mono, cabeza);
			break;
		default:
			cout << "Saliendo..." << endl;
			break;
		}
	} while (opc < 3);

	system("PAUSE");
	return 0;
}

struct nodo* crear_nodo(int x, int y)
{
	nodo *np;
	np = (nodo*)malloc(sizeof(nodo));
	np->coeficiente = x;
	np->exponente = y;
	np->sig = NULL;
	return np;
}

struct nodo* insertar_final(int x, int y, nodo* cabeza)
{
	nodo *np;
	np = crear_nodo(x, y);
	if (cabeza == NULL)
	{
		return np;
	}
	else
	{
		nodo *aux;
		for (aux = cabeza; aux->sig != NULL; aux = aux->sig);
		aux->sig = np;
		return cabeza;
	}
}

void MultiNumPol(int num, nodo* cabeza)
{
	int cont = 0;
	cout << "Operacion" << endl;
	cout << num << " * ";
	imprimri_lista(cabeza);
	cout << endl;
	cout << "Resultado" << endl;
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		if (cabeza->exponente == 0)
		{
			cout << (cabeza->coeficiente)*num;
		}
		else
		{

			if (((cabeza->coeficiente)*num) < 0)
			{
				cout << (cabeza->coeficiente)*num << "x" << cabeza->exponente;
			}
			else if (((cabeza->coeficiente)*num) > 0 && cont != 0)
			{
				cout << "+" << (cabeza->coeficiente)*num << "x" << cabeza->exponente;
			}
			else if (((cabeza->coeficiente)*num) > 0 && cont == 0)
			{
				cout << (cabeza->coeficiente)*num << "x" << cabeza->exponente;
			}
			cont++;
		}
	}
	cout << endl;
	free(cabeza);
}

void MultiMonPol(nodo* mono, nodo* cabeza)
{
	int coe = 0, exp = 0;
	nodo *res = NULL;
	cout << "Operacion" << endl;
	imprimri_lista(mono);
	cout << " * ";
	imprimri_lista(cabeza);
	cout << endl;
	cout << "Resultado" << endl;
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		coe = ((cabeza->coeficiente)*(mono->coeficiente));;
		exp = (cabeza->exponente) + (mono->exponente);
		res = insertar_final(coe, exp, res);
	}
	imprimri_lista(res);
	cout << endl;
	free(cabeza);
	free(mono);
	free(res);
}


//Paso de parametros por valor y por referencia
void imprimri_lista(nodo* cabeza)
{
	int cont = 0;
	for (; cabeza != NULL; cabeza = cabeza->sig)
	{
		if (cabeza->exponente == 0)
		{
			cout << (cabeza->coeficiente);
		}
		else
		{
			if ((cabeza->coeficiente) < 0)
			{
				cout << cabeza->coeficiente << "x" << cabeza->exponente;
			}
			else if ((cabeza->coeficiente) > 0 && cont == 0)
			{
				cout << cabeza->coeficiente << "x" << cabeza->exponente;
			}
			else if ((cabeza->coeficiente) > 0 && cont != 0)
			{
				cout << "+" << cabeza->coeficiente << "x" << cabeza->exponente;
			}
		}
		cont++;
	}
}
