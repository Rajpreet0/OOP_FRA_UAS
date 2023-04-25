#include <iostream>

// Weitere Verwendungen der Zeichenkette in C++

int main(){

    // Neue weise wie man eine Zeichenkette macht, mit dem Char Pointer
    const char* name = "Rajpreet";
    // name[0] = 'K' -> geht nicht, weil wir const haben
    // delete(name); -> Faustregel: Ohne new kein Delete
    std::cout << name << std::endl;


    // Andere Char Anweisungen
    const wchar_t* name3 = L"Rajpreet"; //Ein Wide Char (kommt auf dem PC an wie wide der ist: 16 oder 32 Bit)
    const char16_t* name4 = u"Rajpreet"; //Ein Char mit 16 Bit Speicherbreite
    const char32_t* name5 = U"Rajpreet"; //Ein Char mit 32 Bit Speicherbreite
    

    // Verwendung des String operators, welches bei der std:: funktion dabei ist
    std::string name6 = "Rajpreet";

    // Das Zusammenfügen von Strings 
    // Es MUSS eine Variable sein mit der man den String zusammen addiert 
    std::string name7 = name6 +  " Singh";
    std::cout << name7 << std::endl;


    // Andere String Anweisungen 
    std::wstring name8 = L"Rajpreet";
    std::u32string name9 = U"Rajpreet";


    // Ein Mehrzeiliger Text ohne Beachtung von maskierten Sonderzeichen durch RAW-Strings
    const char* mehrzeiliger_text = R"(Ein Zeilenumbruch geht in C nomralerweise mit \n, aber hier wird das ignoriert.
    Viel einfacher ist dies mit einem RAW-String.
    Da kann man sogar "Hochkommata" verwenden.
    )";
    std::cout << mehrzeiliger_text;

    return 0;

}