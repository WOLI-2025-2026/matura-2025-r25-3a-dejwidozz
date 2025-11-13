//Dawid Soltysiak 

#include <iostream>
#include <fstream>
#include <vector>

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


int main() 
{
    ifstream plik("../zalaczniki-2025/symbole.txt");
    if(!plik.is_open())
    {
        cerr << "nie mozna otworzyc pliku" << endl;
        return 1;
    }

    vector<string> linie;
    string linia; 