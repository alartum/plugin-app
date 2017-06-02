#include "helloprinter.hpp"

void HelloPrinter::print()
{
    std::cout << "Hello, World!" << std::endl;
}

Printer* constructor(){
   return new HelloPrinter;
}

extern "C"{
    void print_a(){
        std::cout << "print_a" << std::endl;
        //a = 20;
        std::cout << "a = " << a << std::endl;
    }
}

class proxy {
public:
   proxy(){
      // register the maker with the factory
      //constructors["HelloPrinter"] = constructor;
      //std::cout << "a = " << a << std::endl;
      std::cout << "proxy constructor" << std::endl;
   }
};
// our one instance of the proxy
proxy p;

