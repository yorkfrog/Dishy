#ifdef UNITTEST
#include "gtest.h"

// test fixtures
#include "NullActionTest.h"

// Test targets
#include "../InputEvent.h"
#include "../NullAction.h"
#include "../main.h"

namespace NullActionTestNS {

const int defActionId = 10;

// Test class instantiation
TEST_F(NullActionTest, classConstructionFromEventObject)
{

	EXPECT_EQ(1, InputEvent::instanceCount);
	EXPECT_EQ(0, NullAction::instanceCount);
	{
		unique_ptr<InputEvent> pEvent1 = make_unique<InputEvent>(2, 'b');
		NullAction action = NullAction(defActionId, pEvent1);
		EXPECT_NE(&action, NULL);
		EXPECT_EQ(typeid(NullAction), typeid(action));
		EXPECT_EQ(action.getId(), defActionId);

		EXPECT_NE((action.getEvent()).get(), pEvent1.get());
		EXPECT_EQ(action.getEvent()->getId(), pEvent1->getId());
		EXPECT_EQ(action.getDescription(), "");
		EXPECT_EQ(1, NullAction::instanceCount);

		pEvent1.reset();
	}
	EXPECT_EQ(0, NullAction::instanceCount);
	EXPECT_EQ(1, InputEvent::instanceCount);
}

TEST_F(NullActionTest, classConstructionFromEventNewPointer)
{

	EXPECT_EQ(1, InputEvent::instanceCount);
	EXPECT_EQ(0, NullAction::instanceCount);
	{
		unique_ptr<InputEvent> pEvent1 = make_unique<InputEvent>(1, 'a');
		NullAction action = NullAction(defActionId, pEvent1);
		EXPECT_NE(&action, NULL);
		EXPECT_EQ(typeid(NullAction), typeid(action));

		EXPECT_NE((action.getEvent()).get(), pEvent1.get());
		EXPECT_EQ(action.getId(), defActionId);
		EXPECT_EQ(action.getEvent()->getId(), pEvent1->getId());
		EXPECT_EQ(action.getDescription(), "");
		EXPECT_EQ(1, NullAction::instanceCount);
//		delete pEvent1;
	}
	EXPECT_EQ(0, NullAction::instanceCount);
	EXPECT_EQ(1, InputEvent::instanceCount);
}

TEST_F(NullActionTest, classCopyConstruction)
{
	// copy constructor
	EXPECT_EQ(1, InputEvent::instanceCount);
	EXPECT_EQ(0, NullAction::instanceCount);
	{
		unique_ptr<InputEvent> event1 = make_unique<InputEvent>(1, 'a');
		NullAction action = NullAction(defActionId, event1);
		NullAction action2 = NullAction(action);
		EXPECT_EQ(2, NullAction::instanceCount);
		EXPECT_EQ(4, InputEvent::instanceCount);
		EXPECT_EQ(typeid(NullAction), typeid(action2));
		ASSERT_NE(&action, &action2);
		ASSERT_NE(action.getEvent().get(), action2.getEvent().get())<< "Expect event is copied so event ptr's a1.event != a2.event";
	}
	EXPECT_EQ(0, NullAction::instanceCount);
	EXPECT_EQ(1, InputEvent::instanceCount);
}

TEST_F(NullActionTest, classOperatorEquals)
{
	// copy constructor
	EXPECT_EQ(1, InputEvent::instanceCount);
	EXPECT_EQ(0, NullAction::instanceCount);
	{
		unique_ptr<InputEvent> event1 = make_unique<InputEvent>(1, 'a');
		NullAction action1 = NullAction(defActionId, event1);
		unique_ptr<InputEvent> event3 = make_unique<InputEvent>(3, 'c');
		NullAction action3 = NullAction(defActionId, event3);

		ASSERT_NE(action1.getEvent().get(), action3.getEvent().get());
		EXPECT_NE(action1.getEvent()->getId(), action3.getEvent()->getId());
		EXPECT_NE(action1.getEvent()->getData(), action3.getEvent()->getData());
		EXPECT_NE(action1.getEvent(), action3.getEvent());
		EXPECT_EQ(2, NullAction::instanceCount);
		EXPECT_EQ(5, InputEvent::instanceCount);

		action1 = action3;

		EXPECT_EQ(action1.getEvent()->getId(), action3.getEvent()->getId());
		EXPECT_EQ(action1.getEvent()->getData(), action3.getEvent()->getData());
		ASSERT_NE(action1.getEvent().get(), action3.getEvent().get());

		EXPECT_EQ(2, NullAction::instanceCount);
		EXPECT_EQ(5, InputEvent::instanceCount);
	}
	EXPECT_EQ(0, NullAction::instanceCount);
	EXPECT_EQ(1, InputEvent::instanceCount);
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
TEST_F(NullActionTest, actionRun)
{

	NullAction action = NullAction(defActionId, gDefaultEvent);
	EXPECT_NE(&action, NULL);

	EXPECT_EQ(0, action.run());

}

TEST_F(NullActionTest, setGetActionDescription)
{

	NullAction action = NullAction(defActionId, gDefaultEvent);
	string desc = "TestDesc";
	action.setDescription(desc);
	EXPECT_EQ(desc, action.getDescription());

	action.setDescription("String Literal");
	EXPECT_EQ("String Literal", action.getDescription());
}

TEST_F(NullActionTest, noActionConstructionMemoryLeak)
{
	// the Test Fixture creates an InputEvent instance which we won;t use.
	EXPECT_EQ(1, InputEvent::instanceCount) << "Check 0 InputEvent instance on entry.";
	EXPECT_EQ(0, NullAction::instanceCount) << "Check 0 NullAction instance on entry.";
	{
		unique_ptr<InputEvent> event1 = make_unique<InputEvent>(1, 'a');
		unique_ptr<InputEvent> pEvent2 = make_unique<InputEvent>(2, 'b');

		NullAction action1 = NullAction(defActionId, event1);
		NullAction action2 = NullAction(defActionId, pEvent2);
		Action *action = &action2;
		EXPECT_EQ(5, InputEvent::instanceCount);
		EXPECT_EQ(2, NullAction::instanceCount);
//		delete pEvent2;
	}
	EXPECT_EQ(1, InputEvent::instanceCount);
	EXPECT_EQ(0, NullAction::instanceCount);
}

TEST_F(NullActionTest, clone)
{
	// the Test Fixture creates an InputEvent instance which we won;t use.
	EXPECT_EQ(1, InputEvent::instanceCount) << "Check 0 InputEvent instance on entry.";
	EXPECT_EQ(0, NullAction::instanceCount) << "Check 0 NullAction instance on entry.";
	{
		unique_ptr<InputEvent> event1 = make_unique<InputEvent>(1, 'a');
		NullAction action1 = NullAction(defActionId, event1);

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




TEST(ActionInterfaceTest, runViaAction)
{

	int id = 1;
	char data = 'c';
	unique_ptr<InputEvent> gDefaultEvent = make_unique<InputEvent>(id, data);

	NullAction action = NullAction(defActionId, gDefaultEvent);

	Action *bAction = &action;
	EXPECT_EQ(1, NullAction::instanceCount);
}

} // end namespace

#endif

