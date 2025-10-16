#include <iostream>
using namespace std;

int addition (int i, int k) {
    int result;
    result = i + k;
    return result;
}

int main () {
    int outputResult;
    outputResult = addition(5, 10);
    cout <<"The result is: "<< outputResult <<endl;
    if (outputResult >= 15) {
        cout <<"the result is greater than 15";
    }
    return 0;
};