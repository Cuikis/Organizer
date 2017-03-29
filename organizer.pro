TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    child.cpp \
    group.cpp \
    memory.cpp \
    subgroup.cpp \
    functions.cpp

HEADERS += \
    child.h \
    group.h \
    memory.h \
    subgroup.h \
    functions.h
