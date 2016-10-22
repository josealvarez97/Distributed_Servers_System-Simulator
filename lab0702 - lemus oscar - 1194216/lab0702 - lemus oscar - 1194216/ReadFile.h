#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

class ReadFile
{
public:
	ReadFile();
	~ReadFile();
private: 
	ifstream file;
public:
	void ReadInput(string Entrada);
};

