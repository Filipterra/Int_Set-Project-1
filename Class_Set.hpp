/*
 * Class_Set.hpp
 *
 *  Created on: Mar 11, 2018
 *      Author: Filip
 */

#ifndef CLASS_SET_HPP_
#define CLASS_SET_HPP_

#define MAX_INT_VAL 100
#include <iostream>


class Set {
    int *Elements;
    char *Name;
public:
	Set (const char*);
    Set (const Set&);
	Set (int, ...);
	//dorobić operatory na R-referencje
	~Set ();
	Set operator+ (const Set&) const;
	Set operator+ (int) const;
	Set& operator+= (const Set&);
	Set operator- (const Set&) const;
	Set operator- (int) const;
	Set& operator-= (const Set&);
	Set operator* (const Set&) const;
	Set& operator*= (const Set&);
	Set& operator= (const Set&);
	friend std::ostream& operator<< (std::ostream&, const Set&);
};



#endif /* CLASS_SET_HPP_ */

