#include "signalmanager.h"

SignalManager::SignalManager(QWidget *parent) :
    QTabWidget(parent)
{
    rotationSensor = new QRotationSensor(this);
    rotationSensor->start();
    if (!rotationSensor->isActive()) {
        qWarning("RotationSensor didn't start!");
    }

    connect(rotationSensor, SIGNAL(readingChanged()), this, SLOT(updateReading()));
}

void SignalManager::rotationDialMoved(int value)
{
    qDebug("Dial moved: %d", value);
}

void SignalManager::verticalMovementSliderMoved(int value)
{
    qDebug("Vertical slider moved: %d", value);
}

void SignalManager::updateReading()
{
    qDebug("Rotation changed");
    emit xRotationChanged(rotationSensor->reading()->x());
    emit yRotationChanged(rotationSensor->reading()->y());
    emit zRotationChanged(rotationSensor->reading()->z());
}
