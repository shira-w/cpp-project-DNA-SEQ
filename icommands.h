#ifndef __ICOMMANDS_H__
#define __ICOMMANDS_H__

//#include "../Model/dna_data.h"
#include "../Model/dna_stracture.h"
//#include "../my_libreries/stl.h"
#include "Commands/commands_librery.h"

#include <iostream>
#include <vector>

using std::cout;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::vector;

class Icommands
{
public:
	virtual ~Icommands();
	virtual string execute(const vector<string>& params)=0;
	virtual const string document()=0;
};

inline Icommands::~Icommands()
{
}
#endif //__ICOMMANDS_H__
