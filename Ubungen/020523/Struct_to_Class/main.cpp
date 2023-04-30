#include <iostream>

class Foobar {
    public: 
        int foo;
        int bar; 

    void eigenschaften_asugeben(){
        std::cout << "foo=" << this->foo << " und bar=" << this->bar << std::endl; 
    }

    void foo_eingeben(){
        std::cout << "Geben Sie bitte einen Wert fuer foo ein: ";
        std::cin  >> this->foo;
    }

    void bar_eingeben(){
        std::cout << "Geben Sie bitte einen Wert fuer bar ein: ";
        std::cin  >> this->bar;
    }


    void eigenschaften_einlesen(){
        std::cout << "Es werden nun die Werte fuer foo und bar eingelesen.\n";
        foo_eingeben();
        bar_eingeben();
    }
};


int main() {

    Foobar instanzeins;
    Foobar instanzzwei;

    instanzeins.eigenschaften_einlesen();
    instanzzwei.eigenschaften_einlesen();
    instanzeins.eigenschaften_asugeben();
    instanzzwei.eigenschaften_asugeben();

}