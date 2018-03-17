/*
* Copyright (c) 2001-2017, Alexey Rumyantsev.
* e-mail: rumiantcev@yandex.ru
* All rights reserved.
*
*/
// ---------------------------------------------------------------------------
#ifndef sVecH
#define sVecH
#pragma once

 #include "general.h"
/* �������� �������� ������� � ������������ ����� ���������� ��� ������ */
//����� ����� ��� ����, ����� ����� ���� ������, ��� ����������� �������, ���������� ������������ ����� �� ��������
 //���������� ��������� ����������� ������� ������ (�����������, ����� auto_ptr ��� �� ���� � �������)
/**
 * -----------------------------------SimpleVec--------------------------------
 */
class sVec {
public:
	unsigned long size;
	
	LDouble *v;
	long linkCount;

	explicit __fastcall sVec(unsigned long);
	__fastcall sVec(const LDouble *vv, unsigned long sz);
	virtual __fastcall ~sVec();
	void operator delete(void* p);

private:
	void __fastcall create();
	sVec(const sVec&);
};
// ---------------------------------------------------------------------------
#endif
