TEMPLATE = lib

CONFIG = plugin

QMAKE_CXX = g++-6

QMAKE_CXXFLAGS += -std=c++14

SOURCES = \
    byeprinter.cpp

HEADERS += \
    byeprinter.hpp

OBJECTS_DIR = tmp

DESTDIR = ../bin
