/*
Autor:  Iwan Tswigun
Grupa:  ŚR/P 18:00
Data:   15 stycznia 2021 r.
Tytuł:  Program Lab6
Notatka: Używam środowiska Microsoft Visual Studio bo Falcon pomimo instalacji w domyślnym folderze czasem wyrzuca błąd o braku kompilatora g++ i trzeba po kilka razy klikać żeby uruchomić nową kompilację
*/

#include <stdio.h>
#include <iostream>

using namespace std;

struct Towar
{
    char nazwa[20];
    float cena;
    int ilosc;
};



void UtworzenieTablicy(Towar*& Tab, int &Rozmiar);

void WypisanieTowarow(Towar* Tab, int Rozmiar);

void DodajTowar(Towar*& Tab, int& Rozmiar);

void UsunTowar(Towar*& Tab, int& Rozmiar);

void UsunListe(Towar*& Tab, int& Rozmiar);

int main()
{
    setlocale(LC_CTYPE, "Polish");

    // OBOWIĄZKOWY wydruk danych autora
    cout << "Autor: Iwan Tswigun (ŚR/P 18:00) " << endl << endl;

    Towar* Tab = NULL;

    int Rozmiar = 0;

    int wybor;

    for (;;)
    {
        {
            cout << "Wybierz numer funkcji do wywołania od 1 do 7, żeby zakończyć wybierz 0" << endl;
            cout << "1 - utworzenie nowej listy" << endl;
            cout << "2 - wypisanie wszystkich towarów" << endl;
            cout << "3 - dodanie nowego towaru" << endl;
            cout << "4 - usunięcie towaru o wskazanym numerze" << endl;
            cout << "5 - usunięcie całej listy" << endl;
        }

        cin >> wybor;

        switch (wybor)
        {
        case 1: UtworzenieTablicy(Tab, Rozmiar); break;

        case 2: WypisanieTowarow(Tab, Rozmiar); break;

        case 3: DodajTowar(Tab, Rozmiar); break;
        
        case 4: UsunTowar(Tab, Rozmiar); break;
        
        case 5: UsunListe(Tab, Rozmiar); break;

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

void UtworzenieTablicy(Towar*& Tab, int &Rozmiar)
{
    if (Tab != NULL)
    {
        free(Tab);
    }

    cout << "Podaj rozmiar tworzonej listy" << endl;
    cin >> Rozmiar;

    Tab = (Towar*)malloc((Rozmiar ) * (sizeof(Towar)));

    //cout << "Nazwa    Cena jednostkowa    Ilość" << endl;

    for (int i = 0; i < Rozmiar; i++)
    {
        cout << "Podaj nazwę "<<i+1<<" towaru" << endl;
        cin.getline(Tab[i].nazwa, sizeof(Tab[i].nazwa));//zuzycie entera przy rozmiarze
        cin.getline(Tab[i].nazwa, sizeof(Tab[i].nazwa));
        cout<<"Podaj cenę " << i + 1 << " towaru" <<endl;
        cin >> Tab[i].cena;
        cout << "Podaj ilość " << i + 1 << " towaru" << endl;
        cin >> Tab[i].ilosc;
    }
}

void WypisanieTowarow(Towar* Tab, int Rozmiar)
{
    if (Tab == NULL)
    {
        cout << "Nie ma utworzonej listy" << endl;
        return;
    }

    int licznik = 0;
    int licznik2 = 0;
    float suma;

    cout << "       Nazwa        | Cena jednostkowa | Ilość" << endl;

    for (int i = 0; i <Rozmiar; i++)
    {
        //cout << Tab[i].nazwa[19] << endl;
        cout << Tab[i].nazwa;

        for (int j = 0; Tab[i].nazwa[j]!=NULL; j++)
        {
            licznik = licznik + 1;
        }

        for (int j = 0; j < sizeof(Tab[i].nazwa) - (1+licznik); j++)
        {
            cout << " ";
        }
            
        cout << " | " << Tab[i].cena;

        suma = ((int)(Tab[i].cena * 100));
        suma = suma / 100.0;

        for (  ; suma>0; )
        {
            if (suma>(int)suma)
            {
                suma = suma * 10;
                licznik2 = 1;
            }
            else
                {
                    licznik2 = licznik2 + 1;
                    suma = (int)(suma / 10);
                }
        }

        for (int j = 0; j < 16 - licznik2; j++)
        {
            cout << " ";
        }

        cout << " | " << Tab[i].ilosc << endl;

        licznik = 0;
        licznik2 = 0;
    }
}

void DodajTowar(Towar* &Tab, int& Rozmiar)
{
    //Towar* NowaLista;
    Tab = (Towar*)realloc(Tab, (Rozmiar + 1) * (sizeof(Towar)));
    //Tab = NowaLista;

    cout << "Podaj nazwę " << Rozmiar + 1 << " towaru" << endl;
    cin.getline(Tab[Rozmiar].nazwa, sizeof(Tab[Rozmiar].nazwa));//zuzycie entera przy rozmiarze
    cin.getline(Tab[Rozmiar].nazwa, sizeof(Tab[Rozmiar].nazwa));
    cout << "Podaj cenę " << Rozmiar + 1 << " towaru" << endl;
    cin >> Tab[Rozmiar].cena;
    cout << "Podaj ilość " << Rozmiar + 1 << " towaru" << endl;
    cin >> Tab[Rozmiar].ilosc;

    Rozmiar = Rozmiar + 1;
}

void UsunTowar(Towar* &Tab, int& Rozmiar)
{
    if (Tab == NULL)
    {
        cout << "Nie ma utworzonej listy" << endl;
        return;
    }

    int numer;

    cout << "Podaj numer towaru który chcesz usunąć:" << endl;
    cin >> numer;

    if (numer > Rozmiar || numer <= 0)
    {
        cout << "Nieprawidłowy numer" << endl;
        return;
    }

    for (int i = numer-1; i < Rozmiar-1; i++)
    {
        Tab[i] = Tab[i + 1];
    }

    if (numer == 1 && Rozmiar==1)
    {
        free(Tab);
        Tab = NULL;
        Rozmiar = 0;
        return;
    }

    Tab = (Towar*)realloc(Tab, (Rozmiar - 1) * (sizeof(Towar)));
    Rozmiar = Rozmiar - 1;
}

void UsunListe(Towar* &Tab, int& Rozmiar)
{
    if (Tab == NULL)
    {
        cout << "Nie ma utworzonej listy" << endl;
        return;
    }

     free(Tab);
     Tab = NULL;
     Rozmiar = 0;
     return;
}
