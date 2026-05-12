#include"pch.h"

#include"TonkatsuEvents.h"

namespace Tonkatsu
{
	KeyEvent::KeyEvent(Key keyCode, KeyAction action): mKeyCode(keyCode), mAction(action)
	{

	}

	Key KeyEvent::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyAction KeyEvent::GetAction() const
	{
		return mAction;
	}

	void KeyEvent::SetKeyCode(Key newKeyCode)
	{
		mKeyCode = newKeyCode;
	}

	void KeyEvent::SetAction(KeyAction newAction)
	{
		mAction = newAction;
	}

}