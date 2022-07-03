/*
Autor:  Iwan Tswigun
Grupa:  ŚR/P 18:00
Data:   28 października 2020 r.
Tytuł:  Program Lab3
Notatka: Używam środowiska Microsoft Visual Studio bo Falcon pomimo instalacji w domyślnym folderze czasem wyrzuca błąd o braku kompilatora g++ i trzeba po kilka razy klikać żeby uruchomić nową kompilację
*/

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

#define ROZMIAR 5

float tablica[ROZMIAR];

void wczytanie(float tab[])
{
    cout << "Podaj wartości poszczególnych elementów tablicy" << endl;

    for (int i = 0; i < ROZMIAR; i++)
    {
        cout << "Tab[" << i << "]= ";
        cin >> tab[i];
    }
}

void wypisanie(float tab[])
{
    cout << fixed;
    cout << setprecision(1);
    cout << "Tab = [  ";

    for (int i = 0; i < ROZMIAR; i++)
    {
        cout << tab[i] << "  ";
    }

    cout << "]" << endl;
}

void przeliczanie(float tab[])
{
    int licznikdodatni = 0;
    int licznikujemny = 0;
    float sumadodatnia = 0;
    float sumaujemna = 0;
    float sredniadodatnia;
    float sredniaujemna;
    int sortowanierosnaco = 1;
    int sortowaniemalejaco = 1;

    for (int i = 0; i < ROZMIAR; i++)
    {
        if (tab[i] > 0)
        {
            licznikdodatni = licznikdodatni + 1;

            sumadodatnia = sumadodatnia + tab[i];
        }

        if (tab[i] < 0)
        {
            licznikujemny = licznikujemny + 1;

            sumaujemna = sumaujemna + tab[i];
        }

        if (i < ROZMIAR - 1)
        {
            //wykluczenie rosnącego
            if (tab[i] >= tab[i + 1])
            {
                sortowanierosnaco = 0;
            }

            //wykluczenie malejącego
            if (tab[i] <= tab[i + 1])
            {
                sortowaniemalejaco = 0;
            }
        }
    }

    sredniadodatnia = sumadodatnia / licznikdodatni;
    sredniaujemna = sumaujemna / licznikujemny;

    cout << "Ilość liczb dodatnich wynosi " << licznikdodatni << " a ujemnych " << licznikujemny << endl;
    cout << "Suma liczb dodatnich wynosi " << sumadodatnia << " a ujemnych " << sumaujemna << endl;

    if (licznikdodatni > 0)
    {
        cout << "Średnia liczb dodatnich wynosi " << sredniadodatnia<<endl;
    }

    if (licznikujemny > 0)
    {
        cout << "Średnia liczb ujemnych wynosi " << sredniaujemna<<endl;
    }

    if (sortowanierosnaco == 1)
    {
        cout << "Liczby w tablicy są uporządkowane rosnąco" << endl;
    }

    if (sortowaniemalejaco == 1)
    {
        cout << "Liczby w tablicy sa uporządkowane malejąco" << endl;
    }
}

void losowanie(float tab[])
{
    float min, max, losowa;

    cout << "Podaj wartość minimalną" << endl;

    cin >> min;

    cout << "Podaj wartość maksymalną" << endl;

    cin >> max;

    srand(time(NULL));

    for (int i = 0; i < ROZMIAR; i++)
    {
        losowa = min + (double)rand() / RAND_MAX * (max - min);

        tab[i] = losowa;
    }
}

void sortowanie(float tab[])
{
    float zamiennik;
    for (int i = 0; i < ROZMIAR-1; i++)
    {
        for (int j = 0; j < ROZMIAR - 1 ; j++)
        {
            if (tab[j ] > tab[j+1])
            {
                zamiennik = tab[j ];
                tab[j ] = tab[j+1];
                tab[j+1] = zamiennik;
            }
        }
    }
}

int main()
{
    setlocale(LC_CTYPE, "Polish");

    // OBOWIĄZKOWY wydruk danych autora
    cout << "Autor: Iwan Tswigun (ŚR/P 18:00) " << endl << endl;

    int wybor;

    for (;;)
    {
        cout << "Wybierz numer zadania do wywołania od 1 do 5, żeby zakończyć wybierz 0" << endl;
        cout << "1 - zadanie 1 - wczytanie elementów z klawiatury" << endl;
        cout << "2 - zadanie 1 - wypisanie elementów" << endl;
        cout << "3 - zadanie 1 - wypisanie komunikatów" << endl;
        cout << "4 - zadanie 2 - losowanie elementów" << endl;
        cout << "5 - zadanie 3 - sortowanie elementów" << endl;

        cin >> wybor;

        switch (wybor)
        {
            case 1: wczytanie(tablica); break;

            case 2: wypisanie(tablica); break;

            case 3: przeliczanie(tablica); break;

            case 4: losowanie(tablica); break;

            case 5: sortowanie(tablica); break;

            case 0: break;
        }

        if (wybor == 0)
        {
            cout << "Koniec programu" << endl;

            break;
        }
    }
}