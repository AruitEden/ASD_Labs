#pragma once
#include <iostream>
#include <string>
class Warrior
{
private:
	std::string name;
	int power;

public:
	const std::string& getName()const;
	void setName(const std::string name);


	int getPower()const;
	void setPower(const int power);



	Warrior(std::string name = "", int power = 0);



	friend std::ostream& operator << (std::ostream& out, const Warrior &warrior);
	friend std::istream& operator >> (std::istream& in, Warrior& warrior);


	friend bool operator == (const Warrior& warrior1, const Warrior& warrior2);
	friend bool operator != (const Warrior& warrior1, const Warrior& warrior2);


	friend bool operator > (const Warrior& warrior1, const Warrior& warrior2);
	friend bool operator >= (const Warrior& warrior1, const Warrior& warrior2);

	friend bool operator < (const Warrior& warrior1, const Warrior& warrior2);
	friend bool operator <= (const Warrior& warrior1, const Warrior& warrior2);
};

