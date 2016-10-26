#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "RequestQueue.h"
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

using namespace std;

class CReadFile
{
public:
	CReadFile();
	~CReadFile();
private: 
	ifstream file;
public:
	void ReadInput(string Entrada, int ServersProccessingInfo[3], int ServersRamInfo[3], int ServersOperationsPerTickInfo[3], CRequestQueue* requestQueue);
};

