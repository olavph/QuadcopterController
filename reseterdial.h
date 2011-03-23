#ifndef RESETERDIAL_H
#define RESETERDIAL_H

#include <QDial>

class ReseterDial : public QDial
{
    Q_OBJECT
public:
    explicit ReseterDial(QWidget *parent = 0);

signals:

public slots:
    void resetValue();
};

#endif // RESETERDIAL_H
