#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

#include <QWidget>
#include <QLCDNumber>
#include <QTime>
#include <QHBoxLayout>


class Digitalclock : public QWidget
{
    Q_OBJECT
public:
    explicit Digitalclock(QWidget *parent = nullptr);
    void timerEvent(QTimerEvent*e) override ;

protected:
    void createwidgets();
    void placewidgets();

private:
    QLCDNumber *hour;
    QLCDNumber *minutes;
    QLCDNumber *seconds;
    QHBoxLayout *digiclock;
};

#endif // DIGITALCLOCK_H
