#pragma once

#include "Filter.hpp"
#include <array>

namespace EdgeDetection
{
	/**
	 * 3x3 Vertical Sobel filter.
	 */
	class VerticalSobelFilter : public Filter
	{
	  protected:

		void filterPixel(const PixelMatrix &input, PixelMatrix &output, int x, int y) override;

	  private:

		std::array<std::array<float, 3>, 3> factors =
			{
				std::array{-1.f, 0.f, 1.f},
				std::array{-2.f, 0.f, 2.f},
				std::array{-1.f, 0.f, 1.f}
			};
	};
}
