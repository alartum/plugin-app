TEMPLATE = lib

CONFIG = plugin

QMAKE_CXXFLAGS += -std=c++14

SOURCES = \
    helloprinter.cpp

HEADERS += \
    printer.hpp \
    helloprinter.hpp

OBJECTS_DIR = tmp

