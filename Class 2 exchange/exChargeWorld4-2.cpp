#include <stdio.h>
	//������ ����� 
	const float RATE_USD = 1233.1; //�޷�ȯ�� 
	const float RATE_YEN = 9.844; //��ȭȯ�� 
	const float RATE_EURO = 1342.64; //����ȯ�� 
	const float RATE_RMB = 193.54; //�߱�ȯ�� 
	const float RATE_GBP = 1605.03; //����ȯ��
	float RATE = 0;//ȯ�� ������ ���� 
	int returnWon = 0;
	int outputFinal = 0; //������ ����ȯ�ϱ� 
	float output = 0; //�޷� ȯ���� �Ǽ���
	int inputWon = 50000; //���� 
	int returnWon1000; 
	int returnWon500; 
	int returnWon100; 
	int returnWon50; 
	int returnWon10; 
	int selectCon;
	char *curren;
	
int SelectN (int SelectCon) {
	switch (SelectCon) {
	//�޷� 
	case 1 : 
	RATE = RATE_USD;
	break;
	
	//��ȭ 
	case 2 : 
	RATE = RATE_YEN; //��ȭ�� 100�� �������� ȯ����  ȯ��ȴ�. 
	break;
	
	//���� 
	case 3 : 
	RATE = RATE_EURO;
	break;
	
	//��ȭ  
	case 4 : 
	RATE = RATE_RMB;
	break;
	
	//���� 
	case 5 : 
	RATE = RATE_GBP;
	break;
	}
	output = inputWon / RATE; //ȯ����� 
	outputFinal = output; //ȯ���� ������ ����ȯ 
	return outputFinal;
}

void SelectC (int SelectCon) {
	switch (selectCon) {
	case 1 :
		printf("�޷�\n");
		break;
	case 2 :
		printf("��ȭ\n");
		break;
	case 3 :
		printf("����\n");
		break;
	case 4 :
		printf("����\n");
		break;
	case 5 :
		printf("�Ŀ��\n");
		break;
	} 
}
int changeCal (int SelectCon) {
	if (selectCon == 1 || selectCon == 3 || selectCon == 4 || selectCon == 5) {
		returnWon = ((int)(output*100)%100)*RATE/100; 
		returnWon = returnWon/10*10;
	} else if (selectCon == 2) {	
		returnWon = ((int)(output*100)%100)*RATE; 
		returnWon = returnWon/10*10;
	}
}

void changeQ(int returnWon) {
	returnWon1000 = returnWon/1000;
	returnWon500 = returnWon%1000/500;
	returnWon100 = returnWon%1000%500/100;
	returnWon50 = returnWon%1000%500%100/50;
	returnWon10 = returnWon%1000%500%100%50/10;
	printf("1000�� %d��, 500��%d��, 100��%d��, 50��%d��, 10��%d�� \n", returnWon1000, returnWon500, returnWon100, returnWon50, returnWon10);
} 

void outputCurrency(int selectCon, int outputFinal) {
	int returnD1000 = outputFinal/1000;
	int returnD500 = outputFinal%1000/500;
	int returnD100 = outputFinal%1000%500/100;
	int returnD50 = outputFinal%1000%500%100/50;
	int returnD20 = outputFinal%1000%500%100%50/20;
	int returnD10 = outputFinal%1000%500%100%50%20/10;
	int return20D10 = outputFinal%1000%500%100%50/10; //20���� ���� �� 
	int returnD5 = outputFinal%1000%500%100%50%20%10/5;
	int return20D5 = outputFinal%1000%500%100%50%10/5; //20���� ���� �� 
	int returnD2 = outputFinal%1000%500%100%50%20%10%5/2;
	int returnD1 = outputFinal%1000%500%100%50%20%10%5%2;
	int return2D1 = outputFinal%1000%500%100%50%20%10%5; //2 ���� ���� �� 
	int return202D1 = outputFinal%1000%500%100%50%10%5; //2, 20 ���� ���� �� 
	if (selectCon == 1 || selectCon == 3) {//�޷�, ���� 
	printf("100%s %d��, 50%s %d��, 20%s %d��, 10%s %d��, 5%s %d��, 2%s %d��, 1%s %d��  \n"
	, curren, returnD100, curren, returnD50, curren, returnD20, curren, returnD10, curren, returnD5, curren, returnD2, curren, returnD1);
	} else if (selectCon == 2) {//��ȭ 
	printf("1000%s %d��, 500%s %d��, 100%s %d��, 50%s %d��, 10%s %d��, 5%s %d��,1%s %d�� \n"
	, curren, returnD1000, curren, returnD500, curren, returnD100, curren, returnD50, curren, return20D10, curren, return20D5, curren, return202D1);
	} else if (selectCon == 4) {//���� 
	printf("100%s %d��, 50%s %d��, 20%s %d��, 10%s %d��, 5%s %d��, 1%s %d�� \n"
	, curren, returnD100, curren, returnD50, curren, returnD20, curren, returnD10, curren, returnD5, curren, return2D1);
	} else if (selectCon == 5) {//�Ŀ�� 
	printf("50%s %d��, 20%s %d��, 10%s %d��, 5%s %d��, 1%s %d�� \n"
	, curren, returnD50, curren, returnD20, curren, returnD10, curren, returnD5, curren, return2D1);
	}
}
char currency (int selectCon) {
	switch(selectCon) {
		case 1 :
			curren = "�޷�";
			break;
		case 2 :
			curren = "��";
			break;
		case 3 :
			curren = "����";
			break;
		case 4 :
			curren = "����";
			break;
		case 5 :
			curren = "�Ŀ��";
			break;
	}
	return *curren; 
}


int main() {
	//������ �Էº� 
	printf("ȯ���� ���ϴ� ��ȭ �ݾ��� �Է��ϼ���(��ȭ) : ");
	scanf("%d", &inputWon);
	do {
		printf("ȯ���� ���ϴ� ��ȭ�� ���� �ϼ���(1:USD, 2:YEN, 3:EURO, 4:RMB, 5:GBP) : ");
		scanf("%d", &selectCon); 
	} while (selectCon<1 || selectCon>5);
	
	SelectN(selectCon);//���� �� ȯ�� ���� 
	printf("ȯ�� ���� %d�� ->%d ", inputWon, outputFinal);
	SelectC(selectCon);//������ ��ȭ�̸� ��� 

	currency (selectCon);//��ȭ �������ϴ� �Լ� 
	outputCurrency(selectCon, outputFinal);//��ȭ ����з� �Լ� 
	
	changeCal(selectCon);//���� �� �ܵ���� 
	printf("�Ž����� : %d��\n", returnWon);
	changeQ(returnWon);//�Ž����� ������� 

	return 0;
}
		
