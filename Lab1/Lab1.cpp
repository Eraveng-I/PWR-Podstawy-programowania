/*
Autor:  Iwan Tswigun
Grupa:  ŚR/P 18:00
Data:   28 października 2020 r.
Tytuł:  Program Lab1zaj
Notatka: Używam środowiska Microsoft Visual Studio bo Falcon pomimo instalacji w domyślnym folderze czasem wyrzuca błąd o braku kompilatora g++ i trzeba po kilka razy klikać żeby uruchomić nową kompilację
*/
#define _USE_MATH_DEFINES
#include <cmath>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;


void zadanie1()
{
    double a, b, c, delta, x1, x2;

    cout << "Podaj współczynniki a,b,c" << endl;
    cin >> a >> b >> c;

    if (a == 0)
    {
        cout << "Brak równania kwadratowego" << endl;
    }
    else
    {
        delta = b * b - 4 * a * c;
        if (delta < 0)
        {
            cout << "Brak pierwiastków rzeczywistych" << endl;
        }
        else
        {
            if (delta == 0)
            {
                x1 = x2 = 0 - b / (2 * a);


                cout << "x1=x2= " << x1 << endl;
            }
            else
            {
                if (delta > 0)
                {
                    x1 = (-b - sqrt(delta)) / (2 * a);
                    x2 = (-b + sqrt(delta)) / (2 * a);

                    cout << "x1= " << x1 << " x2= " << x2 << endl;
                }
            }
        }
    }
}

void zadanie2()
{
    int dzien, miesiac, rok;
    int zgodnosc = 1;

    cout << "Podaj datę dzień miesiąc rok" << endl;
    cin >> dzien >> miesiac >> rok;

    //sprawdzenie duzych miesiecy
    if (0 < dzien && dzien < 32 && 0 < miesiac && miesiac < 13)
    {
        //sprawdzenie malych miesiecy
        if ((miesiac == 4 || miesiac == 6 || miesiac == 9 || miesiac == 11) && dzien == 31)
        {
            zgodnosc = 0;
        }
        else
        {
            //sprawdzenie lutych przesteczych
            if (rok % 400 == 0 || (rok % 100 != 0 && rok % 4 == 0))
            {
                if (dzien > 29 && miesiac == 2)
                {
                    zgodnosc = 0;
                }
            }
            else
            {
                //sprawdzenie lutych zwyklych
                if (dzien > 28 && miesiac == 2)
                {
                    zgodnosc = 0;
                }
            }
        }
    }
    else
    {
        zgodnosc = 0;
    }

    //ostateczna odpowiedz
    if (zgodnosc == 0)
    {
        cout << "Nieprawidłowa data" << endl;
    }
    else
    {
        cout << "Prawidłowa data" << endl;
    }
}

void zadanie3()
{
    float promienmaly, promienduzy, roznica, r, obwod, pole, promienfaktyczny;
    int ilosc;

    printf("Podaj minimalny promień: ");
    scanf_s("%f", &promienmaly);

    printf("Podaj maksymalny promień: ");
    scanf_s("%f", &promienduzy);

    printf("Podaj liczbę wierszy: ");
    scanf_s("%d", &ilosc);

    roznica = (promienduzy - promienmaly) / (ilosc - 1);

    printf("\n");

    for (int i = 0; i < 45; i++)
    {
        printf("=");
    }

    printf("\n");

    printf("|  Lp  | promień  | obwód koła | pole koła | \n");

    for (int i = 0; i < 45; i++)
    {
        printf("=");
    }

    printf("\n");

    for (int i = 1; i < ilosc + 1; i++)
    {
        promienfaktyczny = promienmaly + (i - 1) * roznica;
        obwod = 2 * promienfaktyczny * M_PI;
        pole = M_PI * promienfaktyczny * promienfaktyczny;

        printf("| %4d | %f | %10f | %f | \n", i, promienfaktyczny, obwod, pole);
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
        cout << "Wybierz numer funkcji do wywołania od 1 do 3, żeby zakończyć wybierz 0" << endl;
        cin >> wybor;
        if (wybor == 1)
        {
            zadanie1();
        }
        else
        {
            if (wybor == 2)
            {
                zadanie2();
            }
            else
            {
                if (wybor == 3)
                {
                    zadanie3();
                }
                else
                {
                    if (wybor == 0)
                    {
                        break;
                    }
                }
            }
        }
    }

}
