#include "list_dinamis.h"

DynamicList CreateLD() {
	DynamicList A;
	A.Content = (LinkedList *)malloc(sizeof(LinkedList) * InitialCapacity);
	A.Capacity = InitialCapacity;
	A.Neff = 0;
	return A;
}

void DeallocateLD(DynamicList *l) {
	free((*l).Content);
}

boolean IsEmptyLD(DynamicList l) {
    return l.Neff == 0;
}

boolean IsFullLD(DynamicList l) {
    return l.Neff == l.Capacity;
}

boolean IsIdxValidLD(DynamicList l, Key i) {
    return i < l.Neff && i >= 0;
}

ElType GetLD(DynamicList l, Key i) {
    return Title(l.Content[i]);
}

void InsertLD(DynamicList *l, ElType x, Key i) {
	LinkedList xsb;

	CreateSB(&xsb);
	Title(xsb) = x;

    int j;

    if (IsFullLD(*l)) {
		LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(Title((*l).Content[j]), &Title(temp[j]));
			First(temp[j]) = First((*l).Content[j]);
		}

		DeallocateLD(l);
		(*l).Capacity *= 2;
		(*l).Content = (LinkedList *)malloc(sizeof(LinkedList) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(Title(temp[j]), &Title((*l).Content[j]));
			First((*l).Content[j]) = First(temp[j]);
		}
		free(temp);
    }

	for (j = (*l).Neff; j > i; j--)
	{
		PasteWord(Title((*l).Content[j - 1]), &Title((*l).Content[j]));
		First((*l).Content[j]) = First((*l).Content[j - 1]);
	}

	PasteWord(Title(xsb), &Title((*l).Content[i]));
	(*l).Neff++;
}

void DeleteLD(DynamicList *l, Key i) {
	int j;
	for (j = i; j < (*l).Neff; j++)
	{
		PasteWord(Title((*l).Content[j + 1]), &Title((*l).Content[j]));
		First((*l).Content[j]) = First((*l).Content[j + 1]);
	}
	(*l).Neff--;

    if ((*l).Neff <= ((*l).Capacity / 4)) {
		LinkedList *temp = (LinkedList *)malloc(sizeof(LinkedList) * (*l).Capacity);
		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(Title((*l).Content[j]), &Title(temp[j]));
			First(temp[j]) = First((*l).Content[j]);
		}

		DeallocateLD(l);
		(*l).Capacity /= 2;
		(*l).Content = (LinkedList *)malloc(sizeof(LinkedList) * (*l).Capacity);

		for (j = 0; j < (*l).Neff; j++)
		{
            PasteWord(Title(temp[j]), &Title((*l).Content[j]));
			First((*l).Content[j]) = First(temp[j]);
		}
		free(temp);
    }
}

void DeleteAtListDin(DynamicList *array, IdxType i)
{
	int j;
	for (j = i; j < array->Neff; j++)
	{
		(*array).Content[j] = (*array).Content[j + 1];
	}
	(*array).Neff--;
}

void DisplayLD(DynamicList l) {
	if (IsEmptyLD(l)) {
		printf("Kosong\n");
	}
	else {
		for (int i = 0; i < l.Neff; i++) {
			printf("    %d. ", i+1);
			displayWordNewLine(Title(l.Content[i]));
		}
	}
}

void DisplayIsiLD(DynamicList l, ElType x) {
	boolean found = false;
	int i = 0;
	while (i < l.Neff && !found) {
		if (IsWordSame(Title(l.Content[i]), x)) {
			DisplaySB(l.Content[i]);
			found = true;
		}
		i++;
	}
	if (!found) {
		printf("Playlist tidak ada\n");
	}
}

void DisplaySemuaLD(DynamicList l) {
	if (IsEmptyLD(l)) {
		printf("Kosong\n");
	}

	for (int i = 0; i < l.Neff; i++) {
		printf("Judul %d: ", i+1);
		displayWordNewLine(Title(l.Content[i]));
		DisplaySB(l.Content[i]);
	}

}