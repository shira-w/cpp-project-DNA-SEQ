#ifndef __LIST_H__
#define __LIST_H__

#include "../icommands.h"

class List: public Icommands
{
public:
	//List();
	/*virtual*/ string execute(const vector<string>& params); 
	/*virtual*/ const string document();
};

//inline List::List(){}

inline string List::execute(const vector<string>& params)
{
	DnaStracture::allIds();
	return "EOL";
}

inline const string List::document()
{
	return "shows all the sequences in the system, by order.\nmanipulated since last save, is prefixed by a - sign.\nA sequence that was manipulated after last save, is prefixed by a * sign.\n A sequence that is not connected to any file yet is prefixed by a o sign.\n";
}
#endif //__LIST_H__
