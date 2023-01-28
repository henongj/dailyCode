
//https://www.acmicpc.net/problem/3003
//Å·, Äý, ·è, ºñ¼ó, ³ªÀÌÆ®, Æù
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