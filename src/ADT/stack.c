#include <stdio.h>
#include "stack.h"

void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 0.. MaxElStack */
/* Ciri stack kosong : TOP bernilai Undef */
{
      Top(*S) = Undef;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
      return Top(S) == Undef;
}
boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
      return Top(S) == MaxElStack - 1;
}

/****************** Proses semua elemen Stack ******************/
int NbElmtStack(Stack S)
/* Mengirimkan banyaknya elemen Stack; mengirimkan 0 jika Stack kosong */
{
      int count = 0;
      INFOTYPE dump;
      while (!IsEmptyStack(S))
      {
            Pop(&S, &dump);
            count++;
      }
      return count;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack *S, INFOTYPE X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
      Top(*S)++;
      InfoTop(*S) = X;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack *S, INFOTYPE *X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
      (*X) = InfoTop(*S);
      Top(*S)--;
}

Stack ReverseStack(Stack in){
    Stack out;
    CreateEmptyStack(&out);
    INFOTYPE element;
    while(!IsEmptyStack(in)){
        Pop(&in, &element);
        Push(&out, element);
    }
    return out;
}