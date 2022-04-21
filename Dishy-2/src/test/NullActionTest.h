
#include "gtest.h"

#include "../InputEvent.h"

class NullActionTest : public ::testing::Test  {


protected:
	int id ;
	char data ;
	InputEvent* gDefaultEvent  ;

	virtual void SetUp();
	virtual void TearDown();
};

