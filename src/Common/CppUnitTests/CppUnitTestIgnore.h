#pragma once

#define CPPUNIT_IGNORE(condition) \
	if (condition) \
	{ \
		CPPUNIT_NS::Message("test ignored", "Expression: " #condition); \
		return; \
	}
