#ifndef __LOAD_H__
#define __LOAD_H__

#include <fstream>      
#include <cstring>
#include <string>

#include "../icommands.h"
#include "commands_librery.h"

using std::string;
using std::cout;
using std::endl;


class Load: public Icommands
{
public:
	Load();
	/*virtual*/ string execute(const vector<string>& params);     /*TODO maybe about params*/
	/*virtual*/ const string document();
private:
	void createSuitableDnaData(long unsigned int size,const string& str,const string& fileName,DnaData** ptrDna);
};

inline Load::Load(){}

inline void Load::createSuitableDnaData(long unsigned int size,const string& str,const string& fileName,DnaData** ptrDna)
{
	
}

inline void dropEndOfFile(string& fileName)
{
	fileName = fileName.substr(0, fileName.rfind('.'));
}

inline const string Load::document()
{
	return "load <file_name>  [@<sequence_name>]\n ==================loads the sequence from the file, assigns it with a number (ID) and a default name, if one was not provided (based on the file name, possibly postfixed with a number if the name already exists), and prints it..\n \
 			EX: cmd >>> load my_dna_seq.rawdna\
          \n  [14] my_dna_seq: AACGTTTTTGAACACCAGTCAACAACTAGCCA...TTG\n";
}



#endif //__LOAD_H__
