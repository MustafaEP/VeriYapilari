#include <stdio.h>
#include <stdlib.h>

#define BOYUT 10

int kuyruk[BOYUT];
int front = -1, rear = -1;

void enqueue(int sayi) //kuyruga sayi ekleme
{
    if(rear == BOYUT-1)
    {
        printf("Kuyruk dolu \n");
        return;
    }

    if(front == -1)
        front = 0;

    rear++;
    kuyruk[rear] = sayi;
}

int dequeue()
{
    if(front == -1 || front > rear)
    {
        printf("\nKuyruk Bous\n");
    }
    int cikan = kuyruk[front];
    if(front == rear)
    {
        front = -1;
        rear = -1;
        return cikan;
    }

    front++;
    return cikan;
}

void yazdir()
{
    for(int i = front; i<=rear; i++)
    {
        if(i == front && i == rear)
        {
            printf("\n%d-> %d (front) (rear)", i, kuyruk[i]);
        }
        else if(i == front )
        {
            printf("\n%d-> %d (front)",i, kuyruk[i]);
        }
        else if(i == rear)
        {
            printf("\n%d-> %d (rear)",i, kuyruk[i]);
        }
        else
            printf("\n%d-> %d",i, kuyruk[i]);

    }
}

int main()
{
    int sayi, secim;
    while(1)
    {
        printf("1- ekle\n");
        printf("2- cikar\n");
        scanf("%d", &secim);
        switch(secim)
        {
        case 1:
            printf("Sayi girin...");
            scanf("%d", &sayi);
            enqueue(sayi);
            yazdir();
            printf("\n\n");
            break;

        case 2:
            sayi = dequeue();
            printf("cikarilan = %d", sayi);
            yazdir();
            printf("\n\n");
        }
    }
    return 0;
}
