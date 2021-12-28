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

	PixelMatrix::PixelMatrix(int width, int height)
		: width(width), height(height) 
	{
		pixels.assign(width * height, 0); // Fill with zeroes
	}

	Types::Byte& PixelMatrix::at(int x, int y)
	{
		return pixels.at(x + width * y);
	}

	Types::Byte& PixelMatrix::at(const Vector2Int& position)
	{
		return at(position.x, position.y);
	}
	

	Types::Byte PixelMatrix::at(int x, int y) const
	{
		return pixels.at(x + width * y);
	}

	Types::Byte PixelMatrix::at(const Vector2Int& position) const
	{
		return at(position.x, position.y);
	}

	Types::Byte PixelMatrix::atSafe(int x, int y, Types::Byte alternative) const
	{
		if ((x < 0 || width-1 < x) || (y < 0 || height-1 < y))
		{
			return alternative;
		}

		return pixels.at(x + width * y);
	}

	Types::Byte PixelMatrix::atSafe(const Vector2Int& position, Types::Byte alternative) const
	{
		return atSafe(position.x, position.y, alternative);
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

	std::ostream& operator<<(std::ostream& out, const PixelMatrix& matrix)
	{
		for (int y = 0; y < matrix.getHeight(); y++)
		{
			for (int x = 0; x < matrix.getWidth(); x++)
			{
				Types::Byte value = matrix.at(x, y);
				out << (int)value << " ";
			}
			out << std::endl;
		}

		return out;
	}

	PixelMatrix PixelMatrix::getEdgeGradient(const PixelMatrix& horizontal, const PixelMatrix& vertical)
	{
		assert(horizontal.width == vertical.width && horizontal.height == vertical.height);

		PixelMatrix output (horizontal.width, horizontal.height);

		const auto width = horizontal.width;
		const auto height = horizontal.height;

		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				const auto gX = static_cast<float>(horizontal.at(i, j));
				const auto gY = static_cast<float>(vertical.at(i, j));
				output.at(i, j) = static_cast<Types::Byte>(std::sqrt(gX*gX + gY*gY));
			}
		}

		return output;
	}

	PixelMatrix PixelMatrix::getAngle(const PixelMatrix& horizontal, const PixelMatrix& vertical)
	{
		assert(horizontal.width == vertical.width && horizontal.height == vertical.height);

		PixelMatrix output (horizontal.width, horizontal.height);

		const auto width = horizontal.width;
		const auto height = horizontal.height;

		for (int i = 0; i < width; ++i)
		{
			for (int j = 0; j < height; ++j)
			{
				const auto gX = static_cast<float>(horizontal.at(i, j));
				const auto gY = static_cast<float>(vertical.at(i, j));
				output.at(i, j) = static_cast<Types::Byte>(std::atan(gX / gY));
			}
		}

		return output;
	}
}
