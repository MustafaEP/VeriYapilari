#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 10

int dizi[BOYUT];
int diziKontrol[BOYUT];
int sayi;
int sayi1;
int matris[4][4];


void diziyiYazdir()
{
    for(int i = 0; i< BOYUT; i++){
        printf("\ndizi[%d] = %d\n", i, dizi[i]);
    }
    printf("\n");
}


void elemanEkle(int kacinciEleman, int eklenecekSayi)
{
    dizi[kacinciEleman] = eklenecekSayi;
}

void rastgeleElemanEKle(int eklenecekElemanSayisi)
{
    int konum;
    int deger;
    int i = 0;
    while(i < eklenecekElemanSayisi)
    {
        konum = rand() % 10;
        deger = rand() % 50 + 1;
        dizi[konum] = deger;
        i++;
    }
}

int elemanSil(int kacinciEleman)
{
    int i = kacinciEleman;
    for (i; i<BOYUT; i++)
    {
        dizi[i] = dizi [i+1];
    }
}

void diziyiTersCevir()
{
    int gecici;
    int bas = 0;
    int son = BOYUT-1;
    while(bas<son)
    {
        int gecici = dizi[bas];
        dizi[bas] = dizi[son];
        dizi[son] = gecici;
        bas++;
        son--;
    }
}

void matrisYazdir()
{
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}

void matrisRastgeleElemanEkle()
{
     for(int i=0; i<4; i++)
    {
        for(int j=0; j<4; j++)
        {
            matris[i][j] = rand() % 2;
        }
    }
}



int main()
{

    for(int i = 0; i < BOYUT; i++)
    {
        diziKontrol[i] = -1;
    }


    while(1==1){

    printf("**********MENU**********\n");
    printf("Diziyi yazdirmak icin 0...\n");
    printf("Diziye eleman eklemek icin 1...\n");
    printf("Diziye rastgele eleman eklemek icin 2...\n");
    printf("Eleman silmek için 3...\n");
    printf("Diziyi ters cevirmek icin 4...\n");
    printf("Matrise rastgele eleman eklemek icin 5...\n");
    printf("Matris yazdirmak icin 6...\n");
    int secim;
    scanf("%d", &secim);


    switch(secim)
    {
    case 0:
        diziyiYazdir();
        break;

    case 1:
        printf("Kacinci indise eleman eklemek istersiniz...\n");
        scanf("%d", &sayi);
        printf("Hangi sayiyi eklemek istersiniz...\n");
        scanf("%d", &sayi1);
        elemanEkle(sayi, sayi1);
        break;

    case 2:
        printf("Kac tane rastgele eleman eklemek istersiniz...\n");
        scanf("%d", &sayi);
        rastgeleElemanEKle(sayi);
        break;

    case 3:
        printf("Kacinci elemani silmek istersiniz...\n");
        scanf("%d", &sayi);
        elemanSil(sayi);
        break;

    case 4:
        printf("Diziyi ters ceviriliyor...\n");
        diziyiTersCevir();
        break;

    case 5:
        printf("Matris rastgele eleman ekleniyor...\n");
        matrisRastgeleElemanEkle();
        break;

    case 6:
        printf("Matris yazdiriliyor...\n");
        matrisYazdir();
        break;
    }

    }


    return 0;
}
