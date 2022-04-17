/*
 * localRun.cpp
 *
 *  Created on: 17 Apr 2022
 *      Author: colin
 */
#include <stdio.h>

#include "main.h"

int main(int argc, char *argv[])
{
	printf("Init local run...\n");
	setup();
	printf("\nStart loop for local run...\n");
	loop();
	printf("\nExit local run.");


}


