#include <iostream>
using namespace std;
class Simple_calculator
{
public:
    void performOperation(int choice, double num1, double num2)
    {
        switch (choice)
        {
        case 1:
            cout << "Addition: " << (num1 + num2) << endl;
            break;
        case 2:
            cout << "Subtraction: " << (num1 - num2) << endl;
            break;
        case 3:
            cout << "Multiplication: " << (num1 * num2) << endl;
            break;
        case 4:
            if (num2 != 0)
                cout << "Division: " << (num1 / num2) << endl;
            else
                cout << "Error: Division by zero!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
};
int main()
{
    Simple_calculator s;
    int choice;
    double num1, num2;
    cout << "Select operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n";
    cin >> choice;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    s.performOperation(choice, num1, num2);
    return 0;
}
