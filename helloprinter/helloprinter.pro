TEMPLATE = lib

CONFIG = plugin

QMAKE_CXX = g++-6

QMAKE_CXXFLAGS += -std=c++14

SOURCES = \
    helloprinter.cpp

HEADERS += \
    printer.hpp \
    helloprinter.hpp

OBJECTS_DIR = tmp

DESTDIR = ../bin
