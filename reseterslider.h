#ifndef RESETERSLIDER_H
#define RESETERSLIDER_H

#include <QSlider>

class ReseterSlider : public QSlider
{
    Q_OBJECT
public:
    explicit ReseterSlider(QWidget *parent = 0);

signals:

public slots:
    void resetValue();
};

#endif // RESETERSLIDER_H
