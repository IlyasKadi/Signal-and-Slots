#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <QWidget>
#include <QTimerEvent>

class QRadioButton;

class TrafficLight: public QWidget{
  Q_OBJECT

public:

  TrafficLight(QWidget * parent = nullptr);
  void timerEvent(QTimerEvent *e) override;
  void keyPressEvent(QKeyEvent *event) override;

protected:
     void createWidgets();
     void placeWidgets();


private:
  int index=0;
  int times[3]={4,1,2};
  int currentTime;
  QVector<QRadioButton*> lights ;
  QRadioButton * redlight;
  QRadioButton * yellowlight;
  QRadioButton * greenlight;

};


#endif
