#pragma once

#include "common.h"

class VisualComponent
{
public:
	VisualComponent() {}

	virtual void Draw() {}

	virtual void Resize(){}
};


class Decorator : public VisualComponent
{
public:
	Decorator(VisualComponent* v) : component_(v) {}

	virtual void Draw(){
		component_->Draw();
	}

	virtual void Resize(){
		component_->Resize();
	}

private:
	VisualComponent* component_;
};


class BorderDecorator : public Decorator
{
public:
	BorderDecorator(VisualComponent* v, int borderWidth)
	: Decorator(v), width_(10) {}

	virtual void Draw()
	{
		cout << "BorderDecorator::Draw" << endl;
		Decorator::Draw();
		DrawBorder(width_);
	}
	
private:
	void DrawBorder(int)
	{
		cout << "BorderDecorator::DrawBorder" << endl;
	} 

private:
	int width_;
};


class ScrollDecorator : public Decorator
{
public:
	ScrollDecorator(VisualComponent* v) : Decorator(v) {}

	virtual void Draw()
	{
		cout << "ScrollDecorator::Draw" << endl;
		Decorator::Draw();
		DrawScroll();
	}

	void DrawScroll()
	{
		cout << "ScrollDecorator::DrawScroll" << endl;
	}
};


class TextView : public VisualComponent
{
public:
	virtual void Draw()
	{
		cout << "TextView::Draw" << endl;
	}
};


class Window
{
public:
	void SetContents(VisualComponent* v)
	{
		cout << "Window::SetContents" << endl;
		v->Draw();
	}
};
