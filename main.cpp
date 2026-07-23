#include <iostream>

namespace gigel{
    int bani = 100;
    int pin = 1234;
    std::string fullname = "Gigel Marcel";
}

// Declarari functii
int depozitare();
int retragere();
int afisarebani();
int schimbarepin();

int main(){
    using namespace gigel;
    int optiune;
    std::cout << "Se verifica detaliile contului...\n";
    std::cout << "Bun venit " << fullname << "\nVa rog selectati una din optiunile de mai jos.\n1. Depozitare\n2. Retragere numerar\n3. Afisare suma de bani\n4. Schimbare pin\n" << std::endl;
    std::cin >> optiune;
    switch(optiune){
case 1:
    depozitare();
    break;
case 2:
    retragere();
    break;
case 3:
    afisarebani();
    break;
case 4:
    schimbarepin();
    break;
default:
    return 404;
    }
    return 0;
}

int reintoarcere(){
    char raspuns;
    std::cout << "Doriti sa va intoarceti inapoi?(Y/N): ";
    std::cin >> raspuns;
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
    std::cout << "Te rugam sa introduci pin-ul: ";
    std::cin >> pinintrodus;
    std::cout << "Se verifica pin-ul...\n";
    if(pinintrodus == pin)
        return true;
    else{
        std::cout << "Pin introdus gresit!\n";
        logare();}
    return 66;
}

int depozitare(){
    using namespace gigel;
    int suma;
    if(logare()){
        std::cout << "Suma care doriti sa o depozitati: ";
        std::cin >> suma;
        bani += suma;
        std::cout << "Bani au fost adaugati in cont!" << std::endl;
        reintoarcere();
        return 0;}
    else
        return 403;
}

int retragere(){
    using namespace gigel;
    int suma;
    if(logare()){
        std::cout << "Suma care doriti sa o retrageti: ";
        std::cin >> suma;
        bani -= suma;
        std::cout << "Bani au fost retrasi din cont!" << std::endl;
        reintoarcere();
        return 0;}
    else
        return 403;
}

int afisarebani(){
    using namespace gigel;
    if(logare()){
        std::cout << "Suma pe care o aveti in cont este: " << bani << std::endl;
        reintoarcere();
        return 0;}
    else
        return 403;
}

int schimbarepin(){
    using namespace gigel;
    int pinnou;
    if(logare()){
        std::cout << "Introduceti noul pin: ";
        std::cin >> pinnou;
        pin = pinnou;
        std::cout << "Pin schimbat cu succes!" << std::endl;
        reintoarcere();
        return 0;}
    else
        return 403;
}
