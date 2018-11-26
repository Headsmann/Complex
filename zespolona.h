
#include <iostream>

using namespace std;

template <class T>
class Zespolona {
private:
	//Zmienne prywatne
	T reNum;
	T imNum;
public:
	//Deklaracja konstruktorów
	Zespolona();
	Zespolona(T re);
	Zespolona(T re, T im);

	//Deklaracja operatorów
	Zespolona<T> operator+(const Zespolona<T>&)const;
	Zespolona<T> operator-(const Zespolona<T>&)const;
	Zespolona<T> operator*(const Zespolona<T>&)const;
	Zespolona<T> operator/(const Zespolona<T>&)const;
	Zespolona<T> operator+=(const Zespolona<T>&);
	Zespolona<T> operator-=(const Zespolona<T>&);
	Zespolona<T> operator*=(const Zespolona<T>&);
	Zespolona<T> operator/=(const Zespolona<T>&);
	Zespolona<T> operator=(const Zespolona<T>&);
	bool operator==(const Zespolona&) const;
	template <class U>
	friend ostream& operator<<(ostream&, const Zespolona<U>&);


};

//Konstruktor bez argumetów
template<class T>
Zespolona<T>::Zespolona()
{
	reNum = 0.0;
	imNum = 0.0;
}
//Konstruktor z jednym argumentem
template<class T>
Zespolona<T>::Zespolona(const T re)
{
	reNum = re;
	imNum = 0.0;
}


//Konstruktor z dwoma argumentami
template<class T>
Zespolona<T>::Zespolona(const T re, const T im)
{
	reNum = re;
	imNum = im;
}

//DODAWANIE
template<class T>
Zespolona<T> Zespolona<T>::operator +(const Zespolona<T>& obj) const
{
	Zespolona<T> temp;
	temp.reNum = reNum + obj.reNum;
	temp.imNum = imNum + obj.imNum;
	return temp;
}
//ODEJMOWANIE
template<class T>
Zespolona<T> Zespolona<T>::operator -(const Zespolona<T>& obj) const
{
	Zespolona<T> temp;
	temp.reNum = reNum - obj.reNum;
	temp.imNum = imNum - obj.imNum;
	return temp;
}
//MNOZENIE
template<class T>
Zespolona<T> Zespolona<T>::operator *(const Zespolona<T>& obj) const
{
	Zespolona<T> temp;
	temp.reNum = (reNum * obj.reNum) - (imNum * obj.imNum);
	temp.imNum = (reNum * obj.imNum) + (imNum * obj.reNum);
	return temp;
}
//DZIELENIE
template<class T>
Zespolona<T> Zespolona<T>::operator /(const Zespolona<T>& obj) const
{
	Zespolona<T> temp;
	temp.reNum = ((reNum * obj.reNum) + (imNum * obj.imNum)) / ((pow(obj.reNum, 2.0)) + (pow(obj.imNum, 2.0)));
	temp.imNum = ((obj.reNum * imNum) - (reNum * obj.imNum)) / ((pow(obj.reNum, 2.0)) + (pow(obj.imNum, 2.0)));
	return temp;
}
//OPERATOR PORÓWNANIA
template <class T>
bool Zespolona<T>::operator ==(const Zespolona& obj) const
{
	return (reNum == obj.reNum && imNum == obj.imNum);
}
//OPERATOR =
template <class T>
Zespolona<T> Zespolona<T>::operator=(const Zespolona& obj)
{
	if (this != &obj)
	{
		reNum = obj.reNum;
		imNum = obj.imNum;
	}

	return  *this;
}
//OPERATOR +=
template<class T>
Zespolona<T> Zespolona<T>::operator +=(const Zespolona<T>& obj)
{
	reNum += obj.reNum;
	imNum += obj.imNum;

	return *this;
}
//OPERATOR -=
template<class T>
Zespolona<T> Zespolona<T>::operator -=(const Zespolona<T>& obj)
{
	reNum -= obj.reNum;
	imNum -= obj.imNum;
	return *this;
}
//OPERATOR *=
template<class T>
Zespolona<T> Zespolona<T>::operator *=(const Zespolona<T>& obj)
{

	reNum = (reNum * obj.reNum) - (reNum * obj.imNum);
	imNum = (imNum * obj.reNum) + (imNum * obj.imNum);
	return *this;
}
//OPERATOR /=
template<class T>
Zespolona<T> Zespolona<T>::operator /=(const Zespolona<T>& obj)
{
	T temp;
	temp = reNum;
	reNum = ((reNum * obj.reNum) + (imNum * obj.imNum)) / ((pow(obj.reNum, 2.0)) + (pow(obj.imNum, 2.0)));
	imNum = ((obj.reNum * imNum) - (temp * obj.imNum)) / ((pow(obj.reNum, 2.0)) + (pow(obj.imNum, 2.0)));
	return *this;
}
//OPERATOR WEJSCIA
template<class T>
ostream& operator<<(ostream& out, const Zespolona<T>& zesp)
{
	out << zesp.reNum;
	out << "+";
	out << zesp.imNum;
	out << "i";
	return out;
}