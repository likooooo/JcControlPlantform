QT       += core gui xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
#    Lib/PlantformIO/***.cpp\
    Lib/PlantformIO/InterfaceSlnController.cpp \
    Lib/PlantformIO/ProjController.cpp \
    Lib/PlantformIO/SlnController.cpp \
    Lib/PlantformIO/XmlController.cpp \
    mainwindow.cpp\
    main.cpp

HEADERS += \
#    Lib/PlantformIO/***.h\ #若想修改库目录里的内容接触注释
    Lib/PlantformIO/InterfaceSlnController.h \
    Lib/PlantformIO/ProjController.h \
    Lib/PlantformIO/SlnController.h \
    Lib/PlantformIO/XmlController.h \
    mainwindow.h
FORMS += \
    mainwindow.ui

#将指定库目录内的文件全部导入
INCLUDEPATH +=
    Lib


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
#    Lib/PlantformIO/* \
    #icon
    A:/Qt/Tools/QtCreator/share/qtcreator/qbs/share/qbs/examples/cocoa-application/CocoaApplication/dmg.iconset/icon_32x32.png \
    #readme
    Readme
