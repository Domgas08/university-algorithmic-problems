#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include <math.h>
const int skir = 'A' - 10;   //skirtumas tarp ascii koduotes ir kad 'A' reprezentuotu skaiciu 10

int main()
{
    printf("Si programa konvertuoja is skaiciavimo sistemos x, i skaiciavimo sistema y. x ir y yra jusu pasirenkmieji skaiciai.\n");
    int x, y;
    printf("Pasirinkite sistema x: ");
    scanf("%d", &x);
    printf("Pasirinkite sistema y: ");
    scanf("%d", &y);

    char skx[999], sky[999];        //skaicius x sistemoj, skaicius y sistemoj
    printf("Koks skaicius turi but konvertuojamas?\n");
    scanf("%s", &skx);


    if(x < 2 || x > 37 || y < 2 || y > 37)
    {
        printf("Netinka x arba y sistemos");
        return 0;
    }


    if(skx == 0)    //jeigu 0
    {
        printf("Konvertuotas skaicius i y sistema: 0");
        return 0;
    }

    int paskid = strlen(skx) - 1;   //paskutinio skaitmens indeksas

    long sk10 = 0;
    int laipsnis = 0;

    while(paskid >= 0)//pavercia i desimtaine sistema
    {
        int skait;      //skaitmuo
        if(!isdigit(skx[paskid]))
        {
            skait = skx[paskid] - skir;
        }
        else skait = skx[paskid] - '0';


        sk10 += skait * (int)pow(x, laipsnis);
        paskid--;
        laipsnis++;

    }

    ///printf("%d\n", sk10);            //isspausdintu 10tainej sistemojj skaiciu
    laipsnis = 0;

    while(sk10 > 0)
    {

        if(sk10 % y <= 9)
        {
            sky[laipsnis] = (sk10 % y) + '0';
        }
        else
        {
            sky[laipsnis] = (sk10 % y) + skir;
        }
        sk10 /= y;
        laipsnis++;
    }
    printf("Konvertuotas skaicius i y sistema:\n");
    for(int i = laipsnis-1; i >= 0; i--)
    {
        printf("%c", sky[i]);
    }




    return 0;
}
