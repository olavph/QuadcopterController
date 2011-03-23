#ifndef PAGESTACK_H
#define PAGESTACK_H

#include <QTabWidget>
#include <QRotationSensor>

// add Qt Mobility Project Namespace
QTM_USE_NAMESPACE

class SignalManager : public QTabWidget
{
    Q_OBJECT
public:
    explicit SignalManager(QWidget *parent = 0);
signals:
    void xRotationChanged(int value);
    void yRotationChanged(int value);
    void zRotationChanged(int value);
public slots:
    void rotationDialMoved(int value);
    void verticalMovementSliderMoved(int value);
    void updateReading();
private:
    QRotationSensor * rotationSensor;
};

#endif // PAGESTACK_H
