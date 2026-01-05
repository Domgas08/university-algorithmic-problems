#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QSortProcess(int *a, int st, int fn)
{

    if(st >= fn) return;
    int piv = (fn+st)/2;



    //sortinam pirma / vidurini / paskutini
    if (a[st] > a[piv])
    {
        int t = a[st];
        a[st] = a[piv];
        a[piv] = t;
    }
    if (a[piv] > a[fn])
    {
        int t = a[piv];
        a[piv] = a[fn];
        a[fn] = t;
    }
    if (a[st] > a[piv])
    {
        int t = a[st];
        a[st] = a[piv];
        a[piv] = t;
    }

    int t = a[fn-1];
    a[fn-1] = a[piv];
    a[piv] = t;
    piv = fn-1;


    int i = st, j = fn-1;
    while(j > i)
    {
        while (a[i] <= a[piv] && i < piv)
        {
            ++i;
        }
        while(a[j] >= a[piv] && j > st)
        {
            --j;
        }


        if(i > j)
        {

            t = a[i];
            a[i] = a[piv];
            a[piv] = t;
            piv = i;
            break;
        }
        t = a[j];
        a[j] = a[i];
        a[i] = t;

    }

    QSortProcess(a, st, piv-1);
    QSortProcess(a, piv+1, fn);

}



int Qsort(int a[], int n)
{

    QSortProcess(a, 0, n-1);

}



int main()
{

    int a[] = {4, 5, 8, 1, 90, 80, 70};     //pavyzdinis testas
    Qsort(a, 5);                            //i funkcija paduoti masyva ,   kiek elementu norime rikiuoti nuo masyvo pradzios


    return 0;
}
