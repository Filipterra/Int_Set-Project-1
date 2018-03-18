/*
 * Class_Set.hpp
 *
 *  Created on: Mar 11, 2018
 *      Author: filip
 */

#ifndef CLASS_SET_HPP_
#define CLASS_SET_HPP_

#include <iostream>
#include <vector>

class Set {
	std::vector<int> Elements;
	std::string Name;
public:
	Set (std::string);
	Set (std::vector<int>);
	Set (int);
	~Set ();
	Set operator+ (const Set&) const;
	Set& operator+= (const Set&);
	Set operator- (const Set&) const;
	Set& operator-= (const Set&);
	Set operator* (const Set&) const;
	Set& operator*= (const Set&);
	Set& operator= (const Set&);
	friend std::ostream& operator<< (std::ostream&, const Set&);
};



#endif /* CLASS_SET_HPP_ */

