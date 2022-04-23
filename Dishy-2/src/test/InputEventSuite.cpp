#ifdef UNITTEST
#include "gtest.h"
#include "../InputEvent.h"
#include "../main.h"

namespace InputEventTestTestNS {

// Test class
TEST(InputEventTest, classConstruction)
{

	int id = 1;
	char data = 'c';
	InputEvent event = InputEvent(id, data);

	EXPECT_EQ(typeid(InputEvent), typeid(event));
	EXPECT_EQ(id, event.getId());
	EXPECT_EQ(data, event.getData());

	// copy constructor
	InputEvent event2 = InputEvent(event);

	EXPECT_EQ(typeid(InputEvent), typeid(event2));
	ASSERT_NE(&event, &event2);
	EXPECT_EQ(id, event2.getId());
	EXPECT_EQ(data, event2.getData());

}

// valid char input
TEST(InputEventTest, getInputEventFromValidInput)
{

	InputEvent event = getEventForInput('1');
	EXPECT_EQ(InputEvent::btn1pressEvent, event.getId());
	EXPECT_EQ('1', event.getData());

	event = getEventForInput('2');
	EXPECT_EQ(InputEvent::btn2pressEvent, event.getId());
	EXPECT_EQ('2', event.getData());

	event = getEventForInput('3');
	EXPECT_EQ(InputEvent::btn3pressEvent, event.getId());
	EXPECT_EQ('3', event.getData());

	event = getEventForInput('4');
	EXPECT_EQ(InputEvent::btn4pressEvent, event.getId());
	EXPECT_EQ('4', event.getData());
}

// Invalid char input
TEST(InputEventTest, getInputActionFromInvalidInput)
{

	InputEvent event = getEventForInput('0');
	EXPECT_EQ(typeid(InputEvent), typeid(event));
	EXPECT_EQ(InputEvent::invalidEvent, event.getId());
	EXPECT_EQ('0', event.getData());

	event = getEventForInput('a');
	EXPECT_EQ(InputEvent::invalidEvent, event.getId());
	EXPECT_EQ('a', event.getData());

	event = getEventForInput('z');
	EXPECT_EQ(InputEvent::invalidEvent, event.getId());
	EXPECT_EQ('z', event.getData());

	event = getEventForInput('5');
	EXPECT_EQ(InputEvent::invalidEvent, event.getId());
	EXPECT_EQ('5', event.getData());

	event = getEventForInput(' ');
	EXPECT_EQ(InputEvent::invalidEvent, event.getId());
	EXPECT_EQ(' ', event.getData());

	event = getEventForInput('\t');
	EXPECT_EQ(InputEvent::invalidEvent, event.getId());
	EXPECT_EQ('\t', event.getData());

	event = getEventForInput('\0');
	EXPECT_EQ(InputEvent::invalidEvent, event.getId());
	EXPECT_EQ('\0', event.getData());
}

TEST(InputEventTest, noConstructionMemoryLeak)
{
	EXPECT_EQ(0, InputEvent::instanceCount);
	{
		InputEvent event1 = InputEvent(1, 'c');
		InputEvent event2 = InputEvent(2, 'x');
		InputEvent *pEvent = &event2;
		EXPECT_EQ(2, InputEvent::instanceCount);
	}
	EXPECT_EQ(0, InputEvent::instanceCount);
}

} // end namespace

#endif
