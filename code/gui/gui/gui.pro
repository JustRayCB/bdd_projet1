QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS+=-lmysqlcppconn -lpugixml

SOURCES += \
    database.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    database.hpp \
    mainwindow.hpp

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../opt/homebrew/Cellar/mysql-connector-c++/8.0.33/lib64/release/ -lmysqlcppconn.9.8.0.33
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../opt/homebrew/Cellar/mysql-connector-c++/8.0.33/lib64/debug/ -lmysqlcppconn.9.8.0.33
else:unix: LIBS += -L$$PWD/../../../../../../../../../opt/homebrew/Cellar/mysql-connector-c++/8.0.33/lib64/ -lmysqlcppconn.9.8.0.33

INCLUDEPATH += $$PWD/../../../../../../../../../opt/homebrew/Cellar/mysql-connector-c++/8.0.33/include
DEPENDPATH += $$PWD/../../../../../../../../../opt/homebrew/Cellar/mysql-connector-c++/8.0.33/include

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../../../../opt/homebrew/Cellar/pugixml/1.13/lib/release/ -lpugixml.1.13
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../../../../opt/homebrew/Cellar/pugixml/1.13/lib/debug/ -lpugixml.1.13
else:unix: LIBS += -L$$PWD/../../../../../../../../../opt/homebrew/Cellar/pugixml/1.13/lib/ -lpugixml.1.13

INCLUDEPATH += $$PWD/../../../../../../../../../opt/homebrew/Cellar/pugixml/1.13/include
DEPENDPATH += $$PWD/../../../../../../../../../opt/homebrew/Cellar/pugixml/1.13/include
