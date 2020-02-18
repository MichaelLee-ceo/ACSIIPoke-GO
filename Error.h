#ifndef ERROR_H
#define ERROR_H
#include <stdexcept>
using std::runtime_error;

class WrongInput : public runtime_error
{
public:
	WrongInput::WrongInput()					//exception
		:runtime_error("Invalid input") {}
};

#endif
