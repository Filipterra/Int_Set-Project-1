/*
 * Class_Set.hpp
 *
 *  Created on: Mar 11, 2018
 *      Author: Filip Przybysz
 */

#ifndef CLASS_SET_HPP_
#define CLASS_SET_HPP_

#define MAX_INT_VAL 100

class Set {
    int *Elements;
    char *Name;
public:
	Set (const char*);
    Set (const Set&);
	Set (int, ...);
	Set (Set&& S);
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
	Set& operator= (Set&&);
	bool operator== (const Set&) const;
	friend std::ostream& operator<< (std::ostream&, const Set&);

	#ifdef DEBUG
	friend bool Test0();
	friend bool Test1();
	friend bool Test2();
	friend bool Test3();
	friend bool Test4();
	friend bool Test5();
	friend bool Test6();
	friend bool Test7();
	friend bool Test8();
	friend bool Test9();
	friend bool Test10();
	#else
	friend char* Ret_name(const Set&);
	#endif
};



#endif /* CLASS_SET_HPP_ */

