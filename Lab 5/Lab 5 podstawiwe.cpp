/*
Autor:  Iwan Tswigun
Grupa:  ŚR/P 18:00
Data:   28 grudnia 2020 r.
Tytuł:  Program Lab5
Notatka: Używam środowiska Microsoft Visual Studio bo Falcon pomimo instalacji w domyślnym folderze czasem wyrzuca błąd o braku kompilatora g++ i trzeba po kilka razy klikać żeby uruchomić nową kompilację
*/

#include <stdio.h>
#include <iostream>

using namespace std;


    // Inicjalizacja dynamicznej tablicy dwuwymiarowej.
    // Funkcję należy wywołać na początku programu.
    void InicjacjaTablicy(char**& wskaznik);

    // Dodawanie nowego imienia do tablicy dynamiczne.j
    void DodajImie(char* buf, char**& wskaznik, int d);

    // Usuwanie imienia znajdującego się w tablicy na pozycji nr,
    void UsuniecieIndeksu(int ktory, char**& wskaznik);

    //Usuwanie z tablicy imienia, wprowadzonego z klawiatury
    void UsuniecieImienia(char* buf, char**& wskaznik, int d);

    // drukowanie na ekranie wszystkich imion
    void WypiszWszystkieImiona(char** wskaznik);

    // drukowanie na ekranie imion rozpoczynających wskazaną literą
    void WypiszLitere(char pierwszalitera, char** wskaznik);

    // sortowanie imion zawartych w tablicy według alfabetu
    void SortowanieAlfabetyczne(char** wskaznik);

    // sortowanie imion zawartych w tablicy według długości
    void SortowanieDlugosci(char** wskaznik);

int main()
{
	setlocale(LC_CTYPE, "Polish");

	// OBOWIĄZKOWY wydruk danych autora
	cout << "Autor: Iwan Tswigun (ŚR/P 18:00) " << endl << endl;

    //int** wskaznik;
	char*(*(wskaznik));			// wskaźnik na dwuwymiarową tablice dynamiczną
								// w której będą pamiętane wszystkie imiona.
	char bufor[81];				// bufor na dane wczytywane z klawiatury
    char litera;
    int dlugosc = sizeof(bufor) / sizeof(bufor[0]);
    int numer;

    int wybor;

	InicjacjaTablicy(wskaznik);			// Inicjalizacja tablicy dynamicznej
								        // implementacja menu, w którym będą wywoływane
								        // funkcje wykonujące operacje na tablicy dynamicznej

    for (;;)
    {
        {
            cout << "Wybierz numer funkcji do wywołania od 1 do 5, żeby zakończyć wybierz 0" << endl;
            cout << "1 - dodanie imienia z klawiatury" << endl;
            cout << "2 - wypisanie wszystkich imion" << endl;
            cout << "3 - wypisanie imion na podaną literę" << endl;
            cout << "4 - usunięcie imienia z wskazanym indeksem" << endl;
            cout << "5 - usunięcie wskazanego imienia" << endl;
            cout << "6 - sortowanie alfabetyczne" << endl;
            cout << "7 - sortowanie według ilości znaków" << endl;
        }

        cin >> wybor;

        switch (wybor)
        {
        case 1: DodajImie(bufor, wskaznik, dlugosc); break;

        case 2: WypiszWszystkieImiona(wskaznik); break;

        case 3:
        {
            cout << "Wpisz literę na jaką mają się zaczynać wypisane słowa" << endl;

            cin >> litera;

            WypiszLitere(litera, wskaznik);

            break;
        }

        case 4: 
        {
            cout << "Podaj numer indeksu jaki chcesz usunąć" << endl;

            cin >> numer;

            UsuniecieIndeksu(numer, wskaznik);

            break;
        }
        case 5: UsuniecieImienia(bufor, wskaznik, dlugosc); break;

        case 6: SortowanieAlfabetyczne(wskaznik); break;

        case 7: SortowanieDlugosci(wskaznik); break;

        case 0: break;
        }

        if (wybor == 0)
        {
            cout << "Koniec programu" << endl;

            break;
        }
    }
        
    free(wskaznik);
	return 0;
}

void InicjacjaTablicy(char **& wskaznik)
{
    wskaznik = (char**)malloc(sizeof(char*));
    wskaznik[0] = NULL;
}

void DodajImie(char* buf, char**& wskaznik, int d)
{
    int pozycja = 0;

    cin.getline(buf, sizeof(buf)); // zuzycie entera przy wyborze

    cout << "Podaj imię jakie chcesz dodać" << endl;
    
    cin.getline(buf, d);

    for (; wskaznik[pozycja] != NULL; pozycja++)
    {

    }

    wskaznik = (char**)realloc(wskaznik, (pozycja + 2) * sizeof(char*));

    wskaznik[pozycja] = _strdup( buf);

    wskaznik[pozycja + 1] = NULL;
}

void WypiszWszystkieImiona(char** wskaznik)
{
    cout << "Imiona w tablicy to:" << endl;

    for (int i = 0; wskaznik[i] != NULL; i++)
    {
        cout << "Tab[" << i << "] = ";

        for (int l = 0; wskaznik[i][l] != NULL; l++)
        {
            cout << wskaznik[i][l];
        }
        
        //cout << " - adres - " << (void*)wskaznik[i];      //sprawdzenie poprawnosci zmiany wskazywanego adresu
        cout << endl;
    }
}

void WypiszLitere(char pierwszalitera, char** wskaznik)
{
    cout << "Imiona w tablicy na literę "<<pierwszalitera<<" to:" << endl;

    for (int i = 0; wskaznik[i] != NULL; i++)
    {
        if (wskaznik[i][0] == pierwszalitera)
        {
            cout << "Tab[" << i << "] = ";

            for (int l = 0; wskaznik[i][l] != NULL; l++)
            {
                cout << wskaznik[i][l];
            }

            cout << endl;
        }        
    }
}

void UsuniecieIndeksu(int ktory, char**& wskaznik)
{
    int pozycja = 0;

    for (; wskaznik[pozycja] != NULL; pozycja++)
    {

    }

    if (ktory >= pozycja || ktory < 0)
    {
        cout << "Nieprawidłowy numer indeksu" << endl;
        return;
    }

    free(wskaznik[ktory]);  //czy potrzebne?
    
    for (int i = ktory; i < pozycja; i++)
    {
        wskaznik[i] = wskaznik[i + 1];
    }

    wskaznik = (char**)realloc(wskaznik, (pozycja) * sizeof(char*));
}

void UsuniecieImienia(char* buf, char**& wskaznik, int d)
{
    cin.getline(buf, sizeof(buf)); // zuzycie entera przy wyborze

    cout << "Podaj imię jakie chcesz usunąć" << endl;

    cin.getline(buf, d);

    for (int i=0; wskaznik[i] != NULL;)
    {
        if (strcmp(wskaznik[i], buf) == 0)
        {
            UsuniecieIndeksu(i, wskaznik);
        }
        else
            {
                i = i + 1;
            }
    }
}

void SortowanieAlfabetyczne(char** wskaznik)
{
    char* zamiennik;

    for (int i=0; wskaznik[i] != NULL;i++)
    {
        for (int j = 0; wskaznik[j+1] != NULL; j++)
        {
            if (strcmp(wskaznik[j], wskaznik[j+1]) > 0)
            {
                zamiennik = wskaznik[j];
                wskaznik[j] = wskaznik[j + 1];
                wskaznik[j + 1] = zamiennik;
            }
        }
    }
}

void SortowanieDlugosci(char** wskaznik)
{
    char* zamiennik;

    for (int i = 0; wskaznik[i] != NULL; i++)
    {
        for (int j = 0; wskaznik[j + 1] != NULL; j++)
        {
            if (strlen(wskaznik[j]) > strlen(wskaznik[j+1]))
            {
                zamiennik = wskaznik[j];
                wskaznik[j] = wskaznik[j + 1];
                wskaznik[j + 1] = zamiennik;
            }
        }
    }
}