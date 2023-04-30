#include <iostream>


class Bruch{
    public: 
        // Ein Bruch besteht aus zwei bestandteilen (Zähler/Nenner)
        int zaehler;
        int nenner;

    // Mit der Funktion wird das Einlesen der Brüche ermöglicht
    void einlesen(){
        std::cout << "Bitte geben Sie einen Bruch ein: " << std::endl;
        std::cout << "Zähler ist: ";
        std::cin >> this->zaehler;
        std::cout << "Nenne ist: ";
        std::cin >> this->nenner;
        
        ausgeben();
    }

    // Mit dieser Funktion könnne die Brüche ausgegeben werden
    void ausgeben(){
       std::cout << " Der Bruch ist (" << this->zaehler << "/" << this->nenner << ")" << std::endl;
    }

    // Hier werden zwei eingegebene Brüche multipliziert
    Bruch multiplizieren(const Bruch& zweiter_bruch){
        Bruch ergebnis_bruch;

        // Beide Kompnenten werden einfach multipliziert und in einem neuen Bruch getan
        ergebnis_bruch.zaehler = this->zaehler * zweiter_bruch.zaehler;
        ergebnis_bruch.nenner = this->nenner * zweiter_bruch.nenner;

        // Falls gekürzt werden kann wird gekürzt
        ergebnis_bruch.shorting();
        // Er soll das Ergebnis dann zurückgegeben
        return ergebnis_bruch;
    }

    // Hier werden zwei eingegebene Brüche dividert
    Bruch divideren(const Bruch& zweiter_bruch){
        Bruch ergebnis_bruch;

        // Bei dem Divideren passiert wieder eine multiplikation nur hier wird der Kehrwert eines Bruches genommen
        ergebnis_bruch.zaehler = this->zaehler * zweiter_bruch.nenner;
        ergebnis_bruch.nenner = this->nenner * zweiter_bruch.zaehler;

        ergebnis_bruch.shorting();
        return ergebnis_bruch;
    }

    // Hier werden zwei eingegebene Brüche addiert
    Bruch addieren(Bruch& zweiter_bruch){
        Bruch ergebnis_bruch;
        // Beim addieren zweier Brüche muss der Nenner gleich sein
        // Bei dem Nennen multiplizieren wir ihn einfach
        ergebnis_bruch.nenner = this->nenner * zweiter_bruch.nenner;
        // Bei dem Zähler multiplizieren wir den Zähler mit dem gegenüber liegenden Nenner des zweiten Bruches 
        // und bei dem zweiten Bruch genau andersherum
        ergebnis_bruch.zaehler = (this->zaehler * zweiter_bruch.nenner) + (zweiter_bruch.zaehler * this->nenner);
        ergebnis_bruch.shorting();
        return ergebnis_bruch;
    }

    // Hier werden zwei eingegbene Brüche subtrahiert
    Bruch subtrahieren(Bruch& zweiter_bruch){
        Bruch ergebnis_bruch;
        // Hier wird das gleich prinzip wie beim addieren angewendet nur, dass der Operator ein Minus zeichen ist.
        ergebnis_bruch.nenner = this->nenner * zweiter_bruch.nenner;
        ergebnis_bruch.zaehler = (this->zaehler * zweiter_bruch.nenner) - (zweiter_bruch.zaehler * this->nenner);
        ergebnis_bruch.shorting();
        return ergebnis_bruch;
    }

    // Hier wird eine Hilfsfunktion implmentiert, welche den ggT ausrechnet (Euklider Algorithmus -> Rekursiv)
    int ggT(int a, int b){
        // Wenn der Rest 0 ist, dann soll er den ggT zurückliefern
        if(b == 0) return a;
        // Rekursiver Aufruf
        return ggT(b, a % b);
    }

    // Funktion zur kürzung einer Funktion
    void shorting(){
        // Die Hilfsfunktion wird genutzt um den gemeinsamen Teiler herauszufinden
        int teiler = ggT(zaehler, nenner);
        // Die beiden Komponenten werden dementsprechend geteilt
        zaehler = zaehler / teiler;
        nenner = nenner / teiler;
    }

};

int main(){

    Bruch viertel;
    Bruch anderer_bruch;   

    /*+++++++++++++++++ Aufrufen der Funktionen ++++++++++++++++++++*/

    viertel.einlesen();
    anderer_bruch.einlesen();

    Bruch ergebnis_multi = viertel.multiplizieren(anderer_bruch);
    std::cout << "Wenn wir beide Brüche Multiplizieren dann ergbit es";
    ergebnis_multi.ausgeben();
  

    Bruch ergebnis_divi = viertel.divideren(anderer_bruch);
    std::cout << "Wenn wir beide Brüche Dividern dann ergbit es";
    ergebnis_divi.ausgeben();

    
    Bruch ergebnis_addi = viertel.addieren(anderer_bruch);
    std::cout << "Wenn wir beide Brüche Addieren dann ergbit es";
    ergebnis_addi.ausgeben();

    Bruch ergebnis_subt = viertel.subtrahieren(anderer_bruch);
    std::cout << "Wenn wir beide Brüche Subtrahieren dann ergbit es";
    ergebnis_subt.ausgeben();

    return 0;
}

