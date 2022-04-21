
#ifdef UNITTEST
#include "gtest.h"

// test fixtures
#include "NullActionTest.h"

// Test targets
#include "../InputEvent.h"
#include "../NullAction.h"
#include "../main.h"


// Test class instantiation
TEST_F(NullActionTest, classConstruction) {

	NullAction action = NullAction(gDefaultEvent);
	EXPECT_NE(&action, NULL);
	EXPECT_EQ(typeid(NullAction), typeid(action));
	EXPECT_EQ(1, action.instanceCount);

	// copy constructor
	NullAction action2 = NullAction(action);
	EXPECT_EQ(2, action.instanceCount);
	EXPECT_EQ(typeid(NullAction), typeid(action2));
	ASSERT_NE(&action, &action2);

}

// DEATH TEST#endif /* NULLACTIONTEST_H_ */

// this test will cause the assert to trigger and fail the test
// Arduino does not allow for threads so we cannot use DEATH_TEST
/*
 TEST(NullActionTest, invalidEventOnActionConstruction) {
 // null event pointer
 NullAction action1 = NullAction(NULL);

 // pointer to NULL
 InputEvent* pNullEvent = NULL;
 NullAction action2 = NullAction(pNullEvent);

 }
 */

// Test class run
TEST_F(NullActionTest, actionRun) {

	NullAction action = NullAction(gDefaultEvent);
	EXPECT_NE(&action, NULL);

	EXPECT_EQ(0, action.run());

}

TEST_F(NullActionTest, setGetActionDescription) {

	NullAction action = NullAction(gDefaultEvent);
	string desc = "TestDesc";
	action.setDescription(&desc);

	EXPECT_EQ(desc, *(action.getDescription()));
}

TEST_F(NullActionTest, noActionMemoryLeak) {
	{
		NullAction baseAction = NullAction(gDefaultEvent);
		DisplayAction displayAction = DisplayAction(1, gDefaultEvent);
		Action *action = &displayAction;
		EXPECT_EQ(2, NullAction::instanceCount);
	}
	EXPECT_EQ(0, NullAction::instanceCount);
}

TEST(ActionInterfaceTest, runViaAction) {

	int id = 1;
	char data = 'c';
	InputEvent gDefaultEvent = InputEvent(id, data);

	NullAction action = NullAction(&gDefaultEvent);

	Action *bAction = &action;
	EXPECT_EQ(1, NullAction::instanceCount);
}

#endif


