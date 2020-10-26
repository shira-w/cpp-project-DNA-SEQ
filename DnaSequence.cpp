#include "DnaSequence.h"
const char trueNucs[] = "AGCT";

bool DnaSequence::Nucleotid::IsValidNucleotid(char candidate)
{
	if (candidate == '\0')
		return true;
	for (size_t j = 0; j <= 3; j++)
	{
		if (trueNucs[j] == candidate)
			return true;
	}
	return false;
}

bool DnaSequence::isValidDna(const char* candidate)const
{
	for (size_t i = 0; i < strlen(candidate); i++)
	{
		Nucleotid n;
		if (n.IsValidNucleotid(candidate[i]))
			return true;
	}
	return false;
}

void DnaSequence::initNucleotids(const char* sequence)
{
	m_nucleotids = new Nucleotid[strlen(sequence)+1];
	size_t i;
	for (i = 0; i <strlen(sequence); i++)
	{
		m_nucleotids[i] = sequence[i];
	}
	m_nucleotids[i]='\0';
}
char* DnaSequence::getCopyNucs()const
{
	char* mewSequence = new char[length()+1];
	size_t i;
	for (i = 0; i < length(); i++)
		mewSequence[i] = m_nucleotids[i].getNuc();
	mewSequence[i]='\0';

	return mewSequence;
}
void DnaSequence::writeToFile(std::string filename)const
{
	 std::ofstream myfile;
	 myfile.open(filename.c_str());
	 myfile << getCopyNucs();
	 myfile.close();
}
void DnaSequence::readFromFile(std::string filename)
{
	 std::ifstream myfile;
	 std::string word;
	 myfile.open(filename.c_str());
	 myfile >> word;
	 initNucleotids(word.c_str());
}

std::string DnaSequence::getAsStr(size_t from, size_t to)const
{
	 std::string str;
	 for (size_t i = from; i <= to; i++)
		 str += (*this)[i].getNuc();
	 return str;
}

DnaSequence DnaSequence::slice(size_t from, size_t to)const
{
	 DnaSequence dna(getAsStr(from,to).c_str());
	 return dna;
}
 
DnaSequence DnaSequence::pair()const
{
	 std::map<char, char> pairing;
	 pairing['A'] = 'T';
	 pairing['T'] = 'A';
	 pairing['G'] = 'C';
	 pairing['C'] = 'G';
	 std::string temp = getAsStr(0,length()-1);
	 for (size_t i = 0; i < temp.length(); i++)
		 temp[i] = pairing[temp[i]];
	 DnaSequence d1(temp);
	 return d1;
}

size_t DnaSequence::find(const DnaSequence& dna)const
{
	std::string substring=dna.getAsStr(0,length()-1);
	std::string str=getAsStr(0,length()-1);
	size_t index=-1;
	for(size_t i=0;i< str.length();i++)
	{
		if(str[i]==substring[i])
		{
			index=i;
			while(str[i]==substring[i])
				i++;
			if((i-1-index)==substring.length())
				break;
		}
	}
	return index;
}
int DnaSequence::count(const DnaSequence& dna)const
{
	std::string substring=dna.getAsStr(0,length()-1);
	std::string str=getAsStr(0,length()-1);
	size_t index=0;
	int count=0;
	for(size_t i=0;i< str.length();i++)
	{
		if(str[i]==substring[i])
		{
			index=i;
			while(str[i]==substring[i])
				i++;
			if((i-1-index)==substring.length())
				count++;
		}
	}
	return count;
}
std::vector<size_t> DnaSequence::findAll(const DnaSequence& dna)const
{
	std::string substring=dna.getAsStr(0,length()-1);
	std::string str=getAsStr(0,length()-1);
	std::vector<size_t> indexs;
	size_t index=-1;
	for(size_t i=0;i< str.length();i++)
	{
		if(str[i]==substring[i])
		{
			index=i;
			while(str[i]==substring[i])
				i++;
			if((i-1-index)==substring.length())
				indexs.push_back(index);
		}
	}
	return indexs;

}
std::vector<std::string> DnaSequence::consensusSequence()const
{
	std::string str=getAsStr(0,length()-1);
	std::vector<std::string> consensus;
	std::string temp="ATG";
	bool flag=0;
	int jump=1;
	for(size_t i=0; i< str.length();i+=jump)
	{
		if(flag==1)
		{
			temp+=str.substr(i,3);
			if((str[i]=='T'&&str[i+1]=='A'&&str[i+2]=='G' )||(str[i]=='T'&&str[i+1]=='A'&&str[i+2]=='A')||(str[i]=='T'&&str[i+1]=='G'&&str[i+2]=='A'))
			{
				jump=1;
				consensus.push_back(str);
			}
		}
		if(str[i]=='A'&&str[i+1]=='T'&&str[i+2]=='G')
		{
			jump=3;
			flag=1;
		}
		
	}
	return consensus;
}





