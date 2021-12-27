#include "EdgeDetection/NoiseReductionFilter.hpp"

namespace EdgeDetection
{
	void NoiseReductionFilter::filterPixel(const PixelMatrix& input, PixelMatrix& output, int x, int y)
	{
		const auto currentPixel = input.at(x, y);
		float result = 0.f;

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				result += static_cast<float>(input.atSafe(x + i - 2, y + j - 2, currentPixel))
					* factors.at(i).at(j);
			}
		}

		result *= multiplier;

		output.at(x, y) = static_cast<Types::Byte>(result);
	}
}
