#include <iostream>
#include <cmath>

/*
    [x] Instanziieren der Punkte
    [x] Einlesen der Punkte  -> Funktion einlesen();
    [x] Ausgabe der Punkte -> Funktion ausgabe();
    [x] Abstand berchenen siehe unten auf dem Bildschirm ausgeben -> Funktion abstand()
    [x] Zwei Punkte addieren und Punkt auf dem Bildschirm ausgeben  -> Funktion addiere()
*/

class Punkt{
    public: 
        int x;
        int y; 

    // Funktion: Einlesen einer Koordinate 
    void einlesen(){
        std::cout << "Bitte geben Sie zwei Koordinaten ein: " << std::endl;
        std::cout << "x= ";
        std::cin  >> this->x;
        std::cout << "y= ";
        std::cin  >> this->y;
    }

    // Funktion: Ausgabe einer Funktion
    void ausgabe(){
        std:: cout << "(" << this->x << "|" << this->y << ")";
    }

    // Funktion: Abstand berechenen zweier Funktionen mit Vektoraddition und Pythagoras
    double abstand(const Punkt& koordinate2){
        int number_one;
        int number_two;
        double sum = 0;

        // Betrag überprüfen - nicht nötig wegen dem Quadrat unter der Wurzel
        if(this->x > koordinate2.x){
            number_one = this->x - koordinate2.x;
        }else {
            number_one = koordinate2.x - this->x;
        }

        if(this->y > koordinate2.y){
            number_two = this->y - koordinate2.y;
        }else {
            number_two = koordinate2.y - this->y;
        }

        // Abstand berechenen
        sum = sqrt((number_one*number_one) + (number_two*number_two));
        return sum;
    }

    // Funktion: Vektoraddition
    Punkt addiere(const Punkt& koordinate2){
        Punkt koordiante3;
        koordiante3.x = this->x + koordinate2.x;
        koordiante3.y = this->y + koordinate2.y;
        return koordiante3;
    }

    int text_decision(int number){
        std::cout << "Das sind deine Optionen: " << std::endl;
        std::cout << "(1) Abstand berechenen" << std::endl;
        std::cout << "(2) Addition" << std::endl;
        std::cout << "Bitte wähle eine Option aus mit der Nummer ";
        std::cin  >> number;

        return number;
    }

    void decision(Punkt& koordinate2){
        int decision = 0;

        decision = text_decision(decision);

        if(decision == 1){
            std::cout << "Der Abstand von ";
            this->ausgabe();
            std::cout << " zu ";
            koordinate2.ausgabe();
            std::cout << " ist " << this->abstand(koordinate2) <<  std::endl;
        }else if(decision == 2){
             Punkt koordinate3 = this->addiere(koordinate2);
            std::cout << " Wenn wir beide Kooridnaten addierene kommen wir zu ";
            koordinate3.ausgabe();
        }else{
            std::cout << "Fehlerhafte Eingabe!" << std::endl;
        }
    }

};

int main(){

    Punkt koordinate1;
    Punkt koordinate2;

    koordinate1.einlesen();
    koordinate2.einlesen();


    koordinate1.decision(koordinate2);
   

    return 0;
}


