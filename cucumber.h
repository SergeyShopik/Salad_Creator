#pragma once
#include"mainHeader.h"

class Cucumber: public Base
{
public:
	Cucumber() = default;
	~Cucumber() override = default;

	std::istream& read(std::istream& in) override
	{
		Base::read(in);
		in >> age >> fresh;
		return in;
	}
	std::ostream& print(std::ostream& out) const override
	{
		Base::print(out);
		out << " Origin: " << age << " Fresh: " << fresh;
		return out;
	}

private:
	string age;
	bool fresh;
};