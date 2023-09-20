#pragma once
#include <string>
#include <iostream>

class Student
{
private:

	std::string group;
	std::string name;
	int gpa;


public:

	const std::string& GetGroup()const;
	void SetGroup(const std::string group);


	const std::string& GetName()const;
	void SetName(const std::string name);


	int GetGPA()const;
	void SetGPA(const int gpa);



	Student(std::string group = "", std::string name = "", int gpa = 0);



	Student& operator=(const Student& stud);


	friend std::istream& operator >> (std::istream& is, Student& student);

	friend std::ostream& operator << (std::ostream& os, const Student& student);

};

