/*
Autor:  Iwan Tswigun
Grupa:  ŚR/P 18:00
Data:   28 października 2020 r.
Tytuł:  Program Lab3 zad 4
Notatka: Używam środowiska Microsoft Visual Studio bo Falcon pomimo instalacji w domyślnym folderze czasem wyrzuca błąd o braku kompilatora g++ i trzeba po kilka razy klikać żeby uruchomić nową kompilację
*/

#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

using namespace std;

#pragma warning(disable : 4996)

int main()
{
    setlocale(LC_CTYPE, "Polish");

    // OBOWIĄZKOWY wydruk danych autora
    cout << "Autor: Iwan Tswigun (ŚR/P 18:00) " << endl << endl;
/*
    int tablicaznakow[26] = { 0 };
    char znak;
    

    for (int i=0;i<27;i++)
    {
        znak = getch();

        if (znak == 27)
        {
            break;
        }
    }

    cout << znak << endl;
    */  

    int tablicaznakow[26] = { 0 };
    int licznik = 0;
    char znak;

    cout << "Podaj ciąg wyrazów"<<endl;


    for (;true;)
    {
        znak = getch(); //wczytywanie pojedynczych znaków do tablicy

        if (znak == 27)
        {
            break;
        }

        cout << znak;

        if (znak >= 97 && znak <= 122)
        {
            tablicaznakow[znak - 97]++;
        }
        
        if(znak >= 65 && znak <= 90)
        {
            tablicaznakow[znak - 65]++;
        }

        licznik++;
    }

    cout << endl;
    cout << "Wpisano " << licznik << " znaków" << endl;

    for (int j = 0; j < 26;j++)
    {
            znak = j +65;
            cout << "Litera " << znak << " " << tablicaznakow[j] << " ";

            for(int k = 0; k < tablicaznakow[j];k++ )
            {
                cout << "#";
            }

            cout << endl;
    }

    return 0;
}