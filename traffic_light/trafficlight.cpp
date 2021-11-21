#include "trafficlight.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
#include <QApplication>
#include <QMouseEvent>

TrafficLight::TrafficLight(QWidget * parent): QWidget(parent){

    //Creatign the widgets
    createWidgets();

    //place Widgets
    placeWidgets();
}

void TrafficLight::createWidgets()
{

  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");

  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);
  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");

  greenlight = new QRadioButton;
  greenlight->setEnabled(false);
  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
}



void TrafficLight::placeWidgets()
{

  //VECTOR of lights

  // Placing the widgets
  auto layout = new QVBoxLayout;

  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);

  lights.append(redlight);//4
  lights.append(greenlight);//1
  lights.append(yellowlight);//2

  setLayout(layout);

  index=0;
  startTimer(3000);


}

void TrafficLight::timerEvent(QTimerEvent *e)
{

    index= (index + 1 )%3;
    lights[index]->toggle();

//    currentTime++;

//    if(redlight->isChecked()&& currentTime==4)
//    {
//        yellowlight->toggle();
//        currentTime=0;
//    }
//    if(yellowlight->isChecked()&& currentTime==1)
//    {
//        greenlight->toggle();
//        currentTime=0;
//    }
//    if(greenlight->isChecked()&& currentTime==2)
//    {
//        redlight->toggle();
//        currentTime=0;
//    }


}
void TrafficLight::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_R)
    {

        index=0;
        redlight->toggle();
    }

    if(event->key()==Qt::Key_Y)
     {

            index=1;
            yellowlight->toggle();
     }

     if(event->key()==Qt::Key_G)
     {

         index=1;
         greenlight->toggle();
//               index=2;
//                lights[index]->toggle();
     }
}
