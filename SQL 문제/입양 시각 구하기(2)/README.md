# 입양시각 구하기(2)

소스코드
~~~sql

with A as (SELECT LEVEL -1 AS HOUR
FROM DUAL CONNECT BY LEVEL <= 24), B as (SELECT HOUR, COUNT(HOUR) as 
COUNT
FROM(SELECT TO_NUMBER(TO_CHAR(DATETIME,'fmHH24')) as HOUR 
     FROM ANIMAL_OUTS )
GROUP BY HOUR
ORDER BY HOUR)

SELECT A.HOUR, nvl(B.Count, 0) as Count
FROM A LEFT OUTER JOIN B 
on  A.HOUR = B.HOUR
ORDER BY A.hour;
~~~

## With 구문 사용법
~~~
WITH [WITH절 명칭-1] AS (SELECT [컬럼명-1] FROM [테이블명-1]),
        [WITH절 명칭-2] AS (SELECT [컬럼명-2] FROM [테이블명-2])
SELECT ALIAS명-1.[컬럼명-1]
        , ALIAS명-2.[컬럼명-2]
FROM [WITH절 명칭-1] ALIAS명-1 
       ,  [WITH절 명칭-2] ALIAS명-2
~~~



