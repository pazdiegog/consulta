using namespace std;

int trade(int *array, int start, int end)
	{
		int left, right, pivot, temp;

	pivot = array[start];
	right = end;
	left = start;
	
	//mientras no se cruzen los indices, separamos mayores de menores respecto del pivot
		while (left < right)
		{	while (array[right]>pivot) //si los de la derecha son mayor que el pivot, decremento.
				right--;
			while (array[left]<=pivot) //si los de la izquieda son menor que el pivot, aumento.
				left++;
		//una vez que encuentro un menor y un mayor que el pivot...
		if (left < right) //verifico que no se hayan cruzado los indices y hago el cambio.
			{
			temp=array[left];
			array[left]=array[right];
			array[right]=temp;
			}
		}
		//cuando se cruzan los indices intercambios el pivot con el slot de los indices cruzados.
		temp= array[right];
		array[right]=array[start];
		array[start]=temp;
		
		//retorno la posicion del pivot
		return right;

	}
//funcion recursiva
void quicksort (int *array, int start, int end)
{
	int pivot;
	int tope = 13;
	if (start < end)
	{
		pivot = trade(array, start, end);
		quicksort(array, start, pivot-1); //sublista izquierda
		quicksort(array, pivot+1, end); //sublista derecha
	}
}
