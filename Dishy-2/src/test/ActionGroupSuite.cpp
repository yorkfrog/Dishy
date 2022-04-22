#ifdef UNITTEST
#include "gtest.h"
#include "../InputEvent.h"
#include "../BaseAction.h"
#include "../Action.h"
#include "../ActionGroup.h"
#include "../main.h"



// Test class instantiation
TEST(ActionGroupTest, classConstruction) {

	string description = "TestGroup";

	InputEvent event1 = InputEvent(1, 'a');
  Action* nAction = new NullAction(&event1);
	ActionGroup actionGrp1 = ActionGroup(1, nAction, description);
	EXPECT_EQ(1, actionGrp1.getMaxActions());
	EXPECT_EQ(description, actionGrp1.getDescription());

	delete nAction;

	InputEvent event2 = InputEvent(2, 'b');
  NullAction action2 = NullAction(&event2);
	ActionGroup actionGrp3 = ActionGroup(1, &action2, "Literal Description");
	EXPECT_EQ(1, actionGrp3.getMaxActions());
	EXPECT_EQ("Literal Description", actionGrp3.getDescription());

	// copy constructor
	ActionGroup actionGrp2 = ActionGroup(actionGrp1);
	ASSERT_NE(&actionGrp1, &actionGrp2);

	EXPECT_EQ(1, actionGrp2.getMaxActions());
	EXPECT_EQ(description, actionGrp2.getDescription()) ;
	EXPECT_EQ(0, actionGrp2.run());

}

/*
 * Get tests from NullAction ........
 */

/*
 // Test class instantiation
 TEST(ActionGroupTest, testActionRun) {
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
