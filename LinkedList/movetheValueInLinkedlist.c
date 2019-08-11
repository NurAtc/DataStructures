#include<stdio.h> 
#include<stdlib.h> 
#include<stdbool.h> 

typedef struct Liste
{
	int sayi;
	struct Liste *sonraki;

}Listeler;


void tasi(struct Liste** ilk, int n, int data)
{
    struct Liste *prev=(*ilk);
	struct Liste *ptr1=(*ilk);
	
	while(ptr1->sonraki != NULL) 
	{
		if(ptr1->sayi == data)
		{
			struct Liste *ptr2 = ptr1;
			int i=0; 
			while(ptr2->sonraki != NULL && i<n)
			{
				ptr2 = ptr2->sonraki;
				i++;
			}			

			prev->sonraki = ptr1->sonraki;
			ptr1->sonraki = ptr2->sonraki;
			ptr2->sonraki = ptr1;			
			break;
		}

		else
		{
			prev = ptr1;
			ptr1 = ptr1->sonraki;
		}
	}	

}


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
	int n;
	int data;

	push(&ilk1, 20);
	push(&ilk1, 44);
	push(&ilk1, 15);
	push(&ilk1, 85);
	push(&ilk1, 17);
	push(&ilk1, 21);
	push(&ilk1, 23);
	push(&ilk1, 66);
	push(&ilk1, 77);

	printList(ilk1);
	printf("\n\n");
	 
	printf("Tasinma miktari(n): ");scanf("%d", &n);
	printf("Tasinacak deger: ");scanf("%d", &data);
	tasi(&ilk1, n, data);
	printf("\n");
	printList(ilk1);
	printf("\n");
	
}
