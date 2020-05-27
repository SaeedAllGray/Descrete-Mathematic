#include <iostream>
#include <string>
#include<vector>
using namespace std;
class Contradition1 {};
class Propositions
{
public:
	Propositions(bool v):value(v){}
	Propositions():value(-1){}
	int GetValue() const { return value; }
	Propositions operator~();
	Propositions operator&(Propositions p);
	Propositions operator||(Propositions p);
	Propositions operator>(Propositions p); //-->	
	Propositions operator<=(Propositions p); //<=>
	Propositions operator=(bool assignValue);
	
	void Not(Propositions &q);
	void And(Propositions &p,Propositions &q);
	void Or(Propositions &p,Propositions &q);
	void Thus(Propositions &p,Propositions &q);
	void IfAndOnlyIf(Propositions &p,Propositions &q);
	
	friend ostream& operator<<(ostream &out,const Propositions &p);
	friend istream& operator>>(istream &in, Propositions &p);
private:
	int value;
};
Propositions Propositions::operator~()
{
	Propositions q;
	if(value==1)
		q.value=0;
	else if(value==0)
		q.value=1;
	return q;
}
Propositions Propositions::operator&(Propositions p)
{
	Propositions q;
	if(value==1 && p.value==1)
		q.value=1;
	else if(value==-1 || p.value==-1)
	return q;
	else
		q.value=0;
	return q;
}
Propositions Propositions::operator||(Propositions p)
{
	Propositions q;
	if(value==1 || p.value==1)
		q.value=1;
	else 
		q.value=0;
	return q;
}
Propositions Propositions::operator>(Propositions p)
{
	Propositions q;
	if(value==p.value)
		q.value=1;
	else if(value==0 && p.value==1)
		q.value=1;
	else if (p.value==1 && value==0)
		q.value=0;
	return q;
}
Propositions Propositions::operator<=(Propositions p)
{
	Propositions q;
	if(p.value==value)
		q.value=1;
	else 
		q.value=0;
	return q;
}
Propositions Propositions::operator=(bool assignValue)
{
	if(assignValue==1 && value!=0)
		value=1;
	else if(assignValue==0 && value!=1)
		value=0;
	else if((assignValue==0 && value==1)||(assignValue==1 && value==0))
		value=2;
	return *this;
}
ostream& operator<<(ostream &out,const Propositions &p)
{
	if(p.value==1)
		out<<"True \n";
	else if(p.value==0)
		out<<"False \n";
	else if(p.value==-1)
		out<<"Not Enough Information!\n";
	else if(p.value==2)
		out<<"Contradition occured.\n";
	return out;
}
istream& operator>>(istream &in, Propositions &p)
{
	in>>p.value;
	return in;
}
void Propositions::Not(Propositions &q)
{
	if(value==1)
		q=0;
	else if(value==0)
		q=1;
}
void Propositions::And(Propositions &p,Propositions &q)
{
	if(value==1)
	{
		p=1;
		q=1;
	}
	else if(value==0)
	{
		if(p.value==1)
			q=0;
		else if(q.value==1)
			p=0;
	}
}
void Propositions::Or(Propositions &p,Propositions &q)
{
	
	if(value==1)
	{
		if(p.value==0)
			q=1;
		else if(q.value==0)
			p=1;
	}
	else if(value==0)
	{
		p=0;
		q=0;
	}
}
void Propositions::Thus(Propositions &p,Propositions &q)
{
	if(value==1)
	{
		q.value=1;
	}
	else if(value==0)
	{
		q=0;
		p=1;
	}
}
void Propositions::IfAndOnlyIf(Propositions &p,Propositions &q)
{
	if(value==1)
	{
		if(p.value==0 || q.value==0)
		{
			p=0;
			q=0;
		}
		else if(p.value==1 || q.value==1)
		{
			p=1;
			q=1;
		}
	}
}
int main()
{
	Propositions A(1), B(1), C(1),D(1);
	Propositions p, q, r, s;
	A.Thus(r, s);
	B.Thus(p, r);
	D.Not(q);
	C.And(p, D);
	cout << (~s);
	cout<<"\nAutorized by Saeed All Ghararee. \nAll Rights Reserved. 2019";
	cout<<"\nt.me/SaeedAG";
}

/*
r-->s
p-->r
p^~q
______
:: ~s
*/


