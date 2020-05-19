// Eashan Vytla
// Grade: 9
// 5/11/2020
// Project: Complex Numbers
// File: Complex Numbers.cpp
// More Projects on Github: https://github.com/EashanVytla
// The purpose of this program is to introduce object oriented programming to perform operations on complex numbers

#include <iostream>
#include "VytlaEashan_ComplexNumber.h"

using namespace std;

int main()
{
    char replay;
    do {
        //Complex Number Input String Variables
        string mycomplexnum1;
        string mycomplexnum2;

        //Operation Input Char Variables
        char operation;

        //Math Variables
        float mya1;
        float mya2;
        int power;
        int nval = 0;
        float Radians;
        float Degrees;
        float Magnitude;

        //Introduction
        cout << "Welcome to Wolfram Beta Complex Number Calculator.\n";
        cout << " " << endl;

        //First Complex Number Input
        cout << "To begin, please enter your first complex number: ";
        cin >> mycomplexnum1;
        ComplexNumber complexnum1 = ComplexNumber(mycomplexnum1);  //String Input Constructor
        cout << complexnum1.ToString();

        cout << " " << endl;

        //Operations Menu
        cout << "Here are our most popular services:\n+ - Add\n- - Subtract\n/ - divid\n* - Multiply\n^ - Exponent\n1 - Root\n2 - Rotation by Degrees(ExtraCredit)\n3 - Rotation by Radians(ExtraCredit)\n4 - Magnitude(ExtraCredit)\n5 - Conjugate(ExtraCredit)\n";
        cin >> operation;

        cout << " " << endl;

        ComplexNumber complexnum2;
        if (operation != '4' && operation != '5') {
            if (operation == '^') {         //Exponents 2nd input Question
                cout << "Now, please enter your power: ";
                cin >> power;

            }
            else if (operation == '1') {    //Roots 2nd input Question
                cout << "Please enter n value: ";
                cin >> nval;
            }
            else if (operation == '2') {    //Rotate by Degrees 2nd input Question
                cout << "Please enter Degrees: ";
                cin >> Degrees;
            }
            else if (operation == '3') {    //Rotate by Radians 2nd input Question
                cout << "Please enter Radians: ";
                cin >> Radians;
            }
            else {                          //Operation 2nd input Question
                cout << "Now, please enter your second complex number: ";
                cin >> mycomplexnum2;
                complexnum2 = ComplexNumber(mycomplexnum2);
            }
        }

        //Allocating answer variable for regular solutions
        ComplexNumber answer;

        //Allocating answers array for roots solutions
        //nval is initialized to 0 which means that no space will be allocated, unless it is necessary
        ComplexNumber* answers = new ComplexNumber[nval];

        //Performing operations
        if (operation == '+') {
            answer = complexnum1 + complexnum2;
        }
        else if (operation == '-') {
            answer = complexnum1 - complexnum2;
        }
        else if (operation == '*') {
            answer = complexnum1 * complexnum2;
        }
        else if (operation == '/') {
            answer = complexnum1 / complexnum2;
        }
        else if (operation == '^') {
            answer = complexnum1 ^ power;
        }
        else if (operation == '1') {
            answers = complexnum1.Root(nval);
        }
        else if (operation == '2') {
            answer = complexnum1.RotateByDegrees(Degrees);
        }
        else if (operation == '3') {
            answer = complexnum1.RotateByDegrees(Degrees);
        }

        cout << " " << endl;


        //Outputting solutions
        if (operation == '1') { //Roots
            for (int i = 0; i < nval; i++) {
                if (i != 0) {
                    cout << answers[i].ToString() << endl;
                }
                else {
                    cout << answers[i].ToString() << "(Primary Solution)" << endl;
                }
            }
        }
        else if (operation == '4') { //Magnitude
            cout << complexnum1.magnitude() << endl;
        }
        else if (operation == '5') { //Conjugate
            cout << complexnum1.Conjugate().ToString() << endl;
        }
        else { //All regular solutions
            cout << answer.ToString() << endl;
        }

        cout << " " << endl;

        //Replay Input
        cout << "Do you want to replay? [Y/n]";
        cin >> replay;
    } while (replay == 'Y' || replay == 'y');
    

    return 0;
}
