#include"key.h"

string displace1(string key,char func)
{
	int c0[28] = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36 };
	int d0[28] = { 63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	string retval(28,'0');
	if (func == 'c')
	{
		for (int i = 0; i < 28; i++)
		{
			retval[i] = key[c0[i]-1];
		}
	}
	else if (func == 'd')
	{
		for (int i = 0; i < 28; i++)
		{
			retval[i] = key[d0[i]-1];
		}
	}
	return retval;
}

string roundleft(string k,int length)
{
	if (length == 1)
	{
		char tmp = k[0];
		for (int i = 1; i < 28; i++)
		{
			k[i - 1] = k[i];
		}
		k[27] = tmp;
	}
	else if (length == 2)
	{
		char tmp1 = k[0];
		char tmp2 = k[1];
		for (int i = 2; i < 28; i++)
		{
			k[i - 2] = k[i];
		}
		k[26] = tmp1;
		k[27] = tmp2;
	}
	return k;
}

string displace2(string k1,string k2)
{
	int round2list[48] = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };
	string k = k1 + k2;
	string retval(56, '0');
	for (int i = 0; i < 48; i++)
	{
		retval[i] = k[round2list[i]-1];
	}
	return retval;
}

string key(string k,int num)
{
	int roundbitnum[16] = { 1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1 };
	string result(48, '0');
	string c(28, '0');
	string d(28, '0');
	c = displace1(k, 'c');
	d = displace1(k, 'd');
	for (int i = 0; i < num; i++)
	{
		c = roundleft(c, roundbitnum[i]);
		d = roundleft(d, roundbitnum[i]);
		result = displace2(c, d);
	}
	return result;
}