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

#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <type_traits>

#include <iostream>
#include <fstream>

using namespace std;


class strpie
{
private:
	short size_fixed = 0;
	string data;
	string tempdata = "";

	unsigned len_;   // ORDER DEPENDENCY
	char*    data_;  // ORDER DEPENDENCY

	string buffer = "";
	bool wzstring_count = 0;
	//void set_variable_to_fixed(int z);
public:
	operator std::string() const { return data; }

	strpie(void);

	strpie(const char* s);

	strpie(string tempstr);

	strpie(int a);

	strpie(unsigned int a);

	strpie(__int64 a);

	strpie(unsigned __int64 a);

	strpie(float a);

	strpie(double a);

	// +++++++ const char* string ++++++++++++++
	string& operator= (const char* str);

	string& operator= (string str);

	strpie& operator= (strpie& str);

	string& operator= (int a);

	string& operator= (unsigned int a);

	string& operator= (__int64 a);

	string& operator= (unsigned __int64 a);

	string& operator= (float a);

	string& operator= (double a);

	strpie& operator+ (strpie& str);

	//********************************************************************

	bool operator== (string str);

	//********************************************************************

	string& operator+ (const char* s);

	string& operator+(string str);

	// ++++++++++++++++++++++++++++++++++  strpie = strpie + int

	string& operator+(int a);

	string& operator+(unsigned int a);

	string& operator+(__int64 a);

	string& operator+(unsigned __int64 a);

	string& operator+(float a);

	string& operator+(double a);
	//*******************************************

	string& operator+= (int a);

	string& operator+=(unsigned int a);

	string& operator+=(__int64 a);

	string& operator+=(unsigned __int64 a);

	string& operator+=(float a);

	string& operator+=(double a);

	string& operator+= (string str);

	// ===================================
	void toFixed(short size);

	const char* c_str();

	int length();

	int find(string str);

	int find(string str, int pos);

	int search(string str);

	int indexOf(string str);

	int indexOf(string str, int pos);

	void slice(int pos);

	int charCodeAt();

	string fromCharCode(int ascii);

	string replace(string replace, string to);

	string& operator[] (int index);

	string charAt(int index);

	bool readFile(const char* filename);

	bool writeFile(const char* filename);

	bool test(string str);

	bool test(const char* str);

	int toInt();

	__int64 toInt64();

	__int64 toLongLong();

	float toFloat();

	double toDouble();

	int toIntTotal();

	__int64 toInt64Total();

	float toFloatTotal();

	double toDoubleTotal();

	int toIntTotal(bool *ok);

	__int64 toInt64Total(bool *ok);

	float toFloatTotal(bool *ok);

	double toDoubleTotal(bool *ok);

	void NewLine();
};

ostream& operator<<(ostream& os, strpie mystr);


typename std::enable_if<!std::is_same<const char*, int>::value, std::string>::type
operator+ (string s, int i);


typename std::enable_if<!std::is_same<int, const char*>::value, std::string>::type
operator+ (int i, string s);


typename std::enable_if<!std::is_same<const char*, unsigned int>::value, std::string>::type
operator+ (string s, unsigned int i);


typename std::enable_if<!std::is_same<unsigned int, const char*>::value, std::string>::type
operator+ (unsigned int i, string s);


typename std::enable_if<!std::is_same<const char*, __int64>::value, std::string>::type
operator+ (string s, __int64 i);


typename std::enable_if<!std::is_same<__int64, const char*>::value, std::string>::type
operator+ (__int64 i, string s);


// unsigned __int64   const char* + unsigned __int64 and  unsigned __int64 + const char*
typename std::enable_if<!std::is_same<const char*, unsigned __int64>::value, std::string>::type
operator+ (string s, unsigned __int64 i);


typename std::enable_if<!std::is_same<unsigned __int64, const char*>::value, std::string>::type
operator+ (unsigned __int64 i, string s);


typename std::enable_if<!std::is_same<const char*, float>::value, std::string>::type
operator+ (string s, float a);


typename std::enable_if<!std::is_same<float, const char*>::value, std::string>::type
operator+ (float a, string s);


typename std::enable_if<!std::is_same<const char*, double>::value, std::string>::type
operator+ (string s, double a);


typename std::enable_if<!std::is_same<double, const char*>::value, std::string>::type
operator+ (double a, string s);


std::string operator""_(const char a[], size_t len);


typename std::enable_if<!std::is_same<string, const char*>::value, std::string>::type
operator+ (string str, string strwz);


