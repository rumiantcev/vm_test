/*
* Copyright (c) 2001-2017, Alexey Rumyantsev.
* e-mail: rumiantcev@yandex.ru
* All rights reserved.
*
*/
// ---------------------------------------------------------------------------
#ifndef sMxH
#define sMxH
#pragma once

#include <iostream>
#include "general.h"

/**
 * ------------------------------- sMx -------------------------------------
 */
 //����� ����� ��� ����, ����� ����� ���� ������, ��� ����������� �������, ���������� ������������ ����� �� ��������
 //���������� ��������� ����������� ������� ������ (�����������, ����� auto_ptr ��� �� ���� � �������)
class sMx {
public:
	unsigned long m, n;
	LDouble **v, *vv;
	long linkCount;

	__fastcall sMx(unsigned long, unsigned long);
	explicit __fastcall sMx(unsigned long);
	__fastcall sMx(sMx&);
   //	__fastcall sMx(LDouble **vv, long mm, long nn);
	virtual __fastcall ~sMx();
	void operator delete(void *p);
	/* !inline */ void __fastcall create();

};
// ---------------------------------------------------------------------------
#endif
