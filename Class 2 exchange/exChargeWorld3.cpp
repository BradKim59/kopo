#include <stdio.h>

	const float RATE_USD = 1233.1; //�޷�ȯ�� 
	const float RATE_YEN = 984.4; //��ȭȯ�� 
	const float RATE_EURO = 1342.64; //����ȯ�� 
	const float RATE_RMB = 193.54; //�߱�ȯ�� 
	const float RATE_GBP = 1605.03; //����ȯ��
	float RATE = 0;//ȯ�� ������ ���� 
	int inputWon = 50000; //���� 
	int returnWon = 0;
	int outputFinal = 0; //������ ����ȯ�ϱ� 
	float output = 0; //�޷� ȯ���� �Ǽ���
	int returnWon1000; 
	int returnWon500; 
	int returnWon100; 
	int returnWon50; 
	int returnWon10; 
	int selectCon;

void Cal (float RATE){
	output = inputWon / RATE; //ȯ����� 
	outputFinal = output; //ȯ���� ������ ����ȯ 
	returnWon = output*100;  // 40.54 *100
	returnWon = returnWon%100; // 4055%100 = 54
	returnWon = returnWon*RATE /100; // 54*ȯ��/100 = 665
	returnWon = returnWon/10*10; // 1���ڸ� ����
}

void Cal100 (float RATE){
	//100���������� ������ ������ �ڸ��� �ٽ� 100 ���ؼ� �÷��� 
	output = (inputWon / RATE)*100; //ȯ����� 
	outputFinal = output; //5079
	returnWon = output*100; //5079.23 �� �ڸ��� �츲 507923
	returnWon = returnWon%100; // 23
	//��ȭ ���� ��, 1�������� �ƴ϶�, 100�� �������� ���ؼ� ����ؾ� �Ѵ�. 
	returnWon = returnWon*RATE /100; //23*984.4/100 = 226.412 
	returnWon = returnWon/10*10; // 1���ڸ� ���� 220
}


void Change (int returnWon){
	returnWon1000 = returnWon/1000;
	returnWon = returnWon - returnWon1000 * 1000;
	returnWon500 = returnWon/500;
	returnWon = returnWon - returnWon500 * 500;
	returnWon100 = returnWon/100;
	returnWon = returnWon - returnWon100 * 100;
	returnWon50 = returnWon/50;
	returnWon = returnWon - returnWon50 * 50;
	returnWon10 = returnWon/10;
	printf("1000�� %d��, 500��%d��, 100��%d��, 50��%d��, 50��%d�� \n", returnWon1000, returnWon500, returnWon100, returnWon50, returnWon10);
}

int main() {

	printf("ȯ���� ���ϴ� ��ȭ �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputWon);
	do {
		printf("ȯ���� ���ϴ� ��ȭ�� ���� �ϼ���(1:USD, 2:YEN, 3:EURO, 4:RMB, 5:GBP) : ");
		scanf("%d", &selectCon); 
		} while (selectCon<1 || selectCon>5);
			switch (selectCon) {
			
			//�޷� 
			case 1 : {
			RATE = RATE_USD;
			Cal(RATE);
			printf("�޷�ȯ�� ���� %d�� ->%d�޷�ȯ��\n", inputWon, outputFinal);
			printf("�Ž����� : %d��\n", returnWon);
			break;
			}
			
			//��ȭ 
			case 2 : {
			RATE = RATE_YEN; //��ȭ�� 100�� �������� ȯ����  ȯ��ȴ�. 
			Cal100(RATE);
			printf("��ȭȯ�� ���� %d�� ->%d��ȭȯ��\n", inputWon, outputFinal);
			printf("�Ž����� : %d��\n", returnWon);
			break;
			}
			
			//���� 
			case 3 : {
			RATE = RATE_EURO;
			Cal(RATE);
			printf("����ȯ�� ���� %d�� ->%d����ȯ��\n", inputWon, outputFinal);
			printf("�Ž����� : %d��\n", returnWon);
			break;
			}
			
			//��ȭ  
			case 4 : {
			RATE = RATE_RMB;
			Cal(RATE);
			printf("��ȭȯ�� ���� %d�� ->%d��ȭȯ��\n", inputWon, outputFinal);
			printf("�Ž����� : %d��\n", returnWon);
			break;
			}
			
			//���� 
			case 5 : {
			RATE = RATE_GBP;
			Cal(RATE);
			printf("����ȯ�� ���� %d�� ->%d����ȯ��\n", inputWon, outputFinal);
			printf("�Ž����� : %d��\n", returnWon);
			break;
			}		
		}	
		Change(returnWon);
		return 0;	
	}
		
