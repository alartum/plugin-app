#ifndef BYEPRINTER_HPP
#define BYEPRINTER_HPP

#include "../printer/printer.hpp"

class ByePrinter : public Printer
{
public:
    void print();
    std::string name();
};

#endif // BYEPRINTER_HPP
