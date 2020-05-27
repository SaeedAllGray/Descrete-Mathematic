#include <iostream>
#include<vector>
using namespace std;
void ValueInput(vector<vector<int> > &matrix)
{
	for (int i=0;i<matrix.size();i++)
		for (int j=0;j<matrix.size();j++)
			cin>>matrix[i][j];	
}
vector<vector<int> > Transive(vector<vector<int> > matrix)
{
	int c=0;
	do{
		for (int j=0;j<matrix.size();j++)
			for (int k=0;k<matrix.size();k++)
				for (int l=0;l<matrix.size();l++)
					matrix[j][k] |= matrix[j][l] && matrix[l][k];
		c++;
	} while (c<matrix.size());
	return matrix;
}
vector<vector<int> > Symmetric(vector<vector<int> > matrix)
{
	
	for (int i=0;i<matrix.size();i++)
		for (int j=0;j<matrix.size();j++)
			if(matrix[i][j]==true)
				matrix[j][i]=true;
	return matrix;
}
vector<vector<int> > Reflective(vector<vector<int> > matrix)
{
	for (int i=0;i<matrix.size();i++)
		for (int j=0;j<matrix.size();j++)
			if(i==j)
				matrix[j][i]=true;		
	return matrix;
}
void PrintMatrix(vector<vector<int> > matrix)
{
	for (int i=0;i<matrix.size();i++)
	{
		cout<<"|";
		for (int j=0;j<matrix.size();j++)
		{
			cout<<matrix[i][j]<<' ';
		}
		cout<<"\b|"<<endl;
	}
}
int main() 
{
	cout<<"Enter the size of matrix: ";
	int size;
	cin>>size;
	vector<vector<int> > matrix(size,vector<int>(size));
	cout<<"Enter elements \n";
	ValueInput(matrix);
	cout<<"Reflective closure:\n";
	PrintMatrix(Reflective(matrix));
	cout<<"Symmetric closure:\n";
	PrintMatrix(Symmetric(matrix));
	cout<<"Transive closure:\n";
	PrintMatrix(Transive(matrix));
	
	
	cout<<"\nAutorized by Saeed All Ghararee. \nAll Rights Reserved. 2019";
	cout<<"\nt.me/SaeedAG";
}
