/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#include "input.h"

//===========================
// Read INPUTs
//===========================
char readInput() {
	char chr;
	char cr;
	printf("Enter a character: ");
//	scanf("%c%c",&chr, &cr);
	string input;
	cin >> input;

//	printf("You entered %c.\n", chr);

	cout << "You entered " << input << endl;
	return input.at(0); //chr;
}

