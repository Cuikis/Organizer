TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    child.cpp \
    group.cpp \
    memory.cpp

HEADERS += \
    child.h \
    group.h \
    memory.h
