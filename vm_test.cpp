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
	// устанавливаем локаль русского языка так, чтобы десятичным разделителем была точка, а не запятая
	setlocale(LC_ALL, "Russian.1572");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Vector X(2), Y(2), Z(2); //три вектора из R^2
	LDouble a = 2.0; // коэфф. для проверки умножения на скаляр

	X.one(); //единичный вектор [1,1]
	Y.zero();// создаём нулевой вектор [0,0]
	cout<<"Вектор X: "<<X<<" Счётчик ссылок X: "<<X.v->linkCount<<" Адрес массива: "<<X.v<<endl;
	cout<<"Вектор Y: "<<Y<<" Счётчик ссылок Y: "<<Y.v->linkCount<<" Адрес массива: "<<Y.v<<endl;

	Y=X;// теперь приравниваем X и Y
	cout<<"Вектор X: "<<X<<" Счётчик ссылок X: "<<X.v->linkCount<<" Адрес массива: "<<X.v<<endl;
	cout<<"Вектор Y: "<<Y<<" Счётчик ссылок Y: "<<Y.v->linkCount<<" Адрес массива: "<<Y.v<<endl;

	X*=a;  //домножаем вектор на коэффициент 2.0
	cout<<"Вектор X: "<<X<<" Счётчик ссылок X: "<<X.v->linkCount<<" Адрес массива: "<<X.v<<" Коэфф. a вектора X: "<<X.upd<<endl;
	cout<<"Вектор Y: "<<Y<<" Счётчик ссылок Y: "<<Y.v->linkCount<<" Адрес массива: "<<Y.v<<" Коэфф. a вектора Y: "<<Y.upd<<endl;

	Z= X+Y;
	cout<<"Вектор Z: "<<Z<<" Счётчик ссылок Z: "<<Z.v->linkCount<<" Адрес массива: "<<Z.v<<" Коэфф. a вектора Z: "<<Z.upd<<endl;

	Matrix X_(2), Y_(2), Z_(2); //создаём 3 единичных диагональных матрицы 2x2

	cout<<"Матрица X: "<<endl<<X_<<" Счётчик ссылок X: "<<X_.v->linkCount<<" Адрес массива: "<<X_.v<<endl;
	cout<<"Матрица Y: "<<endl<<Y_<<" Счётчик ссылок Y: "<<Y_.v->linkCount<<" Адрес массива: "<<Y_.v<<endl;

	Y_=X_;// теперь приравниваем X_ и Y_
	cout<<"Матрица X: "<<endl<<X_<<" Счётчик ссылок X: "<<X_.v->linkCount<<" Адрес массива: "<<X_.v<<endl;
	cout<<"Матрица Y: "<<endl<<Y_<<" Счётчик ссылок Y: "<<Y_.v->linkCount<<" Адрес массива: "<<Y_.v<<endl;

	X_*=a;  //домножаем матрицу на коэффициент 2.0
	cout<<"Матрица X: "<<endl<<X_<<" Счётчик ссылок X: "<<X_.v->linkCount<<" Адрес массива: "<<X_.v<<" Коэфф. a матрицы X: "<<X_.upd<<endl;

	Z_= X_+Y_;
	cout<<"Матрица Z: "<<endl<<Z_<<" Счётчик ссылок Z: "<<Z_.v->linkCount<<" Адрес массива: "<<Z_.v<<" Коэфф. a матрицы Z: "<<Z_.upd<<endl;

	return 0;
}
