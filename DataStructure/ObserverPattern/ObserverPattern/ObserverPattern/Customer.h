#pragma once
#include <iostream>
#include "Observer/Observer.h"
#include <vector>


class Customer
{
public:
	virtual void NotifyObserver()=0;
	virtual void AddObserver(Observer* observers)=0;
	virtual void RemoveObserver(Observer* observers)=0;
};