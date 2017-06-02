#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#include <map>

class Printer
{
public:
    virtual void print() = 0;

    // Not using std::function to prevent C++ name mangling
    typedef Printer* constructor_t();
};

// Constructors of all possible printers
//extern std::map<std::string, Printer::constructor_t*> constructors;

int a = 10;

#endif // PLUGIN_HPP
