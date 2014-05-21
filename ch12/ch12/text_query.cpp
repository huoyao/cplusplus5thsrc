#include "text_query.h"
#include "query_result.h"
#include <sstream>
#include <fstream>
using namespace std;

TextQuery::TextQuery(ifstream & infile) :file(new vector<string>)
{
	string text;
	while (getline(infile, text))
	{
		file->push_back(text);
		string word;
		int n = file->size() - 1;
		istringstream strin(text);
		while (strin>>word)
		{
			while(!isalpha(word[0]))
			{
				int i = 0;
				while (word[++i])
				{
					word[i - 1] = word[i];
				}
				word.resize(word.size() - 1);
			}
			while (!isalpha(word[word.size()-1]))
			{
				word.resize(word.size() - 1);
			}
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new set<line_no>);
			lines->insert(n);
		}
	}
}

QueryResult TextQuery::query(const std::string &sought)
{
	shared_ptr<set<line_no>> nodata(new set<line_no>);
	auto result = wm.find(sought);
	if (result==wm.end())
	{
		return QueryResult(sought, file,nodata);
	}
	else
	{
		return QueryResult(sought,file, result->second);
	}
}