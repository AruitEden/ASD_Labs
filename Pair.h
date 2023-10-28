#pragma once



template <class T1, class T2>
struct Pair
{

	T1 first;
	T2 second;


	Pair() : first(), second() {}

	Pair(const T1 first, const T2 second) : first(first), second(second) {}

};