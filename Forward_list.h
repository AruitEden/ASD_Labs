#pragma once
#include <iostream>







template <class T>
class Forward_list
{

protected:

	template<class T>
	class Node
	{

	private:

		T* const m_data;
		Node<T>* m_next;


	public:

		Node(Node<T>* next, const T& data) :
			m_next(next), m_data(new T(data)) {}



		~Node()
		{
			delete m_data;
		}



		bool HasNext() const {
			return m_next != nullptr ? true : false;
		}

		Node<T>* GetNext() {
			return m_next;
		}

		Node<T> const* GetNext() const {
			return m_next;
		}

		void SetNext(Node<T>* next) {
			m_next = next;
		}

		T& GetData() {
			return *m_data;
		}

		const T& GetData() const {
			return *m_data;
		}

	};
	




};



#include "Forward_list.inl"

