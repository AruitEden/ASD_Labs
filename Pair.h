#pragma once



template <class T1, class T2>
struct Pair
{

	T1 first;
	T2 second;


	Pair() : first(), second() {}

	Pair(const T1& first, const T2& second) : first(first), second(second) {}

};



template <class T1, class T2>
inline bool operator==(const Pair<T1, T2>& p1, const Pair<T1, T2>& p2)
{
	return p1.first == p2.first && p1.second == p2.second;
}

template <class T1, class T2>
inline bool operator!=(const Pair<T1, T2>& p1, const Pair<T1, T2>& p2)
{
	return !(p1 == p2);
}

template <class T1, class T2>
inline bool operator>(const Pair<T1, T2>& p1, const Pair<T1, T2>& p2)
{
	if(p1.first > p2.first)
	{
		return true;
	}
	else if(p2.first > p1.first)
	{
		return false;
	}
	else if(p1.second > p2.second)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T1, class T2>
inline bool operator<(const Pair<T1, T2>& p1, const Pair<T1, T2>& p2)
{
	return !(p1 > p2);
}

template <class T1, class T2>
inline bool operator>=(const Pair<T1, T2>& p1, const Pair<T1, T2>& p2)
{
	return !(p1 > p2);
}

template <class T1, class T2>
inline bool operator<=(const Pair<T1, T2>& p1, const Pair<T1, T2>& p2)
{
	return !(p1 < p2);
}