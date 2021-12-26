#include "EdgeDetection/PixelMatrix.hpp"
#include <cassert>

namespace EdgeDetection
{
	using namespace Types;

	PixelMatrix::PixelMatrix(const Image& image) : width{image.width()}, height{image.height()},
		pixels{std::begin(image), std::end(image)}
	{
		assert(image.spectrum() == 1);
	}

	Types::Byte& PixelMatrix::at(int x, int y)
	{
		return pixels.at(x + width * y);
	}

	Types::Byte PixelMatrix::at(int x, int y) const
	{
		return pixels.at(x + width * y);
	}

	int PixelMatrix::getWidth() const
	{
		return width;
	}

	int PixelMatrix::getHeight() const
	{
		return height;
	}

	const std::vector<Types::Byte>& PixelMatrix::getPixels() const
	{
		return pixels;
	}

	Types::Image PixelMatrix::toImage() const
	{
		Image image (width, height);

		cimg_forXY(image, x, y)
		{
			image.atXY(x, y) = at(x, y);
		}

		return image;
	}
}
