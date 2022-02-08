#include <iostream>
#include <string.h>
#include <fstream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	//NN误判概率测试
	double w1_1[20][5];
	double b1_1[20][1];
	double w2_1[1][20];
	double b2_1;
	double w1_2[20000][5];
	double b1_2[20000][1];
	double w2_2[1000][20];
	double b2_2[1000][1];

	FILE *fp;

	fp=fopen("csv/bp_1st_param_0_w1.csv","r");
	for(int i = 0; i < 20; i++ )
		fscanf(fp,"%lf,%lf,%lf,%lf,%lf",&w1_1[i][0],&w1_1[i][1],&w1_1[i][2],&w1_1[i][3],&w1_1[i][4]);
	fclose(fp);

	fp=fopen("csv/bp_1st_param_0_b1.csv","r");
	for(int i = 0; i < 20; i++ )
		fscanf(fp,"%lf",&b1_1[i][0]);
	fclose(fp);

	fp=fopen("csv/bp_1st_param_0_w2.csv","r");
	fscanf(fp,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&w2_1[0][0],&w2_1[0][1],&w2_1[0][2],&w2_1[0][3],&w2_1[0][4],&w2_1[0][5],&w2_1[0][6],&w2_1[0][7],&w2_1[0][8],&w2_1[0][9],&w2_1[0][10],&w2_1[0][11],&w2_1[0][12],&w2_1[0][13],&w2_1[0][14],&w2_1[0][15],&w2_1[0][16],&w2_1[0][17],&w2_1[0][18],&w2_1[0][19]);
	fclose(fp);

	fp=fopen("csv/bp_1st_param_0_b2.csv","r");
	fscanf(fp,"%lf",&b2_1);
	fclose(fp);
	b2_1 += 1;

	for(int j = 0; j < 1000; j++ )
	{
		char fName[100] = {'\0'};
		sprintf(fName, "csv/bp_2nd_param_%d_w1.csv", j);
		fp=fopen(fName,"r");
		for(int i = 0; i < 20; i++ )
			fscanf(fp,"%lf,%lf,%lf,%lf,%lf",&w1_2[j*20+i][0],&w1_2[j*20+i][1],&w1_2[j*20+i][2],&w1_2[j*20+i][3],&w1_2[j*20+i][4]);
		fclose(fp);

		sprintf(fName, "csv/bp_2nd_param_%d_b1.csv", j);
		fp=fopen(fName,"r");
		for(int i = 0; i < 20; i++ )
			fscanf(fp,"%lf",&b1_2[j*20+i][0]);
		fclose(fp);

		sprintf(fName, "csv/bp_2nd_param_%d_w2.csv", j);
		fp=fopen(fName,"r");
		fscanf(fp,"%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf",&w2_2[j][0],&w2_2[j][1],&w2_2[j][2],&w2_2[j][3],&w2_2[j][4],&w2_2[j][5],&w2_2[j][6],&w2_2[j][7],&w2_2[j][8],&w2_2[j][9],&w2_2[j][10],&w2_2[j][11],&w2_2[j][12],&w2_2[j][13],&w2_2[j][14],&w2_2[j][15],&w2_2[j][16],&w2_2[j][17],&w2_2[j][18],&w2_2[j][19]);
		fclose(fp);

		sprintf(fName, "csv/bp_2nd_param_%d_b2.csv", j);
		fp=fopen(fName,"r");
		fscanf(fp,"%lf",&b2_2[j][0]);
		fclose(fp);
		b2_2[j][0] += 1;

	}

   while(1)
   {
	double input[5][1];
	int m;
	int output1,output2;
	int temp0,temp1,temp2,temp3,temp4,temp5,temp6,temp7,temp8,temp9,temp10,temp11,temp12,temp13,temp14,temp15,temp16,temp17,temp18,temp19;

	int data = 1000000;
	int output ;
	cout << "请设定映射数组大小：";
	cin >> output;
	int temp[data];
	double output2_temp1 = 49999.5/(100000000/double(output));
	int output2_temp2 = output/1000;
	int output2_temp3 = output - 1;
	int SumOfConflicts = 0;
	
	string file_name;
	string q = "exit";  
        ifstream file_input;
        cout << "请输入你要测试的文件名：";
        cin >> file_name;
         if(strcmp(file_name.c_str(),q.c_str())==0)
            {break;}
	file_input.open (file_name);
	int x = 0;

	for(string str; getline(file_input, str); )  
	{
		char array[5] = {0};		
		char str_char[1024] = {0};
		int str_length = strlen(strcpy(str_char, str.c_str()))-1;
		unsigned char i = 0;
		str_char[str_length] = 0;
		for(; i < str_length;)
		{
			array[0] ^= str_char[i++];
			array[1] ^= str_char[i++];
			array[2] ^= str_char[i++];
			array[3] ^= str_char[i++];
			array[4] ^= str_char[i++];
		}
		input[0][0] = array[0]/63.5-1;
		input[1][0] = array[1]/63.5-1;
		input[2][0] = array[2]/63.5-1;
		input[3][0] = array[3]/63.5-1;
		input[4][0] = array[4]/63.5-1;

		output1 = round((w2_1[0][0]*tanh(w1_1[0][0]*input[0][0]+w1_1[0][1]*input[1][0]+w1_1[0][2]*input[2][0]+w1_1[0][3]*input[3][0]+w1_1[0][4]*input[4][0]+b1_1[0][0])
		+w2_1[0][1]*tanh(w1_1[1][0]*input[0][0]+w1_1[1][1]*input[1][0]+w1_1[1][2]*input[2][0]+w1_1[1][3]*input[3][0]+w1_1[1][4]*input[4][0]+b1_1[1][0])
		+w2_1[0][2]*tanh(w1_1[2][0]*input[0][0]+w1_1[2][1]*input[1][0]+w1_1[2][2]*input[2][0]+w1_1[2][3]*input[3][0]+w1_1[2][4]*input[4][0]+b1_1[2][0])
		+w2_1[0][3]*tanh(w1_1[3][0]*input[0][0]+w1_1[3][1]*input[1][0]+w1_1[3][2]*input[2][0]+w1_1[3][3]*input[3][0]+w1_1[3][4]*input[4][0]+b1_1[3][0])
		+w2_1[0][4]*tanh(w1_1[4][0]*input[0][0]+w1_1[4][1]*input[1][0]+w1_1[4][2]*input[2][0]+w1_1[4][3]*input[3][0]+w1_1[4][4]*input[4][0]+b1_1[4][0])
		+w2_1[0][5]*tanh(w1_1[5][0]*input[0][0]+w1_1[5][1]*input[1][0]+w1_1[5][2]*input[2][0]+w1_1[5][3]*input[3][0]+w1_1[5][4]*input[4][0]+b1_1[5][0])
		+w2_1[0][6]*tanh(w1_1[6][0]*input[0][0]+w1_1[6][1]*input[1][0]+w1_1[6][2]*input[2][0]+w1_1[6][3]*input[3][0]+w1_1[6][4]*input[4][0]+b1_1[6][0])
		+w2_1[0][7]*tanh(w1_1[7][0]*input[0][0]+w1_1[7][1]*input[1][0]+w1_1[7][2]*input[2][0]+w1_1[7][3]*input[3][0]+w1_1[7][4]*input[4][0]+b1_1[7][0])
		+w2_1[0][8]*tanh(w1_1[8][0]*input[0][0]+w1_1[8][1]*input[1][0]+w1_1[8][2]*input[2][0]+w1_1[8][3]*input[3][0]+w1_1[8][4]*input[4][0]+b1_1[8][0])
		+w2_1[0][9]*tanh(w1_1[9][0]*input[0][0]+w1_1[9][1]*input[1][0]+w1_1[9][2]*input[2][0]+w1_1[9][3]*input[3][0]+w1_1[9][4]*input[4][0]+b1_1[9][0])
		+w2_1[0][10]*tanh(w1_1[10][0]*input[0][0]+w1_1[10][1]*input[1][0]+w1_1[10][2]*input[2][0]+w1_1[10][3]*input[3][0]+w1_1[10][4]*input[4][0]+b1_1[10][0])
		+w2_1[0][11]*tanh(w1_1[11][0]*input[0][0]+w1_1[11][1]*input[1][0]+w1_1[11][2]*input[2][0]+w1_1[11][3]*input[3][0]+w1_1[11][4]*input[4][0]+b1_1[11][0])
		+w2_1[0][12]*tanh(w1_1[12][0]*input[0][0]+w1_1[12][1]*input[1][0]+w1_1[12][2]*input[2][0]+w1_1[12][3]*input[3][0]+w1_1[12][4]*input[4][0]+b1_1[12][0])
		+w2_1[0][13]*tanh(w1_1[13][0]*input[0][0]+w1_1[13][1]*input[1][0]+w1_1[13][2]*input[2][0]+w1_1[13][3]*input[3][0]+w1_1[13][4]*input[4][0]+b1_1[13][0])
		+w2_1[0][14]*tanh(w1_1[14][0]*input[0][0]+w1_1[14][1]*input[1][0]+w1_1[14][2]*input[2][0]+w1_1[14][3]*input[3][0]+w1_1[14][4]*input[4][0]+b1_1[14][0])
		+w2_1[0][15]*tanh(w1_1[15][0]*input[0][0]+w1_1[15][1]*input[1][0]+w1_1[15][2]*input[2][0]+w1_1[15][3]*input[3][0]+w1_1[15][4]*input[4][0]+b1_1[15][0])
		+w2_1[0][16]*tanh(w1_1[16][0]*input[0][0]+w1_1[16][1]*input[1][0]+w1_1[16][2]*input[2][0]+w1_1[16][3]*input[3][0]+w1_1[16][4]*input[4][0]+b1_1[16][0])
		+w2_1[0][17]*tanh(w1_1[17][0]*input[0][0]+w1_1[17][1]*input[1][0]+w1_1[17][2]*input[2][0]+w1_1[17][3]*input[3][0]+w1_1[17][4]*input[4][0]+b1_1[17][0])
		+w2_1[0][18]*tanh(w1_1[18][0]*input[0][0]+w1_1[18][1]*input[1][0]+w1_1[18][2]*input[2][0]+w1_1[18][3]*input[3][0]+w1_1[18][4]*input[4][0]+b1_1[18][0])
		+w2_1[0][19]*tanh(w1_1[19][0]*input[0][0]+w1_1[19][1]*input[1][0]+w1_1[19][2]*input[2][0]+w1_1[19][3]*input[3][0]+w1_1[19][4]*input[4][0]+b1_1[19][0])
		+b2_1)*499.5);
		if(output1 < 0)
			output1 = 0;
		else if(output1 > 999)
			output1 = 999;

		temp0 = output1*20;
		temp1 = temp0 + 1;
		temp2 = temp0 + 2;
		temp3 = temp0 + 3;
		temp4 = temp0 + 4;
		temp5 = temp0 + 5;
		temp6 = temp0 + 6;
		temp7 = temp0 + 7;
		temp8 = temp0 + 8;
		temp9 = temp0 + 9;
		temp10 = temp0 + 10;
		temp11 = temp0 + 11;
		temp12 = temp0 + 12;
		temp13 = temp0 + 13;
		temp14 = temp0 + 14;
		temp15 = temp0 + 15;
		temp16 = temp0 + 16;
		temp17 = temp0 + 17;
		temp18 = temp0 + 18;
		temp19 = temp0 + 19;
		output2 = floor((w2_2[output1][0]*tanh(w1_2[temp0][0]*input[0][0]+w1_2[temp0][1]*input[1][0]+w1_2[temp0][2]*input[2][0]+w1_2[temp0][3]*input[3][0]+w1_2[temp0][4]*input[4][0]+b1_2[temp0][0])
		+w2_2[output1][1]*tanh(w1_2[temp1][0]*input[0][0]+w1_2[temp1][1]*input[1][0]+w1_2[temp1][2]*input[2][0]+w1_2[temp1][3]*input[3][0]+w1_2[temp1][4]*input[4][0]+b1_2[temp1][0])
		+w2_2[output1][2]*tanh(w1_2[temp2][0]*input[0][0]+w1_2[temp2][1]*input[1][0]+w1_2[temp2][2]*input[2][0]+w1_2[temp2][3]*input[3][0]+w1_2[temp2][4]*input[4][0]+b1_2[temp2][0])
		+w2_2[output1][3]*tanh(w1_2[temp3][0]*input[0][0]+w1_2[temp3][1]*input[1][0]+w1_2[temp3][2]*input[2][0]+w1_2[temp3][3]*input[3][0]+w1_2[temp3][4]*input[4][0]+b1_2[temp3][0])
		+w2_2[output1][4]*tanh(w1_2[temp4][0]*input[0][0]+w1_2[temp4][1]*input[1][0]+w1_2[temp4][2]*input[2][0]+w1_2[temp4][3]*input[3][0]+w1_2[temp4][4]*input[4][0]+b1_2[temp4][0])
		+w2_2[output1][5]*tanh(w1_2[temp5][0]*input[0][0]+w1_2[temp5][1]*input[1][0]+w1_2[temp5][2]*input[2][0]+w1_2[temp5][3]*input[3][0]+w1_2[temp5][4]*input[4][0]+b1_2[temp5][0])
		+w2_2[output1][6]*tanh(w1_2[temp6][0]*input[0][0]+w1_2[temp6][1]*input[1][0]+w1_2[temp6][2]*input[2][0]+w1_2[temp6][3]*input[3][0]+w1_2[temp6][4]*input[4][0]+b1_2[temp6][0])
		+w2_2[output1][7]*tanh(w1_2[temp7][0]*input[0][0]+w1_2[temp7][1]*input[1][0]+w1_2[temp7][2]*input[2][0]+w1_2[temp7][3]*input[3][0]+w1_2[temp7][4]*input[4][0]+b1_2[temp7][0])
		+w2_2[output1][8]*tanh(w1_2[temp8][0]*input[0][0]+w1_2[temp8][1]*input[1][0]+w1_2[temp8][2]*input[2][0]+w1_2[temp8][3]*input[3][0]+w1_2[temp8][4]*input[4][0]+b1_2[temp8][0])
		+w2_2[output1][9]*tanh(w1_2[temp9][0]*input[0][0]+w1_2[temp9][1]*input[1][0]+w1_2[temp9][2]*input[2][0]+w1_2[temp9][3]*input[3][0]+w1_2[temp9][4]*input[4][0]+b1_2[temp9][0])
		+w2_2[output1][10]*tanh(w1_2[temp10][0]*input[0][0]+w1_2[temp10][1]*input[1][0]+w1_2[temp10][2]*input[2][0]+w1_2[temp10][3]*input[3][0]+w1_2[temp10][4]*input[4][0]+b1_2[temp10][0])
		+w2_2[output1][11]*tanh(w1_2[temp11][0]*input[0][0]+w1_2[temp11][1]*input[1][0]+w1_2[temp11][2]*input[2][0]+w1_2[temp11][3]*input[3][0]+w1_2[temp11][4]*input[4][0]+b1_2[temp11][0])
		+w2_2[output1][12]*tanh(w1_2[temp12][0]*input[0][0]+w1_2[temp12][1]*input[1][0]+w1_2[temp12][2]*input[2][0]+w1_2[temp12][3]*input[3][0]+w1_2[temp12][4]*input[4][0]+b1_2[temp12][0])
		+w2_2[output1][13]*tanh(w1_2[temp13][0]*input[0][0]+w1_2[temp13][1]*input[1][0]+w1_2[temp13][2]*input[2][0]+w1_2[temp13][3]*input[3][0]+w1_2[temp13][4]*input[4][0]+b1_2[temp13][0])
		+w2_2[output1][14]*tanh(w1_2[temp14][0]*input[0][0]+w1_2[temp14][1]*input[1][0]+w1_2[temp14][2]*input[2][0]+w1_2[temp14][3]*input[3][0]+w1_2[temp14][4]*input[4][0]+b1_2[temp14][0])
		+w2_2[output1][15]*tanh(w1_2[temp15][0]*input[0][0]+w1_2[temp15][1]*input[1][0]+w1_2[temp15][2]*input[2][0]+w1_2[temp15][3]*input[3][0]+w1_2[temp15][4]*input[4][0]+b1_2[temp15][0])
		+w2_2[output1][16]*tanh(w1_2[temp16][0]*input[0][0]+w1_2[temp16][1]*input[1][0]+w1_2[temp16][2]*input[2][0]+w1_2[temp16][3]*input[3][0]+w1_2[temp16][4]*input[4][0]+b1_2[temp16][0])
		+w2_2[output1][17]*tanh(w1_2[temp17][0]*input[0][0]+w1_2[temp17][1]*input[1][0]+w1_2[temp17][2]*input[2][0]+w1_2[temp17][3]*input[3][0]+w1_2[temp17][4]*input[4][0]+b1_2[temp17][0])
		+w2_2[output1][18]*tanh(w1_2[temp18][0]*input[0][0]+w1_2[temp18][1]*input[1][0]+w1_2[temp18][2]*input[2][0]+w1_2[temp18][3]*input[3][0]+w1_2[temp18][4]*input[4][0]+b1_2[temp18][0])
		+w2_2[output1][19]*tanh(w1_2[temp19][0]*input[0][0]+w1_2[temp19][1]*input[1][0]+w1_2[temp19][2]*input[2][0]+w1_2[temp19][3]*input[3][0]+w1_2[temp19][4]*input[4][0]+b1_2[temp19][0])
		+b2_2[output1][0])*output2_temp1)+output1*output2_temp2;
		if(output2 < 0)
			output2 = 0;
		else if(output2 > output2_temp3)
			output2 = output2_temp3;

		temp[x] = output2;
		x++;
	}

	sort(temp, temp+data);
	for(int j = 0; j < data-1; j++)
	{
		if(temp[j] == temp[j+1])
			SumOfConflicts++;
	}
	cout << "data:" << data << "\t\toutput:" << output << "\t\tconflict:" << double(SumOfConflicts)/data*100 << "%" << endl;
	file_input.close();
   }
     cout << "====================================================" << endl;
     cout << "测试结束" << endl;
	return 0;
}

