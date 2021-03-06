// Ex_CH11_DoitBeforeHealth.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "const.h"
#include "std_lib_facilities.h"
#include <bitset>

using namespace std;

int main()
{
	ifstream  iFile(path_text);
	ofstream oFile(path_binary, ios::out|ios::binary);
	
	vector<int> text_binary;
	for (int x; iFile.read(as_bytes(x), sizeof(int));)
	{
		text_binary.push_back(x);
		cout << x << " | ";
	}
		
	for (int x : text_binary)
		oFile.write(as_bytes(x), sizeof(int));

    return 0;
}


