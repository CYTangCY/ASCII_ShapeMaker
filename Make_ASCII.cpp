#include <iostream>
#include <cmath>
#include <string>
#include <random>
#include <ctime>
using namespace std;

// RandomNumber
char getRandomChar() {
    const string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-=_+[]{}|;:',.<>?/";
    static mt19937 generator(time(nullptr)); 
    uniform_int_distribution<int> distribution(0, chars.size() - 1);
    return chars[distribution(generator)];
}

// Basic
class Shape {
protected:
    int dimension;

public:
    Shape(int d) : dimension(d) {}
    virtual void draw() const = 0; 
};

class Circle : public Shape {
public:
    Circle(int r) : Shape(r) {}

    void draw() const override {
        for (int i = -dimension; i <= dimension; i++) {
            for (int j = -2 * dimension; j <= 2 * dimension; j++) {
                if (sqrt(i * i + (j / 2.0) * (j / 2.0)) < dimension)
                    cout << getRandomChar();
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

class Square : public Shape {
public:
    Square(int side) : Shape(side) {}

    void draw() const override {
        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < 2 * dimension; j++) {
                cout << getRandomChar();
            }
            cout << endl;
        }
    }
};

class Diamond : public Shape {
public:
    Diamond(int diagonal) : Shape(diagonal) {}

    void draw() const override {
        int half = dimension / 2;
        for (int i = -half; i <= half; i++) {
            for (int j = -half; j <= half; j++) {
                if (abs(i) + abs(j) <= half)
                    cout << getRandomChar(); 
                else
                    cout << " ";
            }
            cout << endl;
        }
    }
};

void displayShape(const Shape &shape) {
    shape.draw();
}

int main() {
    string choice;
    int input;

    while (true) {
        cout << "Choose a shape (circle, square, diamond) or type 'exit' to quit: ";
        cin >> choice;

        if (choice == "exit") {
            break;
        }

        cout << "Enter dimension: ";
        cin >> input;

        if (choice == "circle") {
            Circle c(input);
            cout << "\nCircle:\n";
            displayShape(c);
        } else if (choice == "square") {
            Square s(input);
            cout << "\nSquare:\n";
            displayShape(s);
        } else if (choice == "diamond") {
            Diamond d(input);
            cout << "\nDiamond:\n";
            displayShape(d);
        } else {
            cout << "Invalid choice. Please choose again.\n";
        }

        cout << endl;
    }

    cout << "Exiting program." << endl;
    return 0;
}