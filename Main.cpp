#include <stdexcept>
#include <iostream>
#include <fstream>
#include <vector>
#include "Enigma.hpp"

using namespace std;

int main(int argc, char **argv)
{
    if(argc < 2)
    {
        cout << "Invalid number of program arguments: ";
        cout << "Usage ./enigma <optional_id.rot> <id.pb>" << endl;
        exit(EXIT_FAILURE);
    }
    vector<string> configuration_files(argv + 1, argv + argc);
    Enigma enigma(configuration_files);
    enigma.configure();
    char plain_text_character = '?';
    while(cin >> ws >> plain_text_character)
    {
        cout << enigma.encode(plain_text_character);
    }
    fclose(stdin);
    //Destructor of enigma called when out of scope
    return 0;
}
