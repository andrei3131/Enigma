#ifndef ENCODABLE_HPP
#define ENCODABLE_HPP

#include <stdexcept>

#define ALPHABET_SIZE 26

class Encodable {
  public:
    /**
     * @return The plain text character based on the cypher character passed
     */
    virtual char encode(char) = 0;
    /**
     *
     * @return Alphabet index of passed character; between 0 and 25
     */
    unsigned int get_alphabet_index(char);
    /**
     *
     * @return The character found in the alphabet at passed index
     */
    char get_char_at_alphabet_index(unsigned int);
};


#endif
