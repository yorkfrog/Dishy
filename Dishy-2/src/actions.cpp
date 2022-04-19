/*
 *  Created on: Nov 27, 2015
 *      Author: jan
 */

#include "actions.h"

//===========================
// Do Actions / OUTPUTS
//===========================
int doActionButton1(ActionEvent* event) {
	printf("\nDoing action ONE on [%c].\n", event->getData());
	return 1;
}
int doActionButton2(ActionEvent* event) {
	printf("\nDoing action TWO on [%c].\n", event->getData());
	return 1;
}
int doActionButton3(ActionEvent* event) {
	printf("\nDoing action THREE on [%c].\n", event->getData());
	return 1;
}
int doActionButton4(ActionEvent* event) {
	printf("\nDoing action FOUR on [%c].\n", event->getData());
	return 1;
}

int doActionDefault(ActionEvent* event) {
	printf("\nNO action for [%c].\n", event->getData());
	return 0;
}




