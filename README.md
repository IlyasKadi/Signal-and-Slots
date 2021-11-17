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

This exercise follows up to add **interactive** functionality to the **calculator** widgets written in the previous homework. The goal is to use [Signals and Slots](https://doc.qt.io/qt-5/signalsandslots.html) to simulate a basic calculator behavior. The supported operations are `*, +, -, /`.


<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Setup -->
## Setup

In the **starter project** [Callcultaor.zip]() . You’ll find a Qt project to that create the main widget as a custom class.

   - Configure and Run the project. You should see a main widget with the calculator buttons.

   - **Investigate** the header file calculator.h to get a clear idea about the *attributes** of the class.

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



<p align="right">(<a href="#top">back to top</a>)</p>


<!-- Digits-Interaction -->
## Digits-Interaction



<p align="right">(<a href="#top">back to top</a>)</p>

<!-- Integer-numbers -->
## Integer-numbers



<p align="right">(<a href="#top">back to top</a>)</p>



<!-- Operation-Interaction -->
## Operation-Interaction




<p align="right">(<a href="#top">back to top</a>)</p>


<!-- Enter-Button -->
## Enter-Button



<p align="right">(<a href="#top">back to top</a>)</p>



<!-- Enhancements -->
## Enhancements



<p align="right">(<a href="#top">back to top</a>)</p>


<!-- Traffic Light -->
# Traffic-Light



<p align="right">(<a href="#top">back to top</a>)</p>







Our Team - [AIT EL KADI Ilyas](https://github.com/IlyasKadi) - [AZIZ Oussama](https://github.com/ATAMAN0)

Project Link: [Signal-and-Slots](https://github.com/IlyasKadi/Signal-and-Slots)

Encadré par : [Mr.BELCAID-Anass](https://anassbelcaid.github.io)

<p align="right">(<a href="#top">back to top</a>)</p>
