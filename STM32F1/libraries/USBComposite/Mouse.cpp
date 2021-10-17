#include "USBComposite.h" 

//================================================================================
//================================================================================
//	Mouse

void HIDMouse::begin(void){
}

void HIDMouse::end(void){
}

void HIDMouse::click(uint8_t b)
{
	_buttons = b;
  sendReport();
	_buttons = 0;
  sendReport();
}

void HIDMouse::move(signed char x, signed char y, signed char wheel)
{
	reportBuffer[1] = _buttons;
	reportBuffer[2] = x;
	reportBuffer[3] = y;
	reportBuffer[4] = wheel;
}

void HIDMouse::stop(bool x, bool y, bool wheel)
{
  if (x)
    reportBuffer[2] = 0;
  if (y)
    reportBuffer[3] = 0;
  if (wheel)
    reportBuffer[4] = 0;
}

void HIDMouse::buttons(uint8_t b)
{
	if (b != _buttons)
	{
    _buttons = b;
	}
}

void HIDMouse::press(uint8_t b)
{
	buttons(_buttons | b);
}

void HIDMouse::release(uint8_t b)
{
	buttons(_buttons & ~b);
}

void HIDMouse::releaseAll()
{
  _buttons = 0;
}

bool HIDMouse::isPressed(uint8_t b)
{
	if ((b & _buttons) > 0)
		return true;
	return false;
}
