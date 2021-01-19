#ifndef __DNASEQUENCE_H__
#define __DNASEQUENCE_H__

#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <cstring>

#include "InvalidNucleotid.h"

class DnaSequence
{

private:
	class Nucleotid
	{

	public:
		Nucleotid();
		Nucleotid(char nuc);
		Nucleotid& operator=(const Nucleotid& nuc);
		operator char() {return m_nuc;};
		bool IsValidNucleotid(char candidate);
		const char& getNuc()const;

	private:
		char m_nuc;
	
	};
	Nucleotid* m_nucleotids;
	void initNucleotids(const char* sequence);
	bool isValidDna(const char* candidate)const;
	
public:
	DnaSequence();
	DnaSequence(const char* sequence);
	DnaSequence(const std::string& sequence);
	DnaSequence(const DnaSequence& dna);//maybe not
	~DnaSequence();
	DnaSequence& operator =(const DnaSequence& dna);
	DnaSequence::Nucleotid& operator[](size_t index);
	const DnaSequence::Nucleotid& operator[](size_t index)const;
	char* getCopyNucs()const;
	size_t length()const;
	void writeToFile(std::string filename)const;
	void readFromFile(std::string filename);
	std::string getAsStr(size_t from, size_t to)const;
	operator std::string()const{return getAsStr(size_t(0),length()-size_t(1));};

	DnaSequence slice(size_t from, size_t to)const;
	DnaSequence pair()const;
	size_t find(const DnaSequence& dna)const;
	int count(const DnaSequence& dna)const;
	std::vector<size_t> findAll(const DnaSequence& dna)const;
	std::vector<std::string> consensusSequence()const;
	
	
friend std::ostream& operator<<(std::ostream& os, DnaSequence& dna);
friend std::ostream& operator<<(std::ostream& os, Nucleotid& nuc);
};

inline DnaSequence::Nucleotid::Nucleotid():m_nuc('\0') {}

inline DnaSequence::Nucleotid::Nucleotid(char nuc) : m_nuc('\0')
{
	if (IsValidNucleotid(nuc))
		m_nuc = nuc;
	else
		throw InvalidNucleotid();
}

inline DnaSequence::Nucleotid& DnaSequence::Nucleotid::operator = (const Nucleotid& nuc)
{
	if (this != &nuc)
		m_nuc = nuc.m_nuc;
	return *this;
}

inline const char& DnaSequence::Nucleotid::getNuc()const
{
	return m_nuc;
}

inline DnaSequence::DnaSequence():m_nucleotids(NULL){}

inline DnaSequence::DnaSequence(const DnaSequence& dna)
{
	initNucleotids(dna.getCopyNucs());
}

inline DnaSequence::~DnaSequence()
{
	delete[] m_nucleotids;
}

inline DnaSequence::DnaSequence(const char* sequence):m_nucleotids(NULL)
{
	if (isValidDna(sequence))
		initNucleotids(sequence);
	else
		throw InvalidDna();
}

inline DnaSequence::DnaSequence(const std::string& sequence):m_nucleotids(NULL)
{
	if (isValidDna(sequence.c_str()))
		initNucleotids(sequence.c_str());
	else
		throw InvalidDna();
}

inline DnaSequence& DnaSequence::operator =(const DnaSequence& dna)
{
	if (&dna != this)
		initNucleotids(dna.getCopyNucs());	
	return *this;
}

inline std::ostream& operator<<(std::ostream& os, DnaSequence& dna)
{
	os << dna.getCopyNucs() << std::endl;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, DnaSequence* dna)
{
	os << (*dna).getCopyNucs() << std::endl;
	return os;
}

inline std::ostream& operator<<(std::ostream& os, DnaSequence::Nucleotid& nuc)
{
	os << nuc.getNuc() << std::endl;
	return os;
}

inline bool operator ==(const DnaSequence& dna1,const DnaSequence& dna2)
{
	char* dna1NucsCopy = dna1.getCopyNucs();
	char* dna2NucsCopy = dna2.getCopyNucs();
	const bool identical = (strcmp(dna1NucsCopy,dna2NucsCopy)==0);
	delete dna1NucsCopy;
	delete dna2NucsCopy;
        return identical;
}

inline bool operator !=(const DnaSequence& dna1, const DnaSequence& dna2)
{
	return !(dna1==dna2);
}

inline DnaSequence::Nucleotid& DnaSequence::operator[](size_t index) //set
{
	if (index >= 0 && index < length())
		return m_nucleotids[index];
	else
		throw std::out_of_range("index out of range of the sequence");
}

inline const DnaSequence::Nucleotid& DnaSequence::operator[](size_t index)const //get
{
	if (index >= 0 && index < length())
		return m_nucleotids[index];
	else
		throw std::out_of_range("index out of range of the sequence");
}

inline size_t DnaSequence::length()const
{
	size_t i = 0;
	while (m_nucleotids[i].getNuc() != '\0')
		i++;
	return i;
}

#endif
