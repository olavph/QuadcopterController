#ifndef BLUETOOTHMANAGER_H
#define BLUETOOTHMANAGER_H

#include <QString>
#include <QObject>
#include <qbluetooth.h>
#include <qbluetoothdevicediscoveryagent.h>
#include <qbluetoothlocaldevice.h>

// add Qt Mobility Project Namespace
QTM_USE_NAMESPACE

class BluetoothManager : public QObject
{
    Q_OBJECT
public:
    explicit BluetoothManager(QString targetDeviceName, QObject *parent = 0);
signals:
    void status(QString);
    void busy(bool);
public slots:
    void startScan();
    void deviceFound(const QBluetoothDeviceInfo&);
    void pairingDone(const QBluetoothAddress&, QBluetoothLocalDevice::Pairing);
private slots:
    void scanFinished();
    void hostModeStateChanged(QBluetoothLocalDevice::HostMode);
private:
    QString targetDeviceName;
    QBluetoothDeviceDiscoveryAgent *discoveryAgent;
    QBluetoothLocalDevice *localDevice;
};

#endif // BLUETOOTHMANAGER_H
