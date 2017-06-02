// Dynamic libraries
#include <dlfcn.h>

#include "../printer/printer.hpp"
#include <iostream>
#include <functional>
#include <algorithm>
#include <map>
#include <list>

std::map<std::string, Printer::constructor_t*> constructors;

int main(int argc, char* argv[]){
    void *lib_handle = dlopen("./libprinter.so", RTLD_NOW);
    if (!lib_handle){
        std::cerr << dlerror() << std::endl;
        return 1;
    }

    typedef void (*print_foo)();
    print_foo* f = (print_foo*)dlsym(lib_handle, "print_a");
    if (f == NULL){
        std::cout << "Can't load" << std::endl;
        std::cout << dlerror() << std::endl;
    }else {
        std::cout << "Calling f" << std::endl;
        (*f)();
    }

    dlclose(lib_handle);

    return 0;
}


