#ifndef PAGESTACK_H
#define PAGESTACK_H

#include "bluetoothmanager.h"
#include <QTabWidget>
#include <qrotationsensor.h>

#define DEVICE_NAME "OLAV-LAPTOP"

// add Qt Mobility Project Namespace
//QTM_USE_NAMESPACE

class SignalManager : public QTabWidget
{
    Q_OBJECT
public:
    explicit SignalManager(QWidget *parent = 0);
signals:
    void xRotationChanged(int value);
    void yRotationChanged(int value);
    void zRotationChanged(int value);
    void bluetoothStatusChanged(QString status);
    void scanEnabled(bool);
public slots:
    void rotationDialMoved(int value);
    void verticalMovementSliderMoved(int value);
    void updateReading();
    void scanForBluetoothDevice();
    void changeBluetoothStatus(QString status);
    void enableScan(bool busy);
private:
    QRotationSensor * rotationSensor;
    BluetoothManager * btManager;
};

#endif // PAGESTACK_H
