/*
MIT License.
https://forums.wz2100.net
1 December 2018 - Release date
1.0 version


Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include "strpie.h"



strpie::strpie(void){}

strpie::strpie(const char* s)
{
	data = s;
}
strpie::strpie(string tempstr)
{
	data = tempstr;
}
strpie::strpie(int a)
{
	data = to_string(a);
}
strpie::strpie(unsigned int a)
{
	data = to_string(a);
}
strpie::strpie(__int64 a)
{
	data = to_string(a);
}
strpie::strpie(unsigned __int64 a)
{
	data = to_string(a);
}
strpie::strpie(float a)
{
	if (size_fixed == 0)
	{
		data = data + to_string(a);
	}

	stringstream strmem;
	strmem << fixed << setprecision(size_fixed) << a;
	data = data + strmem.str();
}
strpie::strpie(double a)
{
	if (size_fixed == 0)
	{
		data = data + to_string(a);
	}

	stringstream strmem;
	strmem << fixed << setprecision(size_fixed) << a;
	data = data + strmem.str();
}
string& strpie::operator= (string str)
{
	data = str;
	//strpie f;
	return data;
}
bool strpie::operator== (string str)
{	
	int lenA = (int)data.length();
	int lenB = (int)str.length();

	if (lenA == lenB)
	{
		int pos = (int)data.find(str);

		if (pos == -1)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}
string& strpie::operator= (int a)
{
	data = to_string(a);
	return data;
}

string& strpie::operator= (unsigned int a)
{
	data = to_string(a);
	return data;
}
string& strpie::operator= (__int64 a)
{
	data = to_string(a);
	return data;
}
string&  strpie::operator= (unsigned __int64 a)
{
	data = to_string(a);
	return data;
}
string& strpie::operator= (float a)
{
	if (size_fixed == 0)
	{
		data = to_string(a);
	}
	else
	{
		stringstream strmem;
		strmem << fixed << setprecision(size_fixed) << a;
		data = strmem.str();
	}
	return data;
}
string& strpie::operator= (double a)
{
	if (size_fixed == 0)
	{
		data = to_string(a);
	}
	else
	{
		stringstream strmem;
		strmem << fixed << setprecision(size_fixed) << a;
		data = strmem.str();
	}
	return data;
}

string& strpie::operator+ (const char* s)
{
	data = "" + data + string(s);
	return data;
}
string& strpie::operator+(string str)
{
	return data = "" + data + str;
}
string& strpie::operator+(int a)
{
	return data = data + to_string(a);
}
string& strpie::operator+(unsigned int a)
{
	return data = data + to_string(a);
}
string& strpie::operator+(__int64 a)
{
	return data = data + to_string(a);
}
string& strpie::operator+(unsigned __int64 a)
{
	return data = data + to_string(a);
}
string& strpie::operator+(float a)
{
	if (size_fixed == 0)
	{
		return data = data + to_string(a);
	}

	stringstream strmem;
	strmem << fixed << setprecision(size_fixed) << a;
	return data = data + strmem.str();
}
string& strpie::operator+(double a)
{
	if (size_fixed == 0)
	{
		return data = data + to_string(a);
	}

	stringstream strmem;
	strmem << fixed << setprecision(size_fixed) << a;
	return data = data + strmem.str();
}

string& strpie::operator+= (int a)
{
	data = data + to_string(a);
	return data;
}
string& strpie::operator+=(unsigned int a)
{
	data = data + to_string(a);
	return data;
}
string& strpie::operator+= (__int64 a)
{
	data = data + to_string(a);
	return data;
}
string&  strpie::operator+= (unsigned __int64 a)
{
	data = data + to_string(a);
	return data;
}
string& strpie::operator+= (float a)
{
	if (size_fixed == 0)
	{
		data = data + to_string(a);
	}
	else
	{
		stringstream strmem;
		strmem << fixed << setprecision(size_fixed) << a;
		data = data + strmem.str();
	}
	return data;
}
string& strpie::operator+= (double a)
{
	if (size_fixed == 0)
	{
		data = data + to_string(a);
	}
	else
	{
		stringstream strmem;
		strmem << fixed << setprecision(size_fixed) << a;
		data = data + strmem.str();
	}
	return data;
}
string& strpie::operator+= (string str)
{
	data = data + str;
	return data;
}

bool strpie::readFile(const char* filename)
{
	std::ifstream filedata(filename);
	std::stringstream wss;
	wss << filedata.rdbuf();
	data = wss.str();
	return true;
}
bool strpie::writeFile(const char* filename)
{
	std::ofstream outFile(filename, std::ios::out | std::ios::binary);
	outFile.write(data.c_str(), data.length());
	outFile.close();
	return true;
}

bool strpie::test(const char* str)
{
	if ((int)data.find(str) < 0) { return false; }
	else { return true; };
}

bool strpie::test(string str)
{
	if ((int)data.find(str) < 0) { return false; }
	else { return true; };
}

int strpie::toInt()
{
	return std::stoi(data);
}

__int64 strpie::toInt64()
{
	return std::stoll(data);
}

__int64 strpie::toLongLong()
{
	return std::stoll(data);
}

float strpie::toFloat()
{
	return std::stof(data);
}

double strpie::toDouble()
{
	return std::stod(data);
}

string replacefunc(string source, string replace, string to)
{
	if (replace.empty()) return "";

	size_t start_pos = 0;
	while ((start_pos = source.find(replace, start_pos)) != std::string::npos)
	{
		source.replace(start_pos, replace.length(), to);
		start_pos += to.length();
	}
	return source;
}

string strpie::replace(string replace, string to)
{
	return replacefunc(data, replace, to);
}


string correctNumber(string strfrom, bool* ok)
{
	//strfrom = replacefunc(strfrom, " ", "");
	const char* forcheck = ".0123456789"; // 11 symbols
	string strto = "";
	int len = (int)strfrom.length();
	int point = 0;
	bool booldigit = false;
	int checkdigit = 0;
	for (int x = 0; x < len; x++)
	{
		for (int y = 0; y < 11; y++)
		{
			if (strfrom[x] == forcheck[y])
			{
				checkdigit = checkdigit + y;
				if (strfrom[x] == '.' && point > 0)
				{} // don't include the second point
				else
				{
					strto = strto + strfrom[x];
				}	
			}
			if (strfrom[x] == '.') { point++; }
		}
	}
	if (checkdigit < 1) 
	{ 
		strto = "0"; 
		*ok = 0; 
		return strto;
	}
	else
	{
		*ok = 1;
		return strto;
	}	
}

//*****************************************************************
int strpie::toIntTotal()
{	
	bool ok;
	string str = correctNumber(data, &ok);
	if (ok) { return std::stoi(str); }
	else { return std::stoi("0"); }
}
int strpie::toIntTotal(bool *ok)
{
	string str = correctNumber(data, ok);
	if (ok) { return std::stoi(str); }
	else { return std::stoi("0"); }
}

__int64 strpie::toInt64Total()
{
	bool ok;
	string str = correctNumber(data, &ok);
	if (ok) { return std::stoll(str); }
	else { return std::stoll("0"); }
}
__int64 strpie::toInt64Total(bool *ok)
{
	string str = correctNumber(data, ok);
	if (ok) { return std::stoll(str); }
	else { return std::stoll("0"); }
}

float strpie::toFloatTotal()
{
	bool ok;
	string str = correctNumber(data, &ok);
	if (ok) { return std::stof(str); }
	else { return std::stof("0"); }
}

float strpie::toFloatTotal(bool *ok)
{
	string str = correctNumber(data, ok);
	if (ok) { return std::stof(str); }
	else { return std::stof("0"); }
}

double strpie::toDoubleTotal()
{
	bool ok;
	string str = correctNumber(data, &ok);
	if (ok) { return std::stold(str); }
	else { return std::stold("0"); }
}

double strpie::toDoubleTotal(bool *ok)
{
	string str = correctNumber(data, ok);
	if (ok) { return std::stold(str); }
	else { return std::stold("0"); }
}
//***************************************************************************
void strpie::NewLine()
{
	data = data + "\n";
}

ostream& operator<<(ostream& os, strpie mystr)
{
	string temp = string(mystr.c_str());
	return os << temp;
}

typename std::enable_if<!std::is_same<const char*, int>::value, std::string>::type
operator+ (string s, int i)
{
	return s + std::to_string(i);
}

typename std::enable_if<!std::is_same<int, const char*>::value, std::string>::type
operator+ (int i, string s)
{
	return  std::to_string(i) + s;
}

typename std::enable_if<!std::is_same<const char*, unsigned int>::value, std::string>::type
operator+ (string s, unsigned int i)
{
	return s + std::to_string(i);
}

typename std::enable_if<!std::is_same<unsigned int, const char*>::value, std::string>::type
operator+ (unsigned int i, string s)
{
	return  std::to_string(i) + s;
}

typename std::enable_if<!std::is_same<const char*, __int64>::value, std::string>::type
operator+ (string s, __int64 i)
{
	return s + std::to_string(i);
}

typename std::enable_if<!std::is_same<__int64, const char*>::value, std::string>::type
operator+ (__int64 i, string s)
{
	return  std::to_string(i) + s;
}

// unsigned __int64   const char* + unsigned __int64 and  unsigned __int64 + const char*
typename std::enable_if<!std::is_same<const char*, unsigned __int64>::value, std::string>::type
operator+ (string s, unsigned __int64 i)
{
	return s + std::to_string(i);
}

typename std::enable_if<!std::is_same<unsigned __int64, const char*>::value, std::string>::type
operator+ (unsigned __int64 i, string s)
{
	return  std::to_string(i) + s;
}

typename std::enable_if<!std::is_same<const char*, float>::value, std::string>::type
operator+ (string s, float a)
{

	return s + to_string(a);

//	stringstream strmem;
//	strmem << fixed << setprecision(0) << a;
//	return s + strmem.str();
}

typename std::enable_if<!std::is_same<float, const char*>::value, std::string>::type
operator+ (float a, string s)
{

	return to_string(a) + s;

//	stringstream strmem;
//	strmem << fixed << setprecision(0) << a;
//	return strmem.str() + s;
}

typename std::enable_if<!std::is_same<const char*, double>::value, std::string>::type
operator+ (string s, double a)
{

	return s + to_string(a);

//	stringstream strmem;
//	strmem << fixed << setprecision(0) << a;
//	return s + strmem.str();
}

typename std::enable_if<!std::is_same<double, const char*>::value, std::string>::type
operator+ (double a, string s)
{

	return to_string(a) + s;
	
	//stringstream strmem;
	//strmem << fixed << setprecision(0) << a;
	//return strmem.str() + s;
}

std::string operator""_(const char a[], size_t len)
{
	return std::string(a);
}

typename std::enable_if<!std::is_same<string, const char*>::value, std::string>::type
operator+ (string str, string strwz)
{
	return str.append(strwz);
}


strpie& strpie::operator+ (strpie& str)
{

	if (wzstring_count) { buffer = data;  wzstring_count = 0; }
	buffer = buffer + str;
	str = buffer;
	return str;
}

strpie& strpie::operator= (strpie& str)
{
	wzstring_count = 1;
	data = str.data;
	return str;
}

string& strpie::operator= (const char* str)
{
	data = str;
	//strpie f;
	return data;
}
void strpie::toFixed(short size)
{
	size_fixed = size;
}
const char* strpie::c_str()
{
	return data.c_str();
}
int strpie::length()
{
	return (int)data.length();
}
int strpie::find(string str)
{
	return (int)data.find(str);
}
int strpie::find(string str, int pos)
{
	return (int)data.find(str, pos);
}
int strpie::search(string str)
{
	return (int)data.find(str);
}
int strpie::indexOf(string str)
{
	return (int)data.find(str);
}
int strpie::indexOf(string str, int pos)
{
	return (int)data.find(str, pos);
}
void strpie::slice(int pos)
{
	data.erase(pos, 1);
}
int strpie::charCodeAt()
{
	return (int)data[0];
}
string strpie::fromCharCode(int ascii)
{
	//string str = (const char*)char((char)ascii);
	data = char((char)ascii);
	return data;
}

string& strpie::operator[] (int index)
{
	if (data.length() > index)
	{
		tempdata = string(1, data[index]);
		return tempdata;
	}
	tempdata = "undefined";
	return tempdata;
}
string strpie::charAt(int index)
{
	if (data.length() > index)
	{
		return string(1, data[index]);
	}
	return string("");// undefined");
}

