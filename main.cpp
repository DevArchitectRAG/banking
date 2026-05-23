#include <iostream>

using namespace std;

namespace gigel{
    int bani = 100;
    int pin = 2010;
    string fullname = "Gigel Marcel";
}

// Declarari functii
int depozitare();
int retragere();
int afisarebani();
int schimbarepin();

int main(){
    using namespace gigel;
    int optiune;
    cout << "Se verifica detaliile contului..." << endl;
    cout << "Bun venit " << fullname << "\nVa rog selectati una din optiunile de mai jos.\n1. Depozitare\n2. Retragere numerar\n3. Afisare suma de bani\n4. Schimbare pin\n";
    cin >> optiune;
    switch(optiune){
case 1:
    depozitare();
case 2:
    retragere();
case 3:
    afisarebani();
case 4:
    schimbarepin();
default:
    return 404;
    }
    return 0;
}

int reintoarcere(){
    char raspuns;
    cout << "Doriti sa va intoarceti inapoi?(Y/N): ";
    cin >> raspuns;
    if(raspuns == 'Y' || raspuns == 'y')
        main();
    else if(raspuns == 'N' || raspuns == 'n')
        return 1;
    else
        return 404;
    return 66;
}

bool logare(){
    using namespace gigel;
    int pinintrodus;
    cout << "Te rugam sa introduci pin-ul: ";
    cin >> pinintrodus;
    cout << "Se verifica pin-ul...\n";
    if(pinintrodus == pin)
        return true;
    else{
        cout << "Pin introdus gresit!\n";
        logare();}
    return 66;
}

int depozitare(){
    using namespace gigel;
    int suma;
    if(logare()){
        cout << "Suma care doriti sa o depozitati: ";
        cin >> suma;
        bani += suma;
        cout << "Bani au fost adaugati in cont!" << endl;
        reintoarcere();
        return 0;}
    else
        return 403;
}

int retragere(){
    using namespace gigel;
    int suma;
    if(logare()){
        cout << "Suma care doriti sa o retrageti: ";
        cin >> suma;
        bani -= suma;
        cout << "Bani au fost retrasi din cont!" << endl;
        reintoarcere();
        return 0;}
    else
        return 403;
}

int afisarebani(){
    using namespace gigel;
    if(logare()){
        cout << "Suma pe care o aveti in cont este: " << bani << endl;
        reintoarcere();
        return 0;}
    else
        return 403;
}

int schimbarepin(){
    using namespace gigel;
    int pinnou;
    if(logare()){
        cout << "Introduceti noul pin: ";
        cin >> pinnou;
        pin = pinnou;
        cout << "Pin schimbat cu succes!" << endl;
        reintoarcere();
        return 0;}
    else
        return 403;
}
