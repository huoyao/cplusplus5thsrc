#ifndef TEXTQURY_H_
#define TEXTQURY_H_
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <memory>
class QueryResult;
class TextQuery
{
public:
	using line_no = std::vector<std::string >::size_type;
	TextQuery(std::ifstream &);
	QueryResult query(const std::string &);
private:
	std::shared_ptr<std::vector<std::string>> file;
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};
#endif