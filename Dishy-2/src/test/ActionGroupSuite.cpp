#ifdef UNITTEST
#include "gtest.h"
#include "../InputEvent.h"
#include "../BaseAction.h"
#include "../Action.h"
#include "../ActionGroup.h"
#include "../main.h"



// Test class instantiation
TEST(ActionGroupTest, classConstruction) {
	/*
	int id = 1;
	char ag_data = 'c';
	InputEvent ag_event = InputEvent(id, ag_data);



  Action* nAction = new NullAction(&ag_event);
	string description = "TestGroup";

	ActionGroup actionGrp1 = ActionGroup(1, nAction, &description);

	EXPECT_EQ(1, actionGrp1.getMaxActions());
	EXPECT_EQ(description, *(actionGrp1.getDescription()));

	// copy constructor
	// NullAction action2 = NullAction(action);
	//Action* nAction2 = new NullAction(&ag_event);
	ActionGroup actionGrp2 = ActionGroup(actionGrp1);
	ASSERT_NE(&actionGrp1, &actionGrp2);

	EXPECT_EQ(1, actionGrp2.getMaxActions());
	EXPECT_EQ(description, *(actionGrp2.getDescription())) ;
	EXPECT_EQ(1, actionGrp2.run());

*/

}

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
