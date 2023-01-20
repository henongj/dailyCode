#include<iostream>
namespace lecture_2023_01_20
{
	void getDividendAndDivisor(void)
	{
		int nDividend{};
		int nDivisor{};
		int nQuotient{};
		int nRemainder{};

		printf("제수 입력 : ");
		scanf_s("%d", &nDividend);
		printf("피제수 입력 : ");
		scanf_s("%d", &nDivisor);

		nQuotient = nDividend / nDivisor;
		nRemainder = nDividend - (nDivisor * nQuotient);
		//nRemainder = nDividend % nDivisor;
		printf("몫 : %d\n", nQuotient);
		printf("나머지 : %d\n", nRemainder);
	}

	void isOdd(void)
	{
		int nNumber{};
		int nRemainderOfTwo{};

		printf("숫자 입력 : ");
		scanf_s("%d", &nNumber);

		nRemainderOfTwo = nNumber % 2;

		if (nRemainderOfTwo == 0)
			printf("짝수\n");
		if (nRemainderOfTwo == 1)
			printf("홀수\n");
	}

	void operatePlusMinus(void)
	{
		int nData{};

		/* 이렇게 쓰지마라, 섞지도 말고, 연산결과는 컴파일러마다 달라서 확정적이지 않다 */
		printf("%d\n", nData++);
		printf("%d\n", nData);
		printf("%d\n", ++nData);

		/* 이렇게 쓰고, 섞지마라 */
		nData++;
		printf("%d\n", nData);
		nData++;

		/*이건 컴파일러, 함수 호출 규약마다 달라서 모른다, 뒤지기 싫으면 쓰지마라*/
		int nData2{};
		printf("%d %d %d\n", ++nData2, ++nData2, ++nData2);
		int nData3{};
		printf("%d %d %d\n", nData3++, nData3++, nData3++);

		// ++nData++ 하면 안 되는 이유는 무엇일까?
		// 연산자 작업 후 남는 임시변수는 const라서 연산이 안 된다
	}
}