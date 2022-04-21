
#include "gtest.h"

#include "../InputEvent.h"
#include "../NullAction.h"

class ActionGroupTest : public ::testing::Test  {

protected:
	int id ;
	char data ;
	InputEvent* gpInputEvent  ;
	NullAction* gpNullAction ;

	virtual void SetUp();
	virtual void TearDown();
};

