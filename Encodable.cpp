#include "Encodable.hpp"

unsigned int Encodable::get_alphabet_index(char indexed_character)
{
    //Throws an exception if character is not A..Z
    std::string msg = "Enigma only encodes upper-case characters.(" +
                       std::to_string(indexed_character) + ")";
    if(indexed_character < 'A' || indexed_character > 'Z') {
       throw std::invalid_argument(msg);
    }
    return indexed_character - 'A';
}

char Encodable::get_char_at_alphabet_index(unsigned int index) {
    //Throws an exception if character's index is not pos(A)..pos(Z)
    std::string msg = "Enigma only encodes upper-case characters.(" +
                       std::to_string(index) + ")";
    if(index <  0 || index > 26) {
      throw std::invalid_argument(msg);
    }
    return (char) (index + 'A');
}
