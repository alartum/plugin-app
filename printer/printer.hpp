#ifndef PLUGIN_HPP
#define PLUGIN_HPP

#include <iostream>
#include <string>

class Printer
{
public:
    virtual void print() = 0;
    virtual std::string name()  = 0;

    typedef Printer* constructor_t();
};

#endif // PLUGIN_HPP
