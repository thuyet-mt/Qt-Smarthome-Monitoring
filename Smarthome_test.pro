QT       += core gui sql mqtt charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bedroomform.cpp \
    co2chartform.cpp \
    doorcontrolform.cpp \
    faceform.cpp \
    fingerform.cpp \
    forgotpassform.cpp \
    gardenform.cpp \
    humidchartform.cpp \
    livingroomform.cpp \
    loginform.cpp \
    main.cpp \
    mainwindow.cpp \
    passform.cpp \
    preschartform.cpp \
    registerform.cpp \
    rfidform.cpp \
    tempchartform.cpp \
    usermanageform.cpp

HEADERS += \
    bedroomform.h \
    co2chartform.h \
    doorcontrolform.h \
    faceform.h \
    fingerform.h \
    forgotpassform.h \
    gardenform.h \
    humidchartform.h \
    livingroomform.h \
    loginform.h \
    main.h \
    mainwindow.h \
    passform.h \
    preschartform.h \
    registerform.h \
    rfidform.h \
    tempchartform.h \
    usermanageform.h


FORMS += \
    bedroomform.ui \
    co2chartform.ui \
    doorcontrolform.ui \
    faceform.ui \
    fingerform.ui \
    forgotpassform.ui \
    gardenform.ui \
    humidchartform.ui \
    livingroomform.ui \
    loginform.ui \
    mainwindow.ui \
    passform.ui \
    preschartform.ui \
    registerform.ui \
    rfidform.ui \
    tempchartform.ui \
    usermanageform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    faceRecognition.py \
    test.py
