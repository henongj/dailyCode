
//https://school.programmers.co.kr/learn/courses/30/lessons/133025
//���Ϸ� ���� ���̽�ũ�� ����

/* ����

SELECT FLAVOR
FROM FIRST_HALF
WHERE TOTAL_ORDERED > 3000 AND FLAVOR IN(
	SELECT FLAVOR
	FROM ICECREAM_INFO
	WHERE INGREDIENT_TYPE = 'fruit_based'
);

*/
