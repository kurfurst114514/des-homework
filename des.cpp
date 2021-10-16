#include"des.h"
#include<cmath>
char strxor(char a, char b)
{
	if (a == b)
	{
		return '0';
	}
	else
	{
		return '1';
	}
}

int string_to_int(string s)
{
	int result = 0;
	for(int i = 0; i < s.length(); i++)
	{
		int index = s.length()-i-1;
		if (s[index] == '1')
		{
			result += 1 << i;
		}
	}
	return result;
}

string int_to_string(int x,int length)
{
	string result;
	for (int i = length-1; i >= 0; i--)
	{
		int tmp = (x & (1 << i)) >> i;
		if (tmp == 0)
		{
			result += "0";
		}
		else
		{
			result += "1";
		}
	}
	return result;
}

string displaceip(string input,char func)
{
	int IP[64] = { 58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7 };
	string result(32, '0');
	if (func == 'l')
	{
		for (int i = 0; i < 32; i++)
		{
			result[i] = input[IP[i]-1];
		}
	}
	else if (func == 'r')
	{
		for (int i = 0; i < 32; i++)
		{
			result[i] = input[IP[i + 32]-1];
		}
	}
	return result;
}

string ndisplaceip(string r, string l)
{
	string s = r + l;
	int nIP[64] = { 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };
	string result;
	for (int i = 0; i < 64; i++)
	{
		result[i] = s[nIP[i]-1];
	}
	return result;
}

string emcyptfunc(string A, string k)
{
	int E[48] = { 32,1,2,3,4,5,4,5,6,7,8,9,8,9,10,11,12,13,12,13,14,15,16,17,16,17,18,19,20,21,20,21,22,23,24,25,24,25,26,27,28,29,28,29,30,31,32,1 };
	string tmp(48, '0');
	for (int i = 0; i < 48; i++)
	{
		tmp[i] = A[E[i]-1];
	}
	for (int i = 0; i < 48; i++)
	{
		tmp[i] = strxor(tmp[i], k[i]);
		//tmp[i] = tmp[i] ^ k[i];
	}
	int S[8][4][16] = { {{14,4,13,1,2,15,11,8,3,18,6,12,5,9,0,7},{0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},{4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},{15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13}},
						{{15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},{3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},{0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},{13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9}},
						{{10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},{13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},{13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},{1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12}},
						{{7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},{13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},{10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},{3,15,0,6,10,1,13,8,9,4,5,11,12,7,3,14}},
						{{2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},{14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},{4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},{11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3}},
						{{12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},{10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},{9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},{4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13}},
						{{4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},{13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},{1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},{6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12}},
						{{13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},{1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},{7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},{2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11}}, };
	string stmp[8];
	string sres[8];
	for (int i = 0; i < 8; i++)
	{
		stmp[i] = "";
		sres[i] = "";
	}
	for (int i = 0; i < 48; i++)
	{
		//int index = i % 6;
		int snum = i / 6;
		stmp[snum] += tmp[i];
	}
	for (int i = 0; i < 8; i++)
	{
		string xstr(2,'0');
		string ystr(4, '0');
		xstr[0] = stmp[i][0];
		xstr[1] = stmp[i][5];
		ystr[0] = stmp[i][1];
		ystr[1] = stmp[i][2];
		ystr[2] = stmp[i][3];
		ystr[3] = stmp[i][4];
		int x = string_to_int(xstr);
		int y = string_to_int(ystr);
		int tres = S[i][x][y];
		sres[i] = int_to_string(tres,4);
	}
	tmp = sres[0] + sres[1] + sres[2] + sres[3] + sres[4] + sres[5] + sres[6] + sres[7];
	int P[32] = { 16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25 };
	string result(32,'0');
	for (int i = 0; i < 32; i++)
	{
		result[i] = tmp [P[i]-1];
	}
	return result;
}

string des(string input,string password)
{
	string l, r;
	l = displaceip(input, 'l');
	r = displaceip(input, 'r');
	string subkey[16];
	for (int i = 0; i < 16; i++)
	{
		subkey[i] = key(password, i+1);
	}
	for (int i = 0; i < 16; i++)
	{
		string tmpstr = emcyptfunc(r, subkey[i]);
		string tmpr = r;
		for (int j = 0; j < 32; j++)
		{
			//r[j] = tmpstr[j] ^ l[j];
			r[j] = strxor(tmpstr[j], l[j]);
		}
		l = tmpr;
	}
	string preresult = r + l;
	string result(64, '0');
	int nIP[64] = { 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };
	for (int i = 0; i < 64; i++)
	{
		result[i] = preresult[nIP[i]-1];
	}
	return result;
}

string ndes(string input, string password)
{
	string l, r;
	l = displaceip(input, 'l');
	r = displaceip(input, 'r');
	string subkey[16];
	for (int i = 0; i < 16; i++)
	{
		subkey[i] = key(password, i + 1);
	}
	for (int i = 0; i < 16; i++)
	{
		string tmpstr = emcyptfunc(r, subkey[15-i]);
		string tmpr = r;
		for (int j = 0; j < 32; j++)
		{
			//r[j] = tmpstr[j] ^ l[j];
			r[j] = strxor(tmpstr[j], l[j]);
		}
		l = tmpr;
	}
	string preresult = r + l;
	string result(64, '0');
	int nIP[64] = { 40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25 };
	for (int i = 0; i < 64; i++)
	{
		result[i] = preresult[nIP[i] - 1];
	}
	return result;
}