
//#ifdef EXCLUDE

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
unique_ptr<NullAction> makeNullAction(int actionId, int eventId, char data)
{
	unique_ptr<InputEvent> event1 = make_unique<InputEvent>(eventId, data);
	return make_unique<NullAction>(actionId, event1);
}

// 1 event instance
// 1 action instance
// 1 actionGrp instance
unique_ptr<ActionGroup> makeActionGroup(int actionGroupid = defActionGrpId, int actionGrpMax = 1, string desc = defaultDescription, int actionId = defaultId, char actionData = defaultActionData)
{
	unique_ptr<Action> action1 = makeNullAction(defActionId, actionId, actionData);
	action1->setDescription((string("Action[") + to_string(actionId) + (string("]:")) + desc));
	return make_unique<ActionGroup>(actionGroupid, actionGrpMax, action1, desc);
}
shared_ptr<ActionGroup> makeSharedActionGroup(int actionGroupid = defActionGrpId, int actionGrpMax = 1, string desc = defaultDescription, int actionId = defaultId, char actionData = defaultActionData) {
	unique_ptr<ActionGroup> tmp = makeActionGroup(actionGroupid , actionGrpMax , desc , actionId , actionData);
	return make_shared<ActionGroup>(*(tmp.get()) ) ;
}

void expectAfterActionGroupConstruction(unique_ptr<ActionGroup> &actionGrp, string description, int actionGrpInstanceCount)
{
	EXPECT_NE(actionGrp.get(), NULL);
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
		unique_ptr<Action> action1 = makeNullAction(defActionId, defaultId, defaultActionData);
		unique_ptr<ActionGroup> actionGrp1 = make_unique<ActionGroup>(defActionGrpId, 1, action1, defaultDescription);
		expectAfterActionGroupConstruction(actionGrp1, defaultDescription, 1);
	}
	expectStartEndInstaneCounts();
}

TEST(ActionGroupTest, classConstructionFromActionNewPointer)
{

	expectStartEndInstaneCounts();
	{
		unique_ptr<InputEvent> event1 = make_unique<InputEvent>(defaultId, defaultActionData);
		unique_ptr<Action> pAction1 =  make_unique<NullAction>(10, event1);


//		InputEvent event1 = InputEvent(defaultId, defaultActionData);
//		NullAction *pAction1 = new NullAction(10, &event1);
		unique_ptr<ActionGroup> actionGrp1 = make_unique<ActionGroup>(defActionGrpId, 1, pAction1, defaultDescription);
		expectAfterActionGroupConstruction(actionGrp1, defaultDescription, 1);
	}
	expectStartEndInstaneCounts();
}

TEST(ActionGroupTest, classCopyConstruction)
{
	// copy constructor
	expectStartEndInstaneCounts();
	{
		unique_ptr<NullAction> action1 = makeNullAction(defActionId, defaultId, defaultActionData);
		unique_ptr<ActionGroup> actionGrp1 = makeActionGroup();
		unique_ptr<ActionGroup> actionGrp2 = make_unique<ActionGroup>( *(actionGrp1.get()) );
		expectAfterActionGroupConstruction(actionGrp2, defaultDescription, 2);
		ASSERT_NE(actionGrp1, actionGrp2);
		ASSERT_NE(&(actionGrp1->getDescription()), &(actionGrp2->getDescription()));
		ASSERT_EQ(actionGrp1->getDescription(), actionGrp2->getDescription());
		ASSERT_EQ(actionGrp1->getMaxActions(), actionGrp2->getMaxActions());
	}
	expectStartEndInstaneCounts();
}

TEST(ActionGroupTest, classOperatorEquals)
{
	expectStartEndInstaneCounts();
	{

		shared_ptr<ActionGroup> actionGrp1 = makeSharedActionGroup(100, 10, "Group1");
		shared_ptr<ActionGroup> actionGrp2 = makeSharedActionGroup(200, 20, "My Group 2");

		EXPECT_NE(actionGrp1.get(), actionGrp2.get());
		EXPECT_NE(actionGrp1->getId(), actionGrp2->getId());
		EXPECT_NE(actionGrp1->getMaxActions(), actionGrp2->getMaxActions());
		EXPECT_NE(actionGrp1->getDescription(), actionGrp2->getDescription());
		EXPECT_NE(actionGrp1->run(), actionGrp2->run());
		EXPECT_EQ(2, ActionGroup::instanceCount);
		EXPECT_EQ(2, NullAction::instanceCount);
		EXPECT_EQ(2, InputEvent::instanceCount);

		actionGrp1 = actionGrp2;

		EXPECT_EQ(actionGrp1.get(), actionGrp2.get());
		EXPECT_EQ(actionGrp1->getId(), actionGrp2->getId());
		EXPECT_EQ(actionGrp1->getMaxActions(), actionGrp2->getMaxActions());
		EXPECT_EQ(actionGrp1->getDescription(), actionGrp2->getDescription());
		EXPECT_EQ(actionGrp1->run(), actionGrp2->run());
		EXPECT_EQ(1, ActionGroup::instanceCount);
		EXPECT_EQ(1, NullAction::instanceCount);
		EXPECT_EQ(1, InputEvent::instanceCount);
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
 unique_ptr<ActionGroup> actionGrp1 = ActionGroup(1, NULL, defaultDescription);

 // null action pointer
 ActionGroup* pActionGrp = NULL;
 unique_ptr<ActionGroup> actionGrp2 = ActionGroup(1, pActionGrp, defaultDescription);
 }
 */

// Test class run
TEST(ActionGroupTest, actionRun)
{
	unique_ptr<ActionGroup> actionGrp1 = makeActionGroup();

	EXPECT_EQ(28, actionGrp1->run());
}

TEST(ActionGroupTest, setGetActionDescription)
{
	unique_ptr<ActionGroup> actionGrp1 = makeActionGroup();
	string desc = "TestDesc";
	actionGrp1->setDescription(desc);
	EXPECT_EQ(desc, actionGrp1->getDescription());

	actionGrp1->setDescription("String Literal");
	EXPECT_EQ("String Literal", actionGrp1->getDescription());
}

TEST(ActionGroupTest, noActionConstructionMemoryLeak)
{

	expectStartEndInstaneCounts();
	{
		// 1 event instance
		// 1 action instance
		// 1 actionGrp instance
		shared_ptr<ActionGroup> pActionGrp1 = makeSharedActionGroup();

		// 1 event instance
		// 1 action instance
//		unique_ptr<NullAction> nAction = makeNullAction(defActionId, defaultId, defaultActionData);

		// 1 event instance
		// 1 action instance
		// 1 actionGrp instance
		shared_ptr<ActionGroup> pActionGrp2 = makeSharedActionGroup(defActionGrpId, 1, defaultDescription, defActionId, defaultActionData);
	//	ActionGroup *pActionGrp2 = new ActionGroup(defActionGrpId, 1, &nAction, defaultDescription);
		ActionGroup pActionGrp3 = *(pActionGrp1.get());
		EXPECT_EQ(3, InputEvent::instanceCount);
		EXPECT_EQ(3, NullAction::instanceCount);
		EXPECT_EQ(3, ActionGroup::instanceCount);
	}
	expectStartEndInstaneCounts();
}

TEST(ActionGroupTest, clone)
{
	expectStartEndInstaneCounts();
	{
		string groupDesc = "Cloned Group Description";
		unique_ptr<ActionGroup> actionGrp1 = makeActionGroup(20, 2, groupDesc);

		unique_ptr<Action> pActionGrpClone = unique_ptr<Action>(actionGrp1->clone());

		EXPECT_NE(pActionGrpClone, actionGrp1);
		EXPECT_EQ(pActionGrpClone->getDescription(), actionGrp1->getDescription());
		EXPECT_EQ(pActionGrpClone->run(), actionGrp1->run());
		EXPECT_EQ(pActionGrpClone->run(), actionGrp1->run());
		EXPECT_EQ(2, ActionGroup::instanceCount);
		EXPECT_EQ(2, NullAction::instanceCount);
		EXPECT_EQ(2, InputEvent::instanceCount);
	}
	expectStartEndInstaneCounts();
}

} // end namesapce

#endif

