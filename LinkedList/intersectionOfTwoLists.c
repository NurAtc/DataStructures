// Intersection Of Two Linkedlist

#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 

typedef struct Liste
{
	int sayi;
	struct Liste *sonraki;

}Listeler;

void push(struct Liste** head, int s);

// 1.listeyle 2.listeyi karşılaştırcaz. önce 1.nin ilk elemanıyla 2.nin tüm elemanlarını,
// sonra 1.nin ikinci elemanıyla 2.nin tüm elemanlarını..
struct Liste *getIntersection(struct Liste *ilk1, struct Liste *ilk2) 
{
	struct Liste *result = NULL;
	// result adında bi list oluşturuyoruz. Ortak elemanları buna ekleyip fonksiyonun sonunda döndürcez
	struct Liste *gecici = ilk2;
	// yukarıda anlattığımız karşılaştırma mantığına göre, 2.listenin head'ini kaybetmememiz lazım
	// yeniden lazım olcak

	while(ilk1 != NULL) // 1.listenin head'i null değilse(karşılaştırmaya 1.den başlıyoruz çünkü)
	{
		while(gecici!= NULL) // 2.listenin head'i null değilse
		{
			if(ilk1->sayi == gecici->sayi) // 1. ve 2.nin karşılaştırması
				push(&result, ilk1->sayi); // elemanlar aynıysa, result'ı ve elemanı push'a gönderip result'a eklet
			gecici = gecici->sonraki; // 2.listenin bi sonrasına geç
		}

		// 1.listenin ilk elemanıyla 2.listenin tüm elemanlarını karşılaştırdık
		// şimdi de 1.listenin bi sonraki elemanıyla 2.listenin tüm elemanlarını karşılaştıralım.
		gecici = ilk2; // 2.listenin en başına gelelim yine
		ilk1 = ilk1->sonraki; // 1.listenin de bi sonraki elemanına gelelim
	}

	return result; // push fonksiyonunda result'a eklenen ortak elemanları return edelim, maindeki intersecn değişkenine
}

void push(struct Liste** ilk, int s) // yeni gelen elemanı listenin başına ekler
{				     // bu yüzden de ekleme yapılacak listenin head'ini ve yeni gelen değeri parametre alır
	struct Liste* temp = (struct Liste*)malloc(sizeof(struct Liste));

	temp->sayi = s;
	temp->sonraki = (*ilk);
	(*ilk) = temp;
} 

void printList(struct Liste *list)
{
	while(list != NULL)
	{
		printf("%d ", list->sayi);
		list = list->sonraki;	
	}
}

int main()
{
	struct Liste* ilk1 = NULL; 
	struct Liste* ilk2 = NULL; 
	struct Liste* intersecn = NULL; // getIntersection fonksiyonunun dönüş tipi struct Liste *.
					// fonksiyonun dönderdiği değeri altta intersecn'e atıycaz.

	push(&ilk1, 22); // head'i ilk1 olan listeye ekleme yapalım.
	push(&ilk1, 11);
	push(&ilk1, 17);
	push(&ilk1, 10);	

	push(&ilk2, 10); // head'i ilk2 olan listeye ekleme yapalım.
	push(&ilk2, 11);
	push(&ilk2, 44);
	push(&ilk2, 17);

	printList(ilk1); // listeleri bi yazdıralım.
	printf("\n");
	printList(ilk2);
	printf("\n");

	intersecn = getIntersection (ilk1, ilk2); // fonksiyona gönderelim. gelen değerini de intersecn'e atayalım.
	printf ("\nIntersection list is \n"); 
	printList (intersecn); // ortak elemanları tutan intersecn'i, yazdırma fonksiyonuna gönderelim.
}
