#include "EdgeDetection/GradientSuppression.hpp"
#include "EdgeDetection/Vector2Int.hpp"

namespace EdgeDetection
{
	void suppressNonMaximums(const PixelMatrix& gradientIntensity, const PixelMatrix& gradientDirection, PixelMatrix& output)
	{
		float width = gradientIntensity.getWidth();
		float height = gradientIntensity.getHeight();

		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < height; y++)
			{
				Vector2Int currPos = Vector2Int(x, y);

				Vector2Int direction = Vector2Int::fromDirection( ((Direction)gradientDirection.at(x, y)) );
				Vector2Int neighbour1Pos = currPos + direction;
				Vector2Int neighbour2Pos = currPos + ((-1)*direction);
				
				Types::Byte currVal = gradientIntensity.at(currPos);
				Types::Byte neighbour1Val = gradientIntensity.atSafe(neighbour1Pos, 0);
				Types::Byte neighbour2Val = gradientIntensity.atSafe(neighbour2Pos, 0);

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
