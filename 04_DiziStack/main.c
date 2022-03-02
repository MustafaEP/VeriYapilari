#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define BOYUT 10

int dizi[BOYUT];
int top = -1;

bool doluMu()
{
    if(top == BOYUT -1)
        return true;
    else
        return false;
}

bool bosMu()
{
    if(top == -1)
        return true;
    else
        return false;
}

void push(int sayi)
{
    bool dolu = doluMu();
    if(dolu == true)
    {
        printf("\nStackoverflow...");
        return;
    }
    top = top + 1;
    dizi[top] = sayi;
}

int pop()
{
    bool bos = bosMu();
    if(bos == true)
    {
        printf("\nStack zaten bos");
        return;
    }
    int eskiTop = dizi[top];
    top--;
    return eskiTop;
}

int peek()
{
    return dizi[top];
}

void yazdir()
{
    for(int i = top; i>= 0; i--)
    {
        printf("%d\n", dizi[i]);
    }
}


int main()
{

    int secim = 0, sayi = 0, okunacak = 0;
    while(1)
    {
        printf("\nHangi islemi yapmak istersiniz: \n");
        printf("1 - push\n");
        printf("2 - pop\n");
        printf("3 - peek\n");
        scanf("%d", &secim);

        switch(secim)
        {
            case 1:
                printf("Eklemek isdediginiz sayiyi giriniz: ");
                scanf("%d", &sayi);
                push(sayi);
                yazdir();
                break;

            case 2:
                pop();
                yazdir();
                break;

            case 3:
                okunacak = pop();
                printf("---%d---", okunacak);
                top += 1;
                break;
        }
    }

    return 0;
}
