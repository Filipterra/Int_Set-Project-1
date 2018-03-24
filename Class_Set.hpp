/*
 * Class_Set.hpp
 *
 *  Created on: Mar 11, 2018
 *      Author: Filip
 */

#ifndef CLASS_SET_HPP_
#define CLASS_SET_HPP_

#define MAX_INT_VAL 100

class Set {
public:
#ifndef DEBUGG
    int *Elements;
    char *Name;
#endif
	Set (const char*);
    Set (const Set&);
	Set (int, ...);
	//Set (Set&& S);
	~Set ();
	Set operator+ (const Set&) const;
	Set operator+ (int) const;
	Set& operator+= (const Set&);
	Set operator+= (int);
	Set operator- (const Set&) const;
	Set operator- (int) const;
	Set& operator-= (const Set&);
	Set operator-= (int);
	Set operator* (const Set&) const;
	Set& operator*= (const Set&);
	Set& operator= (const Set&);
	//Set& operator= (Set&&);
	bool operator== (const Set&) const;
	friend std::ostream& operator<< (std::ostream&, const Set&);
};



#endif /* CLASS_SET_HPP_ */

