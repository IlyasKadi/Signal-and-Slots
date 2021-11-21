#include "digitalclock.h"
#include <QTime>


Digitalclock::Digitalclock(QWidget *parent) : QWidget(parent)
{
     createwidgets();
     placewidgets();
     setWindowTitle("Digital clock");
     startTimer(1000);
}
void Digitalclock:: createwidgets()
{
    hour    = new QLCDNumber;
    minutes = new QLCDNumber;
    seconds = new QLCDNumber;
    digiclock = new QHBoxLayout;
}
void Digitalclock ::placewidgets()
{
    setLayout(digiclock);
    digiclock->addWidget(hour);
    digiclock->addWidget(minutes);
    digiclock->addWidget(seconds);
}
void Digitalclock::timerEvent(QTimerEvent *e)
{
    auto T = QTime::currentTime();
    hour->display(T.hour());
    minutes->display(T.minute());
    seconds->display(T.second());
}
