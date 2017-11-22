#include <iostream>
#include <cstring>
#include "size.h"
#include "./tlvprotocol/tlvprotocol.h"

using namespace std;

static constexpr size_t BUFF_SIZE = 1024;

void test_write_buffer()
{
	char buffer[BUFF_SIZE] = {0};
	int a = 66;
	bool b = true;
	const char *s = "hello";
	
	char *p = buffer;

	// 写入一个int
	*((int*)p) = a;
	p += sizeof(int);

	// 再写入一个bool
	*((bool*)p) = b;
	p += sizeof(bool);

	// 写入一个字符串
	strcpy(p, s);
	p += (strlen(s) + 1);

	int write_sz = p - buffer;
	cout << "write size: " << write_sz << endl;	// 4 + 1 + 6

	p = buffer;
	
	// 读出一个int
	cout << *((int*)p) << endl;
	p += sizeof(int);

	// 再读出一个bool
	cout << *((bool*)p) << endl;
	p += sizeof(bool);

	// 再读出一个字符串
	cout << p << endl;
	p += (strlen(s) + 1);
}

void test_size()
{
	int a = 0;
	string s;

	cout << size(a) << endl;
	cout << size(s) << endl;
}

static char buffer[BUFF_SIZE];
void test_serialize()
{
	// 初始化
	TLVSerializer tlv_s;
	tlv_s.Reset(buffer, BUFF_SIZE);

	// 往里面push一个int
	int a = 10;
	tlv_s.Push(a);

	// 往里面push一个bool
	bool b = true;
	tlv_s.Push(b);

	// 往里面push一个字符串
	const char *str = "hello";
	tlv_s.Push(str);

	cout << tlv_s.Size() << endl;	// (1+4) + (1+1) + (1+4+6) = 18
}

void test_unserialize()
{
	// 初始化
	TLVUnserializer tlv_us;
	tlv_us.Reset(buffer, BUFF_SIZE);

	// 从里面Pop一个int
	int a = 0;
	tlv_us.Pop(&a);
	cout << a << endl;

	// 从里面Pop一个bool
	bool b = false;
	tlv_us.Pop(&b);
	cout << b << endl;

	// 从里面Pop一个字符串
	const char *str = nullptr;
	tlv_us.Pop(&str);
	string s(str);
	cout << s << endl;
}

int main()
{
	//test_write_buffer();
	
	//test_size();
	
	test_serialize();
	test_unserialize();

	return 0;
}
