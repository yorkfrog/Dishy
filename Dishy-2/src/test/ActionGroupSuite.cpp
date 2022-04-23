#ifdef UNITTEST
#include "gtest.h"
#include "../InputEvent.h"
#include "../BaseAction.h"
#include "../Action.h"
#include "../ActionGroup.h"
#include "../main.h"

namespace ActionGroupTestNS {


const int defActionGrpId = 1;
const int defActionId = 1;
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
NullAction makeNullAction(int actionId, int eventId, char data)
{
	InputEvent event1 = InputEvent(eventId, data);
	return NullAction(actionId, &event1);
}

// 1 event instance
// 1 action instance
// 1 actionGrp instance
ActionGroup makeActionGroup(int actionGroupid = defActionGrpId, int actionGrpMax = 1, string desc = defaultDescription, int actionId = defaultId, char actionData = defaultActionData)
{
	NullAction action1 = makeNullAction(defActionId, actionId, actionData);
	action1.setDescription((string("Action[") + to_string(actionId) + (string("]:")) + desc));
	return ActionGroup(actionGroupid, actionGrpMax, &action1, desc);
}

void expectAfterActionGroupConstruction(ActionGroup *actionGrp, string description, int actionGrpInstanceCount)
{
	EXPECT_NE(actionGrp, NULL);
	EXPECT_EQ(typeid(ActionGroup), typeid(*actionGrp));
	EXPECT_EQ(description, actionGrp->getDescription());
	EXPECT_EQ(defActionGrpId, actionGrp->getId());
	EXPECT_EQ(1, actionGrp->getMaxActions());
	EXPECT_EQ(actionGrpInstanceCount, ActionGroup::instanceCount);
}

// Test class instantiation
TEST(ActionGroupTest, classConstructionFromActionObject)
{

	expectStartEndInstaneCounts();
	{
		NullAction action1 = makeNullAction(defActionId, defaultId, defaultActionData);
		ActionGroup actionGrp1 = ActionGroup(defActionGrpId, 1, &action1, defaultDescription);
		expectAfterActionGroupConstruction(&actionGrp1, defaultDescription, 1);
	}
	expectStartEndInstaneCounts();
}

TEST(ActionGroupTest, classConstructionFromActionNewPointer)
{

	expectStartEndInstaneCounts();
	{
		InputEvent event1 = InputEvent(defaultId, defaultActionData);
		NullAction *pAction1 = new NullAction(10, &event1);
		ActionGroup actionGrp1 = ActionGroup(defActionGrpId, 1, pAction1, defaultDescription);
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
		NullAction action1 = makeNullAction(defActionId, defaultId, defaultActionData);
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

TEST(ActionGroupTest, classOperatorEquals)
{
	expectStartEndInstaneCounts();
	{
		ActionGroup actionGrp1 = makeActionGroup(100, 10, "Group1");
		ActionGroup actionGrp2 = makeActionGroup(200, 20, "My Group 2");

		EXPECT_NE(actionGrp1.getId(), actionGrp2.getId());
		EXPECT_NE(actionGrp1.getMaxActions(), actionGrp2.getMaxActions());
		EXPECT_NE(actionGrp1.getDescription(), actionGrp2.getDescription());
		EXPECT_NE(actionGrp1.run(), actionGrp2.run());
		EXPECT_EQ(2, ActionGroup::instanceCount);
		EXPECT_EQ(2, NullAction::instanceCount);
		EXPECT_EQ(2, InputEvent::instanceCount);

		actionGrp1 = actionGrp2;

		EXPECT_NE(&actionGrp1, &actionGrp2);
		EXPECT_EQ(actionGrp1.getId(), actionGrp2.getId());
		EXPECT_EQ(actionGrp1.getMaxActions(), actionGrp2.getMaxActions());
		EXPECT_EQ(actionGrp1.getDescription(), actionGrp2.getDescription());
		EXPECT_EQ(actionGrp1.run(), actionGrp2.run());
		EXPECT_EQ(2, ActionGroup::instanceCount);
		EXPECT_EQ(2, NullAction::instanceCount);
		EXPECT_EQ(2, InputEvent::instanceCount);
	}
	expectStartEndInstaneCounts();
}

// DEATH TEST#endif /* NULLACTIONTEST_H_ */
// this test will cause the assert to trigger and fail the test
// Arduino does not allow for threads so we cannot use DEATH_TEST
/*
 TEST(ActionGroupTest, invalidEventOnActionConstruction)
 {
 // null action
 ActionGroup actionGrp1 = ActionGroup(1, NULL, defaultDescription);

 // null action pointer
 ActionGroup* pActionGrp = NULL;
 ActionGroup actionGrp2 = ActionGroup(1, pActionGrp, defaultDescription);
 }
 */

// Test class run
TEST(ActionGroupTest, actionRun)
{
	ActionGroup actionGrp1 = makeActionGroup();

	EXPECT_EQ(28, actionGrp1.run());
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
		NullAction nAction = makeNullAction(defActionId, defaultId, defaultActionData);

		// 1 event instance
		// 1 action instance
		// 1 actionGrp instance
		ActionGroup *pActionGrp2 = new ActionGroup(defActionGrpId, 1, &nAction, defaultDescription);
		ActionGroup *pActionGrp3 = &actionGrp1;
		EXPECT_EQ(3, InputEvent::instanceCount);
		EXPECT_EQ(3, NullAction::instanceCount);
		EXPECT_EQ(2, ActionGroup::instanceCount);
		delete pActionGrp2;
	}
	expectStartEndInstaneCounts();
}

TEST(ActionGroupTest, clone)
{
	expectStartEndInstaneCounts();
	{
		string groupDesc = "Cloned Group Description";
		ActionGroup actionGrp1 = makeActionGroup(20, 2, groupDesc);

		Action *pActionGrpClone = actionGrp1.clone();

		EXPECT_NE(pActionGrpClone, &actionGrp1);
		EXPECT_EQ(pActionGrpClone->getDescription(), actionGrp1.getDescription());
		EXPECT_EQ(pActionGrpClone->run(), actionGrp1.run());
		EXPECT_EQ(pActionGrpClone->run(), actionGrp1.run());
		EXPECT_EQ(2, ActionGroup::instanceCount);
		EXPECT_EQ(2, NullAction::instanceCount);
		EXPECT_EQ(2, InputEvent::instanceCount);

		delete pActionGrpClone;
	}
	expectStartEndInstaneCounts();
}

} // end namesapce

#endif
