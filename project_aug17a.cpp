#include <iostream>
#include <fstream>
#include <string>
#include <array>


using namespace std;

ifstream in;

typedef struct  {
	char agrupacion;
	char candidato;
	int lista;
	int votos;
}Listado;
const unsigned int MAX = 10 * 3;
array<Listado , 30> senadores, diputados;
unsigned n;
Listado r;
string GetNombreDeArchivoDeMesa(string UnaMesa)
{
	return "Mesa" + UnaMesa + ".txt";
}

string UnaMesa;

int main()
{
	cout << "Seleccione el numero de mesa: ";
	cin >> UnaMesa;
	in.open(GetNombreDeArchivoDeMesa(UnaMesa));
	void MostrarListados();
	void SumarLosVotos();
	void CalcularEInformarLasEstadisticas();
	MostrarListados();
	cin >> UnaMesa; //congelar la pantalla y evitar que termine
}


void ImprimirArreglo(array<Listado, 30>& a)
{
	for (int i = 0; i < 30; ++i)
		cout << a.at(i).agrupacion<<"\t"
		<< a.at(i).lista<<"\t"
		<< a.at(i).candidato<<"\t"
		<< a.at(i).votos<<"\t\n";
}


void OrdenarPorVoto()
{

}


void OrdenarPorAgrupacion()
{

}


void OrdenarPorLista()
{

}


void OrdenarPorCandidato()
{

}


void OrdenarPorAgrupacionYVotos()
{

}


void OrdenarPorCandidatosYVotos()
{

}


void OrdenarPorAgrupacionCandidatosYVotos()
{

}


void MostrarListado1() 
{
	OrdenarPorVoto();
	cout<< "Senadores"<<endl;
	ImprimirArreglo(senadores);
	cout<< "Diputados"<<endl;
	ImprimirArreglo(diputados);
}

void MostrarListados() 
{
	MostrarListado1();
}


void PonerEnCeroLosVotos(array<Listado,30>& a)
{
	for (int i = 0; i<30; ++i)
		a.at(i).votos = 0;
}



void PonerEnCeroLosVotosDeSenadoresYDiputados()
{
	PonerEnCeroLosVotos(senadores);
	PonerEnCeroLosVotos(diputados);
}

void SumarLosVotosDeUnArchivo(string nombreDeArchivo)
{
	in.open(GetNombreDeArchivoDeMesa(UnaMesa));
	void AvanzarHastaSenadores();
	void SumarVotosDeSenadores();
	void AvanzarHastaDiputados();
	void SumarVotosDeDiputados();
	in.close();
}

void SaltearLineas(unsigned n)
{	string line;
	getline (in, line);
}

void SaltearVotosEnBlancoEImpugnados()
{
	SaltearLineas(2);
}

void SumarVotosDeUnCargo(array <Listado, 30>& a)
{	
	Listado LeerRegistro();
	for (int i = 0; i < 30; ++i)
	{
		r=LeerRegistro();
		a.at(i).agrupacion = r.agrupacion;
		a.at(i).lista = r.lista;
		a.at(i).candidato = r.candidato;
		a.at(i).votos += r.votos;
	}
	SaltearVotosEnBlancoEImpugnados();
}
Listado LeerRegistro()
{string line;
	in
		>> r.agrupacion
		>> r.lista
		>> r.candidato
		>> r.votos;
		getline(in,line);
	return r;
}

void SumarVotosDeSenadores()
{
	SumarVotosDeUnCargo(senadores);
}

void SumarVotosDeDiputados()
{
	SumarVotosDeUnCargo(diputados);
}

void AvanzarHastaSenadores()
{
	SaltearLineas(3);
}

void AvanzarHastaDiputados()
{
	SaltearLineas(3);
}

void SumarLosVotosDeLosArchivos()
{
	SumarLosVotosDeUnArchivo(GetNombreDeArchivoDeMesa(UnaMesa));
}

void SumarLosVotos()
{
	PonerEnCeroLosVotosDeSenadoresYDiputados();
	SumarLosVotosDeLosArchivos();
}