#include "Enigma.hpp"

Enigma::Enigma(std::vector<std::string> configuration_files) {
    this->configuration_files = configuration_files;
    plugboard = new Plugboard();
    reflector = new Reflector();
}

Enigma::~Enigma() {
    delete reflector;
    delete plugboard;
}

void Enigma::configure()
{
    //Configures machine components
    std::string plugboard_configuration_file = configuration_files.back();
    is_valid_file_extension(plugboard_configuration_file, ".pb");
    plugboard->configure(plugboard_configuration_file);
    for(int i = 0; i < configuration_files.size() - 1; i++)
    {
        Rotor *rotor = new Rotor();
        is_valid_file_extension(configuration_files[i], ".rot");
        rotor->configure(configuration_files[i]);
        rotors.push_back(std::shared_ptr<Rotor>(rotor));
    }
}

char Enigma::encode(char plain_text_character)
{
    if(!is_valid_character(plain_text_character)) {
        throw std::invalid_argument("Enigma converts character in range A-Z");
    }
    char plugboard_encoding = plugboard->encode(plain_text_character);
    char prev_rotor_encoding = plugboard_encoding;
    for(int i = 0; i < rotors.size(); i++)
    {
        int prev_rotations = 0;
        if(i != 0)
        {
            prev_rotations = (-1) * (rotors[i - 1]->get_current_rotations());
        }
        //Normalisation depends on the number of rotations of prev. rotor
        char normalised_char = normalise(prev_rotor_encoding, prev_rotations);
        prev_rotor_encoding = rotors[i]->encode(normalised_char);
    }
    char reflector_encoding = reflector->encode(prev_rotor_encoding);
    prev_rotor_encoding = reflector_encoding;
    for(long int i = rotors.size() - 1; i >= 0; i--)
    {
        unsigned int prev_rotations;
        if(i == 0)
        {
            prev_rotations = 0;
        } else
        {
            prev_rotations = rotors[i - 1]->get_current_rotations();
        }
        char not_normalised_character = rotors[i]->decode(prev_rotor_encoding);
        prev_rotor_encoding = normalise(not_normalised_character,
                                        prev_rotations);
    }
    //Rotors Cascade
    bool next = true;
    for(int i = 0; i < rotors.size(); i++)
    {
        //Always rotate first rotor
        //Rotate next iff the first has completely rotated
        rotors[i]->rotate();
        if(rotors[i]->has_completely_rotated())
        {
            rotors[i]->reset_current_rotations();
        } else {
            next = false;
        }
        if(!next) {break;}

    }

    return plugboard->encode(prev_rotor_encoding);
}


//Private Methods
bool Enigma::is_valid_character(char c)
{   int index = get_alphabet_index(c);
    return index >= get_alphabet_index('A') && index <= get_alphabet_index('Z');
}

char Enigma::normalise(char character, int prev_rotations) {
    //rotations < 0 for encoding and > 0 for decoding
    //Encoding adaptation to rotations
    unsigned int alpha_index = get_alphabet_index(character);
    if (prev_rotations == 0) { return character; }
    int offset = alpha_index + prev_rotations;
    offset = offset < 0 ? mod_alpha_size(ALPHABET_SIZE + offset) :
                          mod_alpha_size(offset);
    return get_char_at_alphabet_index(offset);

}

bool Enigma::is_valid_file_extension(std::string rotor_in, std::string extension)
{
    int size = extension.length();
    bool is_valid = rotor_in.substr(rotor_in.length() - size, size) == extension;
    if(!is_valid)
    {
        throw std::runtime_error("Invalid file extension");
    }
    return is_valid;
}

int Enigma::mod_alpha_size(int index)
{
    return index % ALPHABET_SIZE;
}