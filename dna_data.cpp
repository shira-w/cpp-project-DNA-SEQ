#include "dna_data.h"

int DnaData::s_id=1;

int DnaData::s_e_name=1;

string DnaData::s_name="seq";


void DnaData::setNameInCtor(const string& name)
{
	if(name=="")
	{
		String s_nameW(s_name);
		s_nameW.addToString(s_e_name++);
		m_name=s_nameW.getStr();	
	}
}






