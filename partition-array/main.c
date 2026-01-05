#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void cpyArray (bool a[], bool b[], int n)      //a reiksmes gaus b reiksmes. Kopijuoja masyva
{
    for(int i = 0; i < n; i++)
    {
        a[i] = b[i];

    }
}


void markAsBuvo(int sk, int mas[], bool buvo[], int n)  //surandam indeksa su reikiama reiksme ir pazymim kad jau toki panaudojom indeksa
{
    for(int i = 0; i < n; i++)
    {
        if(mas[i] == sk && buvo[i] == 0)
        {
            buvo[i] = 1;
            break;
        }
    }
}
void printKelias(int kel[], int suma, bool buvo[], int n, int mas[])       //ispspausdina 'kelia' kuriuo turim eit kad gaut suma
{
    while(suma != 0)
    {
        printf("%d ", suma - kel[suma]);
        markAsBuvo(suma-kel[suma], mas, buvo, n);
        suma = kel[suma];
    }
}


int main()
{
    printf("Nurodykite kokia suma tures gaut programa pasirinkus atitinkamus masyvo elementus\n");

    printf("Kiek bus masyvo elementu: ");
    int n;
    scanf("%d", &n);

    int mas[n];

    printf("surasykite masyvo elementus\n");
    int suma = 0;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &mas[i]);
        suma += mas[i];
    }


    int kelias[suma+1];     //kelias kuriuo reikia eit kad pasiekt norima suma (backtrackinimui naudojamas)

    bool dp[suma+1];        //dinaminio programavimo masyvas. Jame 1 bus pazymeta kokias sumas galime sudaryt
    for(int i = 0; i < suma+1; i++)
    {
        dp[i] = 0;
        kelias[i] = 0;
    }
    dp[0] = 1;

    //------------imanomu sumu suradimas-----------------

    for(int k = 0; k < n; k++)
    {
        int pridet = mas[k];
        bool ndp[suma+1];   //naujas dinaminio programavimo masyvas (kad reiksmes nesiduplikuotu

        cpyArray(ndp, dp, suma+1);


        for(int i = 0; i < suma+1; i++)
        {
            if(dp[i] == 1 && i+pridet <= suma && dp[i+pridet] == 0)
            {
                kelias[i+pridet] = i;
                ndp[i+pridet] = 1;
            }
        }

        cpyArray(dp, ndp, suma+1);
    }



    //------------spausdinimas--------------


    printf("Suskirstyti demenys:\n");

    for(int i = suma / 2; i <= suma; i++)   //ieskom kuo arciau vidurio
    {
        if(dp[i] == 1 && dp[suma - i] == 1)
        {
            bool buvo[n];   //saugo kokie indeksai jau  buvo panaudoti skaiciuojant pirma puse

            for(int j = 0; j < n; j++) buvo[j] = 0;


            printKelias(kelias, i, buvo, n, mas);

            printf("\n----------------------\n");

            for(int k = 0; k < n; k++)
            {
                if(buvo[k] == 0) printf("%d ", mas[k]); //isspausdinam tuos skaicius kurie nebuvo panaudoti pirmai pusei (reiskia jie sudaro antra puse)
            }
            break;
        }
    }

    return 0;
}
