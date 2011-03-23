#include "reseterslider.h"

ReseterSlider::ReseterSlider(QWidget *parent) :
    QSlider(parent)
{
    connect(this, SIGNAL(sliderReleased()), this, SLOT(resetValue()));
}

void ReseterSlider::resetValue()
{
    setValue(0);
}
