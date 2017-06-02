#include "helloprinter.hpp"

void HelloPrinter::print()
{
    std::cout << "Hello, World!" << std::endl;
}

extern "C" {
    Printer* constructor(){
       return new HelloPrinter;
    }

    class proxy {
    public:
       proxy(){
          // register the maker with the factory
          //constructors["HelloPrinter"] = constructor;
          std::cout << "a = " << a << std::endl;
          std::cout << "proxy()" << std::endl;
       }
    };
    // our one instance of the proxy
    proxy p;
}

