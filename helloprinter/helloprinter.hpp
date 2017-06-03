#ifndef HELLOPRINTER_HPP
#define HELLOPRINTER_HPP

#include "../printer/printer.hpp"

class HelloPrinter : public Printer
{
public:
    void print();
    std::string name();
};

#endif // HELLOPRINTER_HPP
