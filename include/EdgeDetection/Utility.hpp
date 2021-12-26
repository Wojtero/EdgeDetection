#pragma once

#include <string_view>
#include <CImg.h>

#include "EdgeDetectionTypes.hpp"

namespace EdgeDetection::Utility
{
	using namespace Types;

	auto loadImage(std::string_view pathToImage) -> Image;

	void saveImage(const Image& image, std::string_view pathToImage);

	auto toGrayscale(const Image& image) -> Image;
}
