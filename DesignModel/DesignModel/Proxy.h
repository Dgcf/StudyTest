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

namespace proxy
{
	class subject
	{
	public:
		virtual void songhua() = 0;
	};

	class zhuojiayi: public subject
	{
	public:
		void songhua()
		{
			cout << "zhuojiayi: " << __func__ << endl;
		}
	};

	class daili: public subject
	{
	public:
		daili(zhuojiayi* s) : z_(s) {}
		void songhua()
		{
			cout << "daili: " << __func__ << endl;
			z_->songhua();
		}

	private:
		zhuojiayi* z_;
	};
}
