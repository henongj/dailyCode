
//https://www.acmicpc.net/problem/3003
//ŷ, ��, ��, ���, ����Ʈ, ��
void fGetChessPiece(void)
{
	int chessPiece[6] = { 1, 1, 2, 2, 2, 8 };
	for (int i = 0; i < 6; i++)
	{
		int input;
		cin >> input;
		cout << chessPiece[i] - input << " ";
	}
}

/*
int main(void)
{
	fGetChessPiece();
}
*/