#include <iostream>
#include <fstream>

using namespace std;

int litera(char znak){
    //Funkcja ktora zwraca:
    //0 jesli litera jest mala
    //1 jesli litera jest duza
    //2 jesli znak nie jest litera
    if(znak >= 'a' && znak <= 'z') return 0;
    else if(znak >= 'A' && znak <= 'Z') return 1;
    else return 2;
}

string szyfruj(int cyfra, string linia){
    //Funkcja ktora zwraca zaszyfrowana linie
    char z;
    char a;
    for(int i = 0; i < linia.length(); i++){
        if(litera(linia[i]) == 0){
            z = 'z';
            a = 'a';
            if(linia[i] + cyfra <= z && linia[i] + cyfra >= a){
            linia[i] = linia[i] + cyfra;
            }
            else if(linia[i] + cyfra < a){
                linia[i] = (linia[i] + 26) + cyfra;
            }
            else{
                linia[i] = (linia[i] - 26) + cyfra;
            }
        }
        else if(litera(linia[i]) == 1){
            z = 'Z';
            a = 'A';
            if(linia[i] + cyfra <= z && linia[i] + cyfra >= a){
                linia[i] = linia[i] + cyfra;
            }
            else if(linia[i] + cyfra < a){
                linia[i] = (linia[i] + 26) + cyfra;
            }
            else{
                linia[i] = (linia[i] - 26) + cyfra;
            }
        }
    }
    return linia;
}

int main()
{
    fstream szyfr;
    szyfr.open("szyfr.txt", ios::in);
    //Szyfrowanie
    if(szyfr.good()){
        string linia;
        fstream zaszyfr;
        zaszyfr.open("zaszyfr.txt", ios::out);
        //Liczba przesuniecia
        int cyfra;
        cout << "O ile chcesz szyfrowac: ";
        cin >> cyfra;
        while(getline(szyfr, linia)){
            zaszyfr << szyfruj(cyfra, linia) << endl;
        }
        szyfr.close();
        zaszyfr.close();
    }
    else{
        printf("Plik nie istnieje");
    }
    return 0;
}
