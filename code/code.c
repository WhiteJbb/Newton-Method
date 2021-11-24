#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
	int i, N;	//루프 회전 수
	double x, x0, tol;	//해, 초기값, x축에 얼마나 근접했는가(오차)
	double f(double), f1(double);	//사용자 정의 함수(함수, 함수의 미분 값)

	N = 100;	//루프제한 100회 회전	
	x0 = 0;
	tol = 1.0e-6;	//오차 // 1/1000000

	printf("---------------------------------------\n\n");
	printf("Newton-Rahpson Method\n");
	printf("                     made by 동건\n\n");
	printf("---------------------------------------\n\n");
	printf("초기값을 입력해주세요 : ");
	scanf_s("%lf", &x0);

	i = 0;	//카운터 초기화
	while (i < N)	//루프
	{
		x = x0 - f(x0) / f1(x0);	//접선의 방정식의 해
		if (fabs(x - x0) < tol) 	//정지 조건 //fabs = 절댓값
		{
			printf("\n\n 해에 가까운 근사값은 %lf \n", x); // 성공	//해 출력
			return 0;
		}
		i++;	//카운터 증가
		x0 = x;	//초기값 갱신
		printf("\n(%d) x[%lf] = %lf", i, x, f(x)); // 반복	//현재 위치 출력
	}
	printf("\n\n최대 반복 횟수 %d회 끝\n", N); // 실패	//실패 출력
	return 0;
}
// f(x) = e^(x) + x^3
double f(double x)	//대상 함수
{
	return exp(x) + (x*x*x);
}
// f'(x) = e^(x) + 3x^2
double f1(double x)	//대상 함수의 미분 값
{
	return exp(x) + (3*x*x);
}