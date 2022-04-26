/*
 * InputSource.h
 *
 *  Created on: 26 Apr 2022
 *      Author: colin
 */

#ifndef INPUTSOURCE_H_
#define INPUTSOURCE_H_

class InputSource
{
public:
	virtual char readInput() = 0;
  // virtual destructor is required if the object may
  // be deleted through a pointer to Serializable
	virtual ~InputSource() {}
};

#endif /* INPUTSOURCE_H_ */
