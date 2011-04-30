# Add files and directories to ship with the application 
# by adapting the examples below.
# file1.source = myfile
# dir1.source = mydir
DEPLOYMENTFOLDERS = # file1 dir1

symbian:TARGET.UID3 = 0xEFDD9717

INCLUDEPATH += C:/QtSDK/Symbian/SDKs/Symbian3Qt473_12b/src/connectivity/bluetooth
DEPENDPATH += C:/QtSDK/Symbian/SDKs/Symbian3Qt473_12b/src/connectivity/bluetooth
INCLUDEPATH += C:/QtSDK/Symbian/SDKs/Symbian3Qt473_12b/src/sensors
DEPENDPATH += C:/QtSDK/Symbian/SDKs/Symbian3Qt473_12b/src/sensors

# Allow network access on Symbian
#symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment
# the following lines and add the respective components to the 
# MOBILITY variable. 
CONFIG += mobility
MOBILITY += sensors connectivity

SOURCES += main.cpp mainwindow.cpp \
    reseterdial.cpp \
    reseterslider.cpp \
    signalmanager.cpp \
    bluetoothmanager.cpp
HEADERS += mainwindow.h \
    reseterdial.h \
    reseterslider.h \
    signalmanager.h \
    bluetoothmanager.h
FORMS += mainwindow.ui

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

symbian {
    TARGET.CAPABILITY = ReadDeviceData LocalServices WriteDeviceData
}

# QBluetooth
#symbian{
#       INCLUDEPATH += /epoc32/include/QBluetooth
#       LIBS += -lQBluetooth

#       customrules.pkg_prerules  = \
#        ";QBluetooth" \
#        "@\"$$(EPOCROOT)Epoc32/InstallToDevice/QBluetooth_selfsigned.sisx\",(0xA003328D)"\
#        " "

#        DEPLOYMENT += customrules
#}
