#ifndef ROTOR_HPP
#define ROTOR_HPP

#include "Encodable.hpp"
#include "Configurable.hpp"
#include "Decodable.hpp"
#include <fstream>
#include <array>

class Rotor : public Encodable, public Configurable, public Decodable {
  public:
    Rotor();
    /**
     * Initializes mapping based on the mapping in the conf. file
     */
    void configure(std::string);
    /**
     *
     * @return Unnormalised encoding of passed character
     */
    char encode(char);
    /**
     *
     * @return Unnormalised decoding of passed character
     */
    char decode(char);
    /**
     * Rotates the array by one position to the lef
     * Increments current_rotations
     */
    void rotate();
    /**
     *
     * @return true iff current_rotations eq 26
     */
    bool has_completely_rotated();
    /**
     * Sets current_rotations to 0 on a complete rotation
     */
    void reset_current_rotations();
    /**
     *
     * @return Number of rotations rotor has currently effectuated
     */
    unsigned int get_current_rotations() const;
  private:
    unsigned int current_rotations;
    std::array<unsigned int, ALPHABET_SIZE> mapping;
};

#endif
