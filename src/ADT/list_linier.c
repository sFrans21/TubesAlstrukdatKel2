#include <stdio.h>
#include <stdlib.h>

#include "list_linier.h"

boolean IsEmptyLinier (LinierList L)
{
	return (First(L) == NilLinier); 
}
void CreateEmptyLinier (LinierList *L)
{
	First(*L) = NilLinier;
}

addressLinier Alokasi (Word word)
{
	addressLinier P;
	P = (ElmtList *)malloc(sizeof(ElmtList));
	if (P != NilLinier)
	{
		Info(P) = word;
		Next(P) = NilLinier;
		return P;
	}
	else
	{
		return NilLinier;
	}
}

void Dealokasi (addressLinier *P)
{
	free(*P);
}

/*addressLinier Search (LinierList L, Word word)
{
	addressLinier P = First(L);
	boolean found = false;

	while (P != NilLinier && !found)
	{
		if (cmp_word_1(Info(P), word))
		{
			found = true;
		}
		else
		{
			P = Next(P); 
		}
	}

	if (found)
	{
		return P;
	}
	else
	{
		return NilLinier;
	}
}*/

void InsVFirst (LinierList *L, Word word)
{
	addressLinier P = Alokasi(word);

	if (P != NilLinier)
	{
		Next(P) = First(*L);
		First(*L) = P;
	}
}

void InsVLast (LinierList *L, Word word)
{
	addressLinier P = Alokasi(word);

	if (P != NilLinier)
	{
		InsertLastLinier(L, P);
	}
}

void DelVFirst (LinierList *L, Word *word)
{
	addressLinier P;
	DelFirst(L, &P);
	(*word) = Info(P);
	Dealokasi(&P);
}

void DelVLast (LinierList *L, Word *word)
{
	addressLinier P;
	DelLast(L, &P);
	(*word) = Info(P);
	Dealokasi(&P);
}

void InsertFirstLinier (LinierList *L, addressLinier P)
{
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfterLinier (LinierList *L, addressLinier P, addressLinier Prec)
{
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLastLinier (LinierList *L, addressLinier P)
{
	if (IsEmptyLinier(*L))
	{
		InsertFirstLinier(L, P);
	}
	else
	{
		addressLinier last = First(*L);
		while (Next(last) != NilLinier)
		{
			last = Next(last);
		}
		InsertAfterLinier(L, P, last);
	}
}

void DelFirst (LinierList *L, addressLinier *P)
{
	*P = First(*L);
	First(*L) = Next(*P);
	Next(*P) = NilLinier;
}

/*void DelP (LinierList *L, Word word)
{
	addressLinier P = Search(*L, word);

	if (P != NilLinier){
		if (P == First(*L))
		{
			DelFirst(L, &P);
		}
		else
		{
			addressLinier prec = First(*L);
			while (Next(prec) != P)
			{
				prec = Next(prec);
			}
			DelAfter(L, &P, prec);
		}
	}
}*/

void DelLast (LinierList *L, addressLinier *P)
{
	addressLinier last = First(*L);
	addressLinier prec = NilLinier;

	while (Next(last) != NilLinier)
	{
		prec = last;
		last = Next(last);
	}

	*P = last;
	if (prec == NilLinier)
	{
		First(*L) = NilLinier; 
	}
	else
	{
		Next(prec) = NilLinier;
	}
}

void DelAfter (LinierList *L, addressLinier *Pdel, addressLinier Prec)
{
	*Pdel = Next(Prec);
	if (Next(Prec) != NilLinier)
	{
		Next(Prec) = Next(Next(Prec));
		Next(*Pdel) = NilLinier;
	}
}

void PrintInfo (LinierList L)
{
	addressLinier P = First(L);

	if (IsEmptyLinier(L))
	{
		printf("[]");
	}
	else
	{
		printf("[%d", Info(P));
		while (Next(P) != NilLinier)
		{
			P = Next(P);
			printf(",%d", Info(P));
		}
		printf("]");
	}
	printf("\n");
}

int NbElmt (LinierList L)
{
	int count = 0;

	addressLinier P = First(L);

	while (P != NilLinier)
	{
		P = Next(P);
		count++;
	}

	return count;
}

void InversLinierList (LinierList *L)
{
	addressLinier P = First(*L);
	addressLinier A = P;
	addressLinier B = Next(P);
	
	while (B != NilLinier)
	{
		A = B;
		B = Next(B);
		InsertFirstLinier(L, A);
		Next(P) = B;
	}
}

void Konkat1 (LinierList *L1, LinierList *L2, LinierList *L3)
{
	CreateEmptyLinier(L3);
	addressLinier lastL1 = First(*L1);

	if (IsEmptyLinier(*L1))
	{
		First(*L3) = First(*L2);
	}
	else
	{
		First(*L3) = First(*L1);
		while (Next(lastL1) != NilLinier)
		{
			lastL1 = Next(lastL1);
		}
		Next(lastL1) = First(*L2);
	}

	CreateEmptyLinier(L1);
	CreateEmptyLinier(L2);
}