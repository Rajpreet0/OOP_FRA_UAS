#include <iostream>

/*
    [x] You should Program a Function which can take Data, which will be displayed in the console
        -> The Function should take different Datatypes ! Polymorphism !
*/

void ausgabe(const int number){
    std::cout << "Die ganze Zahl hat den Wert " << number << std::endl;
}   

void ausgabe(const double number){
    std::cout << "Die Kommazahl hat den Wert " << number << std::endl;
}

void ausgabe(const char* string){
    std::cout << "Die Zeichenkette hat den Inhalt " << string << std::endl;
}


int main(){

    ausgabe("Hallo Welt!");
    ausgabe(3.14159);
    ausgabe(42);

    return 0;
}