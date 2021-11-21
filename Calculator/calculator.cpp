#include "calculator.h"
#include <QKeyEvent>
#include <QApplication>





Calculator::Calculator(QWidget *parent)
    : QWidget(parent)
{
    createWidgets();
    placeWidget();
    makeConnexions();
}
Calculator::~Calculator()
{
    delete disp;
    delete layout;
    delete buttonsLayout;
}
void Calculator::createWidgets()
{
    //Creating the layouts
    layout = new QVBoxLayout();
    layout->setSpacing(2);
    //grid layout
    buttonsLayout = new QGridLayout;
    //creating the buttons
    for(int i=0; i < 10; i++)
    {
        digits.push_back(new QPushButton(QString::number(i)));
        digits.back()->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        digits.back()->resize(sizeHint().width(), sizeHint().height());
        QPalette pal = digits.back()->palette();
        pal.setColor(QPalette::Button, QColor(Qt::gray));
        digits.back()->setAutoFillBackground(true);
        digits.back()->setPalette(pal);
        digits.back()->update();
    }
    //enter button
    enter = new QPushButton("Enter",this);
    enter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    enter->resize(sizeHint().width(), sizeHint().height());
    QPalette enterpal = enter->palette();
    enterpal.setColor(QPalette::Button, QColor(Qt::green));
    enter->setAutoFillBackground(true);
    enter->setPalette(enterpal);
    enter->update();



    //reset button
    reset = new QPushButton("AC",this);
    QPalette palreset = reset->palette();
    palreset.setColor(QPalette::Button, QColor(Qt::red));
    reset->setAutoFillBackground(true);
    reset->setPalette(palreset);
    reset->update();



    //operatiosn buttons
    operations.push_back(new QPushButton("+"));
    QPalette oppal = digits.back()->palette();
    oppal.setColor(QPalette::Button, QColor(Qt::blue));
    operations.back()->setAutoFillBackground(true);
    operations.back()->setPalette(oppal);
    operations.back()->update();

    operations.push_back(new QPushButton("-"));
    oppal.setColor(QPalette::Button, QColor(Qt::blue));
    operations.back()->setAutoFillBackground(true);
    operations.back()->setPalette(oppal);
    operations.back()->update();

    operations.push_back(new QPushButton("*"));
    oppal.setColor(QPalette::Button, QColor(Qt::blue));
    operations.back()->setAutoFillBackground(true);
    operations.back()->setPalette(oppal);
    operations.back()->update();

    operations.push_back(new QPushButton("/"));
    oppal.setColor(QPalette::Button, QColor(Qt::blue));
    operations.back()->setAutoFillBackground(true);
    operations.back()->setPalette(oppal);
    operations.back()->update();





    //creating the lcd
    disp = new QLCDNumber(this);
    disp->setDigitCount(6);
}
void Calculator::placeWidget()
{
    layout->addWidget(disp);
    layout->addLayout(buttonsLayout);

    //adding the buttons
    for(int i=1; i <10; i++)
        buttonsLayout->addWidget(digits[i], (i-1)/3, (i-1)%3);

    //Adding the operations
    for(int i=0; i < 4; i++)
        buttonsLayout->addWidget(operations[ i], i, 4);

    //Adding the 0 button
    buttonsLayout->addWidget(digits[0], 3, 0);

   //buttonsLayout->addWidget(enter, 3, 1, 1,2);
    buttonsLayout->addWidget(enter, 3,1);
    buttonsLayout->addWidget(reset,3,2);

    setLayout(layout);
}



void Calculator::makeConnexions()
{
     //Connecting the digits
     for(int i=0; i <10; i++)
         connect(digits[i], &QPushButton::clicked,
                 this, &Calculator::newDigit);

     //Connecting the operations
     for(int i=0; i <4; i++)
         connect(operations[i], &QPushButton::clicked,
                 this, &Calculator::changeOperation);

     //Connecting the enter_button
     connect(enter, &QPushButton::clicked,
             this, &Calculator::showresults);

     //Connecting the reset_button
     connect(reset, &QPushButton::clicked,
             this, &Calculator::resetall);
}
void Calculator::newDigit( )
{
    //getting the sender
    auto button = dynamic_cast<QPushButton*>(sender());

    //getting the value
    int value = button->text().toInt();

    //Check if we have an operation defined
    if(operation)
    {

        //check if we have a value or not
        if(!right)
            right = new double(value);
        else if(right)
            *right = 10 * (*right) + value;

          disp->display(*right);
    }

    else
    {
        if(!left)
            left = new double(value);
        else
            *left = 10 * (*left) + value;
        disp->display(*left);
    }
}
void Calculator::changeOperation()
{
    //Getting the sender button
    auto button = dynamic_cast<QPushButton*>(sender());

    //Storing the operation
    operation = new QString{button->text()};

    //Initiating the right button
    right = new double{0};

    //reseting the display
    disp->display(0);
}
void Calculator::showresults()
{
    //getting the sender
    auto button = dynamic_cast<QPushButton*>(sender());

    //getting the value
    enter = new QPushButton{button};

     if(operation== QString{"+"})
    {
        disp->display(*left + *right);
        *left=*left + *right;
        *right=0;

    }
    else if(operation== QString{"-"})
    {
        disp->display(*left - *right);
        *left=*left - *right;
         *right=0;
    }
    else if(operation== QString{"/"})
    {
         if(*right==0)
         {
             disp->display("err");
         }
         else
         {
             disp->display(*left / *right);
             *left=*left / *right;
              *right=0;
         }
    }
    else if(operation== QString{"*"})
    {
        disp->display(*left * *right);
        *left=*left * *right;
         *right=0;
    }
}


void Calculator::resetall()
{
    auto button = dynamic_cast<QPushButton*>(sender());

    //getting the value
    reset = new QPushButton{button};

    //resetting the pointers
    *left=0;
    right=nullptr;
    operation=nullptr;

    //display when resetting(0)
    disp->display(0);
}


void Calculator::keyPressEvent(QKeyEvent *e)
{
    //Exiting the application by a click on space
    if( e->key() == Qt::Key_Escape)
        qApp->exit(0);
    //You could add more keyboard interation here (like digit to button)
}
