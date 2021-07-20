#pragma once
#include "common.h"


class WindowImp;

class Window
{
public:
	Window(): impl_(nullptr){}

	virtual void Open() = 0;

protected:
	WindowImp* GetWindowImp();

private:
	WindowImp* impl_;
};


class IconWindow : public Window
{
public:
	void Open()
	{
		cout << "IconWindow::Open" << endl;
		WindowImp* imp = GetWindowImp();
		if (imp != 0)
		{
			imp->ImpTop();
		}
	}
};


class WindowImp
{
public:
	virtual void ImpTop() = 0;

protected:
	WindowImp() {}
};


class XWindowImp : public WindowImp
{
public:
	XWindowImp() {}

	void ImpTop()
	{
		cout << "XWindowImp::ImpTop" << endl;
	}
};