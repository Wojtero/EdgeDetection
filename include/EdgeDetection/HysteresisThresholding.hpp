#pragma once
#include "EdgeDetection/PixelMatrix.hpp"
#include <vector>

namespace EdgeDetection 
{
	/*
	Takes suppressed gradient intensities and two thresholds
    pixels with values above maxVal are surely edges
    pixel below minval are not edges and are suppressed
    pixels between maxVal and minVal are suppressed if they do not neighbour a sure-edge pixel 
	*/
	void thresholdHysteresis(const PixelMatrix& gradientIntensity, const int maxVal, const int minVal, PixelMatrix& output);

	bool Contains(std::vector<Vector2Int>& vec, Vector2Int& elem);

	bool isPossibleEdgeMiddle(const PixelMatrix& gradientIntensity, const Vector2Int pos, const int maxVal,
		const int minVal, const Direction directions[]);
}