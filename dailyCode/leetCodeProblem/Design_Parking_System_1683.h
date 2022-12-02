
//https://leetcode.com/problems/design-parking-system/?envType=study-plan&id=programming-skills-i
//1603. Design Parking System
#ifndef ___Design_Parking_System_1683_h___
#define ___Design_Parking_System_1683_h___
#include<algorithm>
#include<iostream>
#include<map>
#include<queue>
#include<string>
#include<unordered_map>
#include<utility>
#include<vector>
#include<sstream>
#include<stack>
using namespace std;

class ParkingSystem {
public:
	int big;
	int medium;
	int small;

	// use uniform initialization
	ParkingSystem(int big, int medium, int small) : big(big), medium(medium), small(small) {}

	bool addCar(int carType) {
		if (carType == 1) {
			if (big > 0) {
				big--;
				return true;
			}
			else {
				return false;
			}
		}
		else if (carType == 2) {
			if (medium > 0) {
				medium--;
				return true;
			}
			else {
				return false;
			}
		}
		else if (carType == 3) {
			if (small > 0) {
				small--;
				return true;
			}
			else {
				return false;
			}
		}
		return false;
	}
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

#endif // ___Design_Parking_System_1683_h___