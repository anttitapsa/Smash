QT       += gui \
         multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    characterselect.cpp \
    game.cpp \
    gingerbread.cpp \
    levelselect.cpp \
    main.cpp \
    mainmenu.cpp \
    options.cpp \
    options_view.cpp \
    platform.cpp \
    player.cpp

HEADERS += \
    characterselect.h \
    game.h \
    gingerbread.h \
    lakki.h \
    levelselect.h \
    mainmenu.h \
    options.h \
    options_view.h \
    platform.h \
    player.h \
    totoro.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resourses.qrc

DISTFILES +=
