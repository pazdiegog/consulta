using namespace std;

int aux;
void burbujeo (int array[], int MAX)
{
for (int i=0; i<MAX-1; i++)
	for (int j=0; j<MAX-1; j++)
		if (array[j] > array [j+1])
		{
			aux=array[j];
			array[j]=array[j+1];
			array[j+1]=aux;
		}
}
