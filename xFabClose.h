#pragma once

#include <Spore\BasicIncludes.h>

#define xFabClosePtr intrusive_ptr<xFabClose>

// To avoid repeating UTFWin:: all the time.
using namespace UTFWin;

class xFabClose 
	: public IWinProc
	, public DefaultRefCounted
{
public:
	static const uint32_t TYPE = id("xFabClose");
	
	xFabClose();
	~xFabClose();

	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
	
	int GetEventFlags() const override;
	// This is the function you have to implement, called when a window you added this winproc to received an event
	bool HandleUIMessage(IWindow* pWindow, const Message& message) override;
	
private:
};