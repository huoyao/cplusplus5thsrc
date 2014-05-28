// exercise.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	vec.push_back(1);
	cout << "vec.at(2) " << vec[0] << endl;
	//vec.resize(50);
	//vec.reserve(50);
	for (int i = 0; i != 50;++i)
	{
		vec.push_back(i);
		cout << "vec " << vec[i] << endl;
	}
	cout <<"size of vec:"<< sizeof(vec) << endl;
	cout << sizeof (vec[0]) << endl;
	cout << "vec.max_size()" << vec.max_size() << endl;
	cout << "vec.capacity()" << vec.capacity() << endl;
	cout << "vec.at(2) " << vec[20] << endl;
	return 0;
}

