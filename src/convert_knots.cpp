#include <iostream>
#include "convert_knots.h"
using namespace std;

int main()
{
	int knots = 0;
    cout << "Enter an integer number of knots: " << endl;
    cin >> knots;
    cout << "Miles per minute: " << knots_to_miles_per_minutes(knots) << endl;
    return 0;
}
