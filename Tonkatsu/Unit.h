#pragma once

#include"TonkatsuUtility.h"

#include"Picture.h"

namespace Tonkatsu {
	class TONKATSU_API Unit {
	public:
		Unit(const std::string& fileName);
		Unit(const std::string& fileName, int xPos, int yPos);

		void SetCoordinates(int newXPos, int newYPos);
		int GetXCoordinate() const;
		int GetYCoordinate() const;

		void IncrementXPosition(int amount);
		void IncrementYPosition(int amount);

		void SetSpeed(int newSpeed);
		int GetSpeed() const;

		Dimensions GetDimensions() const;

		bool IsVisible() const;
		void MakeVisible();
		void MakeInvisible();

	private:
		Picture mPicture;
		int mXPos{ 0 };
		int mYPos{ 0 };
		int mSpeed{ 0 };
		bool mIsVisible{ true };

		friend class Renderer;
		friend bool TONKATSU_API Collide(const Unit& one, const Unit& another);
	};
}