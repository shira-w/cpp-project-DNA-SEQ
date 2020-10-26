#ifndef INVALIDNUCLEOTID_H
#define INVALIDNUCLEOTID_H

#include <stdexcept>  

class InvalidDna :public std::invalid_argument
{
public:
	InvalidDna();
	/*virtual*/ const char* what() const throw();

};
inline InvalidDna::InvalidDna() :std::invalid_argument("") {}

inline const char* InvalidDna::what() const throw()
{
	return "Invalid Dna\n";
}


class InvalidNucleotid : public InvalidDna
{
public:
	InvalidNucleotid();
	/*virtual*/ const char* what() const throw();
};
inline InvalidNucleotid::InvalidNucleotid():InvalidDna() {}

inline const char* InvalidNucleotid::what() const throw()
{
	return "Invalid Nucleotid\n";
}


#endif
