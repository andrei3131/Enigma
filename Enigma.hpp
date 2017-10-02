#ifndef ENIGMA_HPP
#define ENIGMA_HPP

#include "Plugboard.hpp"
#include "Rotor.hpp"
#include "Reflector.hpp"
#include "Encodable.hpp"
#include <array>
#include <string>
#include <map>
#include <vector>
#include <memory>

class Enigma : public Encodable {
  public:
    Enigma(std::vector<std::string>);
    ~Enigma();
    /**
     * Initialises all heap allocated components
     */
    void configure();
    /**
     *
     * @return The cypher character of the character type in the machine
     */
    char encode(char);
  private:
    /**
     *
     * @return The input charcter through rotor, considering rotations
     */
    char normalise(char, int);
    /**
     *
     * @return true iff character in [A..Z]
     */
    bool is_valid_character(char);
    /**
     *
     * @return true iff the extension of the file is one of [.rot, .pb]
     */
    bool is_valid_file_extension(std::string, std::string);
    /**
     *
     * @return argument % ALPHABET_SIZE
     */
    int mod_alpha_size(int);
  private:
    Plugboard *plugboard;
    Reflector *reflector;
    std::vector<std::string> configuration_files; //No. of components varies
    std::vector<std::shared_ptr<Rotor>> rotors;
};

#endif
