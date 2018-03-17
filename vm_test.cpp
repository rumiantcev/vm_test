#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include "lib/general.h"
#include "lib/vector.h"
#include "lib/matrix.h"


using namespace ::std;


#include <stdio.h>

int _tmain(int argc, _TCHAR* argv[])
{
	// ������������� ������ �������� ����� ���, ����� ���������� ������������ ���� �����, � �� �������
	setlocale(LC_ALL, "Russian.1572");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Vector X(2), Y(2), Z(2); //��� ������� �� R^2
	LDouble a = 2.0; // �����. ��� �������� ��������� �� ������

	X.one(); //��������� ������ [1,1]
	Y.zero();// ������ ������� ������ [0,0]
	cout<<"������ X: "<<X<<" ������� ������ X: "<<X.v->linkCount<<" ����� �������: "<<X.v<<endl;
	cout<<"������ Y: "<<Y<<" ������� ������ Y: "<<Y.v->linkCount<<" ����� �������: "<<Y.v<<endl;

	Y=X;// ������ ������������ X � Y
	cout<<"������ X: "<<X<<" ������� ������ X: "<<X.v->linkCount<<" ����� �������: "<<X.v<<endl;
	cout<<"������ Y: "<<Y<<" ������� ������ Y: "<<Y.v->linkCount<<" ����� �������: "<<Y.v<<endl;

	X*=a;  //��������� ������ �� ����������� 2.0
	cout<<"������ X: "<<X<<" ������� ������ X: "<<X.v->linkCount<<" ����� �������: "<<X.v<<" �����. a ������� X: "<<X.upd<<endl;
	cout<<"������ Y: "<<Y<<" ������� ������ Y: "<<Y.v->linkCount<<" ����� �������: "<<Y.v<<" �����. a ������� Y: "<<Y.upd<<endl;

	Z= X+Y;
	cout<<"������ Z: "<<Z<<" ������� ������ Z: "<<Z.v->linkCount<<" ����� �������: "<<Z.v<<" �����. a ������� Z: "<<Z.upd<<endl;

	Matrix X_(2), Y_(2), Z_(2); //������ 3 ��������� ������������ ������� 2x2

	cout<<"������� X: "<<endl<<X_<<" ������� ������ X: "<<X_.v->linkCount<<" ����� �������: "<<X_.v<<endl;
	cout<<"������� Y: "<<endl<<Y_<<" ������� ������ Y: "<<Y_.v->linkCount<<" ����� �������: "<<Y_.v<<endl;

	Y_=X_;// ������ ������������ X_ � Y_
	cout<<"������� X: "<<endl<<X_<<" ������� ������ X: "<<X_.v->linkCount<<" ����� �������: "<<X_.v<<endl;
	cout<<"������� Y: "<<endl<<Y_<<" ������� ������ Y: "<<Y_.v->linkCount<<" ����� �������: "<<Y_.v<<endl;

	X_*=a;  //��������� ������� �� ����������� 2.0
	cout<<"������� X: "<<endl<<X_<<" ������� ������ X: "<<X_.v->linkCount<<" ����� �������: "<<X_.v<<" �����. a ������� X: "<<X_.upd<<endl;

	Z_= X_+Y_;
	cout<<"������� Z: "<<endl<<Z_<<" ������� ������ Z: "<<Z_.v->linkCount<<" ����� �������: "<<Z_.v<<" �����. a ������� Z: "<<Z_.upd<<endl;

	return 0;
}
