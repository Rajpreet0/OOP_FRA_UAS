#include <iostream>

/*
    Polymorphismus = Ich kann den gleich Funktionsbezeichner mehrmals verwenden, solange der Compiler die Parameter 
                     deutlich unterscheiden kann, also unterschiedliche Datentypen oder mehre Datentypen 
*/


/*
+++++++++++++++++++ BEISPIELE +++++++++++++++++++ 
*/

// Alle Funktionen haben den gleichen Namen
// Alle Funktionen sind aber unterschiedlich (disjunkt) bezüglich der Parameter
void do_something(int number){
    std::cout << "Number integer: " << number << std::endl;
}

void do_something(float number){
    std::cout << "Number integer: " << number << std::endl;
}

void do_something(const char* text){
    std::cout << "The Test is: " << text << std::endl;
}

void do_something(int a, int b){
    std::cout << "The First Number is: " << a << " The Second Number is: " << b << std::endl;
}


int main(){

    int number = 7;
    float number_float = 1.3;
    const char* text = "Popo";
    int number_integer_test = 5;

    do_something(number);
    do_something(number_float);
    do_something(text);
    do_something(number, number_integer_test);
    
}