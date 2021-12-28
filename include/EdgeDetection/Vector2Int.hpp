#pragma once

namespace EdgeDetection
{
	enum class Direction {
		North, NorthEast,
		East, SouthEast,
		South, SouthWest,
		West, NorthWest
	};

	/*
	Rounds angle in radians (from -PI to PI) to a direction
	*/
	Direction angleToDirection(float angle);


	struct Vector2Int
	{
		int x;
		int y;

		Vector2Int(int x, int y);
		static Vector2Int fromDirection(Direction direction);

		friend Vector2Int operator+(const Vector2Int& right, const Vector2Int& left);
		friend Vector2Int operator*(float multiplier, const Vector2Int& left);
	};
}