#ifndef __MANAGER_H__
#define __MANAGER_H__

#include <iostream>

#include "command_collection.h"
#include "command_line.h"
#include "I-O/iwriter.h"
/*TODO check the private m_cc Vs CommandCollection::*/

using std::cout;
using std::endl;

/*TODO command line and interface*/

class Manager
{
public:
	Manager(Ireader* ir,Iwriter* iw);
	/*TODO think about constractor*/
	void initSystem();
	void shutDown();
	void startUp();

private:
	CommandCollection m_cc;
	Ireader* m_ir;
	/*TODO command line pointer, exist alone?*/
	CommandLine m_cl;
	Iwriter* m_iw;
};
/*TODO maybe need to free*/
inline Manager::Manager(Ireader* ir,Iwriter* iw):m_cc(ir),m_ir(ir),m_iw(iw) {
	
}

inline void Manager::initSystem()
{
	cout<<"initialize--- hello"<<endl;
	CommandFactory::createCommand("quit");
}

inline void Manager::shutDown()
{
	cout<<"good-Bye-----shutDown"<<endl;
}
inline void Manager::startUp()
{
	cout<<"start-up"<<endl;
	m_cl.run();
}
#endif //__MANAGER_H__

