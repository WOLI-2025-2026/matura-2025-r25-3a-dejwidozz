//Dawid Soltysiak 

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <list>
#include <set>
#include <map>

using namespace std;

string z3_1_path_symbole_txt = "../zalaczniki-2025/symbole.txt";

bool czy_palindrom(string slowo)
{
    int dlugosc = slowo.length();
    for(int i = 0; i < dlugosc / 2; i++)
    {
        if(slowo[i] != slowo[dlugosc - i - 1])
        {
            return false;
        }
    }
    return true;
}

void zadanie2_1()
{
    ifstream plik(z3_1_path_symbole_txt);
    if(!plik.is_open())
    {
        cerr << "nie mozna otworzyc pliku" << endl;
    }

    ofstream wyniki("wynik2_1.txt");

    string linia;
    while(plik >> linia)
    {
        if (czy_palindrom(linia))
        {
            cout << linia << endl;
            wyniki << linia <<endl;
        }
    }

    plik.close();
    wyniki.close();
}

void zadanie2_3()
{
    ifstream plik(z3_1_path_symbole_txt);
    if(!plik.is_open())
    {
        cerr << "nie mozna otworzyc pliku" << endl;
        return;
    }

    ofstream wyniki("wynik2_3.txt");

    int max_dlugosc = 0;
    string max_ciag = "";
    string linia;

    while(plik >> linia)
    {
        int i = 0;
        while(i < linia.length())
        {
            int j = i;
            while(j < linia.length() && linia[j] == linia[i])
            {
                j++;
            }
            int dlugosc = j - i;
            if(dlugosc > max_dlugosc)
            {
                max_dlugosc = dlugosc;
                max_ciag = linia.substr(i, dlugosc);
            }
            i = j;
        }
    }

    cout << max_dlugosc << " " << max_ciag << endl;
    wyniki << max_dlugosc << " " << max_ciag << endl;

    plik.close();
    wyniki.close();
}

void zadanie2_4()
{
    ifstream plik(z3_1_path_symbole_txt);
    if(!plik.is_open())
    {
        cerr << "nie mozna otworzyc pliku" << endl;
        return;
    }

    ofstream wyniki("wynik2_4.txt");

    long long max_wartosc = 0;
    string max_ciag = "";
    string linia;

    while(plik >> linia)
    {
        int i = 0;
        while(i < linia.length())
        {
            set<char> znaki_uzyte;
            int j = i;
            while(j < linia.length() && znaki_uzyte.find(linia[j]) == znaki_uzyte.end())
            {
                znaki_uzyte.insert(linia[j]);
                j++;
            }
            string aktualny_ciag = linia.substr(i, j - i);
            
            long long wartosc = 0;
            map<char, int> znak_do_cyfry;
            int siguiente_cyfra = 0;
            
            for(char c : aktualny_ciag)
            {
                if(znak_do_cyfry.find(c) == znak_do_cyfry.end())
                {
                    znak_do_cyfry[c] = siguiente_cyfra;
                    siguiente_cyfra++;
                }
                wartosc = wartosc * 10 + znak_do_cyfry[c];
            }
            
            if(wartosc > max_wartosc)
            {
                max_wartosc = wartosc;
                max_ciag = aktualny_ciag;
            }
            
            i++;
        }
    }

    cout << max_wartosc << " " << max_ciag << endl;
    wyniki << max_wartosc << " " << max_ciag << endl;

    plik.close();
    wyniki.close();
}

void zadanie2_2()
{
    ifstream plik(z3_1_path_symbole_txt);
    if(!plik.is_open())
    {
        cerr << "nie mozna otworzyc pliku" << endl;
        return;
    }
    
    vector<string> wiersze;
    string linia;
    while(getline(plik, linia)){
        wiersze.push_back(linia);
    }
    plik.close();

    ofstream wynik("wynik2_2.txt");

    int liczba_wierszy = wiersze.size();
    int licznik_kwadratow = 0;

    string odp = "";

    for(int i = 1; i < liczba_wierszy - 1; i++){
        int dlugosc = wiersze[i].length();
        for(int j = 1; j < dlugosc - 1; j++){
            char znak = wiersze[i][j];

            bool kwadrat = true;
            for(int di = -1; di <= 1 && kwadrat; di++){
                for(int dj = -1; dj <= 1; dj++){
                    if(wiersze[i+di][j+dj] != znak){ kwadrat = false; break; }
                }
            }

            if(kwadrat){
                licznik_kwadratow++;
                odp += to_string(i+1) + " " + to_string(j+1) + " ";
            }
        }
    }

    cout << "Liczba kwadratow: " << licznik_kwadratow << endl;
    odp = to_string(licznik_kwadratow) + " " + odp;

    wynik << odp;

    wynik.close();
}


int main()

{
    zadanie2_1();
    zadanie2_2();
    zadanie2_4();
    zadanie2_3();
    return 0;
}
