#include "EdgeDetection/HysteresisThresholding.hpp"
#include "EdgeDetection/GradientSuppression.hpp"
#include "EdgeDetection/Vector2Int.hpp"

#define NUMBER_OF_DIRECTIONS 4

namespace EdgeDetection
{
	void thresholdHysteresis(const PixelMatrix& gradientIntensity, const int maxVal, const int minVal, PixelMatrix& output)
	{
		float width = gradientIntensity.getWidth();
		float height = gradientIntensity.getHeight();
        
        std::vector<Vector2Int> possibleEdgeMiddles = {};
        std::vector<Vector2Int> doneEdgeMiddles = {};
        Direction neighbourDirections[NUMBER_OF_DIRECTIONS] = {Direction::East, Direction::North, Direction::West, Direction::South};

        //all sure-edge pixels neighbouring possible-edge pixels are marked
		for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < height; y++)
			{
				Vector2Int currPos = Vector2Int(x, y);
                Types::Byte currVal = gradientIntensity.at(currPos);

				if(currVal > maxVal)
                {
                    output.at(currPos) = currVal;
                    if(isPossibleEdgeMiddle(gradientIntensity, currPos, maxVal, minVal, neighbourDirections))
                    {
                        possibleEdgeMiddles.push_back(currPos);
                    }
                }
                else if(currVal < minVal)
                {
                    output.at(currPos) = 0;
                }
			}
		}

        // extend edges
        while(possibleEdgeMiddles.size() > 0)
        {
            Vector2Int currPos = possibleEdgeMiddles.back();
            Types::Byte cmpVal;
            for(int i = 0; i < NUMBER_OF_DIRECTIONS; i++)
            {
                Vector2Int checkPos = currPos + currPos.fromDirection(neighbourDirections[i]);
                cmpVal = gradientIntensity.atSafe(checkPos, -1);
                if(cmpVal <= maxVal && cmpVal >= minVal)
                {
                    if(!Contains(doneEdgeMiddles, checkPos))
                    {
                        output.at(checkPos) = cmpVal;
                        possibleEdgeMiddles.push_back(checkPos);
                    }
                }
            }
            possibleEdgeMiddles.pop_back();
        }


        // suppress all left pixels between maxVal and minVal
       	for (int x = 0; x < width; x++)
		{
			for (int y = 0; y < height; y++)
			{
				Vector2Int currPos = Vector2Int(x, y);
                Types::Byte currVal = gradientIntensity.at(currPos);

				if(currVal <= maxVal && currVal >= minVal)
                {
                    output.at(currPos) = 0;
                }
            }
        }
	}

    bool isPossibleEdgeMiddle(const PixelMatrix& gradientIntensity, const Vector2Int pos, const int maxVal, const int minVal, const Direction directions[])
    {
        Types::Byte cmpVal;
        for(int i = 0; i < NUMBER_OF_DIRECTIONS; i++)
        {
            cmpVal = gradientIntensity.atSafe(pos + pos.fromDirection(directions[i]), -1);
            if(cmpVal <= maxVal && cmpVal >= minVal)
            {
                return true;
            }
        }
        return false;
    }

    bool Contains(std::vector<Vector2Int>& vec, Vector2Int& elem)
    {
        for(int i = vec.size()-1; i >=0; i--)
        {
            if(vec[i].x == elem.x && vec[i].y == elem.y) return true;
        }
        return false;
    }
}