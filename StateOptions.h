#pragma once
#include "IState.h"
#include "Caption.h"

class StateOptions : public IState
{
private:
	Caption credits;
public:
	StateOptions();
	~StateOptions() {};
	virtual void update();
	virtual void render();
	virtual void pollEvent();
};