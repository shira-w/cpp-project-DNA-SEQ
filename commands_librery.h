#ifndef __COMMAND_LIBRERY_H__
#define __COMMAND_LIBRERY_H__
#include <string>
#include <vector>


#include "../../my_libreries/stl.h"
#include "../../Model/dna_stracture.h"

using std::string;
using std::vector;

void dropShtrudel(string& seqName);
void dropHashTag(string& seqId);
const string checkParamsValid(string commandName, const vector<string>& params);
void getNameInAnyCase(string&);

#endif //__COMMAND_LIBRERY_H__
