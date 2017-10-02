#ifndef REFLECTOR_HPP
#define REFLECTOR_HPP

#include "Encodable.hpp"

class Reflector : public Encodable {
  public:
    /**
     *
     * @return Cypher character resulting from reflecting function
     */
    char encode(char);
};

#endif
