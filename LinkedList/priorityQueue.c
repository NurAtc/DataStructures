#include<stdio.h>
#include<stdlib.h>


struct akademisyen
{
    int sicilNo;
    char *ad;
    int unvanID;
    int unvanYili;
    struct akademisyen *next;
}*Akademisyenler;	//head is declared

void push(int, char *, int, int);//declaration of mmethod we are going to use
void pop();		//declaration	


void gorevlendirme(int gorev) //kac kisinin gorevlendirilecegi parametre olarak gelir
{
	struct akademisyen *temp; // queue'mizin başlangıcını yani head'ini(Akademisyenler) hiç bi zaman kaybetmememiz lazım, bu yüzden
	temp = Akademisyenler;	  // oluşturduğumuz temp pointer'ine Akademisyenler pointer'ini atıyoruz. Akademisyenler'i kullanmıyoruz.
	    			  		  // temp pointer'ini kullanıyoruz.

 	printf("\nPriority Queue:\n");
	char* prof; // unvanID'sine göre degisen unvanları yazdırırken prof'u kullancaz.

	int size = 0; // gorevlendirme işleminde queue'mizin uzunluğunu bilmemiz lazım. uzunluğu aşağıda kullancaz zaten.
				  // bu değişkende queue'mizin uzunluğu tutulacak.
	while(temp->next!=NULL) // bu şekilde, queue'nin sonuna geliyoruz. yani node'ların,akademisyenlerin next'i null olana kadar
	{
	    temp = temp->next; // queue'de ilerliyoruz. temp pointer'ına head pointer'ını(Akademisyenler) atamıştık zaten yukarda. 
			               // yani baştan sona temp ile geziyoruz.
	    size++;            // bu esnada da başta değeri 0 olan 'size' değişkeninin değerini bir artırıyoruz.
	}		               // böylece en son, queue'mizin uzunluğunu elde etmiş oluyoruz.
	
	// sonuna geldik ve queue bitti ama bizim görevlendirmeyi ayarlamamız lazım :)
	// o zaman head'imizi tutan Akademisyenler pointer'ını yeniden temp pointer'ına atayalım. çünkü temp şu an başlangıcı değil,
	// null'ı gösteriyor.

	// Yukarıda da aynı işlemi yapmıştık. Bunun önemini burda görmüş olduk. Eğer queue'nin uzunluğunu bulurken Akademisyenler'i kullanmış
	// olsaydık, queue bitmiş olacağı için Akademisyenler pointerımız Null'u gösterecekti ve biz queue'ye artık erişemeyecektik.
	// Akademisyenler'i yani head'i hiç bi zaman kaybetmemeliyiz yani kullanmamalıyız. Onun yerine yine temp'e atayıp kullancaz.
	
	// burda da bu anlattığımız işlemi yaptıktan sonra görevlendirmeye geçiyoruz.
	temp = Akademisyenler; 

	// 5 tane node'umuz, akademisyenimiz var diyelim. 3 tanesini görevlendirmek istiyoruz. Görevlendirmeye sondan yani en düşük
	// ünvanlılardan başlanması isteniyor. O halde sondan 3 tane akademisyeni görevlendirmek istiyorsak, queue'de 2 adım ilerleyip,
	// ondan sonra gelen node'ları, akademisyenleri almamız lazım.

	// bunu da for döngüsünde '(size-gorev+1)' ile ayarlıyoruz. 
	for(int i=0; i<(size-gorev+1); i++) 
            temp = temp->next; // bu şekilde görevlendirmeye başlıycağmız node'a gelmiş olduk.

	while(temp!=NULL) // bu kısımda unvanID'sine göre değişen ünvanların değerini, yukarda oluşturduğumuz 'prof' değişkenine atıyoruz.
	{		          // görevlendirdiğimiz akademisyenleri yazdırırken ünvanlarını da 'prof' değişkeniyle ayarlamış olduğumuz için 
			          // artık bu değişkeni printf'de de kullanabiliriz.
		if(temp->unvanID==1) prof="Prof. Dr.";
		else if(temp->unvanID==2) prof="Doc. Dr.";
		else if(temp->unvanID==3) prof="Dr. Ogr. Uyesi";

								                            // temp değişkeni, görevlendirmeye başlayacağımız node'u göstermekte.
		printf("%d %s %s\n",temp->sicilNo, prof, temp->ad); // O halde temp'i kullanıp görevlendirilmiş node'ları, akademisyenleri
								    					    // yazdırabiliriz.
		temp=temp->next; // sırayla, görevlendirilen tüm node'ları, akademisyenler'i dolaşıyoruz.
						 // null olana kadar. bunu while'da ayarladık.
	}

printf("\n");

}


void disp() // ekrana yazdırma
{
	struct akademisyen *temp;// head'dan yani Akademisyenler'den başlayarak tüm queue'yi dolaşıp yazdıralım.
	temp = Akademisyenler;   // Ama head'i yani Akademisyenler'i asla kaybetmememiz gerektiği için yine temp pointer'ına atayıp kullanalım

	printf("\nPriority Queue:\n");

	char* prof; //unvanID'sine göre içeriği değişecek. Unvan yazdırırken de böylece bunu kullancaz.
	while(temp!=NULL) // temp, queue'nin başını gösteriyor burada zaten. En baştan tüm queue'yi yazdıralım. Null olana kadar.
	{
		if(temp->unvanID==1) prof="Prof. Dr.";
		else if(temp->unvanID==2) prof="Doc. Dr.";
		else if(temp->unvanID==3) prof="Dr. Ogr. Uyesi";
		printf("%d %s %s\n",temp->sicilNo, prof, temp->ad);
		temp=temp->next; // yazdırdıktan sonra bir ilerletelim.
	}

printf("\n");

}

void push(int sNo, char *a, int pri, int uY) // eklenecek akademisyene ait bilgiler parametre olarak gelir.
{
	struct akademisyen *temp, *t;
	// struct akademisyenden türeyen bi temp pointeri oluştururuz ve yeni eklenecek node, akademisyen için bellekte yer ayırırız.
	temp = (struct akademisyen *)malloc(sizeof(struct akademisyen));

	// yeni gelen değerleri temp node'una aktarırız.	
	temp->sicilNo=sNo; // temp'in sicilNo'suna yeni gelen sNo'yu atarız.
	temp->ad=a;        // temp'in ad'ına yeni gelen a'yı atarız. vs vs.
	temp->unvanID=pri;
	temp->unvanYili=uY;
	temp->next=NULL; // next değerine de şimdilik null atıyoruz.
	
	if(Akademisyenler==NULL) // eğer queue boşsa
		Akademisyenler = temp; // head yani başlangıç değeri olan Akademisyenler'e temp node'unu atarız.

	/// unvanIDsi büyük olanın priority'si daha küçüktü. Bunu bi hatırlayalım.

	else if(Akademisyenler->unvanID>pri) // head'in unvanID'si, yeni gelenin pri değerinden daha büyükse 
	{				     				 // yeni geleni, head'in önüne ekleriz yani head olur.
					     
		temp->next=Akademisyenler;   // O halde, yeni node'umuz olan temp'in next'i, eski head'imiz olan Akademisyenler'i gösterir.
		Akademisyenler=temp;	     // temp'imiz de yeni head olur. head'i tutan hep Akademisyenler olduğu için,
					     		     // temp'i Akademisyenlere atarız.
	}

	else
	{
		t=Akademisyenler; // t'ye head değerini atıyoruz (Her zaman head=Akademisyenler)

		// Ve t'yi kullanarak queue'de dolaşmaya başlıyoruz. Yeni node'umuzun 'pri' değerine uyan yeri bulmaya çalışcaz. 
		// t'nin next'i null oluncaya kadar ve t'nin next'inin unvanID'si(t'nin unvanID'si değil, bura önemli!!)
		// yeni node'un pri değerinden küçük olana kadar ilerlemeye devam et.
		while(t->next!=NULL && (t->next)->unvanID<=pri )  
			t=t->next;
		temp->next=t->next; // uygun yeri bulduğunda eklemeyi yaparız. yeni node'un yani temp'in next'i, t'nin next'i dir.
		t->next=temp; //temp de t'nin next'idir.

		// Yeni node, uygun yere yani t'nin next'ine eklenmiştir.
	}
//disp();
}

void del(int silinecek) // silinecek akademisyenin sicilno'su paremetre olarak gelir.
{
    struct akademisyen *prev, *temp=Akademisyenler; // prev ve temp değişkenleri oluşturuyoruz. 
													// head'i(Akademisyenler) kaybetmemek için yine onu temp'e kopyalıyoruz ve temp'i
													// kullanıyoruz.

	// head'i yani onu atadığımız temp'i kullanarak queue'de silinecek elemanı(sicilNo'ya göre) aramaya başlıyoruz.
    if (temp != NULL && temp->sicilNo == silinecek) // eğer silinecek eleman en baştaysa;
    { 
        Akademisyenler = temp->next;   // en baştaki elemanın next'ini asıl headimiz(Akademisyenler) yapıyoruz.
		printf("\nRemoved: %d",temp->sicilNo); // silinen akademisyenin sicilNo'sunu yazdırdık.
        free(temp);               // ve eski head'imizi sildik. (İşlemleri hep temp üzerinden yaptık.
	    // Asıl head'imize yani Akademisyenler'e dokunmamız lazım.
    } 

    // Search for the sicilNo to be deleted, keep track of the 
    // previous node as we need to change 'prev->next' 

	// Eğer yukarıdaki şart bize uymuyorsa bu kısım çalışır.
    else
    {
        while (temp != NULL && temp->sicilNo != silinecek) // temp'imiz yani geçici head'imizi kullanarak queue'de arama yapmaya başlıyoruz.
        { 												   // temp'in sicilNo'su silinecek sicilno'ya eşit olmadığı sürece,
             prev = temp;       // temp'i hep prev'e atıyoruz ve ondan sonra ilerletiyoruz.
             temp = temp->next; // Çünkü silme işleminde önceki değere de ihtiyacımız olacak.
         } 
    
  
        // If key was not present in linked list 
        if (temp == NULL)
            printf("\nError List Empty");
  
        // Unlink the node from linked list 
         prev->next = temp->next; // silinecek değeri bulduğumuzda, temp'in öncesinin(prev) next'ini temp'in next'ine bağlarız.

    free(temp); // ve aradaki silinecek temp'i artık boş bırakırız yani sileriz.

    }
   
    disp();

}


int main()
{
	int ch, sNo, unvanID, uY, silinecek, gorev, check=1;
	char *a;

	// 3 tane akademisyen oluşturuyoruz. (sicilNo, ad, unvanID, unvanYili)
	// Ekleme fonksiyonunu kullanarak önce bunları bi queue'ye ekliyoruz.
	push(129,"tubi",2,1990);
	push(123,"nihal",3,1995);
	push(127,"hatic",1,1998);
	disp();

while(check==1)
{
	printf("\n1. List\n2. Gorevlendirme\n3. Insert\n4. Remove\n5. Exit\nIn Priority Queue Select:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1: // Listeleme
			disp();	
			break;
		case 2: // Görevlendirme
			printf("Kac kisi gorevlendirilecek?\n"); scanf("%d", &gorev);
			gorevlendirme(gorev);
			break;
		case 3: // Ekleme
			printf("\nEnter sicilNo and ad and unvanID and unvanYili: ");
			scanf("%d%s%d%d",&sNo,a,&unvanID,&uY); //input from user
			push(sNo,a,unvanID,uY);	//Send Element and its priority for insertion
			break;
		case 4: // Silme
			printf("Silinecek kaydın sicilno'sunu giriniz: "); scanf("%d", &silinecek);
			del(silinecek);
			break;
		case 5:
			check=0; //Stops the loop
			break;
		default:
			printf("Wrong Choice");
	printf("\nPress 1 to continue or 0 to stop");
	scanf("%d",&check);
	}
}
return 0;
} //end of Main
