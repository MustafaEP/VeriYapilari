/*
    *YIGIN(stack), verilerin eklenmesi ve silinmesinin tepe(top) adý verilen listenin
    bir ucu ile kisitlandigi dogrusal bir listedir.
    *Bir dizi veriyi bir yigina yerlestirip cikarirsak, veri sirasi tersine cevrilir.
    *Bu ozellik last in - first out(LIFO) bilinir
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int sayi;
    struct node* sonraki;
};

struct node* top;

/*
    Yalnizca en uste bir nesneyi ekleyebiriz.
*/
void push(int sayi) //ekleme
{
    struct node* eklenecek = (struct node*)malloc(sizeof(struct node));
    eklenecek->sayi = sayi;

    eklenecek->sonraki = top;
    top = eklenecek;
}

void pop() //cikartma
{
    if(top == NULL)
    {
        printf("Zaten eleman yok. UNDERFLOW\n");
        //Eger stack bos ise stack Underflow durumdadir.
        return;
    }

    struct node* cikarilacak = top;
    top = cikarilacak->sonraki;
    free(cikarilacak);
}

void yazdir()
{
    struct node* temp = top;
    while(temp != NULL)
    {
        printf("%d\n", temp->sayi);
        temp = temp->sonraki;
    }
}

int main()
{

    int secim;
    int sayi;
    while(1)
    {
        printf("1- push\n");
        printf("2- pop\n");
        printf("3- yazdir\n");
        scanf("%d", &secim);

        printf("\n");

        switch(secim)
        {
        case 1:
            printf("Eklenecek sayi: ");
            scanf("%d", &sayi);
            push(sayi);
            yazdir();
            break;
        case 2:
            pop();
            yazdir();
            break;
        case 3:
            yazdir();
            break;
        }
    }

    return 0;
}
