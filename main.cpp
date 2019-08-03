#include <iomanip>
#include <cmath>
#include <iostream>

using namespace std;


const int NUM_POINTS = 5;

int main() {
    
    // Declare Variables
    int x1 = 95, x2 = 85, x3 = 80, x4 = 70, x5 = 60;
    int y1 = 85, y2 = 95, y3 = 70, y4 = 65, y5 = 70;
    int sum_x, sum_y;
    double x_m, y_m;
    double summationTerm1, summationTerm2, summationTerm3;
    double equationConstant1, equationConstant2;
    double std_dev_x, std_dev_y, coefficientOfdetermination;
    
    // Get x_i and y_i values
    cout << "Input x1, y1" << endl;
    cin >> x1 >> y1;
    cout << "Input x2, y2" << endl;
    cin >> x2 >> y2;
    cout << "Input x3, y3" << endl;
    cin >> x3 >> y3;
    cout << "Input x4, y4" << endl;
    cin >> x4 >> y4;
    cout << "Input x5, y5" << endl;
    cin >> x5 >> y5;
    
    //Calculate mean for x and y
    //Calcukate the summation of (x_i - x_m)^2 where x_i is the value for each x and x_m is the mean for x
    //Calculate the summation of (y_i - y_m)^2 where y_i is the value for each y and y_m is the mean for y
    //Calculate the summation of (x_i - x_m)(y_i - y_m) where the variables correspond to the same values for previous two items
    //Calculate the constants b1 and b0 from the linear regression line. Also caluclate std dev for x and y and coefficient of determination
    sum_x = x1 + x2 + x3 + x4 + x5;
    sum_y = y1 + y2 + y3 + y4 + y5;
    x_m = sum_x / static_cast<double>(NUM_POINTS);
    y_m = sum_y / static_cast<double>(NUM_POINTS);
    summationTerm1 = pow (x1 - x_m, 2) + pow (x2 - x_m, 2) + pow (x3 - x_m, 2) + pow (x4 - x_m, 2) + pow (x5 - x_m, 2);
    summationTerm2 = pow (y1 - y_m, 2) + pow (y2 - y_m, 2) + pow (y3 - y_m, 2) + pow (y4 - y_m, 2) + pow (y5 - y_m, 2);
    summationTerm3 = (x1-x_m)*(y1-y_m) + (x2-x_m)*(y2-y_m) + (x3-x_m)*(y3-y_m) + (x4-x_m)*(y4-y_m) + (x5-x_m)*(y5-y_m);
    equationConstant1 = summationTerm3 / summationTerm1;
    equationConstant2 = y_m - (equationConstant1 * x_m);
    std_dev_x = sqrt(summationTerm1 / NUM_POINTS);
    std_dev_y = sqrt(summationTerm2 / NUM_POINTS);
    coefficientOfdetermination = pow((1/static_cast<double>(NUM_POINTS)) * summationTerm3 / (std_dev_x * std_dev_y), 2);
    
    
    //Output x_i and y_i values
    cout << "coordinate" << setw(5) << "x" << setw(7) << "y" << endl;
    cout << setw(7) << "1" << setw(8) << x1 << setw(7) << y1 << endl;
    cout << setw(7) << "2" << setw(8) << x2 << setw(7) << y2 << endl;
    cout << setw(7) << "3" << setw(8) << x3 << setw(7) << y3 << endl;
    cout << setw(7) << "4" << setw(8) << x4 << setw(7) << y4 << endl;
    cout << setw(7) << "5" << setw(8) << x5 << setw(7) << y5 << endl;
    cout << setw(22) << "_________________" << endl << endl;
    

    //Output sum and avg values
    cout << setw(7) << "sum" << setw(8) << sum_x << setw(7) << sum_y << endl;
    cout << setw(7) << "avg" << setw(8) << setprecision(4) << showpoint << x_m << setw(7) << y_m << endl << endl << endl;
    
    
    //Output summation values
    cout << "Summation of the following terms" << endl;
    cout << left << setw(15) << "(x_i - x_m)^2" << setw(16) << "(y_i - y_m)^2" << right << setw(22) << "(x_i - x_m)(y_i - y_m)" << endl;
    cout << setw(13) << setprecision(5) << showpoint << summationTerm1;
    cout << setw(15) << setprecision(5) << showpoint << summationTerm2;
    cout << setw(25) << setprecision(5) << showpoint << summationTerm3 << endl << endl << endl;
    
    
    //Output constants b1 and b0 values
    cout << setw(7) << "b1" << setw(7) << "b0" << endl;
    cout << setw(7) << setprecision(2) << equationConstant1 << setw(7) << setprecision(4) << equationConstant2 << endl << endl << endl;
    
    
    //Output std deviation for x and y values and coefficient of determination value
    cout << setw(11) << "std_dev_x" << setw(11) << "std_dev_y" << setw(8) << "R^2" << endl;
    cout << setw(11) << setprecision(4) << std_dev_x;
    cout << setw(11) << std_dev_y;
    cout << setw(8) << setprecision(2) << coefficientOfdetermination << endl;
    
    
    return 0;
}
