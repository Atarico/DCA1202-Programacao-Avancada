TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    cutbox.cpp \
    cutellipsoid.cpp \
    cutsphere.cpp \
    cutvoxel.cpp \
    geometricfigure.cpp \
    putbox.cpp \
    putellipsoid.cpp \
    putsphere.cpp \
    putvoxel.cpp \
    sculptor.cpp

HEADERS += \
    cutbox.h \
    cutellipsoid.h \
    cutsphere.h \
    cutvoxel.h \
    geometricfigure.h \
    putbox.h \
    putellipsoid.h \
    putsphere.h \
    putvoxel.h \
    sculptor.h
