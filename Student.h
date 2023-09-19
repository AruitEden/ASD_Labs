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

	std::string GetGroup();
	void SetGroup(std::string group);


	std::string GetName();
	void SetName(std::string name);


	int GetGPA();
	void SetGPA(int gpa);



	Student();
	Student(std::string group, std::string name, int gpa);



	Student& operator=(const Student& stud);


	friend std::istream& operator >> (std::istream& is, Student& student);

	friend std::ostream& operator << (std::ostream& os, const Student& student);

};

