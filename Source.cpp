#include <iostream>
#include <string>
#include <sstream>

using namespace std;



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
    cout << " Result: " << sum; //we display the total sum

}