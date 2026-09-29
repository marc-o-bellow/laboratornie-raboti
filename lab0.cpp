#include <iostream>

using namespace std;

int hello(void);
int greeting(void);
int calc(void);
int final(void);
int calc_double(void);
int area(void);
int celsius(void);

int main(void) {
    int id;
    while (1) {
        id = 0;
        cout << "Choose a program to run:\n"
            "  1. Hello\n"
            "  2. Greeting\n"
            "  3. Calculator\n"
            "  4. Final\n"
            "  Additional:\n"
            "    5. Calc PLUS PRO MAX\n"
            "    6. Area\n"
            "    7. Celsius\n"
            "  \n"
            "  0. Quit\n"
            "\n"
            "program id: ";

        cin >> id;

        if (id == 0) {
            cout << "Goodbye!\n";
            break;
        }
        cout << id;
        cout << "\n--- START ---\n\n";

        switch (id) {
        case 1:
            hello();
            break;
        case 2:
            greeting();
            break;
        case 3:
            calc();
            break;
        case 4:
            final();
            break;
        case 5:
            calc_double();
            break;
        case 6:
            area();
            break;
        case 7:
            celsius();
            break;
        default:
            cout << "Wrong program id. Try again: \n\n";
            break;
        }
        cout << "\n--- END ---\n\n";
    }

    return 0;
}

int hello(void) {
    cout << "Hello world\n";
    return 0;
}

int greeting(void) {
    int age;
    cout << "Enter your age: ";
    cin >> age;
    cout << "Your age is " << age << "\n";
    return 0;
}

int calc(void) {
    int a, b;

    cout << "Enter 2 numbers:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "Sum: " << a << " + " << b << " = " << a + b << endl;
    cout << "Sub: " << a << " - " << b << " = " << a - b << endl;
    cout << "Mul: " << a << " * " << b << " = " << a * b << endl;

    return 0;
}

int final(void) {
    int v, t;

    cout << "Enter speed v: ";
    cin >> v;
    cout << "Enter time t: ";
    cin >> t;
    cout << "Distance s = " << v * t;

    return 0;
}

int calc_double(void) {
    int a, b;

    cout << "Enter 2 numbers:\n";
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    cout << "Sum: " << a << " + " << b << " = " << a + b << endl;
    cout << "Sub: " << a << " - " << b << " = " << a - b << endl;
    cout << "Mul: " << a << " * " << b << " = " << a * b << endl;
    cout << "Div: " << a << " / " << b << " = " << (double)a / b << endl;
    return 0;
}
int area(void) {
    double l, w;

    cout << "Enter length and width:\n";
    cout << "l = ";
    cin >> l;
    cout << "w = ";
    cin >> w;

    cout << "Area: " << l << " * " << w << " = " << l * w << endl;

    return 0;
}
int celsius(void) {
    double c;

    cout << "Enter temperature:\n";
    cout << "C = ";
    cin >> c;

    cout << "F = : " << c << " * 9 / 5 + 32  = " << c * 9 / 5 + 32 << endl;

    return 0;
}

