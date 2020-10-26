#ifndef __DNA_STRACTURE_H__
#define __DNA_STRACTURE_H__

#include "dna_data.h"
#include "../my_libreries/stl.h"

#include <algorithm>
#include <map>
#include <string>
#include <stdio.h>
#include <stdlib.h> 
#include <cstring>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

/*TODO there is aconnection between dna_data : id, name and the maps???*/
/*TODO statics*/


class DnaStracture
{
public:
	static const string& getName(int id);
	static DnaData* getSeq(const string& str);
	static void addName(int id,string str);
	static void addSeq(string str,DnaData* dna);
	static bool findId(int id);
	static bool findName(const string& str);
	static void allIds();

private:
	static map<int,string> m_FromIdToName;
	static map<string,DnaData*> m_FromNameToDnaData;
	//void pharseStringToArray(string str);
	static const string nextFileName(string name,int currentNum);
	static bool isNextFileNameExist(string name,int currentNum);
	static void print(const std::pair<int,string> &p);
	static const vector<string> signStatus;
	static void updateName();
	
};



inline bool DnaStracture::findId(int id)
{
	map<int,string>::iterator it;
	it = m_FromIdToName.find(id);
	return (it!=m_FromIdToName.end());
}

inline bool  DnaStracture::findName(const string& str)
{
	map<string,DnaData*>::iterator it;
	it = m_FromNameToDnaData.find(str);
	return (it!=m_FromNameToDnaData.end());
}

inline const string DnaStracture::nextFileName(string name,int currentNum)
{
	String nameS(name);
	if (currentNum==0)
	{
		if (nameS.endWithNum())
		{
			nameS.increaseName();
		}
		return nameS.getStr();
	}
	else
	{
		String nameS(name,"_");
		nameS.addToString(currentNum);
		return nameS.getStr();
	}
}

inline bool DnaStracture::isNextFileNameExist(string name,int currentNum)
{
	const string nextFile=nextFileName(name,currentNum);
	map<string,DnaData*>::iterator it;
	it = m_FromNameToDnaData.find(nextFile); 
	return  (it!=DnaStracture::m_FromNameToDnaData.end());
}
/*
inline void DnaStracture::pharseStringToArray(string str)
{
	//pharse the string to array of characters
	int current_num=0;
	int n = str.length(); 
    char char_array[n + 1]; 
    strcpy(char_array, str.c_str());
	//extract the current numeric value
}*/

inline const string& DnaStracture::getName(int id)
{
	return m_FromIdToName[id];
}
//TODO if exist

inline DnaData* DnaStracture::getSeq(const string& str)
{
	return (m_FromNameToDnaData[str]);
}

inline void DnaStracture::addName(int id,string name)
{
	String nameS(name);
	int currentNum=0;
	while (isNextFileNameExist(name,currentNum))
	{
		currentNum++;
	}
	if (currentNum!=0)
	{
		nameS.addToString(currentNum);
	}

	m_FromIdToName[id]=nameS.getStr();
}

inline void DnaStracture::addSeq(string name,DnaData* dna)
{
	int currentNum=0;
	String nameS(name);
	while (isNextFileNameExist(name,currentNum))
	{
		currentNum++;
	}
	if (currentNum!=0)
	{
		nameS.addToString(currentNum);
	}

	dna->setName(nameS.getStr());
	m_FromNameToDnaData[nameS.getStr()]=dna;
}

inline void DnaStracture::print(const std::pair<int,string> &p) {
	DnaData* dna=getSeq(p.second);
	std::cout <<signStatus[dna->getStatus()]<< " [" << p.first << "] " << p.second <<": "<<dna->getSequence();
}

inline void DnaStracture::allIds()
{
	if (m_FromIdToName.size()==0)
		cout<< "==============EMPTY"<<endl;
	std::for_each(m_FromIdToName.begin(), m_FromIdToName.end(), print);
}

#endif //__DNA_STRACTURE_H__
