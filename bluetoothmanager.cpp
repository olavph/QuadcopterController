#include "bluetoothmanager.h"
#include <qbluetoothaddress.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>
#include <QDebug>

BluetoothManager::BluetoothManager(QString targetDeviceName, QObject *parent)
:   QObject(parent), targetDeviceName(targetDeviceName), discoveryAgent(new QBluetoothDeviceDiscoveryAgent), localDevice(new QBluetoothLocalDevice)
{
    qDebug() << "Starting bluetooth manager with target" << targetDeviceName;

    connect(localDevice, SIGNAL(hostModeStateChanged(QBluetoothLocalDevice::HostMode)),
            this, SLOT(hostModeStateChanged(QBluetoothLocalDevice::HostMode)));
    localDevice->setHostMode(QBluetoothLocalDevice::HostConnectable);

    //TODO change to limited
    discoveryAgent->setInquiryType(QBluetoothDeviceDiscoveryAgent::GeneralUnlimitedInquiry);

    connect(discoveryAgent, SIGNAL(deviceDiscovered(const QBluetoothDeviceInfo&)),
            this, SLOT(deviceFound(const QBluetoothDeviceInfo&)));
    connect(discoveryAgent, SIGNAL(finished()), this, SLOT(scanFinished()));

    connect(localDevice, SIGNAL(pairingFinished(const QBluetoothAddress&, QBluetoothLocalDevice::Pairing)),
            this, SLOT(pairingDone(const QBluetoothAddress&, QBluetoothLocalDevice::Pairing)));
}

void BluetoothManager::deviceFound(const QBluetoothDeviceInfo &info)
{
    qDebug() << "Bluetooth device found:" << info.name();
    if (info.name() == targetDeviceName) {
        qDebug() << "Pairing with device:" << info.name();
        emit status("Pairing");
        localDevice->requestPairing(info.address(), QBluetoothLocalDevice::Paired);
        discoveryAgent->stop();
    }
}

void BluetoothManager::startScan()
{
    qDebug() << "Scanning for bluetooth device" << targetDeviceName;
    emit status("Scanning");
    emit busy(true);
    discoveryAgent->start();
}

void BluetoothManager::scanFinished()
{
    qDebug() << "Device not found";
    emit status("Device not found");
    emit busy(false);
}

void BluetoothManager::hostModeStateChanged(QBluetoothLocalDevice::HostMode mode)
{
    if (mode == QBluetoothLocalDevice::HostPoweredOff) {
        qDebug() << "Bluetooth is off";
        emit status("Off");
        emit busy(false);
    }
}

void BluetoothManager::pairingDone(const QBluetoothAddress &address, QBluetoothLocalDevice::Pairing pairing)
{
    if (pairing == QBluetoothLocalDevice::Paired || pairing == QBluetoothLocalDevice::AuthorizedPaired ) {
        qDebug() << "Successfully paired";
        emit status("Paired");
    } else {
        qDebug() << "Failed pairing with device";
        emit status("Pairing failed");
    }
    emit busy(false);
}
