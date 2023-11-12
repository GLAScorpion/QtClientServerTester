QT += quick network
SOURCES += \
        clienthandler.cpp \
        main.cpp \
        myclient.cpp \
        utils.cpp

resources.files = main.qml 
resources.prefix = /$${TARGET}
RESOURCES += resources

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    clienthandler.h \
    myclient.h \
    utils.h

DISTFILES += \
    android/AndroidManifest.xml \
    android/build.gradle \
    android/res/values/libs.xml

android {
    ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

    DISTFILES += \
        android/AndroidManifest.xml \
        android/build.gradle \
        android/res/values/libs.xml
}
