
//https://school.programmers.co.kr/learn/courses/30/lessons/133025
//과일로 만든 아이스크림 고르기

/* 정답

SELECT FLAVOR
FROM FIRST_HALF
WHERE TOTAL_ORDERED > 3000 AND FLAVOR IN(
	SELECT FLAVOR
	FROM ICECREAM_INFO
	WHERE INGREDIENT_TYPE = 'fruit_based'
);

*/
