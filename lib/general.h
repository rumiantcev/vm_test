/*
* Copyright (c) 2001-2017, Alexey Rumyantsev.
* e-mail: rumiantcev@yandex.ru
* All rights reserved.
*
*/
// ---------------------------------------------------------------------------
#ifndef general_H
#define general_H

#include <string>
#include <sstream>
#include <map>
#include <list>
#include <vector>
#include <math.h>
#include <assert.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <locale.h>
#include <windows.h>
#include<time.h>
#include <io.h>
#include<iterator>
#include <stdlib>
#include <sstream>
#include <algorithm>
//#include <system.hpp>

class Vector;

typedef double LDouble;
const std::string states[4] = {
	"����� ������", "���� ����������", "�������", "������ �����������"};

typedef enum OpType {
	opMin = 0, opMax = 1, opZero = 2
} OpType;

typedef enum ZeroAware {
	nZAware = false, ZAware = true
} ZeroAware;

typedef enum FindBase {
	nFind = false, yFind = true
} FindBase;

typedef enum FindPath {
	nPath = false, yPath = true
} FindPath;

typedef enum optSearch {
	optNone = 0, optAnnealing = 1, optGradient = 2, optTimS = 3
} optSearch;

typedef std::vector<LDouble>alphType;
typedef alphType::value_type aplhVal;
typedef std::map<long, bool>seekType;
typedef std::list<long>pathType;
typedef std::vector<long>VecOfLong;
typedef std::vector<unsigned long>VecOfUL;
typedef std::vector<std::string>VecOfStr;
//typedef std::map<std::string,std::string>MapOfStr;
//typedef std::map<std::string,LDouble>MapOfLD;
typedef std::vector<LDouble>VecOfLD;
typedef std::vector<bool>VecOfBool;
typedef std::vector<Vector*>VecOfVec;


//��������� ���� �������� a
inline int signof(LDouble a) { return (a == 0.0) ? 0 : (a<0 ? -1 : 1); }

inline bool isOdd(long a) { return (a%2 == 0.0) ? true : false; }

// ------------------------------constructor ----------------------------------//
inline unsigned long __fastcall factorial( unsigned long i){
	while (i == 0)
		i *= (i-1);
	return i;
}

//������� ������ � �������� ��������
struct DeleteObj {
	template<typename T>
	void operator()(const T* ptr) const {
		if (ptr != NULL)
			delete ptr;
	}
};

//---- �������������� � std::string
 inline std::string intToStr(int i){
	std::string str;
	std::stringstream oss;
	oss << i;
	oss >> str;
	return str;
}

 inline std::string ldToStr(LDouble ld){
	std::string str;
	std::stringstream oss;
	oss << ld;
	oss >> str;
	return str;
}


#endif
