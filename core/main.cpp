#include <iostream>
#include <algorithm>
#include <map>
#include <list>

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <dlfcn.h>

#include "../printer/printer.hpp"

const size_t BUF_SIZE = 1024;

int main(int argc, char* argv[]){
    FILE *dl;   // handle to read directory
    const char *command_str = "ls *.so";
    char in_buf[BUF_SIZE];
    dl = popen(command_str, "r");
    if(!dl){
        perror("popen");
        exit(-1);
    }

    void *dlib;
    char name[1024];
    std::list<void*> handles;
    while(fgets(in_buf, BUF_SIZE, dl)){
        // trim off the whitespace
        char *ws = strpbrk(in_buf, " \t\n");
        if(ws) *ws = '\0';
        sprintf(name, "./%s", in_buf);
        dlib = dlopen(name, RTLD_NOW);
        if(dlib == NULL){
            std::cerr << dlerror() << std::endl;
            exit(-1);
        }
        handles.push_back(dlib);
    }

    std::map<std::string, Printer::constructor_t*> constructors;

    std::for_each(handles.cbegin(),
                  handles.cend()  ,
                  [&constructors](auto& handle){
        const char* (*name)() = (const char* (*)())dlsym(handle, "name");
        constructors[(*name)()] = (Printer::constructor_t*)dlsym(handle, "constructor");
    });

    std::cout << "Loading: " << std::endl;
    std::for_each(constructors.cbegin(),
                  constructors.cend()  ,
                  [](auto& it){std::cout << it.first << std::endl;});

    std::cout << std::endl << "Calling: " << std::endl;
    std::for_each(constructors.cbegin(),
                  constructors.cend()  ,
                  [](auto& it){
        Printer* p = it.second();
        std::cout << p->name() << ": ";
        p->print();
        std::cout << std::endl;
    });

    std::for_each(handles.cbegin(),
                  handles.cend()  ,
                  [](auto& handle){
        dlclose(handle);
    });

    return 0;
}

