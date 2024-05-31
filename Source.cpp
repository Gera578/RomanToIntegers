#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string IntToRoman(int num) {
    string roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
    int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };

    string result = ""; //variable to display the value in string

    for (int i = 0; i < 13; i++) {
        while (num >= values[i]) {
            num -= values[i];
            result += roman[i];
        }
    }

    return result;
}



int main() {
    string s = "MCMXCIV";
    int sum = 0;


    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == 'I') {
            if (i+1 < s.size() //avoid a 'out-of range' error
                and s[i + 1] == 'V') //skips the first element and checks the next element
            {
                sum += 4; //if I exists and then V exists, then 4 is added to the sum
                i++; //increments i by 1 to skip the 'V'.
            }
            else if (i + 1 < s.size() and s[i + 1] == 'X') {
                sum += 9;
                i++;
            }
            else {
                sum += 1; //if there was no V, then the answer is 1, which is the value of the letter
            }
        }
        else if (s[i] == 'X') {
            if (i + 1 < s.size() and s[i + 1] == 'L') {
                sum += 40;
                i++; //increments i by 1 to skip the 'V'.
            }
            else if (i + 1 < s.size() and s[i + 1] == 'C') {
                sum += 90;
                i++;
            }
            else {
                sum += 10;
            }
        }
        else if (s[i] == 'C') {
            if (i + 1 < s.size() and s[i + 1] == 'D') {
                sum += 400;
                i++; //increments i by 1 to skip the 'V'.
            }
            else if (i + 1 < s.size() and s[i + 1] == 'M') {
                sum += 900;
                i++;
            }
            else {
                sum += 100;
            }
        }
        //values for individual letters
        else if (s[i] == 'V') {
            sum += 5;
        }
        else if (s[i] == 'L') {
            sum += 50;
        }
        else if (s[i] == 'D') {
            sum += 500;
        }
        else if (s[i] == 'M') {
            sum += 1000;
        }
    }
    cout << " Result: " << sum << endl; //we display the total sum

    int number = 1994;

    string romanNumber = IntToRoman(number);
    cout << "Integer: "<<number<<" to roman number: " << romanNumber << endl;



}