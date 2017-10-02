#include "Plugboard.hpp"


void Plugboard::configure(std::string plugboard_configuration_file)
{
    //Checks configuration_file validity and reads pairs of chars from file
    //Symmetric configuration of the wiring
    //O(1) retreival time, but more memory usage
    //Array used instead of map/ hash_map: better worst case complexity lookup
    configure_default_wiring();
    std::ifstream plugboard_in(plugboard_configuration_file);
    if(!plugboard_in.is_open()) {throw std::runtime_error("File not found: " + plugboard_configuration_file);}
    std::string pair_left,pair_right;
    if(!is_empty(plugboard_in)) {
        while (plugboard_in >> pair_left >> pair_right) {
            unsigned int domain_value = static_cast<unsigned int>(std::stoi(
                    pair_left));
            unsigned int image_value = static_cast<unsigned int>(std::stoi(
                    pair_right));
            wiring.at(domain_value) = image_value;
            wiring.at(image_value) = domain_value;
        }
    }
    plugboard_in.close();
}

char Plugboard::encode(char plaintext_character)
{
    unsigned int alphabet_index = get_alphabet_index(plaintext_character);
    char character = get_char_at_alphabet_index(wiring.at(alphabet_index));
    return character;
}

char Plugboard::decode(char cyphertext_character)
{
    return encode(cyphertext_character);
}


void Plugboard::configure_default_wiring()
{
    for(int i = 0; i < wiring.size(); i++)
    {
        wiring.at(i) = i;
    }
}

bool Plugboard::is_empty(std::ifstream& file)
{
    return file.peek() == std::ifstream::traits_type::eof();
}