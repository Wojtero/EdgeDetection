#pragma once

#include "Filter.hpp"
#include <array>

namespace EdgeDetection
{
	/**
	 * 3x3 Horizontal Sobel filter.
	 */
	class HorizontalSobelFilter : public Filter
	{
	  protected:

		void filterPixel(const PixelMatrix &input, PixelMatrix &output, int x, int y) override;

	  private:

		std::array<std::array<float, 3>, 3> factors =
			{
				std::array{1.f, 2.f, 1.f},
				std::array{0.f, 0.f, 0.f},
				std::array{-1.f, -2.f, -1.f}
			};
	};
}
