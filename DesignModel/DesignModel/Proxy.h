#pragma once

#include "common.h"

class Graphic
{
public:
	virtual ~Graphic(){}

	virtual void Draw() = 0;
	virtual void HandleMouse() = 0;
	virtual void GetExtent() = 0;
	
};


class Image: public Graphic
{
public:
	Image() {
		cout << "Image::Image" << endl;
	}

	void Draw()
	{
		cout << "Image::Draw" << endl;
	}

	void HandleMouse()
	{
		cout << "Image::HandleMouse" << endl;
	}

	void GetExtent()
	{
		cout << "Image::GetExtent" << endl;
	}
};


class ImageProxy : public Graphic
{
public:
	ImageProxy()
	{
		cout << "ImageProxy" << endl;
	}

	void Draw()
	{
		GetImage()->Draw();
	}

protected:
	Image* GetImage()
	{
		return new Image();
	}

private:
	Image* image_;
};
