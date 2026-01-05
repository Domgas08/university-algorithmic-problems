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

void printKelias(int kel[], int suma)       //ispspausdina 'kelia' kuriuo turim eit kad gaut suma
{
    while(suma != 0)
    {
        printf("%d ", suma - kel[suma]);
        suma = kel[suma];
    }
}


int main()
{
    printf("Nurodykite kokia suma tures gaut programa pasirinkus atitinkamus masyvo elementus\n");
    int suma;
    scanf("%d", &suma);


    printf("Kiek bus masyvo elementu: ");
    int n;
    scanf("%d", &n);

    int mas[n];

    printf("surasykite masyvo elementus\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &mas[i]);
    }


    int kelias[suma+1];     //kelias kuriuo reikia eit kad pasiekt norima suma (backtrackinimui naudojamas)

    bool dp[suma+1];        //dinaminio programavimo masyvas. Jame 1 bus pazymeta kokias sumas galime sudaryt
    for(int i = 0; i < suma+1; i++)
    {
        dp[i] = 0;
        kelias[i] = 0;
    }
    dp[0] = 1;


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


    if(dp[suma] == 0) printf("Neimanoma sudaryt tokios sumos");
    else
    {
        printf("Sumos demenys: ");
        printKelias(kelias, suma);
    }





    return 0;
}
