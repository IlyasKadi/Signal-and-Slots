<div id="top"></div>


<!-- PROJECT LOGO -->
<br />
<div align="center">
    <img src="images/logo.png" alt="Logo" width="550" height="380">
  <h2 align="center">Signal and Slots</h2>
  <h3 align="center">Implements your first Gui Interactive Widget</h3>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
      <li>
         <a href="#about-the-project">About The Project</a>
         <ul>
            <li><a href="#getting-started">getting started</a></li>
         </ul>
      </li>
        <li><a href="#Calculator">Calculator</a>
            <ul>
               <li><a href="#Setup">Setup</a></li>
               <li><a href="#Custom-Slots">Custom Slots</a></li>
               <li><a href="#Digits-Interaction">Digits Interaction</a></li>
               <li><a href="#Integer-numbers">Integer numbers</a></li>
               <li><a href="#Operation-Interaction">Operation Interaction</a></li>
               <li><a href="#Enter-Button">Enter Button</a></li>
               <li><a href="#Enhancements">Enhancements</a></li>
            </ul>
          </li>
        <li><a href="#Traffic-Light">Traffic Light</a></li> 
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
# About The Project

<!-- GETTING STARTED -->
## Getting Started

This is an example of how you may give instructions on setting up your project locally.
To get a local copy up and running follow these simple example steps.

1. [**How to install Qt**](https://anassbelcaid.github.io/CS221/qtcreator/)
2. **Clone the repo**
   ```sh
   git clone https://github.com/IlyasKadi/Signal-and-Slots.git
   ```

<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Calculator -->
# Calculator

This exercise follows up to add **interactive** functionality to the **calculator** widgets written in the previous homework. The goal is to use [Signals and Slots](https://doc.qt.io/qt-5/signalsandslots.html) to simulate a basic calculator behavior. The supported operations are`*, +, -, /`.

<p align="center">
     <img src="images/calculator.png">
   </p> 
  
  > Preview of our basic Calculator 
```cpp
class Calculator : public QWidget
{
    Q_OBJECT
public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
 // Add you custom slots here
protected:
    void createWidgets();        //Function to create the widgets
    void placeWidget();         // Function to place the widgets
    void makeConnexions();      // Create all the connectivity
//events
protected:
    void keyPressEvent(QKeyEvent *e)override;     //Override the keypress events

private:
    double * left= new double{0};          //left operand
    double * right=nullptr;         // right operand
    QString *operation=nullptr;  // Pointer on the current operation

public slots:
   void newDigit();
   void changeOperation();
   void showresults();
   void resetall();

private:
    QGridLayout *buttonsLayout; // layout for the buttons
    QVBoxLayout *layout;        //main layout for the button
    QVector<QPushButton*> digits;  //Vector for the digits
    QPushButton *enter;            // enter button
    QPushButton *reset;            // reset button
    QVector<QPushButton*> operations; //operation buttons
    QLCDNumber *disp;             // Where to display the numbers

};
```
   
<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Setup -->
## Setup

In the **starter project** [Callcultaor.zip]() . You’ll find a Qt project to that create the main widget as a custom class.

   - Configure and Run the project. You should see a main widget with the calculator buttons.

   - **Investigate** the header file calculator.h to get a clear idea about the \*attributes\** of the class.

   - You should special attention to the following attributes:
        1. `QVector<QPushButton*> digits` which store a pointer to each digit.
        2. `QVector<QPUshButton*> opertions` same but for the operations buttons.
        3. `QPushButton *enter` the enter button.

   > For now our application has no **reactivity**. The goal of the rest of the section is to obtain `step/step` a fully functional widget.

In order to have a computing functionality, we will represent any mathematical operation by:

`left   (op)  right`

where `(op)` is one of the following allowed operation `+ - * /`.

Hence we will add the following private members to our class `calculator.h`.

```cpp
private:
    int * left;          //left operand
    int * right;         // right operand
    QString *operation;  // Pointer on the current operation
```


<p align="right">(<a href="#top">back to top</a>)</p>


<!-- Custom-Slots -->
## Custom-Slots

Our first step is to respond to each **digit** click. But here we face a **classical problem** which to map multiple signals to the same slot. The slot has to behave **differently** according the which digit was pressed. This problem is thoroughly investigated in [J.Blanchette Blog](https://doc.qt.io/archives/qq/qq10-signalmapper.html).

The trivial solution is to create a slot for each button, but that will be cumbersome.

```cpp
public slots:
        void button0Clicked();
        void button1Clicked();
        ...
        void button9Clicked();
```
**Custom Slot**.

For our case, we will use the **Sender** approach which allow a slot to get the **identity** of the sender object. From that we could get which button was clicked. Hence we will define only one slot such as:

```cpp
public slots:
   void newDigit();
```

<p align="right">(<a href="#top">back to top</a>)</p>


<!-- Digits-Interaction -->
## Digits-Interaction

The idea of this new connexion, it to connect **all the button** to this slot. This function will use the `Sender` method to get the identity of which button was clicked and act accordingly.

   1. Hence we will add the connect the connect all the digits buttons to this slot.

```cpp
     //Connecting the digits
     for(int i=0; i <10; i++)
         connect(digits[i], &QPushButton::clicked, 
                 this, &Calculator::newDigit);
```
   2. Now, we will implement the newDigit slot to show the digit in the LCDNumber.

```cpp
    //Getting the identity of the button using dynamic_cast
    auto button  = dynamic_cast<QPushButton*>(sender());

    // Each button has his own digit in the text
    auto value = button->text()->toInt();

    //Displaying the digit
    disp->display(value);
```
Now each time, you will click on a button, his digit will be **shown** in the LCDNumber.

 > Make sure this step is working as it is the crucial part in the project.


<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Integer-numbers -->
## Integer-numbers

Now that we can react to each digit, it is time to correctly implement the `newDigit` slot. We should clarify two points to clearly understand the implementation:

  - Which number, should be constructing `left` or `right`

      > The response to this question is easy, If we have an operation, then we already have our **left operand** and we should focus on the right.

   - How to add digit to an existing number.

      > Suppose we are working on left = 43. What should happen if we clicked the digit 2. Simply we should move all digit by one digit **(x10)** and then **add** the **2**. Programmatically speeaking this could done by :

      `*left = (*left) * 10 + digit`

Here is the full implementation of this function using the mentioned details:

```cpp
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
            right = new int{value};
        else
            *right = 10 * (*right) + value;

        disp->display(*right);

    }
    else
    {
        if(!left)
            left = new int{value};
        else
            *left = 10 * (*left) + value;

        disp->display(*left);
    }
}
```

Test your application with this code, you should see you number forming by clicking on the digits.

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- Operation-Interaction -->
## Operation-Interaction

Now we will move on the `operation` of the four buttons. We will the same mechanism using the `sender` method. Hence we will define a single slot to handle the click on the operations buttons:

```cpp
public slots:
    void changeOperation();  //Slot to handle the click on operations
    void newDigit();
```
This slot will simply execute the following operations:

   - Get the identity of the sender button.
   - Store the clicked operation.
   - Reset the display to 0

```cpp
void Calculator::changeOperation()
{
    //Getting the sender button
    auto button = dynamic_cast<QPushButton*>(sender());

    //Storing the operation
    operation = new QString{button->text()};

    //Initiating the right button
    right = new int{0};

    //reseting the display
    disp->display(0);
}
```


<p align="right">(<a href="#top">back to top</a>)</p>


<!-- Enter-Button -->
## Enter-Button

The final touch is left to you, You should implement the `slot` for the enter button to compute the result of combining the left and right value according to the operation.!!

<p align="right">(<a href="#top">back to top</a>)</p>



<!-- Enhancements -->
## Enhancements

Our calculator is quite basic, you could enhance his capabilities by:

   - Adding the reset button (C).
   - Adding the three or more operand such as (24 * 23 + 23)!
   - Add a set of operations ( Left that to your creativity!)



<p align="right">(<a href="#top">back to top</a>)</p>


<!-- Traffic Light -->
# Traffic-Light

In this exercise, we will use the [QTimer](https://doc.qt.io/qt-5/qtimer.html) to simulate a **traffic light**.

image
Simulating Traffic Light using Radio Buttons

   1. Download the starter code TrafficLight.zip

   2. Investigate the code in order to underhand each component of the `TrafficLight` class.

   3. Your task is add some functions in order to change `each 3 sedonds` in the following order:

 `Red -> Green -> Yellow`



<p align="right">(<a href="#top">back to top</a>)</p>







Our Team - [AIT EL KADI Ilyas](https://github.com/IlyasKadi) - [AZIZ Oussama](https://github.com/ATAMAN0)

Project Link: [Signal-and-Slots](https://github.com/IlyasKadi/Signal-and-Slots)

Encadré par : [Mr.BELCAID-Anass](https://anassbelcaid.github.io)

<p align="right">(<a href="#top">back to top</a>)</p>
