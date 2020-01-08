#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int Common_denominator(int&_num, const int& _denum, int& _num1, const int& _denum1, const int& maxim);
int Greatest_common_factor(const int& _sum, const int& _maxim);
void Common_factor(vector<int>&vec,const int&value);
class Calculator
{
    int num = 0;
    int denum = 0;
	int num1 = 0;
	int denum1 = 0;
	char oper='0';
	char div='0';

public:
	Calculator()
	{}
	void Fill()
	{
  		   cin >> num >> div >> denum >> oper >> num1 >> div >> denum1;
			cin.ignore();
			if (denum == 0 || denum1 == 0)
			{
				throw runtime_error("division by ZERO in fraction\n");
			}
			
			Rezult(num, denum, num1, denum1, oper);
	}
	void Rezult(int& _num, const int& _denum, int& _num1, const int& _denum1,const char& _oper)
	{
		switch (_oper)
		{
		case '+':
           Addition(_num, _denum, _num1, _denum1);
		   break;
		case'-':
			Subtraction(_num, _denum, _num1, _denum1);
			break;
		case'*':
			Multiplication(_num, _denum, _num1, _denum1);
			break;
		case'/':
			Division(_num, _denum, _num1, _denum1);
		}
		
	}
	void Addition(int& _num, const int& _denum, int& _num1, const int& _denum1)
	{
		if (_num == 0)
		{
			cout << _num1 << div << _denum1;
			return;
		}
		if(_num1==0)
		{
			cout<< _num << div << _denum;
			return;
		}
		int sum =0;
		int maxim = max(_denum, _denum1);
		int common_denominator= Common_denominator(_num, _denum, _num1, _denum1, maxim);
        sum =_num + _num1;
		
		if (sum == common_denominator)
		{
			cout << sum / common_denominator <<endl;
		}
		else
		{
			int rez = Greatest_common_factor(sum, common_denominator);
			Show(sum, common_denominator, rez);
		}
    }
	void Subtraction(int& _num, const int& _denum, int& _num1, const int& _denum1)
	{
		if (_num == 0)
		{
			
			cout <<'-'<< _num1 << div << _denum1;
			return;
		}
		if(_num1==0)
		{
			cout << _num << div << _denum;
			return;
		}
		int sum = 0;
		int maxim = max(_denum, _denum1);
		int common_denominator = Common_denominator(_num, _denum, _num1, _denum1, maxim);
		sum = _num - _num1;
		if (sum == 0)
		{
			cout << 0 << endl;
			return;
		}
		if (sum == common_denominator)
		{
			cout << sum / common_denominator << endl;
		}
		else
		{
			int rez = Greatest_common_factor(sum, common_denominator);
			Show(sum, common_denominator, rez);
		}
	}
	void Multiplication(int& _num, const int& _denum, int& _num1, const int& _denum1)
	{
		if (_num == 0 || _num1 == 0)
		{
			cout << 0 << endl;
			return;
		}
		int com_num = _num * _num1;
		int com_denum = _denum * _denum1;
		int rez= Greatest_common_factor(com_num, com_denum);
		Show(com_num, com_denum, rez);
	}
	void Division(int& _num, const int& _denum, int& _num1, const int& _denum1)
	{
		if (_num == 0)
		{
			cout << 0 << endl;
			return;
		}
		if (_num1 == 0)
		{
			throw runtime_error("division by ZERO in the equation\n");
		}
		int com_num = _num * _denum1;
		int com_denum = _denum * _num1;
		int rez = Greatest_common_factor(com_num, com_denum);
		Show(com_num, com_denum, rez);
	}
	void Show(const int& com_num, const int& com_denum, const int& rez)const
	{
		if ((com_num / rez) == (com_denum / rez))
		{
			
			cout << com_num / rez<<endl;
			return;
		}
		if ((com_denum / rez) == 1)
			{
				cout << com_num / rez<<endl;
				return;
			}
		cout << com_num / rez << div << com_denum / rez << endl;
	}
};
int main()
{
	bool finish = false;
	while (cin)
	{
		Calculator calc;
		try
		{
			calc.Fill();
		}
		catch (runtime_error&er)
		{
			cout << er.what();
		}
	}
	
   system("pause");
   return 0;
}
int Common_denominator(int &_num, const int& _denum, int &_num1, const int& _denum1, const int& maxim)
{

	int q = 100000;
	int rez = 1;
	for (int i = 2; i < q; ++i)
	{

		if (rez%_denum != 0 || rez % _denum1 != 0)
		{
			rez=maxim * i;
		}
		else
		{
			break;
		}
	}
	_num *= (rez/ _denum);
	_num1 *= (rez / _denum1);
	
	return rez;
}
int Greatest_common_factor(const int& _sum,const int& _maxim)
{
	vector<int>vec_sum;
	vector<int>vec_maxim;
	vector<int>vec_equal;
	Common_factor(vec_sum, _sum);
	Common_factor(vec_maxim, _maxim);
	for_each(vec_sum.begin(), vec_sum.end(), [&vec_equal,&vec_maxim](int value) {
		auto rez=find(vec_maxim.begin(), vec_maxim.end(), value);
		if(rez!=vec_maxim.end())
		{ 
			vec_equal.push_back(*rez);
		}
		
	});
	auto greatest = max_element(vec_equal.begin(),vec_equal.end());
	return *greatest;
}
void Common_factor(vector<int>&vec, const int& value)
{
	for (int i = 1; i <= value; ++i)
	{
		if (value%i == 0)
		{
			vec.push_back(i);
		}
	}

}