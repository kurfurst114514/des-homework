#include"des.h"
#include<iostream>



void enpre()
{
	string message(64,'0');
	string keyword(64, '0');
	
	cout << "��������" << endl;
	cin >> message;
	cout << "������Կ" << endl;
	cin >> keyword;
	/*string message = "0011000000110001001100100011001100110100001101010011011000110111";
	string keyword = "0011000100110010001100110011010000110101001101100011011100111000";*/
	string emcymessage;
	emcymessage = des(message, keyword);
	cout << "���ܺ�Ϊ" << emcymessage << endl;
	//system("pause");
	//system("cls");
}

void dispre()
{
	string enmessage(64, '0');
	string keyword(64, '0');
	
	cout << "��������" << endl;
	cin >> enmessage;
	cout << "������Կ" << endl;
	cin >> keyword;
	/*string message = "0011000000110001001100100011001100110100001101010011011000110111";
	string keyword = "0011000100110010001100110011010000110101001101100011011100111000";*/
	string emcymessage;
	emcymessage = ndes(enmessage, keyword);
	cout << "�����ܺ�Ϊ" << emcymessage << endl;
	//system("pause");
	//system("cls");
}

int main()
{
	while (1)
	{
		cout << "��������1����������0" << endl;
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
		cout << "����1�˳���0����" << endl;
		cin >> choice;
		if (choice == 1)
		{
			return 0;
		}
	}
	return 0;
}