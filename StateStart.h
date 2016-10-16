#pragma once
#include <SFML/Graphics.hpp>
#include "IState.h"
#include "TextBox.h"

class StateStart : public IState
{
private:
	TextBox tbEnglish;
	TextBox tbPolish;
	Caption cEnglish;
	Caption cPolish;
	Caption success;
	Caption mistake;
	bool newQuestion;
public:
	StateStart(Flashcards&,Window&);
	~StateStart();
	virtual void update();
	virtual void render();
	virtual void pollEvent();
	void getInput();
	bool isCorrect();
};