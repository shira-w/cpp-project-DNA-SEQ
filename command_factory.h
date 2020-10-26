#ifndef __COMMAND_FACTORY_H__
#define __COMMAND_FACTORY_H__

#include "command_collection.h"
//#include "icommands.h"
#include "Commands/dup.h"
//#include "Commands/find.h"
#include "Commands/help.h"
#include "Commands/len.h"
#include "Commands/list.h"
#include "Commands/load.h"
#include "Commands/new.h"
#include "Commands/quit.h"
//#include "Commands/replace.h"
#include "Commands/save.h"
//#include "Commands/show.h"
//#include "Commands/slice.h"

#include <map>

using std::map;
using std::string;

class CommandFactory
{
	/*TODO think about static*/
public:
	CommandFactory();
	static void createCommand(string str);
private:
	//map<string, Icommands*> m_commandsFactory;
};



#endif //__COMMAND_FACTORY_H__
