#pragma once


inline int RollADice(int Sides)
{
	return FMath::RandRange(1, Sides);
}