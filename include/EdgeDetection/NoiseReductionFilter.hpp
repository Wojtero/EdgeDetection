#pragma once

#include "Filter.hpp"
#include <array>

namespace EdgeDetection
{
	/**
	 * 5x5 Gaussian filter.
	 */
	class NoiseReductionFilter : public Filter
	{
	  protected:

		void filterPixel(const PixelMatrix &input, PixelMatrix &output, int x, int y) override;

	  private:

		float multiplier = 1.f/159.f;

		std::array<std::array<float, 5>, 5> factors =
		{
			std::array{2.f, 4.f, 5.f, 4.f, 2.f},
			std::array{4.f, 9.f, 12.f, 9.f, 4.f},
			std::array{5.f, 12.f, 15.f, 12.f, 5.f},
			std::array{4.f, 9.f, 12.f, 9.f, 4.f},
			std::array{2.f, 4.f, 5.f, 4.f, 2.f}
		};
	};
}
