#ifndef __COMMAND_COLLECTION_H__
#define __COMMAND_COLLECTION_H__

#include "icommands.h"
#include "command_factory.h"
#include "I-O/ireader.h"

#include <map>

using std::map;
using std::string;

class CommandCollection
{
public:	
	CommandCollection(Ireader* ir);
/*TODO think about static*/
	static Icommands* getCommand(string str);
	static void printMap();
	
/*TODO think about: private:*/
	static map<string, Icommands*> m_commandsCollections;
	//TODO think about it Icommands m_ic maybe oposit command collection in Icommands;
};

inline CommandCollection::CommandCollection(Ireader* ir)
{
	
}

inline Icommands* CommandCollection::getCommand(string str)
{
	if (m_commandsCollections.find(str) == m_commandsCollections.end())
		return NULL;
	else
		return m_commandsCollections[str];

}

inline void CommandCollection::printMap()
{

	for(map<string, Icommands* >::const_iterator it = m_commandsCollections.begin();it != m_commandsCollections.end(); ++it)
	{
    		std::cout << it->first << " " << it->second<< "\n";
	}

}


#endif //__COMMAND_COLLECTION_H__


