#include <stdio.h>

int main() {
	int year;
	int month;
	int days = 0;
	int dayOfWeek; 
	char *day [7] = {"��","��","ȭ","��","��","��","��"};
	int monthNor [12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int monthLun [12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	
	//�з°� �޴� �ݺ��� 
	while (true) {
		//�⵵�� ���� �����ͷ� �޴´� 
		printf("�⵵ �Է� : ");
		scanf("%d", &year); 
		//�⵵�� ��¥���� ���ΰ�� 
		if (year == 0 || year < 1900) {
			printf("�����մϴ�"); 
			break;
		}
		printf("�� �Է� : ");
		scanf("%d", &month); 
		//���� ��¥���� ���ΰ�� 
		if (month == 0 || month > 12) {
			printf("�����մϴ�"); 
			break;
		}
		
		//���̺� ��� 
		printf("=================== %d�� %2d�� ===================\n", year, month);
		for (int i = 0; i < 7 /*sizeof(day)/sizeof(char)*/; i++ ) {
		printf("%s\t", day[i]); 	
		}
		printf("\n");
		// ���ϼ� ����ϱ� 
		for (int yearBal = 1900; yearBal < year; yearBal++ ) {
			if (yearBal % 4 == 0 && yearBal % 100 != 0 || yearBal%400 == 0) {
				days = days + 366;
			} else {
				days = days + 365;			
			}
		}
	//	printf("���ϼ�%d\n", days);
		//���ϼ� ����ϱ� 
		for (int monthBal = 1; monthBal<month; monthBal++) {
			if (year % 4 == 0 && year % 100 != 0 || year%400 == 0) {
				days = days + monthLun[monthBal-1];
			} else {
				days = days + monthNor[monthBal-1];			
			}
		}
	//	printf("��+���ϼ�%d\n", days);
		
		//0���� �����ϴ� ���ϼ��� ���ϱ� 
		dayOfWeek = days%7;
	//	printf("%d\n", dayOfWeek);
	
		//�� ù ��¥���ۺκ� ���
		for (int startDate = 0; startDate <= dayOfWeek; startDate++){
			printf("\t");		
		} 
		//������ ��� ����ϱ�
		if (year % 4 == 0 && year % 100 != 0 || year%400 == 0) {
		for (int date = 1; date <= monthLun[month-1]; date+= 7) {
			for (int addDate = 0; addDate < 7; addDate++) {
				if (date + addDate > monthLun[month-1]) {
					break;
					}
					printf("%d\t", date+addDate);
					if ((dayOfWeek+1 + date + addDate) %7 == 0){
					printf("\n");
					}
				}
			}
		//����� ��� ����ϱ� 
		} else {
			for (int date = 1; date <= monthNor[month-1]; date+= 7) {
				for (int addDate = 0; addDate < 7; addDate++) {
					if (date + addDate > monthNor[month-1]) {
						break;
					}
					printf("%d\t", date+addDate);
					if ((dayOfWeek+1 + date + addDate) %7 == 0){
					printf("\n");
					}
				}
			}
		}
		//�����޷� ĭ ���� 
		printf("\n\n\n");
	} 
	return 0;
}

 
