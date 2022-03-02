#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    void* dataPtr;
    struct node* next;
};

struct queues
{
    struct node* front;
    struct node* rear;
    int count;
};


struct queues* createQueue()
{
    struct queues* queue;
    queue = (struct queues*)malloc(sizeof(struct queues));

    if(queue)
    {
        queue->front == NULL;
        queue->rear == NULL;
        queue->count = 0;
    }
    return queue;
}

bool enqueue(struct queues* queue, void* itemPtr)
{
    struct node* newPtr;

    if(!(newPtr = (struct node*)malloc(sizeof(struct node))))
        return false;

    newPtr->dataPtr = itemPtr;
    newPtr->next = NULL;

    if(queue->count == 0)
    {
        queue->front = newPtr;
    }
    else
    {
        queue->rear->next = newPtr;
    }//Kuyruk ta sondan eklenir bastan cikarilir.

    (queue->count)++;
    queue->rear=newPtr;
    return true;
}

bool dequeue(struct queues* queue, void** itemPtr)
{
    struct node* deleteLoc;

    if(!queue->count) // queue nun count degerini kontrol ettik
    {
        return false;
    }
    *itemPtr = queue->front->dataPtr;
    deleteLoc = queue->front; //daha sonra serbest býrakmak için eski front degerimizi gecici bir degere atadik

    if(queue->count == 1) //eger kuyrukta tek eleman varsa silindiginde front ve rear degerleri NULL olur.
    {
        queue->rear = queue->front = NULL
    }
    else
        queue->front = queue->front->next; // bastan sildigimiz icin yeni front degerini atadýr

    (queue->count)--; //count degerini guncelledik

    free(deleteLoc);
    return true;

}
bool queueFront(struct queues* queue, void** itemPtr)
{   //kuyrukun frontunun degerini itemPtr a atayan fonk
    if(!queue->count)
        return false;
    else
    {
        *itemPtr = queue->front->dataPtr;
        return true;
    }
}
bool emptyQueue(struct queues* queue)
{
    return  (queue->count == 0);//kuyruk bosmu bossa true dondurecek
}

int queueCount(struct queues* queue)
{
    return queue->count;//count degerini donduren fonk
}

bool fullQueue(struct queues* queue)
{
    struct queues* temp;
    temp = (struct queues*)malloc(sizeof(*(queue->rear)));

    if(temp)
    {
        free(temp);
        return true;
    }
    return false
}

struct queues* destroyQueue(struct queues* queue)
{
    struct queues* deletePtr;
    if(queue)
    {
        while(queue->front != NULL)
        {
           free(queue->front->dataPtr);
           deletePtr = queue->front;
           queue->front = queue->front->next;
           free(deletePtr);
        }
        free(queue);
    }
    return NULL;
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
