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
    int wiersze;
    int kolumny;

    printf("Program drukuje tabliczkę mnożenia \n");
    printf("Podaj liczbę wierszy: ");
    scanf_s("%d", &wiersze);
    printf("Podaj liczbę kolumn: ");
    scanf_s("%d", &kolumny);
    printf("\n");


    printf("    |");

    for (int i = 1; i < kolumny + 1; i++)
    {
        printf("%4d", i);
    }

    printf("\n");

    for (int i = 0; i < 90; i++)
    {
        printf("=");
    }

    printf("\n");

    for (int w = 1; w < wiersze + 1; w++)
    {
        printf("%4d|", w);

        for (int k = 1; k < kolumny + 1; k++)
        {
            printf("%4d", k*w);
        }

        printf("\n");
    }

}

void zadanie2()
{
    unsigned long liczba;
    int suma = 0;

    cout << "Podaj liczbę całkowitą" << endl;
    cin >> liczba;

    for (;liczba != 0; liczba = liczba / 10)
    {
        suma = suma + liczba % 10; 
    }

    cout << "Suma cyfr w liczbie to " << suma << endl;
}

void zadanie3()
{
    int a, b, nwd, nww, z;

    cout << "Podaj 2 liczby całkowite" << endl;

    cin >> a>> b;
 //   cin >> b;

    //nww
    if (a > b)
    {
        z = a;
    }
    else
        {
            z = b;
        }

    for (nww=z;;nww=nww+z)
    {
        if (nww % a == 0 && nww % b == 0)
        {
            break;
        }
    }

    //nwd
    nwd = a * b / nww;

    cout << "NWD tych liczb to " << nwd << endl;
    cout << "NWW tych liczb to " << nww << endl;
}

void zadanie4()
{
    double eps, wyraz;
    double S1 = 0.00;
    double S2 = 1.00;

    cout << "Podaj (dodatnią) dokladność:" << endl;
    cin >> eps;

    wyraz = pow((-1), 2);

    for (int k = 1 ; fabs( wyraz)> eps ; k++)
    {
        wyraz = pow((-1), k + 1) * 1 / (2*k - 1);

        S1 = S1 + 4.0 *wyraz;
    }

    cout << "Suma pierwszego szeregu to: " << S1 << endl;

    wyraz = 1.00;

    for (int k = 1; fabs(wyraz) > eps; k++)
    {
        wyraz = wyraz / k;

        S2 = S2 + wyraz;
    }

    cout << "Suma pierwszego szeregu to: " << S2 << endl;
}

int main()
{
    setlocale(LC_CTYPE, "Polish");

    // OBOWIĄZKOWY wydruk danych autora
    cout << "Autor: Iwan Tswigun (ŚR/P 18:00) " << endl << endl;

    int wybor;

    for (;;)
    {
        cout << "Wybierz numer zadania do wywołania od 1 do 4, żeby zakończyć wybierz 0" << endl;
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
                                if (wybor == 4)
                                {
                                    zadanie4();
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





}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
