#ifndef __HELP_H__
#define __HELP_H__

#include "../icommands.h"

class Help: public Icommands
{
public:
	Help();
	/*virtual*/ string execute(const vector<string>& params); 
	/*virtual*/ const string document();
};

inline Help::Help(){}

inline const string Help::document()
{
	return "none!\n";
}


#endif //__HELP_H__
