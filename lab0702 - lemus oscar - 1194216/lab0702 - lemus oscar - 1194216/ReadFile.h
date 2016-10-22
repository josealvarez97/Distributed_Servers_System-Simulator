#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class ReadFile
{
public:
	ReadFile(string Entrada);
	~ReadFile();
private: 
	ifstream file;
};

