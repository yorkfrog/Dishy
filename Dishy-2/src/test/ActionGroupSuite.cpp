#ifdef UNITTEST
#include "gtest.h"
#include "../InputEvent.h"
#include "../BaseAction.h"
#include "../Action.h"
#include "../ActionGroup.h"
#include "../main.h"

namespace ActionGroupTestNS {

const int defaultId = 1;
const char defaultActionData = 'a';
const string defaultDescription = "action description";

void expectStartEndInstaneCounts()
{
	EXPECT_EQ(0, InputEvent::instanceCount);
	EXPECT_EQ(0, NullAction::instanceCount);
	EXPECT_EQ(0, ActionGroup::instanceCount);
}

// 1 event instance
// 1 action instance
NullAction makeNullAction(int id, char data)
{
	InputEvent event1 = InputEvent(id, data);
	return NullAction(&event1);
}

// 1 event instance
// 1 action instance
// 1 actionGrp instance
ActionGroup makeActionGroup()
{
	NullAction action1 = makeNullAction(defaultId, defaultActionData);
	return ActionGroup(1, &action1, defaultDescription);
}

void expectAfterActionGroupConstruction(ActionGroup *actionGrp, string description, int actionGrpInstanceCount)
{
	EXPECT_NE(actionGrp, NULL);
	EXPECT_EQ(typeid(ActionGroup), typeid(*actionGrp));
	EXPECT_EQ(description, actionGrp->getDescription());
	EXPECT_EQ(1, actionGrp->getMaxActions());
	EXPECT_EQ(actionGrpInstanceCount, ActionGroup::instanceCount);
}

// Test class instantiation
TEST(ActionGroupTest, classConstructionFromActionObject)
{

	expectStartEndInstaneCounts();
	{
		NullAction action1 = makeNullAction(defaultId, defaultActionData);
		ActionGroup actionGrp1 = ActionGroup(1, &action1, defaultDescription);
		expectAfterActionGroupConstruction(&actionGrp1, defaultDescription, 1);
	}
	expectStartEndInstaneCounts();
}

TEST(ActionGroupTest, classConstructionFromActionNewPointer)
{

	expectStartEndInstaneCounts();
	{
		InputEvent event1 = InputEvent(defaultId, defaultActionData);
		NullAction *pAction1 = new NullAction(&event1);
		ActionGroup actionGrp1 = ActionGroup(1, pAction1, defaultDescription);
		expectAfterActionGroupConstruction(&actionGrp1, defaultDescription, 1);
		delete pAction1;
	}
	expectStartEndInstaneCounts();
}

TEST(ActionGroupTest, classCopyConstruction)
{
	// copy constructor
	expectStartEndInstaneCounts();
	{
		NullAction action1 = makeNullAction(defaultId, defaultActionData);
		ActionGroup actionGrp1 = makeActionGroup();

		ActionGroup actionGrp2 = ActionGroup(actionGrp1);
		expectAfterActionGroupConstruction(&actionGrp2, defaultDescription, 2);
		ASSERT_NE(&actionGrp1, &actionGrp2);
		ASSERT_NE(&(actionGrp1.getDescription()), &(actionGrp2.getDescription()));
		ASSERT_EQ(actionGrp1.getDescription(), actionGrp2.getDescription());
		ASSERT_EQ(actionGrp1.getMaxActions(), actionGrp2.getMaxActions());
	}
	expectStartEndInstaneCounts();
}

/*
 TEST_F(ActionGroupTest, classOperatorEquals) {
 // copy constructor
 EXPECT_EQ(1, InputEvent::instanceCount);
 EXPECT_EQ(0, NullAction::instanceCount);
 {
 InputEvent event1 = InputEvent(1, 'a');
 NullAction action1 = NullAction(&event1);
 InputEvent event3 = InputEvent(3, 'c');
 NullAction action3 = NullAction(&event3);

 EXPECT_NE(action1.getEvent()->getId(), action3.getEvent()->getId());
 EXPECT_NE(action1.getEvent()->getData(), action3.getEvent()->getData());
 EXPECT_NE(action1.getEvent(), action3.getEvent());
 EXPECT_EQ(2, NullAction::instanceCount);
 EXPECT_EQ(5, InputEvent::instanceCount);

 action1 = action3;

 EXPECT_EQ(action1.getEvent()->getId(), action3.getEvent()->getId());
 EXPECT_EQ(action1.getEvent()->getData(), action3.getEvent()->getData());
 EXPECT_NE(action1.getEvent(), action3.getEvent());

 EXPECT_EQ(2, NullAction::instanceCount);
 EXPECT_EQ(5, InputEvent::instanceCount);
 }
 EXPECT_EQ(0, NullAction::instanceCount);
 EXPECT_EQ(1, InputEvent::instanceCount);
 }

 */

// DEATH TEST#endif /* NULLACTIONTEST_H_ */
// this test will cause the assert to trigger and fail the test
// Arduino does not allow for threads so we cannot use DEATH_TEST
/*
 TEST(ActionGroupTest, invalidEventOnActionConstruction) {
 // null event pointer
 NullAction action1 = NullAction(NULL);
 "
 // pointer to NULL
 InputEvent* pNullEvent = NULL;
 NullAction action2 = NullAction(pNullEvent);

 }
 */

// Test class run
TEST(ActionGroupTest, actionRun)
{
	ActionGroup actionGrp1 = makeActionGroup();

	EXPECT_EQ(0, actionGrp1.run());
}

TEST(ActionGroupTest, setGetActionDescription)
{
	ActionGroup actionGrp1 = makeActionGroup();
	string desc = "TestDesc";
	actionGrp1.setDescription(desc);
	EXPECT_EQ(desc, actionGrp1.getDescription());

	actionGrp1.setDescription("String Literal");
	EXPECT_EQ("String Literal", actionGrp1.getDescription());
}

TEST(ActionGroupTest, noActionConstructionMemoryLeak)
{

	expectStartEndInstaneCounts();
	{
		// 1 event instance
		// 1 action instance
		// 1 actionGrp instance
		ActionGroup actionGrp1 = makeActionGroup();

		// 1 event instance
		// 1 action instance
		NullAction nAction = makeNullAction(defaultId, defaultActionData);

		// 1 event instance
		// 1 action instance
		// 1 actionGrp instance
		ActionGroup *pActionGrp2 = new ActionGroup(1, &nAction, defaultDescription);
		ActionGroup *pActionGrp3 = &actionGrp1;
		EXPECT_EQ(3, InputEvent::instanceCount);
		EXPECT_EQ(3, NullAction::instanceCount);
		EXPECT_EQ(2, ActionGroup::instanceCount);
		delete pActionGrp2;
	}
	expectStartEndInstaneCounts();
}

/*
 TEST_F(ActionGroupTest, clone) {
 // the Test Fixture creates an InputEvent instance which we won;t use.
 EXPECT_EQ(1, InputEvent::instanceCount) << "Check 0 InputEvent instance on entry.";
 EXPECT_EQ(0, NullAction::instanceCount) << "Check 0 NullAction instance on entry.";
 {
 InputEvent event1 = InputEvent(1, 'a');
 NullAction action1 = NullAction(&event1);

 string desc = "my null action";
 action1.setDescription(desc);
 Action *pAction1 = &action1;

 Action *pActionClone = pAction1->clone();
 EXPECT_NE(pAction1, pActionClone);
 EXPECT_EQ(pActionClone->getDescription(), action1.getDescription());
 EXPECT_EQ(pActionClone->run(), action1.run());

 EXPECT_EQ(4, InputEvent::instanceCount);
 EXPECT_EQ(2, NullAction::instanceCount);

 delete pActionClone;
 }
 EXPECT_EQ(1, InputEvent::instanceCount);
 EXPECT_EQ(0, NullAction::instanceCount);
 }


 */

}
;
// end namesapce

#endif
