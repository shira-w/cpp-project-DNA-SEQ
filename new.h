//TODO machshir of ima 
//TODO why to give commandline* to quit?

#ifndef __NEW_H__
#define __NEW_H__


#include "../icommands.h"

using std::copy;

class New: public Icommands
{
public:
	New();
	/*virtual*/ string execute(const vector<string>& params);     /*TODO maybe about params*/
	/*virtual*/ const string document();
private:
	void assignSuitableDnaData(string seq,DnaData** dnaPtr, string name="");
	void dropShtrudel(string& seqName);
};

inline New::New(){}

inline void New::assignSuitableDnaData(string seq,DnaData** ptrDna, string name)
{
	if (name=="")
	{	
		DnaData dna(seq,"");
		*ptrDna=&dna;
		cout<<(*ptrDna)->getName()<<endl;
	}
	else
	{
		DnaData dna(seq,name);
		*ptrDna=&dna;
		cout<<(*ptrDna)->getName()<<endl;
	}
}

inline void New::dropShtrudel(string& seq)
{
	seq=seq.substr(1,seq.length()-1);
}

inline const string New::document()
{
	return "new <sequence> [@<sequence_name>]\n ==================Creates a new sequence.If the @<sequence_name> is used, then this will be the name of the new sequence.\
Otherwise, a default name will be provided - seq1 (or seq2, seq3 and so on, if the name is already taken).\n \
 			EX: cmd >>> new ATACTGCCTGAATAC @short_seq \
          \n  [1] short_seq: ATACTGCCTGAATAC\n";
}

#endif //__NEW_H__
