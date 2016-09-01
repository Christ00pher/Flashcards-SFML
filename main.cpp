#include <iostream>

using namespace std;

class IState
{
public:
	virtual void update() = 0;
	virtual void render() = 0;
	IState() {};
	~IState() {};
	static string s;
	static void setString(string x) {s = x;}
	static string getString() {return s;}
};

class StateStart : public IState
{
public:
	virtual void update() {};
	virtual void render() {};
	StateStart() {};
	~StateStart() {};
};

class StateHandle : public IState
{
public:
	void update() {};
	void render() {};
	StateHandle() {};
	~StateHandle() {};
};

int main()
{
	IState* state = new StateStart();
	state -> update();
	state -> render();
	//state -> setString("StateStart");
	//cout << "StateStart->s: " << state->getString() << endl;
	
	state = new StateHandle();
	StateHandle::setString("\nStateHandle");
	
	//cout << "StateHandle->s: " << state->getString() << endl;
	return 0;
}