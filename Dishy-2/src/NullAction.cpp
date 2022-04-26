/*
 * NullAction.cpp
 *
 *  Created on: 19 Apr 2022
 *      Author: colin
 */
//#define DEBUG

#include "environment.h"

using namespace std;

#include "NullAction.h"

/*
static unique_ptr<NullAction> NullAction::build()
{
	unique_ptr<InputEvent> event = make_unique<InputEvent>(100, 'z');
	unique_ptr<NullAction> action = make_unique<NullAction>(1000, event);
	return action;
}
*/

NullAction::NullAction(int id, unique_ptr<InputEvent> &event): BaseAction(id, event)
{
#ifdef DEBUG
	LOG_DEBUG_LN("      # NullAction constructor [%#lx] id:%i\n", this , event->getId() );
#endif
}

NullAction::NullAction(const NullAction &other) : BaseAction(other)
{
#ifdef DEBUG
	LOG_DEBUG_LN("      # NullAction COPY constructor, from [%#lx] to [%#lx]\n", &other , this  );
#endif

}

NullAction::~NullAction()
{
#ifdef DEBUG
	LOG_DEBUG_LN("      # NullAction destructor on [%#lx]\n" , this);
#endif
}

Action* NullAction::clone() const
{
	return new NullAction(*this);
}

int NullAction::run()
{
	printf("run NullAction::%s\n", this->toString());
	return getDescription().length();
}
