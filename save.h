#ifndef __SAVE_H__
#define __SAVE_H__

#include "../icommands.h"
#include <fstream>

using std::ofstream;

class Save: public Icommands
{
public:
	/*virtual*/ string execute(const vector<string>& params);     /*TODO maybe about params*/
	/*virtual*/ const string document();
};

inline const string Save::document()
{
	return "save <seq> [<filename>]\n ==================saves sequence <seq> to a file.\n \
If <filename> is not provided, the sequence name is being used.﻿\
The filename is suffixed by .rawdna.\n";
}


#endif //__SAVE_H__
