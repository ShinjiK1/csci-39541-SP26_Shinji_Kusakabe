#pragma once

#include"TonkatsuUtility.h"
#include"KeyCodes.h"

namespace Tonkatsu
{
	class TONKATSU_API WindowCloseEvent {

	};

	class TONKATSU_API KeyEvent {
	public:
		KeyEvent(Key keyCode, KeyAction action);
		Key GetKeyCode() const;
		KeyAction GetAction() const;
		void SetKeyCode(Key newKeyCode);
		void SetAction(KeyAction newAction);

	private:
		Key mKeyCode{ Key::UNDEF };
		KeyAction mAction{ KeyAction::UNDEFINED };
	};
}