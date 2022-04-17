/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#include "action.h"

//===========================
// Do Actions / OUTPUTS
//===========================
int doActionButton1(char input) {
	printf("\nDoing action ONE on [%c].\n", input);
	return 1;
}
int doActionButton2(char input) {
	printf("\nDoing action TWO on [%c].\n", input);
	return 1;
}
int doActionButton3(char input) {
	printf("\nDoing action THREE on [%c].\n", input);
	return 1;
}
int doActionButton4(char input) {
	printf("\nDoing action FOUR on [%c].\n", input);
	return 1;
}

int doActionDefault(char input) {
	printf("\nNO action for [%c].\n", input);
	return 0;
}

int doActionOnInput(char input) {
	int result = 0;
	switch (input) {
	case '1':
		result = doActionButton1(input);
		break;
	case '2':
		result = doActionButton2(input);
		break;
	case '3':
		result = doActionButton3(input);
		break;
	case '4':
		result = doActionButton4(input);
		break;
	default:
		result = doActionDefault(input);
		break;
	}
	return result;
}

