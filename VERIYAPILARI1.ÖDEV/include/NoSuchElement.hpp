#ifndef NoSuchElement_hpp
#define NoSuchElement_hpp

#include "Exception.hpp"

class NoSuchElement : public Exception{
	public:
		NoSuchElement(const string &msg):Exception(msg) { }
};
#endif