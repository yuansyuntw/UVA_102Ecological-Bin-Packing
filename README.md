# UVA_102Ecological-Bin-Packing

## Solve the problem

My Step:

1.	Read input data.
2.	Calcaulation Movement
3.	Output information

## Step1: Read input data.
Input : B G C B G C B G C

## Step2: Calcaulation Movement And Pick Up minMovement
Do not count the selected numbers.

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
	
## Step3: Output information
Use index to display the recovery order.

	const string RECYCLING_ORDER[ORDER_NUMBER] = { "BCG", "BGC", "CBG" , "CGB", "GBC","GCB" };
