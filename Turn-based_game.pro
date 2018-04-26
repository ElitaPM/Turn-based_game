TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    soldier.cpp \
    warbase.cpp \
    barrier.cpp \
    unit.cpp \
    menu.cpp \
    field.cpp

HEADERS += \
    soldier.h \
    warbase.h \
    barrier.h \
    unit.h \
    menu.h \
    field.h
