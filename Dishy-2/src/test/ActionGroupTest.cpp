
#ifdef UNITTEST
#include "gtest.h"
#include "../InputEvent.h"
#include "../BaseAction.h"
#include "../ActionGroup.h"
#include "main.h"


// Test class instantiation
TEST(ActionGroupSuite, testActionGroupClass) {

	int id = 1;
	char data = 'c';
	InputEvent event = InputEvent(id, data);
//	BaseAction action = BaseAction(&event);

//	ActionGroup actionGrp = ActionGroup(&action);


	//	EXPECT_EQ(typeid(ActionGroup), typeid(actionGrp));
//	EXPECT_EQ(1, actionGrp.instanceCount);

/*

	ASSERT_NE(&action, &action2);




	// copy constructor
	Action action2 = Action(action);


	// null event
	Action action3 = Action(NULL);
	EXPECT_NE(&action3, NULL);
	EXPECT_EQ(false, action3.isValid());
*/
}

/*
// Test class instantiation
TEST(ActionGroupSuite, testActionRun) {
	int id = 1;
	char data = 'c';
	ActionEvent event = ActionEvent(id, data);
	EXPECT_NE(&event, NULL);
	Action action = Action(&event);
	EXPECT_NE(&action, NULL);

	EXPECT_EQ(0, action.run());

	// on invalid object
	Action action2 = Action(NULL);
	EXPECT_EQ(-1, action2.run());
}
*/
#endif
