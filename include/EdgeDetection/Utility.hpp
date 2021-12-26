#pragma once

#include <string_view>
#include <vector>
#include <CImg.h>
#include "EdgeDetectionTypes.hpp"

namespace EdgeDetection::Utility
{
	using namespace Types;

	Image loadImage(std::string_view pathToImage);

	void saveImage(const Image& image, std::string_view pathToImage);

	Image toGrayscale(const Image& image);
}
