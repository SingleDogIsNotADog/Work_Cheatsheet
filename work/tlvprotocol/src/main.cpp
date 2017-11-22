#include <iostream>
#include "size.h"
#include "./tlvprotocol/tlvprotocol.h"

using namespace std;

static constexpr size_t BUFF_SIZE = 1024;

void test_write_buffer()
{
	char buffer[BUFF_SIZE] = {0};
	int a = 66;
	bool b = true;
	
	char *p = buffer;

	// 写入一个int
	*((int*)p) = a;
	p += sizeof(int);

	// 再写入一个bool
	*((bool*)p) = b;
	p += sizeof(bool);

	int write_sz = p - buffer;
	cout << "write size: " << write_sz << endl;	// 5

	p = buffer;
	
	// 读出一个int
	cout << *((int*)p) << endl;
	p += sizeof(int);

	// 再读出一个bool
	cout << *((bool*)p) << endl;
	p += sizeof(bool);
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

	// 往里面push数据
	int a = 10;
	tlv_s.Push(a);
	cout << tlv_s.Size() << endl;	// 1 + 4 = 8
}

int main()
{
	//test_write_buffer();
	
	//test_size();
	
	test_serialize();

	return 0;
}
