#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include<time.h>

#define MAX_TRIES 7

using namespace std;

ifstream fin("cuvinte.in");


char cuv[20];
char de_ghicit[20];
char incercare[10];
char * caut;
char folosite[10];
int folosit_nr = 0;
int incercari = 0;

void init(){
    char cit[100][20];
    for(int i = 0; i < 100; i++){
        fin >> cit[i];
    }

    srand(time(0));
    int i = rand()%100;

    strcpy(cuv, cit[i]);
    memset(de_ghicit, '*', strlen(cuv));
}

void start(){
    cout << "\n\n";
    cout << "Bine ai venit! \n";
}

void win(){
    cout << "\n\n";
    cout << "Bravo! \n";
    cout << "Cuvantul era " << de_ghicit;
    cout << "\n";
    exit(0);
}

void lose(){
    cout << "\n\n";
    cout << "Ai pierdut!\n";
    cout << "Cuvantul era " << cuv;
    cout << "\n";
    exit(-1);
}

void citire(){
    cout << "\n";
    cout << "Alege o litera: ";
    cin >> incercare;
    if(strlen(incercare)>1){
        cout << "\n";
        cout << "Ai introdus mai mult de o litera!";
        citire();
    }
}

void fill_char(){
    while(caut){
        de_ghicit[strlen(cuv)-strlen(caut)] = incercare[0];
        caut = strchr(caut+1, incercare[0]);
    }
}

void afisare(){
    cout << "\n\n";
    cout << "Pana acum cuvantul este: " << de_ghicit << "\n";
    cout << "Mai ai " << MAX_TRIES - incercari << " incercari! \n";
    cout << "Literele deja folosite sunt: " << folosite << "\n";
}

int main()
{
    init();
    cout << de_ghicit;
    start();
    while(incercari < MAX_TRIES){
        citire();
        caut = strchr(cuv, incercare[0]);
        if(caut){
            fill_char();
            if(strcmp(cuv, de_ghicit) == 0){
                win();
            }
            cout << "\n\n";
            cout << "Litera corecta!";
        } else {
            if(strchr(folosite, incercare[0])){
                cout << "\n\n";
                cout << "Litera deja folosita!";
            } else {
                cout << "\n\n";
                cout << "Litera gresita!";
                incercari++;
                folosite[folosit_nr++] = incercare[0];
            }
        }

        afisare();
    }

    lose();
}
