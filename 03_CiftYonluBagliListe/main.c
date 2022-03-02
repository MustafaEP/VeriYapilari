#include <stdio.h>
#include <stdlib.h>

struct node
{
    int sayi;

    struct node* sonraki;
    struct node* onceki;

    //dugumumuzun icinde gosterecegi degerleri atadik
};

struct node* bas = NULL;
struct node* son = NULL;
//baslangýc ve sonda olacak dugumleri olusturduk ve gecici olara NULL degeri verdik

struct node* olustur(int sayi)
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node)); //olusturacagimiz dugume bellekten yer ayirdik.
    yeniDugum->sayi = sayi;                                             //dugumun sayi, sonraki ve onceki degerlerini atadýk.
    yeniDugum->sonraki = NULL;
    yeniDugum->onceki = NULL;

    return yeniDugum;   //Olusturdugumuz dugumu geri gonderdik.
}

void yazdir(struct node* ilk, int ileri)
{
    struct node* temp = ilk;    //dugume gecici bir deger verdik
    while(temp != NULL)         //elimizdeki dugumleri yazdirdik
    {
        printf("%d ", temp->sayi);
        if(ileri == 1)
            temp = temp->sonraki;
        else
            temp = temp->onceki;
    }
    printf("\n\n");
}

void sonaEkle(int sayi)
{
    struct node* sonaEklenecek = olustur(sayi); //sona eklenecek sayi olusturuldu

    if(bas == NULL) //eger olusturulan ilk elemansa direk bas olarak atanýr
    {
        bas = sonaEklenecek;
        return;
    }

    struct node* temp = bas;    //gecici deger olusturuldu
    while(temp->sonraki != NULL)//son eleman buluncu
    {
        temp = temp->sonraki;
    }
    temp->sonraki = sonaEklenecek;
    sonaEklenecek->onceki = temp;
    return;
}


void basaEkle(int sayi)
{
    struct node* basaEklenecek = olustur(sayi);

    if(bas == NULL)
    {
        bas = basaEklenecek;
        return;
    }
    struct node* eski = bas;
    bas = basaEklenecek;
    basaEklenecek->sonraki = eski;
    eski->onceki = bas;
}


void arayaEkle(int sayi, int pos)
{
    struct node* arayaEklenecek = olustur(sayi);

    if(pos == 0)
    {
        basaEkle(sayi);
        return;
    }
    if(bas == NULL && pos>0)
    {
        printf("Bu konum uygun degildir.");
        return;
    }

    int counter = 0;
    struct node* temp = bas;
    int flag = 0;

    while(temp != NULL)
    {
        if(counter == pos)
        {
            flag = 1;
            break;
        }
        temp = temp->sonraki;
        counter++;
    }
    if(flag == 0)
    {
        printf("Boyle bir pozisyon yoktur...\n");
        return;
    }

    if(temp->sonraki == NULL)
    {
        sonaEkle(sayi);
        return;
    }
    /* 10 20 30 40 50 (77) */

    struct node* oncekidugum = temp->onceki;

    oncekidugum->sonraki = arayaEklenecek;
    arayaEklenecek->onceki=oncekidugum;
    arayaEklenecek->sonraki=temp;
    temp->onceki=arayaEklenecek;

}

int main()
{

     int secim, sayi, pos;

   while(1)
   {
        printf("1- Sona Eleman Ekle...\n");
        printf("2- Basa Eleman Ekle...\n");
        printf("3- Araya Eleman Ekle...\n");
        printf("4- Son Elemani Sil...\n");
        printf("5- Bastaki Elemani Sil...\n");
        printf("6- Aradaki Elemani Sil...\n");
        printf("7- Istenilen Elemani Sil...\n");
        printf("8- Ters Cevir(Iterative)...\n");
        printf("9- Ters Cevir(Recursive)...\n");
        printf("Yapmak istediginiz islemi seciniz...\n");
        scanf("%d", &secim);

        switch(secim)
        {

        case 1:
            printf("Eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi);
            sonaEkle(sayi);
            yazdir(bas, 1);
            break;

        case 2:
            printf("Eklenecek sayiyi giriniz: ");
            scanf("%d", &sayi);
            basaEkle(sayi);
            yazdir(bas, 1);
            break;


        case 3:
            printf("Hangi siraya ekliyeceksiniz: ");
            scanf("%d", &pos);
            printf("Hangi sayiyi ekliyeceksiniz: ");
            scanf("%d", &sayi);
            arayaEkle(sayi, pos);
            yazdir(bas, 1);
            break;

        case 4:

            break;

        case 5:

            break;

        case 6:

            break;

        case 7:

            break;

        case 8:

            break;
        case 9:

           break;
        }
   }


    return 0;
}
