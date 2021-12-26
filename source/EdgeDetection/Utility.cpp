#include "EdgeDetection/Utility.hpp"

#include <cassert>
#include <iostream>

namespace EdgeDetection::Utility
{
	auto loadImage(std::string_view pathToImage) -> Image
	{
		return Image{pathToImage.data()};
	}

	void saveImage(const Image& image, std::string_view pathToImage)
	{
		image.save_jpeg(pathToImage.data());
	}

	auto toGrayscale(const Image& image) -> Image
	{
		assert(image.spectrum() >= 3);

		auto calculateGray = [](Byte red, Byte green, Byte blue) -> Byte
		{
			const float redWeight = 0.299;
			const float greenWeight = 0.587;
			const float blueWeight = 0.114;

			const float weightedRed = redWeight * static_cast<float>(red);
			const float weightedGreen = greenWeight * static_cast<float>(green);
			const float weightedBlue = blueWeight * static_cast<float>(blue);

			return static_cast<Byte>(weightedRed + weightedGreen + weightedBlue);
		};

		Image grayImage (image.width(), image.height());

		const int redIndex = 0;
		const int greenIndex = 1;
		const int blueIndex = 2;

		cimg_forXYZ(grayImage, x, y, z)
		{
			grayImage._atXY(x, y) = calculateGray(image(x, y, z, redIndex),
				image(x, y, z, greenIndex),
				image(x, y, z, blueIndex));
		}

		return grayImage;
	}
}
