
#ifdef UNITTEST
#include "gtest.h"
#include "ActionEvent.h"
#include "../BaseAction.h"
#include "main.h"


// Test class instantiation
TEST(ActionSuite, testActionClass) {

	int id = 1;
	char data = 'c';
	ActionEvent event = ActionEvent(id, data);
	EXPECT_NE(&event, NULL);

	BaseAction action = BaseAction(&event);
	EXPECT_NE(&action, NULL);
	EXPECT_EQ(typeid(BaseAction), typeid(action));
	EXPECT_EQ(1, action.instanceCount);
	EXPECT_EQ(true, action.isValid());

	// copy constructor
	BaseAction action2 = BaseAction(action);
	EXPECT_EQ(2, action.instanceCount);

	EXPECT_EQ(typeid(BaseAction), typeid(action2));
	ASSERT_NE(&action, &action2);
	EXPECT_EQ(true, action2.isValid());

	// null event
	BaseAction action3 = BaseAction(NULL);
	EXPECT_NE(&action3, NULL);
	EXPECT_EQ(false, action3.isValid());

}

TEST(ActionXXXXXSuite, testActionRun) {
	int id = 1;
	char data = 'c';
	ActionEvent event = ActionEvent(id, data);
	EXPECT_NE(&event, NULL);

	BaseAction action = BaseAction(&event);

	Action* bAction = &action;
	EXPECT_EQ(true, bAction->isValid());

}

// Test class instantiation
TEST(ActionSuite, testActionRun) {
	int id = 1;
	char data = 'c';
	ActionEvent event = ActionEvent(id, data);
	EXPECT_NE(&event, NULL);
	BaseAction action = BaseAction(&event);
	EXPECT_NE(&action, NULL);

	EXPECT_EQ(0, action.run());

	// on invalid object
	BaseAction action2 = BaseAction(NULL);
	EXPECT_EQ(-1, action2.run());
}

#endif
