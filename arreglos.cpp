#include <iostream>
#include <fstream>
#include <string>
#include <array>
//#include "quicksort.cpp"
#include "burbujeo.cpp"

using namespace std;

void print(int *array, int tope)
	{
		for (int i=0; i<tope ; i++)
			cout<<i<<":"<<array[i]<<endl;
	}

int main ()
{	int const tope = 13;
	int array[tope];
	array [0]= 8;
	array [1]= 1;
	array [2]= 5;
	array [3]= 14;
	array [4]= 4;
	array [5]= 15;
	array [6]= 12;
	array [7]= 6;
	array [8]= 2;
	array [9]= 11;
	array [10]=10;
	array [11]=7;
	array [12]=9;
	
	void print(int *array, int tope);
	cout<< "Sin ordenar:\n";
	print (array, tope);
	//quicksort (array, 0, tope - 1);
	burbujeo(array, tope);
	cout<< "\nOrdenado:\n";
	print (array, tope);	
}
