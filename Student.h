#pragma once
#include <string>

class Student
{
private:

	std::string group;
	std::string name;
	int gpa;


public:

	std::string GetGroup();
	void SetGroup(std::string group);


	std::string GetName();
	void SetName(std::string name);


	int GetGPA();
	void SetGPA(int gpa);



	Student();
	Student(std::string group, std::string name, int gpa);
};

