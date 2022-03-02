#include <stdio.h>
#include <stdlib.h>

int kuyruk[BOYUT];
int front = -1, rear = -1;

void enqueue(int sayi)
{
    if((front == 0 && rear == BOYUT -1) || rear + 1 == front)
    {
        printf("\n************kuyruk dolu***********\n");
        return;
    }

    if(front == -1)
        front = 0;
    rear = ((rear + 1) % BOYUT);
    kuyruk[rear] = sayi;
}

int dequeue()
{
    if(front == -1)
    {
        if(front == -1)
        {
            printf("\n************kuyruk bos***********\n");
            return -1;
        }

        if(froni)
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
