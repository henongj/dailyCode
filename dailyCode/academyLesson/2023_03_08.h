#include<iostream>
namespace academyLecture_2023_03_06
{

	struct S_DATA
	{
		int nData1;
		int nData2;
		//이건 도중 추가라고 가정
		int nData3;
		char fData1;
		char fData2;
	};
	void printSDATA(const S_DATA* s);
	void printSDdATA(S_DATA s);
	void setData(S_DATA* pData, int nData1, int nData2, int nData3, char fData1, char fData2);


	struct S_SCORE
	{
		int nSubjectKorean;
		int nSubjectEnglish;
		int nSubjectMathMatics;
		int* pTest;
	};

	struct S_STUDENT
	{
		char strName[64]{};
		int nId;
		S_SCORE* pScore{};
	};

	int mainSpace2(void)
	{
		S_DATA sData{ 1,2,3,'a','b' };
		printSDATA(&sData);



		return 0;
	}

	int mainSpace3(void)
	{
		S_SCORE sScore{ 20,30,40 };

		S_SCORE* pScore = &sScore;
		S_STUDENT sStudent{ "Kim", 12341234, pScore };
		S_STUDENT* pStudent = &sStudent;

		(*sStudent.pScore).nSubjectEnglish = 100;
		(sStudent.pScore)->nSubjectKorean = 2123;
		(*pScore).nSubjectMathMatics = 12;

		// print subjects
		printf("%d %d %d\n",
			sStudent.pScore->nSubjectKorean,
			sStudent.pScore->nSubjectEnglish,
			sStudent.pScore->nSubjectMathMatics);

		// print subjects with pStudent
		printf("%s : %d %d %d",
			pStudent->strName,
			pStudent->pScore->nSubjectKorean,
			pStudent->pScore->nSubjectEnglish,
			pStudent->pScore->nSubjectMathMatics);


	}
	int mainSpace4(void)
	{
		int nTest{};
		nTest = 25;
		S_SCORE sScore{ 20,30,40, &nTest };

		S_SCORE* pScore = &sScore;
		S_STUDENT sStudent{ "Kim", 12341234, pScore };
		S_STUDENT* pStudent = &sStudent;


		printf("%d", *(*(*pStudent).pScore).pTest);
		printf("%d", *pStudent->pScore->pTest);

		return 0;
	}

	
	void mainSpace1(void)
	{
		//구조체 선언과 동시에 초기화, nData3에 'a'가 들어가는데 그냥 컴파일된다
		S_DATA sData{ 1,2,'a','b' };

		S_DATA* p_sData{};
		p_sData = &sData;

		(*p_sData).nData1 = 3111;
		printf("%d\n", (*p_sData).nData1);

		//이렇게도 가능
		p_sData->nData1 = 1212;
		printf("%d\n", p_sData->nData1);

		S_DATA arr_sData[2]{ {1,2,3,'a','b'}, {4,5,6,'c','d'} };

		S_DATA* pArr_sData[2];
		pArr_sData[0] = &arr_sData[0];
		pArr_sData[1] = &arr_sData[1];

		pArr_sData[0]->nData1 = 1111;
		(*pArr_sData[1]).fData2 = 'z';

		printf("%d %c\n", pArr_sData[0]->nData1, (*pArr_sData[1]).fData2);

	}

	void printSDATA(const S_DATA* s)
	{
		printf("%d %d %d %c %c\n", s->nData1, s->nData2, s->nData3, s->fData1, s->fData2);
	}

	void printSDdATA(S_DATA s)
	{
		printf("%d %d %d %c %c\n", s.nData1, s.nData2, s.nData3, s.fData1, s.fData2);
	}

	void setData(S_DATA* pData, int nData1, int nData2, int nData3, char fData1, char fData2)
	{
		pData->nData1 = nData1;
		pData->nData2 = nData2;
		pData->nData3 = nData3;
		pData->fData1 = fData1;
		pData->fData2 = fData2;
	}

}