#ifndef PLUGBOARD_HPP
#define PLUGBOARD_HPP

#include <array>
#include <fstream>
#include "Encodable.hpp"
#include "Configurable.hpp"
#include "Decodable.hpp"

class Plugboard : public Encodable,  public Configurable, public Decodable {
  public:
    /**
     * Reads plugboard wiring from file and initialises array wiring
     */
    void configure(std::string);
    /**
     *
     * @return Cypher character mapped by the wiring configuration
     */
    char encode(char);
    /**
     *
     * @return Plain text character mapped by the wiring configuration
     */
    char decode(char);
  private:
    /**
     *
     * @return true iff the first character in the file is EOF
     */
    bool is_empty(std::ifstream&);
  private:
    void configure_default_wiring();
    std::array<unsigned int, ALPHABET_SIZE> wiring;
};


#endif
