#include "pch.h"
#include "Unit.h"

namespace Tonkatsu {
	Unit::Unit(const std::string& fileName): mPicture(fileName)
	{
		TONKATSU_LOG("CONSTRUCTING UNIT FOR " << fileName);
	}

	Unit::Unit(const std::string& fileName, int xPos, int yPos): mPicture(fileName), mXPos(xPos), mYPos(yPos)
	{
		TONKATSU_LOG("CONSTRUCTING UNIT FOR " << fileName);
	}

	void Unit::SetCoordinates(int newXPos, int newYPos)
	{
		mXPos = newXPos;
		mYPos = newYPos;
	}

	int Unit::GetXCoordinate() const
	{
		return mXPos;
	}

	int Unit::GetYCoordinate() const
	{
		return mYPos;
	}

	void Unit::IncrementXPosition(int amount)
	{
		mXPos += amount;
	}

	void Unit::IncrementYPosition(int amount)
	{
		mYPos += amount;
	}

	void Unit::SetSpeed(int newSpeed)
	{
		mSpeed = newSpeed;
	}

	int Unit::GetSpeed() const
	{
		return mSpeed;
	}

	Dimensions Unit::GetDimensions() const
	{
		return mPicture.GetDimensions();
	}

	bool Unit::IsVisible() const
	{
		return mIsVisible;
	}

	void Unit::MakeVisible()
	{
		mIsVisible = true;
	}

	void Unit::MakeInvisible()
	{
		mIsVisible = false;
	}

	bool TONKATSU_API Collide(const Unit& one, const Unit& another)
	{
		int xLeftOne = one.mXPos;
		int xRightOne = one.mXPos + one.mPicture.GetDimensions().width;
		int xLeftAnother = another.mXPos;
		int xRightAnother = another.mXPos + another.mPicture.GetDimensions().width;

		bool xOverlap = (xLeftOne <= xLeftAnother && xLeftAnother <= xRightOne) || (xLeftOne <= xRightAnother && xRightAnother <= xRightOne) || (xLeftOne >= xLeftAnother && xRightOne <= xRightAnother);

		int yBottomOne = one.mYPos;
		int yTopOne = one.mYPos + one.mPicture.GetDimensions().height;
		int yBottomAnother = another.mYPos;
		int yTopAnother = another.mYPos + another.mPicture.GetDimensions().height;

		bool yOverlap = (yBottomOne <= yBottomAnother && yBottomAnother <= yTopOne) || (yBottomOne <= yTopAnother && yTopAnother <= yTopOne) || (yBottomOne >= yBottomAnother && yTopOne <= yTopAnother);

		return (xOverlap && yOverlap);
	}
}
