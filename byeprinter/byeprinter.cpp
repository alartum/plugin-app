#include "byeprinter.hpp"

extern "C"{
    const char* name(){
        return "ByePrinter";
    }

    Printer* constructor(){
        return new ByePrinter;
    }
}

std::string ByePrinter::name()
{
    return std::string("ByePrinter");
}

void ByePrinter::print()
{
    std::cout << "Bye, World!" << std::endl;
}
