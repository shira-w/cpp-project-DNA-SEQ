#ifndef __DNA_DATA_H__
#define __DNA_DATA_H__

#include "DnaSequence/DnaSequence.h"
#include "../my_libreries/stl.h"

using std::string;

typedef enum Status
{
	E_Regular,
	E_FileConnect,
	E_FileConnectButManip
}Status;

class DnaData
{
public:
	DnaData(DnaSequence* dnaSeqPtr,const string& name,Status s=E_Regular);
	DnaData(const string& seq,const string& name,Status s=E_Regular);
	static int s_e_name;
	static int s_id;
	static string s_name;
	int getId()const;
	string getName();
	void setName(const string& str);
	DnaSequence* getSequence();
	Status getStatus()const;
	

private:
	int m_id;
	string m_name;
	DnaSequence* m_dnaSeqPtr;
	Status m_s;

//=====================================Auxiliary funcs
	void setNameInCtor(const string& name);
};


inline DnaData::DnaData(const string& seq,const string& name,Status s):m_id(s_id++),m_name(name), m_dnaSeqPtr(new DnaSequence(seq)),m_s(s)
{
	setNameInCtor(name);
}

inline DnaData::DnaData(DnaSequence* dnaSeqPtr,const string& name,Status s):m_id(s_id++),m_name(name), m_dnaSeqPtr(dnaSeqPtr),m_s(s)
{
	setNameInCtor(name);
}

inline int DnaData::getId()const
{
	return m_id;
}

inline string DnaData::getName()
{
	return m_name;
}

inline void DnaData::setName(const string& str)
{
	m_name=str;
}

inline DnaSequence* DnaData::getSequence()
{
	return m_dnaSeqPtr;
}

inline Status DnaData::getStatus()const
{
	return m_s;
}

#endif //__DNA_DATA_H__
