

/*
 * NullActionTest.h
 *
 *  Created on: 21 Apr 2022
 *      Author: colin
 */

#include "NullActionTest.h"

	void NullActionTest::SetUp() {
		id = 1;
		data = 'c';
		gDefaultEvent = make_unique<InputEvent>(id, data);
	}

	void NullActionTest::TearDown() {
		// delete gDefaultEvent;
	}



