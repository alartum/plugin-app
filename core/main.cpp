// Dynamic libraries
#include <dlfcn.h>

#include "../printer/printer.hpp"
#include <iostream>
#include <functional>
#include <algorithm>
#include <map>
#include <list>

std::map<std::string, Printer::constructor_t*> constructors;
int a;

int main(int argc, char* argv[]){

    std::list<void*> dl_list;
    constructors["test"] = nullptr;
    void *lib_handle = dlopen("./libprinter.so", RTLD_NOW);
    if (!lib_handle){
        std::cerr << dlerror() << std::endl;

        return 1;
    }
    else
        dl_list.push_back(lib_handle);

    std::for_each(constructors.begin(),
                  constructors.end(),
                  [](auto& it){std::cout << it.first << std::endl;});

    dlclose(lib_handle);

    return 0;
}


