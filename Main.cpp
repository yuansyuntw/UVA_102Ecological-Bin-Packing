/*	
	UVa: 102 Ecological Bin Packing
	By YuanSyun in 2017/06/29.
*/

#include <iostream>
#include <string>
using namespace std;

//const
const int SPECIES_NUMBER = 3;
const int ORDER_NUMBER = 6;//SPECIES_NUMBER!, 3! = 6. 
/*	Calculation order:
	movement[0] = BCG = 021
	movement[1] = BGC = 012
	movement[2] = CBG = 201
	movement[3] = CGB = 210
	movement[4] = GBC = 102
	movement[5] = GCB = 120
*/
const string RECYCLING_ORDER[ORDER_NUMBER] = { "BCG", "BGC", "CBG" , "CGB", "GBC","GCB" };

//variable
int _in[SPECIES_NUMBER][SPECIES_NUMBER] = { {0,0,0},{0,0,0},{0,0,0} };//B G C
int movement[ORDER_NUMBER];
int minOrderNumber;
int minMovement;
int recyclingOrder[SPECIES_NUMBER];

//function
void setRecyclingOrder(int);
int getMovement(int, int, int);

//main process
int main() {

	//Step1: Input Data
	while (cin >> _in[0][0] >> _in[0][1] >> _in[0][2]
				>> _in[1][0] >> _in[1][1] >> _in[1][2]
				>> _in[2][0] >> _in[2][1] >> _in[2][2]) {

		//Step2: Calculation Movement
		minOrderNumber = 0;
		for (int i = 0; i < ORDER_NUMBER; i++) {
			movement[i] = 0;
			setRecyclingOrder(i);
			if (i == 0) {
				minMovement = getMovement(recyclingOrder[0], recyclingOrder[1], recyclingOrder[2]);
			}
			movement[i] = getMovement(recyclingOrder[0], recyclingOrder[1], recyclingOrder[2]);

			//pick up minMovement
			if (movement[i] < minMovement) {
				minOrderNumber = i;
				minMovement = movement[i];
			}

		}//end for

		 //Step3: Output information
		if (minOrderNumber >= 0 && minOrderNumber < ORDER_NUMBER) {
			cout << RECYCLING_ORDER[minOrderNumber] << " " << minMovement << "\n";
		}
		else {
			//cout << "ERROR! minOrderNumber = " << minOrderNumber << " minMovement = " << minMovement << "\n";
		}
	}//end while

	//system("pause");
	return 0;
}//end main

void setRecyclingOrder(int _index) {
	switch (_index) {
	case 0:
		recyclingOrder[0] = 0;
		recyclingOrder[1] = 2;
		recyclingOrder[2] = 1;

		break;
	case 1:
		recyclingOrder[0] = 0;
		recyclingOrder[1] = 1;
		recyclingOrder[2] = 2;

		break;
	case 2:
		recyclingOrder[0] = 2;
		recyclingOrder[1] = 0;
		recyclingOrder[2] = 1;

		break;
	case 3:
		recyclingOrder[0] = 2;
		recyclingOrder[1] = 1;
		recyclingOrder[2] = 0;

		break;
	case 4:
		recyclingOrder[0] = 1;
		recyclingOrder[1] = 0;
		recyclingOrder[2] = 2;

		break;
	case 5:
		recyclingOrder[0] = 1;
		recyclingOrder[1] = 2;
		recyclingOrder[2] = 0;

		break;
	default:
		break;
	}
}//end getMovement

int getMovement(int _order1, int _order2, int _order3) {
	int _movement=0;

	for (int i = 0; i < SPECIES_NUMBER; i++) {
		if (i != _order1) {
			_movement += _in[0][i];
		}
		if (i != _order2) {
			_movement += _in[1][i];
		}
		if (i != _order3) {
			_movement += _in[2][i];
		}
	}//end for

	return _movement;
}//end getMovement