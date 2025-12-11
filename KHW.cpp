#include <bits/stdc++.h>
using namespace std;

int main()
{
    char typeChar;
    string customerName;
    double kwh;
    cout << "Enter type (C/I/R): ";
    cin >> typeChar;
    cout << "Enter name: ";
    cin >> customerName;
    cout << "Enter KWH: ";
    cin >> kwh;

    double kwhOriginal = kwh;
    double bill = 0.0;
    string typeName;

    typeChar = toupper(typeChar);

    if (typeChar == 'C')
    {
        typeName = "Commercial";
        if (kwh > 1000)
        {
            bill += 1000 * 2.75;
            kwh -= 1000;
            if (kwh > 4000)
            {
                bill += 4000 * 3.90;
                kwh -= 4000;
                bill += kwh * 4.25;
            }
            else
            {
                bill += kwh * 3.90;
            }
        }
        else
        {
            bill += kwh * 2.75;
        }
    }
    else if (typeChar == 'I')
    {
        typeName = "Industrial";
        if (kwh > 1000)
        {
            bill += 1000 * 2.75;
            kwh -= 1000;
            if (kwh > 3000)
            {
                bill += 3000 * 2.95;
                kwh -= 3000;
                if (kwh > 5000)
                {
                    bill += 5000 * 3.20;
                    kwh -= 5000;
                    bill += kwh * 4.50;
                }
                else
                {
                    bill += kwh * 3.20;
                }
            }
            else
            {
                bill += kwh * 2.95;
            }
        }
        else
        {
            bill += kwh * 2.75;
        }
    }
    else if (typeChar == 'R')
    {
        typeName = "Residential";
        if (kwh > 500)
        {
            bill += 500 * 2.50;
            kwh -= 500;
            if (kwh > 500)
            {
                bill += 500 * 3.25;
                kwh -= 500;
                bill += kwh * 4.15;
            }
            else
            {
                bill += kwh * 3.25;
            }
        }
        else
        {
            bill += kwh * 2.50;
        }
    }
    else
    {
        cout << "Invalid type\n";
        return 0;
    }

    cout << "Name: " << customerName << "\n";
    cout << "Type: " << typeName << "\n";
    cout << "KWH: " << kwhOriginal << "\n";
    cout << "Total Electricity Cost: Rs. " << bill << "\n";

    return 0;
}
