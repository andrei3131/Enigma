#include "Reflector.hpp"

 char Reflector::encode(char plain_text_character)
 {
     //Predefined function that maps plaintext chars to their cypher
     unsigned int mapped_index = (get_alphabet_index(plain_text_character) +
                                  get_alphabet_index('N')) % ALPHABET_SIZE;
     return get_char_at_alphabet_index(mapped_index);
 }
