#include <stdio.h>
#include "map.h"

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmptyMap(Map *M){
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */
    (*M).Count = Nil;
}

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M){
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */
    return M.Count == Nil;
}

boolean IsFullMap(Map M){
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */
    return M.Count == MaxEl;
}

/* ********** Operator Dasar Map ********* */
valuetype ValueMap(Map M, keytype k){
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undefined */
    int i = 0;
    valuetype value;
    boolean cek = false;
    while ((i < M.Count) && !cek){
        if (M.Elements[i].Key == k){
            value = M.Elements[i].Value;
            cek = true;
        } else {
            value = Undefined;
        }
        i++;
    }
    return value;
}

void InsertMap(Map *M, keytype k, valuetype v){
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, operasi tidak dilakukan */
    if (!IsFull(*M)){
        if (!IsMember(*M, k)){
            (*M).Count++;
            (*M).Elements[(*M).Count-1].Key = k;
            (*M).Elements[(*M).Count-1].Value = v;
        }
    }
}

void DeleteMap(Map *M, keytype k){
/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k bukan anggota dari M */
    if(IsMember(*M, k)){
        boolean found = false;
        int i = 0;
        while ((i < (*M).Count) && !found){
            if((*M).Elements[i].Key == k){
                found = true;
            } 
            else {
                i++;
            }
        }
        while (i < (*M).Count){
            (*M).Elements[i].Key = (*M).Elements[i+1].Key;
            (*M).Elements[i].Value = (*M).Elements[i+1].Value;
            i++;
        }
        (*M).Count--;
    }
}

boolean IsMemberMap(Map M, keytype k){
/* Mengembalikan true jika k adalah member dari M */
    boolean found = false;
    int i = 0;
    while ((i < M.Count) && !found){
        if (M.Elements[i].Key == k) {
            found = true;
        } else {
            i++;
        }
    }
    return found;
}