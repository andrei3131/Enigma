#include "Rotor.hpp"

Rotor::Rotor() : current_rotations(0) {}


void Rotor::configure(std::string rotor_configuartion_file)
{
    std::ifstream rotor_in(rotor_configuartion_file);
    if(!rotor_in.is_open())
    {
        throw std::runtime_error("File not found " + rotor_configuartion_file);
    }
    for(auto it = mapping.begin(); it != mapping.end(); it++)
    {
        rotor_in >> *it;
    }
    rotor_in.close();
}


char Rotor::encode(char plaintext_character)
{
    unsigned int  map_index= mapping[get_alphabet_index(plaintext_character)];
    return get_char_at_alphabet_index(map_index);
}

char Rotor::decode(char cypher_text)
{
    unsigned int alphabet_index = get_alphabet_index(cypher_text);
    for(int i = 0; i < mapping.size(); i++)
    {
        if(mapping[i] == alphabet_index)
        {
            return get_char_at_alphabet_index(i);
        }
    }
}

void Rotor::rotate()
{
    if(!mapping.empty()) {
        unsigned int first = mapping.at(0);
        for (int i = 0; i < mapping.size() - 1; i++) {
            mapping.at(i) = mapping.at(i + 1);
        }
        mapping.at(mapping.size() - 1) = first;
        current_rotations++;
    }
}

bool Rotor::has_completely_rotated()
{
    return current_rotations == ALPHABET_SIZE;
}


void Rotor::reset_current_rotations() {
    current_rotations = 0;
}

unsigned int Rotor::get_current_rotations() const {
    return current_rotations;
}
