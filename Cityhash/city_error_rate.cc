/*CityHash误判概率测试*/
#include <iostream> //标准输入输出类库
#include <string.h> //字符串类库
#include <fstream> //文本文件类库
#include <time.h> //时间类库
#include <algorithm>
#include <cmath>

#include "city.h"
#ifdef __SSE4_2__
#include "citycrc.h"
#endif

using namespace std;

int main() {
	
	int data = 1000000;
	int output;//索引范围控制
	string file_name;
	string q = "exit";  
	while(1)
     {
	cout << "请设定映射数组大小：";
	cin >> output;
	  
	cout << "请输入你要测试的文件名：";
        cin >> file_name;

        if(strcmp(file_name.c_str(),q.c_str())==0)
            break;
	ifstream in(file_name);
	int i = 0;
	int SumOfConflicts = 0;
	uint64 crc256_results[4];//存储CityHashCrc256函数的返回值，每个元素为64bit
	int temp[data] = {0};

	for(string str; getline(in, str); )  
	{
		char str_char[1024];
		int str_length = strlen(strcpy(str_char, str.c_str()));

         	CityHashCrc256(str_char, str_length, crc256_results);

		temp[i] = (double(crc256_results[0])*pow(2,192)+double(crc256_results[1])*pow(2,128)+double(crc256_results[2])*pow(2,64)+double(crc256_results[3]))*output/pow(2,256);
		i++;

	}

	sort(temp, temp+data);
	for(int j = 0; j < data-1; j++)
	{
		if(temp[j] == temp[j+1])
			SumOfConflicts++;
	}
	cout << "data:" << data << "\toutput:" << output << "\t\tconflict:" << double(SumOfConflicts)/data*100 << "%" << endl;

	in.close();
  }
  cout <<"====================================================================" << endl;
  cout << "测试结束" << endl;
	return 0;
}


