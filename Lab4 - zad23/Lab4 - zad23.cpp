/*
Autor:  Iwan Tswigun
Grupa:  ŚR/P 18:00
Data:   9 grudnia 2020 r.
Tytuł:  Program Lab4
Notatka: Używam środowiska Microsoft Visual Studio bo Falcon pomimo instalacji w domyślnym folderze czasem wyrzuca błąd o braku kompilatora g++ i trzeba po kilka razy klikać żeby uruchomić nową kompilację
*/

#define _USE_MATH_DEFINES
#include <cmath>
#include <conio.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <string.h>

using namespace std;

int mojestrlen(const char* s);

int moje_strcompare(const char* tekst1, const char* tekst2);

char* moje_strcopy( char tekst_wyj[], char tekst_wej[]);

char* moje_strchar(const char* zakres, int znaczek);

/*void wczytanie(char tekst1[])
{
    cout << "Podaj tekst do 100 znaków na jakim chcesz operować" << endl;
    cin>>tekst1;
}*/

int main()
{
    setlocale(LC_CTYPE, "Polish");

    // OBOWIĄZKOWY wydruk danych autora
    cout << "Autor: Iwan Tswigun (ŚR/P 18:00) " << endl << endl;

    char tekst[100];
    char tekst2[100];
    int dlugosc;
    int wybor;
    char * pozycja;
    char znak;



    for (;;)
    {

        cout << "Wpisz 1 żeby wprowadzić tekst główny" << endl;
        cout << "Wpisz 2 żeby wypisać tekst" << endl;
        cout << "Wpisz 3 żeby zmierzyć długość tekstu za pomocą indeksu" << endl;
        cout << "Wpisz 4 żeby wprowadzić tekst porównawczy i porównać go z głównym za pomocą indeksu" << endl;
        cout << "Wpisz 5 żeby skopiować tekst główny do tekstu porównawczego za pomocą indeksu" << endl;
        cout << "Wpisz 6 żeby znaleźć kiedy po raz pierwszy pojawia się znak w tekście głównym za pomocą indeksu" << endl;

        cout << "Wpisz 0 żeby zakończyć" << endl;

        cin >> wybor;

        switch (wybor)
        {
        case 1: 

            cin.getline(tekst, sizeof(tekst)); // zuzycie entera przy wyborze

            cout << "Podaj tekst do 100 znaków na jakim chcesz operować" << endl;
            cin.getline(tekst,100);
            break;

        case 2: 
            for (int i=0; tekst[i]; i++)
            {
                cout << tekst[i];
            }

            cout << endl;
            
            break;

        case 3:
            dlugosc = mojestrlen(tekst);
            cout << "Długość tekstu to " << dlugosc << " znaków" << endl;
            break;

        case 4: 
            cin.getline(tekst2, sizeof(tekst2)); // zuzycie entera przy wyborze

            cout << "Podaj drugi tekst do 100 znaków na jakim chcesz operować" << endl;
            cin.getline(tekst2, 100);

            if (moje_strcompare(tekst, tekst2)==0)
            {
                cout << "Oba teksty są sobie równe" << endl;
            }
            else
                {
                    cout << "Te teksty nie są sobie równe" << endl;
                }
            
            break;

        case 5: 
            moje_strcopy(tekst2, tekst);

            cout << "Drugi tekst to teraz: ";

            for (int i = 0; tekst2[i]; i++)
            {
                cout << tekst2[i];
            }

            cout << endl;

            break;

        case 6:
            cout << "Podaj znak jaki chcesz znaleźć" << endl;
            cin >> znak;

            pozycja = moje_strchar(tekst, znak);

            cout << "Znak znaleziono na pozycji " << pozycja - tekst + 1 << endl;



            break;

//        case 5: sortowanie(tablica); break;

//        case 5: sortowanie(tablica); break;

//        case 5: sortowanie(tablica); break;

//        case 5: sortowanie(tablica); break;

        case 0: break;
        }

        if (wybor == 0)
        {
            cout << "Koniec programu" << endl;

            break;
        }

    }


    
    return 0;
}

int mojestrlen(const char* s)
{
    int i = 0;

    for (;s[i];i++)
    {

    }

    return i;
}

int moje_strcompare(const char* tekst1, const char* tekst2)
{
    int i = 0;

    for (;tekst1[i]==tekst2[i];i++)
    {
        if (tekst1[i+1] == '\0')
        {
            return 0;
        }
    }

    return(tekst1[i] - tekst2[i]);
}

char* moje_strcopy(char tekst_wyj[], char tekst_wej[])
{
    int i = 0;
    tekst_wyj[i] = tekst_wej[i];

    for (; tekst_wyj[i]  != '\0';i++)
    {
        tekst_wyj[i+1] = tekst_wej[i+1];
    }
        
    return(tekst_wyj);
}

char* moje_strchar(const char* zakres, int znaczek)
{
    char* pozycja;

    for (int i = 0; zakres[i] != '\0'; i++)
    {
        if (zakres[i] == znaczek)
        {
            pozycja = (char *) &zakres[i];
            return pozycja;
        }
    }

    return NULL;
}

