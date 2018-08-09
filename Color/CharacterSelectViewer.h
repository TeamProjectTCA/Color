#pragma once
#include "smart_ptr.h"

PTR( CharacterSelectProcessor );

class CharacterSelectViewer  {
public:
	CharacterSelectViewer( CharacterSelectProcessorConstPtr processor );
	virtual ~CharacterSelectViewer( );

public:
	void update( );

private:
	CharacterSelectProcessorConstPtr _processor;
};