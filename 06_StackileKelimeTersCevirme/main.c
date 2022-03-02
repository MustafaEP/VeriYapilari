#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOYUT 50


char kelime[BOYUT];
char kelimeStack[BOYUT];

int top = -1;

bool doluMu() //dizinin dolu olup olmadigi kontrol edildi
{
    if(top >= 49)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool bosMu() //dizinin  bos olup olmadigi kontrol edildi
{
    if(top <=-1)
        return true;
    else
        return false;
}

void push(char a)
{
    bool dolu = doluMu();//dizinin dolu olup olmadigi kontrol edildi
    if(dolu == false)//bos ise
    {
        top = top + 1; //-1 olan ilk degerimizi 0 yaptýk
        kelimeStack[top] =  a;
    }
    else
    {
        printf("\nStackoverflow..."); //dizi doluysa hata donderdi
        return;
    }
}
char pop()
{
    bool bos = bosMu();
    if(bos == true)
    {
        return 0;
    }
    else
    {
        if(bosMu() == true)
            return 0;
        else
        {
            char a = kelimeStack[top];
            top--;
            return a;
        }
}
}



int main()
{
    printf("Bir Kelime girin:\n");
    scanf("%s", kelime);

    for(int i = 0; i<strlen(kelime); i++)
    {
        push(kelime[i]);
    }

    for(int i = 0; i<strlen(kelime); i++)
    {
        kelime[i] = pop();
    }
    /*
        2. for dongusunde pop fonksiyonunu calistiriyoruz ve her seferinde
        kelimestackin son degerini kelime dizisinin ilk elemanýna esitliyoruz
    */

    printf("Ters cevirilen kelime: %s\n ", kelime);
    return 0;
}
