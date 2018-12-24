#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

struct Futbol
{
	string nombre;
	int victorias;
	int derrotas;
	int empates;
	int golesFavor;
	int golesContra;
	string goleadorEquipo;
	int golesGoleador;
	int puntaje;
};

struct Baloncesto
{
	string nombre;
	int victorias;
	int derrotas;
	int numeroPerdidasBalon;
	int rebotesRecogidos;
	string mejorAnotadorTriple;
	int anotacionesTriples;
};

Futbol oFutbol[3];
Baloncesto oBaloncesto[3];

void IntroducirNombre();
void VerMejoresTriplistas();
void VerMejorGoleador();
void VerEquipoGanadorFutbol();
void VerEquipoGAnadorBaloncesto();

int main()
{
	oFutbol[0] = { "", 12, 2, 20, 10, 3, "Lalo", 6, 0 };
	oFutbol[1] = { "", 8, 10, 10, 4, 13, "Arturo", 2, 0 };
	oFutbol[2] = { "", 30, 5, 5, 6, 23, "Jose", 5, 0 };

	oBaloncesto[0] = { "", 100, 5, 34, 13, "Noe", 6 };
	oBaloncesto[1] = { "", 16, 1, 24, 3, "Pedro", 3 };
	oBaloncesto[2] = { "", 60, 12, 24, 23, "Juan", 10 };

	int opc = 0;
	cout << "Practica 1" << endl;
	do
	{
		cout << "1. Introducir Nombre equipos" << endl;
		cout << "2. Listado mejores triplistas" << endl;
		cout << "3. Ver mejor goleador de futbol" << endl;
		cout << "4. Equipo ganador de la liga de futbol" << endl;
		cout << "5. Equipo ganador del la liga de baloncesto" << endl;
		cout << "6. Salir" << endl;
		cin >> opc;
		switch (opc)
		{
		case 1:
			IntroducirNombre();
			cout << "Baloncesto" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << "Instroduzca el nombre del equipo " << i + 1 << endl;
				cin >> oBaloncesto[i].nombre;
			}
			break;
		case 2:
			VerMejoresTriplistas();
			break;
		case 3:
			VerMejorGoleador();
			break;
		case 4:
			VerEquipoGanadorFutbol();
			break;
		case 5:
			VerEquipoGAnadorBaloncesto();
			break;
		case 6:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "No existe la opcion. Saliendo..." << endl;
			break;
		}
	} while (opc < 6);
}

void IntroducirNombre()
{
	int i = 0;
	cin.ignore();
	cout << "Futbol" << endl;
	for (i; i < 3; i++)
	{
		cout << "Instroduzca el nombre del equipo " << i + 1 << endl;
		cin >> oFutbol[i].nombre;
	}
}

void VerMejoresTriplistas()
{
	for (int i = 0; i < 3; i++)
	{
		cout << "Mejor triplista del equipo " << oBaloncesto[i].nombre << " es " << oBaloncesto[i].mejorAnotadorTriple << endl;
	}
}

void VerMejorGoleador()
{
	int mejor = oFutbol[0].golesGoleador;
	string nmejor = oFutbol[0].nombre;
	string gmejor = oFutbol[0].goleadorEquipo;
	if (mejor < oFutbol[1].golesGoleador)
	{
		mejor = oFutbol[1].golesGoleador;
		nmejor = oFutbol[1].nombre;
		gmejor = oFutbol[1].goleadorEquipo;
	}
	else if (mejor < oFutbol[2].golesGoleador)
	{
		mejor = oFutbol[2].golesGoleador;
		nmejor = oFutbol[2].nombre;
		gmejor = oFutbol[2].goleadorEquipo;
	}
	cout << "El mejor Goleador es " << gmejor << " con " << mejor << " goles" << " del equipo " << nmejor << endl;
}

void VerEquipoGanadorFutbol()
{
	for (int i = 0; i < 3; i++)
	{
		oFutbol[i].puntaje = ((oFutbol[i].victorias * 3) + oFutbol[i].empates);
	}

	int ganador = oFutbol[0].puntaje;
	string nombre = oFutbol[0].nombre;
	for (int i = 0; i < 3; i++)
	{
		if (ganador < oFutbol[i].puntaje)
		{
			ganador = oFutbol[i].puntaje;
			nombre = oFutbol[i].nombre;
		}
		else if (ganador < oFutbol[i + 1].puntaje)
		{
			ganador = oFutbol[i + 1].puntaje;
			nombre = oFutbol[i + 1].nombre;
		}
	}
	cout << "El equipo gandor es " << nombre << " con " << ganador << " puntos." << endl;
}

void VerEquipoGAnadorBaloncesto()
{
	int ganador = oBaloncesto[0].victorias;
	string nombre = oBaloncesto[0].nombre;
	for (int i = 0; i < 3; i++)
	{
		if (ganador < oBaloncesto[i].victorias)
		{
			ganador = oBaloncesto[i].victorias;
			nombre = oBaloncesto[i].nombre;
		}
	}
	cout << "El equipo ganador es " << nombre << " con " << ganador << " victorias" << endl;
}