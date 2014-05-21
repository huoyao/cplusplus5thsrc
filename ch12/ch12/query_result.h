#ifndef QUERYRESULT_H_
#define QUERYRESULT_H_
#include <iostream>
#include <vector>
#include <set>
#include <memory>
#include <string>
class QueryResult
{
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	using line_no = std::vector<std::string >::size_type;
	QueryResult(std::string s, std::shared_ptr<std::vector<std::string>> file, std::shared_ptr<std::set<line_no>> lines)
		:sought(s),file(file),lines(lines){}
private:
	std::string sought;
	std::shared_ptr<std::vector<std::string>> file;
	std::shared_ptr<std::set<line_no>> lines;

};
#endif