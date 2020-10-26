#include "dna_stracture.h"


map<int,string> DnaStracture::m_FromIdToName;
map<string,DnaData*> DnaStracture::m_FromNameToDnaData;

std::string temp[] = {".","-","*"};
const std::vector<std::string> DnaStracture::signStatus(temp, temp + sizeof(temp) / sizeof(temp[0]));
