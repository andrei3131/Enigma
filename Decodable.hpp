#ifndef DECODABLE_HPP
#define DECODABLE_HPP

class Decodable {
  public:
    /**
     *
     * @return The plain text character based on the cypher character passed
     */
    virtual char decode(char) = 0;
};


#endif
