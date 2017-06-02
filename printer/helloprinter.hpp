#ifndef HELLOPRINTER_HPP
#define HELLOPRINTER_HPP

#include "printer.hpp"
#include <iostream>

class HelloPrinter : public Printer
{
public:
    void print();
};

#endif // HELLOPRINTER_HPP
