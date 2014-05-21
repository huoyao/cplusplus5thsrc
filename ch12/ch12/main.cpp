#include <iostream>
#include <fstream>
#include "text_query.h"
#include "query_result.h"
using namespace std;

ostream &print(ostream &os,const QueryResult &result)
{
	os << result.sought << " occurs " << result.lines->size() << " " << (result.lines->size() > 1 ? "times" : "time") <<endl;
	for (auto &num:*result.lines)
	{
		os << "\t(line" << num + 1 << ") " << *(result.file->begin() + num) << endl;
	}
	return os;
}

int main(int argc, char **argv)
{
	ifstream infile(argv[1]);
	TextQuery qt(infile);
	string word;
	while (true)
	{
		cout << "enter word to look up,or q to quit" << endl;
		if (!(cin>>word)||word=="q")
		{
			break;
		}
		print(cout,qt.query(word))<<endl;
	}
}