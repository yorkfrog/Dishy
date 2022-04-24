
#include "gtest.h"
#include <memory>

#include "../InputEvent.h"

class NullActionTest : public ::testing::Test  {


protected:
	int id ;
	char data ;
	unique_ptr<InputEvent> gDefaultEvent  ;

	virtual void SetUp();
	virtual void TearDown();
};

