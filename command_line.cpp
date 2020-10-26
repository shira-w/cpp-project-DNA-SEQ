#include "command_line.h"

#include <vector>
#include <iostream>
#include <string.h>

//#include <stdio.h>

using std::string;
using std::vector;
using std::cout;
using std::endl;
using std::cin;
using std::getline;
/*TODO devided to func*/

//find becouse of the exceptions std::map<char,int>::iterator it

//===============================================================Auxiliary Funcs
void split(istringstream& iss,vector<string>& vec)
{
	string str;
	while (iss>> str ) {
		vec.push_back(str);
  	}
}
//===============================================================
/*TODO think about console*/
/*TODO better than static*/
/*TODO think about params*/
/*TODO remove first element and execute fixes(commandLine in quit???)*/
void CommandLine::run()
{
	vector<string> input;
	string line;
	do
	{
		input.clear();
		cout<<"> cmd >>>";
		std::getline(std::cin,line);
		if (line=="")
			continue;

		istringstream convertLine(line);
		
		split(convertLine, input);
		if (input.size()==0)
				continue;
		if(!CommandCollection::getCommand(input[0]))
		{
			CommandFactory::createCommand(input[0]);
		}
		if(CommandCollection::getCommand(input[0]))
		{
			Icommands* currentCommand=CommandCollection::getCommand(input[0]);
			input.erase(input.begin());
			string out=currentCommand->execute(input);
			if (out=="help")
			{
				if (CommandCollection::getCommand(input[1]))
				{
					cout<< CommandCollection::getCommand(input[1])->document();
				}
				else
				{
					cout<< "'"<<input[1]<<"' "<<"is not recognize as an interanal or external command, operable program or batch file.";
				}
			}
			else
			{
				//upgrade
				cout<<out;
			}
			cout<<endl;
		}
		else
		{
			if (input.size()==0)
				continue;
			else
				cout<< "'"<<input[0]<<"' "<<"is not recognize as an interanal or external command, operable program or bash file."<<endl;
		}
	} while(input[0]!="quit");
}


