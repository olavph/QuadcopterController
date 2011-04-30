#include "signalmanager.h"
#include <QDebug>

SignalManager::SignalManager(QWidget *parent) :
    QTabWidget(parent), rotationSensor(new QRotationSensor(this)), btManager(new BluetoothManager(DEVICE_NAME))
{
    qDebug() << "Starting rotation sensor";
    rotationSensor->start();
    if (!rotationSensor->isActive()) {
        qWarning() << "RotationSensor didn't start!";
    }
    connect(rotationSensor, SIGNAL(readingChanged()), this, SLOT(updateReading()));

    connect(btManager, SIGNAL(status(QString)), this, SLOT(changeBluetoothStatus(QString)));
    connect(btManager, SIGNAL(busy(bool)), this, SLOT(enableScan(bool)));
}

void SignalManager::rotationDialMoved(int value)
{
    qDebug() << "Dial moved:" << value;
}

void SignalManager::verticalMovementSliderMoved(int value)
{
    qDebug() << "Vertical slider moved:" << value;
}

void SignalManager::updateReading()
{
//    qDebug() << "Rotation changed";
    emit xRotationChanged(rotationSensor->reading()->x());
    emit yRotationChanged(rotationSensor->reading()->y());
    emit zRotationChanged(rotationSensor->reading()->z());
}

void SignalManager::scanForBluetoothDevice()
{
    btManager->startScan();
}

void SignalManager::changeBluetoothStatus(QString status)
{
    emit bluetoothStatusChanged(status);
}

void SignalManager::enableScan(bool busy)
{
    emit scanEnabled(!busy);
}
