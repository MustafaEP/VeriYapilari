#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    void* dataPtr;
    struct node* link;
} STACK_NODE;

typedef struct
{
    int count;
    STACK_NODE* top;
} STACK;

STACK* createStack()
{
    STACK* stack = (STACK*) malloc (sizeof (STACK)); //stack dugumune yer belirledik
    if(stack) //stackin baslangic degerlerini atadik.
    {
        stack->count = 0;
        stack->top = NULL;
    }
    return stack; //kurdugumuz stack dugumunu geri yolladýk
}

bool pushStack(STACK* stack, void* dataInPtr)
{
    STACK_NODE* newPtr;

    newPtr = (STACK_NODE*) malloc (sizeof(STACK_NODE));
    if(!newPtr)
        return false;

    newPtr->dataPtr = dataInPtr;
    newPtr->link = stack->top;

    stack->top = newPtr;

    (stack->count)++;
    return true;
}

void* popStack(STACK* stack)
{
    void* dataOutPtr;
    STACK_NODE* temp;

    if(stack->count == 0)
        dataOutPtr = NULL;
    else
    {
        temp = stack->top;
        dataOutPtr = stack->top->dataPtr;
        stack->top = stack->top->link;
        free(temp);
        (stack->count)--;
        /*
            stackin top degeri silinecektir. bunun icin ilk olarak stackin top degerini
            gecici bir temp degerine esitledik. Silinecek degerin dataPtr'sini
            daha sonra dondurmak icin kaydettik. yeni top degeri silinecek degerin linkine esitledik
            ve temp degerini serbest býraktýk.
        */
    }
    return dataOutPtr;
}

void* stackTop(STACK* stack)
{
    if(stack->count == 0)
    {
        return NULL;
    }
    else
        return stack->top->dataPtr;
    //yiginin top degerinin dataPtr sini kullaniciya dondurduk.
}

bool emptyStack(STACK* stack)
{
    return (stack->count == 0);
    //stack bos mu kontrol yapildi.
}

bool fullStack(STACK* stack)
{
    //Stack dolu mu kontrol
    STACK_NODE* temp;

    if((temp = (STACK_NODE*)malloc (sizeof(*(stack->top)))))
    {
        free(temp);
        return false;
    }
    return true;
}

int stackCount(STACK* stack)
{
    return stack->count;
    //Stackin count degerini yani icindeki dugum sayisini dondurduk
}

STACK* destroyStack(STACK* stack)
{
    if(stack)
    {
        STACK_NODE* temp;

        while(stack->top != NULL)
        {
            free(stack->top->dataPtr);
            temp = stack->top;

            stack->top = stack->top->link;
            free(temp);
        }
        free(stack);
    }
}

int main()
{


    return 0;
}
