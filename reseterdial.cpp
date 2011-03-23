#include "reseterdial.h"

ReseterDial::ReseterDial(QWidget *parent) :
    QDial(parent)
{
    connect(this, SIGNAL(sliderReleased()), this, SLOT(resetValue()));
}

void ReseterDial::resetValue()
{
    setValue(0);
}
