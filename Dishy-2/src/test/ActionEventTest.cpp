#ifdef UNITTEST
#include "gtest.h"
#include "ActionEvent.h"
#include "main.h"


// Test class
TEST(ActionEventSuite, testActionEventClass) {

	int id = 1;
	char data = 'c';
	ActionEvent event = ActionEvent(id, data);

	EXPECT_EQ(typeid(ActionEvent), typeid(event));
	EXPECT_EQ(id, event.getId());
	EXPECT_EQ(data, event.getData());

	// copy constructor
	ActionEvent event2 = ActionEvent(event);

	EXPECT_EQ(typeid(ActionEvent), typeid(event2));
	ASSERT_NE(&event, &event2);
	EXPECT_EQ(id, event2.getId());
	EXPECT_EQ(data, event2.getData());

}

// valid char input
TEST(ActionEventSuite, testGetEventActionFromValidInput) {

	ActionEvent event = getEventForInput('1');
	EXPECT_EQ(btn1pressEvent, event.getId());
	EXPECT_EQ('1', event.getData());

	event = getEventForInput('2');
	EXPECT_EQ(btn2pressEvent, event.getId());
	EXPECT_EQ('2', event.getData());

	event = getEventForInput('3');
	EXPECT_EQ(btn3pressEvent, event.getId());
	EXPECT_EQ('3', event.getData());

	event = getEventForInput('4');
	EXPECT_EQ(btn4pressEvent, event.getId());
	EXPECT_EQ('4', event.getData());
}

// Invalid char input
TEST(ActionEventSuite, testGetEventActionFromInvalidInput) {

	ActionEvent event = getEventForInput('0');
	EXPECT_EQ(typeid(ActionEvent), typeid(event));
	EXPECT_EQ(invalidEvent, event.getId());
	EXPECT_EQ('0', event.getData());

	event = getEventForInput('a');
	EXPECT_EQ(invalidEvent, event.getId());
	EXPECT_EQ('a', event.getData());

	event = getEventForInput('z');
	EXPECT_EQ(invalidEvent, event.getId());
	EXPECT_EQ('z', event.getData());

	event = getEventForInput('5');
	EXPECT_EQ(invalidEvent, event.getId());
	EXPECT_EQ('5', event.getData());

	event = getEventForInput(' ');
	EXPECT_EQ(invalidEvent, event.getId());
	EXPECT_EQ(' ', event.getData());

	event = getEventForInput('\t');
	EXPECT_EQ(invalidEvent, event.getId());
	EXPECT_EQ('\t', event.getData());

	event = getEventForInput('\0');
	EXPECT_EQ(invalidEvent, event.getId());
	EXPECT_EQ('\0', event.getData());
}


#endif
