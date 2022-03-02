#include <stdio.h>
#include <stdlib.h>

struct node
{
    int sayi;
    struct node* sonraki;

};

struct node* baslangic = NULL;

struct node* olustur(int sayi)
{
    struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
    yeniDugum->sayi = sayi;
    yeniDugum->sonraki=NULL;

    return yeniDugum;
}

void sonaEkle(int sayi)
{
    struct node* sonaEklenecek = olustur(sayi);

    if(baslangic == NULL)
    {
        baslangic = sonaEklenecek;
    }
    else
    {
        struct node* temp = baslangic;
        while(temp->sonraki != NULL)
        {
            temp = temp->sonraki;
        }
        temp->sonraki = sonaEklenecek;

    }
}


void basaEkle(int sayi)
{
    struct node* basaEklenecek = olustur(sayi);

    if(baslangic == NULL)
    {
        baslangic = basaEklenecek;
        return;
    }

    struct node* eskiBirinci = baslangic;
    baslangic = basaEklenecek;
    baslangic->sonraki = eskiBirinci;

}


void arayaEkle(int pos, int sayi)
{
    struct node* arayaEklenecek = olustur(sayi); //arayaEklenecek düðümünü oluþturdum

    if(pos == 0) // eðer pos deðeri 0 ise bu baþa ekleme olayýnýn aynýsý olacaktýr
    {
        basaEkle(sayi);
        return;     // Diger islemleri gereksiz yapýp yormamasý icin fonksiyondan direk ciktim
    }

    int counter = 0; //pos degerine gelip gelmedigini kontrol etmek icin counter(sayac) olusturdum
    struct node* temp = baslangic;  // baslangic ile oynamamak icin gecici bir temp dugumu olusturdum

    while(temp != NULL) //temp degerini pos degerinde istenen elemana getirmek icin while dongusu kullandum ve her dongude counteri artýrdým
    {
        if(counter == pos-1) // istenen siraya gelince donguden cikmasini sagladim
            break;
        temp = temp->sonraki;
        counter++;
    }
    if(counter +1 != pos)   //pos degeri sacma bir sayi ise hata vermemesi icin uyari yazdirdim
    {
        printf("Boyle bir pozisyon yok\n");
        return;
    }
    if(temp->sonraki == NULL)   //eger pos degeri son elemani isaret ediyorsa fonkdan cikmasini sagladim
    {
        sonaEkle(sayi);
        return;
    }

    struct node* gecici = temp->sonraki;    //arayaEklenecek degeri yerine koydum
    temp->sonraki = arayaEklenecek;
    arayaEklenecek->sonraki = gecici;
}

void yazdir()
{
    struct node* temp = baslangic;
    printf("\n***********************************\n");
    while(temp != NULL)
    {
        printf("%d => ", temp->sayi);
        temp = temp->sonraki;
    }
    printf("\n***********************************\n\n");
}

void sondanSil()
{
    if(baslangic == NULL)
    {
        printf("Zaten hic eleman yok...\n");
        return;
    }
    struct node* temp = baslangic; // baslangic degeri yerine gecici bir deger atandi
    if(temp->sonraki == NULL)
    {
        bastanSil();
        return;
    }
    while(temp->sonraki->sonraki != NULL)//son elemani silmek icin onu isaret eden link(sonraki) degerini bulmaliyiz
    {
        temp = temp->sonraki;
    }
    free(temp->sonraki); //son elemani isaret eden sonraki degeri serbest birakildi ve son eleman silindi
    temp->sonraki = NULL; // sonraki degerine NULL atadik.
}

void bastanSil()
{
    if(baslangic == NULL)
    {
        printf("Zaten eleman yok...\n");
    }
    if(baslangic->sonraki == NULL)
    {
        baslangic == NULL;
        return;
    }

    struct node* ikinci = baslangic->sonraki;
    free(baslangic);
    baslangic = ikinci;
}

void aradanSil(int pos)
{
    struct node* temp = baslangic;
    int counter = 0;

    if(pos == 0)
    {
        bastanSil();
        return;
    }
    if(temp->sonraki == NULL)
    {
        sondanSil();
        return;
    }

    while(temp != NULL)
    {
        if(counter == pos-1)
            break;
        temp = temp->sonraki;
        counter++;
    }

    struct node* gecici = temp->sonraki->sonraki;
    free(temp->sonraki);
    temp->sonraki = gecici;
}

void aradanElemanSil(int eleman)
{
    struct node* temp = baslangic;

    if(baslangic == NULL)
    {
        printf("hic eleman yoktur...\n");
        return;
    }

    if(baslangic->sayi == eleman)
    {
        bastanSil();
        return;
    }

    int flag = 0;

    while(temp->sonraki != NULL)
    {
        if(temp->sonraki->sayi == eleman)
        {
            flag == 1;
            break;
        }
        temp = temp->sonraki;
    }

    if(flag == 0)
    {
        printf("Aradiginiz deger bulunamamistir...\n");
        return;
    }

    struct node* gecici = temp->sonraki->sonraki;
    free(temp->sonraki);
    temp->sonraki = gecici;
}

void tersCevirIterative()
{
    struct node* mevcut = baslangic;
    struct node* once = NULL;
    struct node* sonra = NULL;

    while(mevcut != NULL)
    {
        sonra = mevcut->sonraki;
        mevcut->sonraki = once;

        once = mevcut;
        mevcut = sonra;
    }
    baslangic = once;
}

struct node* tersCevirRecursive(struct node* MEVCUT)
{
    if(MEVCUT == NULL)
        return;

    //BASE CASE

    if(MEVCUT->sonraki == NULL)
    {
        baslangic = MEVCUT;
        return MEVCUT;
    }

    struct node* DUGUM = tersCevirRecursive(MEVCUT->sonraki);
    DUGUM->sonraki = MEVCUT;
    MEVCUT->sonraki = NULL;

    return MEVCUT;
}

void bekle(int saniye)
{
    int miliSaniye = 1000 * saniye;
    clock_t start_time = clock();
    while(clock() < start_time + miliSaniye);
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
        printf("Yapmak istediðiniz islemi seciniz...\n");
        scanf("%d", &secim);

        switch(secim)
        {

        case 1:

            printf("Hangi elemani ekleyeceksiniz: ");
            scanf("%d", &sayi);
            sonaEkle(sayi);
            yazdir();
            break;

        case 2:

            printf("Hangi elemani ekleyeceksizin: ");
            scanf("%d", &sayi);
            basaEkle(sayi);
            yazdir();
            break;


        case 3:

            printf("Hangi elemani ekleyeceksizin: ");
            scanf("%d", &sayi);
            printf("Hangi siraya ekleyeceksizin: ");
            scanf("%d", &pos);
            arayaEkle(pos, sayi);
            yazdir();
            break;

        case 4:
            printf("Son eleman silindi...\n");
            sondanSil();
            yazdir();
            break;

        case 5:
            printf("Bastaki eleman silindi...\n");
            bastanSil();
            yazdir();
            break;

        case 6:
            printf("Hangi pozisyonu sileceksiniz...\n");
            scanf("%d", &pos);
            aradanSil(pos);
            yazdir();
            break;

        case 7:
            printf("Hangi elemani sileceksiniz...\n");
            scanf("%d", &sayi);
            aradanElemanSil(sayi);
            yazdir();
            break;

        case 8:
            tersCevirIterative();
            yazdir();

        case 9:
            tersCevirRecursive(baslangic);
            yazdir();
        }
   }

    return 0;
}
