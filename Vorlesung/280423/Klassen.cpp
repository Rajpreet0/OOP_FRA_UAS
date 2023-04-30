#include <iostream>

// OOP verwendet man eine Klasse es ist sowas wie ein Struct in C 
class Beispiel {
 public: // Wir verwenden erstmal public hier überall damit man eine Klasse erstellen kann
    // Variablen einer Klasse sind => Attribute 
    const char* text; // test ist also ein Attribut der Klasse Beispiel
    int zahl1;
    int zahl2;

    // Funktionen einer Klasse sind => Methoden
    void was_bin_ich(){
        // Eine Methode hat automatisch die Attribut der Klasse in der sie sich verbinden
        std::cout << "Ich bin eine Methode der Klasse Beispiel ohne Parameter.\n";
        std::cout << "Und obwohl ich keinerlei Informationen erhalten habe, weiss ich dennoch zu wem ich gehoere, naemlich ";
        // Mit this wird die Klasse gemeint, in welcher man sich befindet hier ist das Beispiel
        std::cout << this << std::endl;
    }

    void info(){
        std::cout << "Ich bin die Instanz der Klasse Beispiel an der Speicheradresse " << this << " hat folgende Werte: " << std::endl;
        // Wenn wir die Attribute einer Klasse aufrufen wollen können wir beim Struct diese aufrufen
        // AUFPASSEN hier wird dann mit einem Pfeiloperator gearbeitet
        std::cout << "text = \"" << this->text << "\"\n ";
        std::cout << "zahl1 = \"" << this->zahl1 << "\"\n ";
        std::cout << "zahl1 = \"" << this->zahl2 << "\"\n "; 
    }
};


void was_bin_ich(){
    std::cout << "Ich bin eine Funktion ohne Parameter. Ich habe daher keinerlei Informationen ueber meine Aussenwelt.\n";
}

// Die C Variante wie man einen Struct bzw. hier eine Klasse aufruft
void info(Beispiel* instanz){
    std::cout << "Die Instanz der Klasse Beispiel an der Speicheradresse " << instanz  << " hat folgende Werte: "  << std::endl;
    std::cout << "text = \"" << instanz->text << "\"\n ";
    std::cout << "zahl1 = \"" << instanz->zahl1 << "\"\n ";
    std::cout << "zahl1 = \"" << instanz->zahl2 << "\"\n ";
     
}


int main() {

    
    // Man muss nicht mehr Struct davor schreiben (in C)
    // Hier werden die Klassen bzw. Instanzen intialisiert
    Beispiel eins; // eins ist eine Instanz der Klasse Beispiel bzw. ein Objekt der Klasse Beispiel
    Beispiel zwei; // ""
    Beispiel drei; // ""

    // Man kann auch eine Klasse als Pointer darstellen lassen
    Beispiel* vier = NULL; // Pointer am Anfang auf nichts zeigen lassen
    vier = new Beispiel(); // Statt Malloc wird hier mit new und delete gearbeitets

    // Andere Variante mit dierkte Initialisierung
    Beispiel* fuenf = new Beispiel(); // Pointer erzeugen und direkt auf eine neue Instanz der Klasse Beispiel zeigen lassen.

    // Den Attributen der Klasse werden so dann wie bei Struct Werte zugeordnet
    eins.text = "Hello Welt";
    eins.zahl1 = 42;
    eins.zahl2 = 12;

    zwei.text = "Ich bin Nummer 2";
    zwei.zahl1 = 0;
    zwei.zahl2 = 14;

    drei.text = "Ich bin die dritte Instanz";
    drei.zahl1 = 42;
    drei.zahl2 = 12;

    // So ruft man eine Funktion auf
    was_bin_ich();
    info(&eins);

    // So ruft man eine Methode auf (Funktion welche in einer Klasse liegt)
    eins.was_bin_ich();
    eins.info();

    // Einer Pointer Klasse Werte zuordnen. Hier aufpassen es wird der Pfeil operator verwendet
    vier->text = "Blabalbalab";
    vier->zahl1 = 4;
    vier->zahl2 = 44;
    vier->info();

    // Mann muss die Pointer Klasse, welche dynamischen Speicher benutzt auch wieder löschen 
    // früher mit free(); heute mit delete();
    delete(vier); // Instanz wieder löschen
    delete(fuenf);

    return 0;
}