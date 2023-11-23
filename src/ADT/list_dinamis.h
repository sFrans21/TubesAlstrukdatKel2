/* file dynamic_list.h */

#include "boolean.h"
#include "mesinkata.h"

#ifndef __DYNAMIC_LIST_H__
#define __DYNAMIC_LIST_H__

#define IdxType int
#define MaxEl 100

typedef struct
{
    Word *A;
    int Neff;
} DynamicList;

/* ********** KONSTRUKTOR ********** */
/* Konstruktor: create list kosong  */
void CreateEmptyDynamic(DynamicList *list);
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong dengan kapasitas MaxEl */

/* ********** DESTRUKTOR ********** */
void DealokasiDynamic(DynamicList *list);
/* I.S. L terdefinisi; */
/* F.S. (L) dikembalikan ke system, melakukan dealokasi/pengembalian */
/* memori ke system */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean IsListEmptyDynamic(DynamicList list);
/* Mengirimkan true jika list L kosong, mengirimkan false jika tidak */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int LengthListDynamic(DynamicList list);
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list kosong */

/* *** Menghasilkan sebuah elemen *** */
Word GetDynamic(DynamicList list, IdxType i);
/* Prekondisi : list tidak kosong, i antara FirstIdxList(L)..LastIdxList(L) */
/* Mengirimkan elemen list yang ke-i */


void InsertLD(DynamicList *list, ElType x, Key i);
/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

void DeleteLD(DynamicList *list, Key i);
/**
 * Fungsi untuk menghapus elemen di index ke-i ArrayDin
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */

void DisplayLD(DynamicList list);
/**
 * print judul semua element dalam list dinamik
 * jika kosong print "Kosong"
 * 
 *     1. {Judul 1}
 *     2. {Judul 2}
 *     3. {Judul 3}
 *     4. {Judul 4}
 * 
 * berakhir akhir dengan '\n'
*/

void DisplayIsiLD(DynamicList list, ElType x);
/**
 * print isi element suatu struktur berkait dengan judul x dalam list dinamik
 * jika kosong print "Kosong"
 * 
 *     1. {Element 1 Judul x}
 *     2. {Element 2 Judul x}
 *     3. {Element 3 Judul x}
 *     4. {Element 4 Judul x}
 * 
 * berakhir akhir dengan '\n'
 * Prekondisi: x adalah member dari l
*/

void DisplaySemuaLD(DynamicList list);
/**
 * print dan judul playlist dan isinya dalam list dinamik
 * jika kosong print "Kosong"
 * 
 * Judul 1: {Judul A}
 *     1. {Element 1 Judul A}
 *     2. {Element 2 Judul A}
 *     3. {Element 3 Judul A}
 *     4. {Element 4 Judul A}
 * Judul 2: {Judul B}
 * Kosong
 * 
 * berakhir akhir dengan '\n'
*/


void DeleteAtListDin(DynamicList *array, IdxType i);
#endif