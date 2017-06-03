#include "helloprinter.hpp"

extern "C"{
    const char* name(){
        return "HelloPrinter";
    }

    Printer* constructor(){
        return new HelloPrinter;
    }
}

std::string HelloPrinter::name()
{
    return std::string("HelloPrinter");
}

void HelloPrinter::print()
{
    std::cout << "Hello, World!" << std::endl;
}
