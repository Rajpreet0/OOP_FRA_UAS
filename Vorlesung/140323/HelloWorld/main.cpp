#include <iostream> // Hinzufügen der Standard Library, sowie <stdio.h>

// using namespace std --> ist nicht best practice, würde std ersetzen


// So umständliches Pointer dinges gibt es nicht mehr
// Jetzt -> Referenzparameter mit '&' (man verwendet damit das Originale !Vorsichtig!)
// Mit 'const' bleibt der Wert konstant und kann dann nicht mehr verändert werden
void inkrementieren(int &x){
    std::cout << "x=" << x << std::endl;
    x++;
    std::cout << "x=" << x << std::endl;
}

int main(int argc, const char *argv[]){
    // cout -> Command Out 
    // Der Datensstrom ("Hello World") geht in cout
    // Möglichkeit -> cout << "Hello, " << " World!" << "\n"
    // Andere Möglichkeit für maskierte Parameter std::cout << "--" << std:endl;
    std::cout << "Hello, world!\n" ;// Das ist das gleiche wie printf("---");
    int a; // Variablen Deklaration
    std::cout << "Bitte gebe eine Zahl ein: "; 
    //! Der Datnsstrom geht somit in die andere Richtung
    std::cin  >> a; // Das gleiche wie scanf()  
    // Ausgeben einer Variable 
    std::cout << "Sie haben " << a << " eingegeben.\n";


    // Verwendung von Refernzparameter 
    int i = 42;
    std::cout << "i=" << i << std::endl;
    std::cout << "Adress von i ist " << &i << std::endl; // Adresse von Werte herausnehmen
    inkrementieren(i);
    std::cout << "i=" << i << std::endl;

    return 0;
}


// Wie man das früher gemacht hat (Werteparameter)

/*
    / Adresse wird wieder zum Wert gemacht
    void inkrementieren(int* x){
        / Der Wert wird dann genutzt
        std::cout << "x=" << *x << std::endl;
        *x = *x + 1;
        std::cout << "x=" << *x << std::endl;
    }

    int i = 42;
    std::cout << "i=" << i << std::endl;
    inkrementieren(&i); // Adresse wird übergeben
    std::cout << "i=" << i << std::endl;


*/