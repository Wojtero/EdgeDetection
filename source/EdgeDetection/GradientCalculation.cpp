#include "EdgeDetection/GradientCalculation.hpp"
#include "EdgeDetection/Vector2Int.hpp"

namespace EdgeDetection
{
	void calculateGradient(
		const PixelMatrix& horizontalGradient,
		const PixelMatrix& verticalGradient,
		PixelMatrix& resultIntensity,
		PixelMatrix& resultDirection)
	{
		size_t width = horizontalGradient.getWidth();
		size_t height = horizontalGradient.getHeight();

		for (size_t x = 0; x < width; x++)
		{
			for (size_t y = 0; y < height; y++)
			{
				Types::Byte horGradByte = horizontalGradient.at(x, y);
				float horGrad = reinterpret_cast<signed char&>(horGradByte);

				Types::Byte vertGradByte = verticalGradient.at(x, y);
				float vertGrad = reinterpret_cast<signed char&>(vertGradByte);

				// Module of the gradient
				float module = sqrt(horGrad * horGrad + vertGrad * vertGrad);

				resultIntensity.at(x, y) = static_cast<Types::Byte>(module);

				// Direction of the gradient
				Direction direction = Direction::North;
				if (horGrad != 0) {
					float angle = atan(vertGrad / horGrad);
					direction = angleToDirection(angle);
				}

				resultDirection.at(x, y) = static_cast<Types::Byte>(direction);
			}
		}
	}
}