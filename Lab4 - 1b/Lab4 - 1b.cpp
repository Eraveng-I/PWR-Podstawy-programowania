/*
Autor:  Iwan Tswigun
Grupa:  ŚR/P 18:00
Data:   9 grudnia 2020 r.
Tytuł:  Program Lab4 1b
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

using namespace std;

void CzytajRownanie(float* a, float* b, float* c);

void WypiszRozwiązanie(int N, float x, float y);

float ObliczWyznacznik(float p1, float p2, float p3, float p4);

int ObliczRozwiązanie(float a1, float b1, float c1, float a2, float b2, float c2, float* x, float* y);


int main()
{
    setlocale(LC_CTYPE, "Polish");

    // OBOWIĄZKOWY wydruk danych autora
    cout << "Autor: Iwan Tswigun (ŚR/P 18:00) " << endl << endl;

    float A1, B1, C1; // pierwsze równanie,
    float A2, B2, C2; // drugie równanie,
    float X, Y; // rozwiązanie,
    int N; // liczba rozwiazan.
    

    CzytajRownanie(&A1, &B1, &C1);
    CzytajRownanie(&A2, &B2, &C2);
    N = ObliczRozwiązanie(A1, B1, C1, A2, B2, C2, &X, &Y);
    WypiszRozwiązanie(N, X, Y);
    //   getch();

    return 0;
}

void CzytajRownanie(float* a, float* b, float* c)
{
    cout << "Podaj współczynniki równania Ax + By = C" << endl;
    cin >> *a;
    cin >> *b;
    cin >> *c;
}

int ObliczRozwiązanie(float a1, float b1, float c1, float a2, float b2, float c2, float* x, float* y)
{
    float W, Wx, Wy;

    W = ObliczWyznacznik(a1, b2, a2, b1);
    Wx = ObliczWyznacznik(c1, b2, c2, b1);
    Wy = ObliczWyznacznik(a1, c2, a2, c1);

    if (W != 0)
    {
        *x = (Wx / W);
        *y = (Wy / W);

        return 1;
    }
    else
    {
        if (Wx == 0 && Wy == 0)
        {
            return 2;
        }
        else
        {
            if (Wx != 0 && Wy != 0)
            {
                return 0;
            }
        }
    }
}

float ObliczWyznacznik(float p1, float p2, float p3, float p4)
{
    float wyznacznik;

    wyznacznik = p1 * p2 - p3 * p4;

    return wyznacznik;
}

void WypiszRozwiązanie(int N, float x, float y)
{
    if (N == 0)
    {
        cout << "Brak rozwiązań(układ sprzeczny)" << endl;
    }
    else
    {
        if (N == 1)
        {
            cout << "Jest jedno rozwiązanie: x = " << x << " y = " << y << endl;
        }
        else
        {
            cout << "Jest nieskończenie dużo rozwiązań " << endl;
        }
    }
}