// C++ implementation of Radix Sort
#include <iostream>
#include "conio.h"
#include <windows.h>
#include <stdio.h>
using namespace std;
 
// A utility function to get maximum value in arr[]
int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}
 
// A function to do counting sort of arr[] according to
// the digit represented by exp.
void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};
 
    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;
 
    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
 
    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
 
    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
 
// The main function to that sorts arr[] of size n using 
// Radix Sort
void radixsort(int arr[], int n)
{
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);
 
    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
 
// A utility function to print an array
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
 
 
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

// Driver program to test above functions
int main()
{
    //int arr[] = {35, 62, 56, 3, 16};
    //int n = sizeof(arr)/sizeof(arr[0]);
    LARGE_INTEGER t_ini, t_fin;
	double secs;
    int m;
   	cout<<"ingrese el tama�o del arreglo"<< endl; 
	cin>>m;
	
		int arregloEntero[m];            
		
		for(int i=0;i<m;i++){         
			arregloEntero[i]=rand()%100;
			cout<<arregloEntero[i]<<" ";
			}          			
			 
	cout << endl;
	
   int n = sizeof(arregloEntero)/sizeof(arregloEntero[0]);
   
    QueryPerformanceCounter(&t_ini);
  	radixsort(arregloEntero, n);
	QueryPerformanceCounter(&t_fin);
	
    cout<<endl;
    cout<<endl;
    print(arregloEntero, n);
    cout<<endl;
	cout<<endl;
	cout<<"el tiempo que se tardo el algoritmo es: ";
	secs = performancecounter_diff(&t_fin, &t_ini);
    printf("%.16g milliseconds\n", secs * 1000.0);
	return 0;
}
