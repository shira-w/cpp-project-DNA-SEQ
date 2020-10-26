#ifndef __LEN_H__
#define __LEN_H__

#include "../icommands.h"



class Len: public Icommands
{
public:
	Len();
	/*virtual*/ string execute(const vector<string>& params); 
	/*virtual*/ const string document();
};

inline Len::Len(){}

inline const string Len::document()
{
	return "len <seq_id>\n ==================prints the length of the sequence.\n \
 			EX: cmd >>> len #34\
          \n  10\n";
}



#endif //__LEN_H__
