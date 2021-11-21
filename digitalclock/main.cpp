#include <QApplication>
#include "digitalclock.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    //Creating the traffic light
    auto light = new Digitalclock;




    //showing the trafic light
    light->show();

    return a.exec();
}
