#include <stdio.h>
#include "stack_belv.h"

void CreateEmptyRiwayat(RiwayatLagu *RL)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxElStack */
/* jadi indeksnya antara 0.. MaxElStack */
/* Ciri stack kosong : TOP bernilai Undef */
{
      Top(*RL) = Undef;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyRiwayat(RiwayatLagu RL)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
      return Top(RL) == Undef;
}
boolean IsFullRiwayat(RiwayatLagu RL)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
      return Top(RL) == MaxElStack - 1;
}

/****************** Proses semua elemen Stack ******************/

/* ************ Menambahkan sebuah elemen ke RiwayatLagu ************ */
void Push (RiwayatLagu *RL, RincianLaguStack CS)
/* Menambahkan X sebagai elemen RiwayatLagu S. */
/* I.S. S mungkin kosong, tabel penampung elemen RiwayatLagu TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*RL) += 1;
    InfoTop(*RL) = CS;
}

/* ************ Menghapus sebuah elemen RiwayatLagu ************ */
void Pop (RiwayatLagu *RL, RincianLaguStack *CS)
/* Menghapus X dari RiwayatLagu S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
    *CS = InfoTop(*RL);
    Top(*RL) -= 1;
}


void InversStack(RiwayatLagu *RL){
    RiwayatLagu temp1, temp2;
    RincianLaguStack detil_temp;
    CreateEmptyRiwayat(&temp1);
    CreateEmptyRiwayat(&temp2);
    while(!IsEmptyRiwayat(*RL)){
        Pop(RL,&detil_temp);
        Push(&temp1, detil_temp);
    }
    while(!IsEmptyRiwayat(temp1)){
        Pop(&temp1,&detil_temp);
        Push(&temp2, detil_temp);
    }
    while (!IsEmptyRiwayat(temp2))
    {
        Pop(&temp2,&detil_temp);
        Push(RL, detil_temp);
    }
}