#include "command_factory.h"

//map<string, Icommands*> CommandFactory::m_commandsFactory;

/*TODO file*/
/*TODO with classes*/
/*
CommandFactory::CommandFactory()
{
	
	m_commandsFactory["new"]=new New;
	m_commandsFactory["load"]=new Load;
	m_commandsFactory["slice"]=new Slice;
	m_commandsFactory["find"]=new Find;
	m_commandsFactory["save"]=new Save;
	m_commandsFactory["show"]=new Show;
	m_commandsFactory["quit"]=new Quit;
	m_commandsFactory["help"]=new Help;
	m_commandsFactory["list"]=new List;
	m_commandsFactory["replace"]=new Replace;
	m_commandsFactory["len"]=new Len;
	m_commandsFactory["dup"]=new Dup;
}*/


void CommandFactory::createCommand(string str)
{
	if(str=="new")
	{
		CommandCollection::m_commandsCollections[str]=new New;
	}
	else if(str=="load")
	{
		CommandCollection::m_commandsCollections[str]=new Load;
	}
	else if(str=="save")
	{
		CommandCollection::m_commandsCollections[str]=new Save;
	}
	else if (str=="quit")
	{
		CommandCollection::m_commandsCollections[str]=new Quit;
	}
	else if (str=="len")
	{
		CommandCollection::m_commandsCollections[str]=new Len;
	}
	else if (str=="dup")
	{
		CommandCollection::m_commandsCollections[str]=new Dup;
	}
	else if (str=="help")
	{
		CommandCollection::m_commandsCollections[str]=new Help;
	}
	else if (str=="list")
	{
		CommandCollection::m_commandsCollections[str]=new List;
	}

}


