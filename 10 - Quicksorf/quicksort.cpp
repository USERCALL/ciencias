// Funci�n para dividir el array y hacer los intercambios
int divide(int *array, int start, int end) {
    int left;
    int right;
    int pivot;
    int temp;
 
    pivot = array[start];
    left = start;
    right = end;
 
    // Mientras no se cruzen los �ndices
    while (left < right) {
        while (array[right] > pivot) {
            right--;
        }
 
        while ((left < right) && (array[left] <= pivot)) {
            left++;
        }
 
        // Si todav�a no se cruzan los indices seguimos intercambiando
        if (left < right) {
            temp = array[left];
            array[left] = array[right];
            array[right] = temp;
        }
    }
 
    // Los �ndices ya se han cruzado, ponemos el pivot en el lugar que le corresponde
    temp = array[right];
    array[right] = array[start];
    array[start] = temp;
 
    // La nueva posici�n del pivot
    return right;
}
 
// Funci�n recursiva para hacer el ordenamiento
void quicksort(int *array, int start, int end)
{
    int pivot;
 
    if (start < end) {
        pivot = divide(array, start, end);
 
        // Ordeno la lista de los menores
        quicksort(array, start, pivot - 1);
 
        // Ordeno la lista de los mayores
        quicksort(array, pivot + 1, end);
    }
}
