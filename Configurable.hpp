#ifndef CONFIGURABLE_HPP
#define CONFIGURABLE_HPP

#include <string>

class Configurable {
  public:
    /**
     * Initialises machine's components using the name of the configuration
     * file passed
     */
    virtual void configure(std::string) = 0;
};

#endif
