#include "EdgeDetection/GradientSuppression.hpp"
#include "EdgeDetection/Vector2Int.hpp"

namespace EdgeDetection
{
	void suppressNonMaximums(const PixelMatrix& gradientIntensity, const PixelMatrix& gradientDirection, PixelMatrix& output)
	{
		float width = gradientIntensity.getWidth();
		float height = gradientIntensity.getHeight();

		for (int x = 1; x < width - 1; x++)
		{
			for (int y = 1; y < height - 1; y++)
			{
				Vector2Int currPos = Vector2Int(x, y);

				Vector2Int direction = Vector2Int::fromDirection( ((Direction)gradientDirection.at(x, y)) );
				Vector2Int neighbour1Pos = currPos + direction;
				Vector2Int neighbour2Pos = currPos + ((-1)*direction);
				
				Types::Byte currVal = gradientIntensity.at(currPos);
				Types::Byte neighbour1Val = gradientIntensity.at(neighbour1Pos);
				Types::Byte neighbour2Val = gradientIntensity.at(neighbour2Pos);

				if (neighbour1Val > currVal || neighbour2Val > currVal)
				{ // The current pixel is not a maximum
					output.at(currPos) = 0;
				}
				else
				{ // Maximum
					output.at(currPos) = currVal;
				}
			}
		}
	}
}
