#include "queue_belv.h"
#include <stdio.h>
#include <stdlib.h>

/* *** Kreator *** */
void CreateQueueBELV(SQueue *q){
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEFBELV */
/* - Index tail bernilai IDX_UNDEFBELV */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
    IDX_HEADBELV(*q) = IDX_UNDEFBELV;
    IDX_TAILBELV(*q) = IDX_UNDEFBELV;
}

/* ********* Prototype ********* */
boolean isQueueEmptyBELV(SQueue q){
/* Mengirim true jika q kosong: lihat definisi di atas */
    return ((IDX_HEADBELV(q) == IDX_UNDEFBELV) && (IDX_TAILBELV(q) == IDX_UNDEFBELV));
}

boolean isQueueFullBELV(SQueue q){
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu ketika IDX_HEADBELV=0 dan IDX_TAILBELV=CAPACITYBELV-1 */
    return (lengthQueueBELV(q) == CAPACITYBELV-1);
}

int lengthQueueBELV(SQueue q){
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
    /* KAMUS LOKAL */
    int length;

    /* ALGORITMA */
    if (isQueueEmptyBELV(q)) {
        length = 0;
    } else if (IDX_TAILBELV(q) >= IDX_HEADBELV(q)){ /*Ketika tail berada di belakang head*/
        length = (IDX_TAILBELV(q) - IDX_HEADBELV(q)) + 1;
    } else { /*Ketika tail berada di depan head*/
        length = (IDX_TAILBELV(q) - IDX_HEADBELV(q)) + (CAPACITYBELV + 1);
    }

    return length;
}

/* *** Primitif Add/Delete *** */
void enqueueBELV(SQueue *q, CurrentSong val){
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAILBELV yang baru, IDX_TAILBELV "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAILBELV baru  */
    if (isQueueEmptyBELV(*q)){
        IDX_HEADBELV(*q) = 0;
        IDX_TAILBELV(*q) = 0;
    } else {
        int i;
        if (IDX_HEADBELV(*q) != 0) { /* Ketika tail sudah berada di posisi paling terakhir, tetapi array belum full, maka tail akan maju ke index awal yakni 0*/
            for (i=IDX_HEADBELV(*q); i <= IDX_TAILBELV(*q); i++) {
                (*q).QueueDetail[i - IDX_HEADBELV(*q)] = (*q).QueueDetail[i];
            }
            IDX_TAILBELV(*q) += 1;
        } else if (IDX_TAILBELV(*q) == CAPACITYBELV-1) {
            IDX_TAILBELV(*q) += 1;
        } else {
            IDX_TAILBELV(*q) += 1;
        }
    } 
    TAILBELV(*q) = val;
}