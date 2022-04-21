
#ifdef UNITTEST
#include "gtest.h"
#include "../InputEvent.h"
#include "../NullAction.h"
#include "main.h"


int id = 1;
char data = 'c';
InputEvent gDefaultEvent = InputEvent(id, data);


// Test class instantiation
TEST(NullActionSuite, testActionClass) {

	NullAction action = NullAction(&gDefaultEvent);
	EXPECT_NE(&action, NULL);
	EXPECT_EQ(typeid(NullAction), typeid(action));
	EXPECT_EQ(1, action.instanceCount);

	// copy constructor
	NullAction action2 = NullAction(action);
	EXPECT_EQ(2, action.instanceCount);

	EXPECT_EQ(typeid(NullAction), typeid(action2));
	ASSERT_NE(&action, &action2);

}

// DEATH TEST
// this test will cause the assert to trigger and fail the test
// Arduino does not allow for threads so we cannot use DEATH_TEST
/*
TEST(NullActionSuite, testActionInvalidEvent) {
	// null event pointer
	NullAction action1 = NullAction(NULL);

  // pointer to NULL
	InputEvent* pNullEvent = NULL;
	NullAction action2 = NullAction(pNullEvent);

}
*/



// Test class run
TEST(NullActionSuite, testActionRun) {

	NullAction action = NullAction(&gDefaultEvent);
	EXPECT_NE(&action, NULL);

	EXPECT_EQ(0, action.run());

}

TEST(NullActionSuite, testActionMemoryLeak) {
	{
		NullAction baseAction = NullAction(&gDefaultEvent);
		DisplayAction displayAction = DisplayAction(1, &gDefaultEvent);
		Action* action = &displayAction;
		EXPECT_EQ(2, NullAction::instanceCount);
	}
	EXPECT_EQ(0, NullAction::instanceCount);
}


TEST(ActionSuite, testActionRun) {
	NullAction action = NullAction(&gDefaultEvent);

	Action* bAction = &action;
	EXPECT_EQ(1, NullAction::instanceCount);
}


#endif
