#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "arrayDin.h"


ArrayDin CreateDynArray() {
    ArrayDin array;
    // Alokasi elemen array secara dinamik menggunakan malloc
    array.A = (ElType*) malloc (100 * sizeof(ElType));
    array.Capacity = 100; // Kapasitas array diset sebesar StartSize
    array.Neff = 0; // Karena masih kosong, elemen efektif array bernilai 0
    return array;
}

void DeallocateList(ArrayDin *array) {
    free(array->A);
    array->Neff = 0;
}

int Length(ArrayDin array) {
    return array.Neff;
}

void InsertIn(char*string , ArrayDin*ListGames ,  int idx){
    int j = idx - 1;
    (*ListGames).A[j] = string;
}

void InsertAt(ArrayDin *array, ElType el, IdxType i) 
 { 
    if((*array).Neff == (*array).Capacity) 
    { 
        (*array).Capacity *= 2; //Kalau penuh perbesar kapasitasnya
        (*array).A = (ElType *) realloc ((*array).A, (*array).Capacity * sizeof(ElType)); //Perbarui besar kapasitasnya
    } 
    IdxType temp = array->Neff; 
    while (temp > i) 
    { 
    (*array).A[temp]=(*array).A[temp-1]; //GESER geser 
    temp--; 
    } 
    (*array).A[i]=el; 
    (*array).Neff++; 
 } 

 void DeleteAt(ArrayDin *array, IdxType i)
{
	int j;
	for (j = i ; j < array->Neff ; j++)
	{
		array->A[j] = array->A[j+1]; 
	}
	
	array->Neff -= 1;
}
  
 void InsertLast(ArrayDin *array, ElType el) 
 { 

    InsertAt(array, el, array->Neff);
 } 
  
 void InsertFirst(ArrayDin *array, ElType el) 
 { 
    InsertAt(array, el, 0); 
 }

boolean IsEmpty (ArrayDin array)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (array.Neff == 0);
}