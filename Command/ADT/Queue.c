#include "boolean.h"
#include "Queue.h"
#include <stdio.h>

/* *** Kreator *** */
void CreateQueue(Queue *q)
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernislai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q)
{
    if (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF)
    {
        return true;
    }
}
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFull(Queue q)
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
{
    return ((IDX_HEAD(q) == CAPACITY) && (IDX_TAIL(q) == CAPACITY));
}
int length(Queue q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */
{
    if (IsEmpty(q))
    {
        return 0;
    }
    else
    {
        return ((IDX_TAIL(q) - IDX_HEAD(q)) + 1);
    }
}
/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val)
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */
{
    /*inisialisasi syarat bahwa q bisa kosong,*/
    if (isEmpty(*q))
    {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
    }
    else
    {
        if (IDX_TAIL(*q) == CAPACITY - 1)
        {
            for (int i = IDX_HEAD(*q); i <= IDX_TAIL(*q); i++)
            {
                (*q).buffer[i - IDX_HEAD(*q)] = (*q).buffer[i];
            }

            IDX_TAIL(*q) -= IDX_HEAD(*q);
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q)
        ++;
    }
    TAIL(*q) = val;
}
void dequeue(Queue *q, ElType *val)
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

{
    *val = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q))
    {
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else
    {
        IDX_HEAD(*q)
        ++;
    }
}
/* *** Display Queue *** */
void displayQueue(Queue q)
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

{
    if (isEmpty(q))
    {
        printf("[]\n");
    }
    else
    {
        int i;
        printf("[");

        if (IDX_TAIL(q) - IDX_HEAD(q) < 0) // indeks tail berada di sebelah kiri indeks head
        {
            for (i = IDX_HEAD(q); i <= CAPACITY - 1; i++)
            {
                printf("%d,", q.buffer[i]);
            }

            for (i = 0; i < IDX_TAIL(q); i++)
            {
                printf("%d,", q.buffer[i]);
            }
        }
        else // indeks tail berada di sebelah kanan indeks head
        {
            for (i = IDX_HEAD(q); i < IDX_TAIL(q); i++)
            {
                printf("%d,", q.buffer[i]);
            }
        }

        printf("%d]\n", TAIL(q));
    }
}
