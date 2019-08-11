// Delete n. node from linkedlist

#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 

typedef struct Liste
{
	int sayi;
	struct Liste *sonraki;

}Listeler;

// silme işleminde 2 durum var
// birincisi baştakini silme -> if
// ikincisi orta veya sondakini silme -> else
void delete(struct Liste** ilk, int n) // silinme yapılacak listeyi ve silinme sırasını parametre alır
{
    struct Liste *prev, *temp=(*ilk);
	
	int i = 1; // silinecek sıraya gelmek için bu değişkeni kullancaz. o yüzden 1'den başlasın.

	if (temp != NULL && n==1) // eğer silinecek eleman en baştaysa;
    { 
        (*ilk) = temp->sonraki;  
        free(temp);               
    } 
	
	else
	{
		while(temp != NULL && i<n) // i<n sayesinde temp'le silinecek node'a geliriz
		{
			prev = temp;           // prev'de silinecek node'un önceki node'unu tutarız
			temp = temp->sonraki;  // temp'i ilerleterek silinecek node'a geliriz
			i++;				   // bunu artırmayı unutmayalım
		}

		prev->sonraki = temp->sonraki; // temp'in yani silinecek node'un sonrasıyla öncesini bağlayalım
		free(temp); 				   // ve temp'i free yapalım
	}

}

// yeni gelen elemanı listenin başına ekler
// bu yüzden de ekleme yapılacak listeyi (head'ini) ve yeni gelen değeri parametre alır
void push(struct Liste** ilk, int s) 
{
	struct Liste* temp = (struct Liste*)malloc(sizeof(struct Liste));

	temp->sayi = s;
	temp->sonraki = (*ilk);
	(*ilk) = temp;
} 

void printList(struct Liste *list)
{
	printf("List: ");

	while(list != NULL)
	{
		printf("%d ", list->sayi);
		list = list->sonraki;	
	}
}

int main()
{
	struct Liste* ilk1 = NULL; 
	int n; // silinecek sırayı n değişkeninde tutalım

	push(&ilk1, 22); // listeye ekleme yapalım. bu yüzden listeyi(head'ini) ve yeni değeri her seferinde push'a gönderelim
	push(&ilk1, 11);
	push(&ilk1, 17);
	push(&ilk1, 10);

	printList(ilk1); // listeyi bi yazdıralım
	printf("\n");
	 
	printf("Delete n. node: ");scanf("%d", &n); // silinecek sırayı input olarak alıp n'e atayalım
	delete(&ilk1, n); // ekleme yaptığımız listeyi ve silinecek sırayı delete fonks.a gönderelim
	printf("\n");
	printList(ilk1); // silinmiş halini yazdıralım
	printf("\n");
	
}
