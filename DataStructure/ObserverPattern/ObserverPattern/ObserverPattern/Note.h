#pragma once
#include <iostream>
#include "Observer/Observer.h"
using namespace std;

class Note : public Observer
{
public:
	void Write();
	void Reset();
private:
	string note;
};
