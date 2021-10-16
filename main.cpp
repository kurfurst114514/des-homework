#include"des.h"
#include<iostream>



void enpre()
{
	string message(64,'0');
	string keyword(64, '0');
	
	cout << "输入明文" << endl;
	cin >> message;
	cout << "输入密钥" << endl;
	cin >> keyword;
	/*string message = "0011000000110001001100100011001100110100001101010011011000110111";
	string keyword = "0011000100110010001100110011010000110101001101100011011100111000";*/
	string emcymessage;
	emcymessage = des(message, keyword);
	cout << "加密后为" << emcymessage << endl;
	//system("pause");
	//system("cls");
}

void dispre()
{
	string enmessage(64, '0');
	string keyword(64, '0');
	
	cout << "输入密文" << endl;
	cin >> enmessage;
	cout << "输入密钥" << endl;
	cin >> keyword;
	/*string message = "0011000000110001001100100011001100110100001101010011011000110111";
	string keyword = "0011000100110010001100110011010000110101001101100011011100111000";*/
	string emcymessage;
	emcymessage = ndes(enmessage, keyword);
	cout << "解密密后为" << emcymessage << endl;
	//system("pause");
	//system("cls");
}

int main()
{
	while (1)
	{
		cout << "加密输入1，解密输入0" << endl;
		int choice = 0;
		cin >> choice;
		if (choice == 1)
		{
			enpre();
		}
		else if (choice == 0)
		{
			dispre();
		}
		cout << "输入1退出，0继续" << endl;
		cin >> choice;
		if (choice == 1)
		{
			return 0;
		}
	}
	return 0;
}