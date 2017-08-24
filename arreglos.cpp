#include <iostream>
#include <fstream>
#include <string>
#include <array>
//#include "burbujeo.cpp"
using namespace std;

struct Listado{
	string agrupacion;
	string candidato;
	int lista;
	int votos;
};

const int MAX = 5;
array<Listado, MAX> partidos;



void print (array<Listado, MAX> partidos)
{
	for (int i=0; i<MAX ; i++)
		cout<<i<<":"<<partidos[i].agrupacion<<", votos: "<< partidos[i].votos<<", lista: "<< partidos[i].lista<<", candidato: "<< partidos[i].candidato<<"\n";
}
void OrdenarPorAgrupacion (array <Listado, MAX> partidos) //burbuja
{
for (int i=0; i<MAX-1; i++)
	for (int j=0; j<MAX-1; j++)
		if (partidos[j].agrupacion > partidos [j+1].agrupacion)
		{
			Listado aux;
			aux=partidos[j];
			partidos[j]=partidos[j+1];
			partidos[j+1]=aux;
		}
	print (partidos);
}

void OrdenarPorVoto (array <Listado, MAX> partidos) //burbuja
{
for (int i=0; i<MAX-1; i++)
	for (int j=0; j<MAX-1; j++)
		if (partidos[j].votos > partidos [j+1].votos)
		{
			Listado aux;
			aux=partidos[j];
			partidos[j]=partidos[j+1];
			partidos[j+1]=aux;
		}
	print (partidos);
}

void OrdenarPorLista (array <Listado, MAX> partidos) //shell
{
	for (int i=MAX/2; i !=0; i/=2)
		for (int j=1; j!=0;)
		{
			j=0;
			for (int k=i; k<MAX;k++)
				if (partidos[k-i].lista>partidos[k].lista)
				{
					Listado temp=partidos[k];
					partidos[k]=partidos[k-i];
					partidos[k-i]=temp;
					j++;
				}
		}
	print (partidos);
}
void OrdenarPorCandidato (array <Listado, MAX> partidos) //insercion
{
	int j;
	string temp;
	for (int i=0; i<MAX; i++)
	{	
		temp= partidos[i].candidato;
		j= i-1;
		while ((j>=0) && (partidos[j].candidato> temp))
		{
			partidos[j+1]=partidos[j];
			j--;
		}
		partidos[j+1].candidato = temp;
	}
	print (partidos);
}
int main ()
{
	partidos[0].agrupacion="FPV";
	partidos[1].agrupacion= "CAMBIEMOS";
	partidos[2].agrupacion= "UNA";
	partidos[3].agrupacion= "PROGRE";
	partidos[4].agrupacion= "FIT";
	partidos[0].candidato= "Daniel";
	partidos[1].candidato= "Mauricio";
	partidos[2].candidato= "Sergio";
	partidos[3].candidato= "Margarita";
	partidos[4].candidato= "Altamira";
	partidos[0].lista=100;
	partidos[1].lista=55;
	partidos[2].lista=96;
	partidos[3].lista=254;
	partidos[4].lista=9;
	partidos[0].votos=100;
	partidos[1].votos=101;
	partidos[2].votos=59;
	partidos[3].votos=41;
	partidos[4].votos=7;
	
	cout << "\nDesordenado: \n";
	print (partidos);

	cout << "\nOrdenado por voto: \n";
	OrdenarPorVoto (partidos);

	cout << "\nOrdenado por agrupacion: \n";
	OrdenarPorAgrupacion(partidos);
	
	cout << "\nOrdenado por lista: \n";
	OrdenarPorLista(partidos);
	
	cout << "\nOrdenado por candidato: \n";
	OrdenarPorCandidato(partidos);

}
