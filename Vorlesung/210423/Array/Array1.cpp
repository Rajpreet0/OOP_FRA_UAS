#include <iostream>

// Kleine Änderungen in C++



int main() {

    // Man kann in C++ direkt Daten zu einem Array hinzuweisen
    // Bei einer direkten Zuweisung ist die Angabe der Größe des Arrays nicht notwendig
    char text[] = {'H', 'a', 'l', 'l', 'o', '\0'};
    std::cout << text << std::endl;


    // Zur Laufzeit erzeugtes Array (dynamisch)

    int size = 0;
    int i;
    // Fragen wie groß das Array überhaupt sein soll
    std::cout << "Wie viele Zahlen sollen eingelesen werden?" << std::endl;
    std::cin >> size;
    // Das Array mit der größe initzialisieren früher mit malloc jetzt mit new
    int* zahlen = new int[size];  //!FRÜHER: (int*) malloc(size * sizeof(int));
    for(i = 0; i < size; i++){
        std::cout << i + 1 << ". Zahlen: ";
        std::cin >> zahlen[i];
    }
    for(i = 0; i < size; i++){
        std::cout << zahlen[i] << " "; 
    }
    // Zeilenumbruch in C++
    std::cout << std::endl;
    // Man muss den Speicherplatz wieder freigeben, dies ging früher mit free, jetzt mit delete
    delete[] zahlen;   //!FRÜHER: free(zahlen);

}