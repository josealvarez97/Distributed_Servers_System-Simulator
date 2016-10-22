#include "stdafx.h"
#include "ReadFile.h"


ReadFile::ReadFile(string Entrada)
{
	file.open(Entrada);

}


ReadFile::~ReadFile()
{
}
