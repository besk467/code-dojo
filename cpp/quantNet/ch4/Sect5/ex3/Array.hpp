#ifndef ARRAY_HPP
#define ARRAY_HPP
#include "Point.hpp"
class Array{

	private:
		Point * m_data;
		int m_length;
	public:
		//constructors and destructors. 
		Array();
		Array(int size_);
		Array(const Array& source_);
		~Array();
		
		// accessor methods. 
		//Point point(int pos_) const;
		int Size() const;
		Point * arr() const;
		Point GetElement(int index_) const;	
		// operator overloads
		Array& operator=(const Array& source_);
		const Point& operator[](int index_);

		// setters
		void SetElement(int index_, Point * target_);
};
#endif