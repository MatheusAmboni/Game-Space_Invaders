QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Boss.cpp \
    BossBullet.cpp \
    Bullet.cpp \
    Enemy.cpp \
    EnemyBullet.cpp \
    Game.cpp \
    GameWin.cpp \
    Health.cpp \
    MeteorBig.cpp \
    MeteorSmall.cpp \
    Ovni.cpp \
    Player.cpp \
    Score.cpp \
    gameover.cpp \
    main.cpp

HEADERS += \
    Boss.h \
    BossBullet.h \
    Bullet.h \
    Enemy.h \
    EnemyBullet.h \
    Game.h \
    GameWin.h \
    Health.h \
    MeteorBig.h \
    MeteorSmall.h \
    Ovni.h \
    Player.h \
    Score.h \
    gameover.h

FORMS += \
    GameWin.ui \
    gameover.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
