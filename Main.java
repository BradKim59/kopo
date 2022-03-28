package seoul;

import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Menu menu = new Menu();
		Save save = new Save();
		Calculator call = new Calculator();
		Scanner scanner = new Scanner(System.in);

		call.calc(args);
		menu.introCity();
		String city = scanner.nextLine();
		call.selectCity(city);
		menu.firstMonth();
		int month1 = scanner.nextInt();
		menu.secondsMonth();
		int month2 = scanner.nextInt();
		call.selectMonth(month1, month2);
		System.out.println(
				"\n"+"======================================================================================================" +"\n" 
				+"���� " + city +" (���� : ����)" + "\n" 
				+"------------------------------------------------------------------------------------------------------" +"\n"
				+"   ���" + "\t|\t" + "40 ���� ����" +"\t"+"|"+"\t"  + "41~85 ����"
				+"\t"+"|" +"\t" + "86~135 ����"  +"\t"+"|"+ "\t" + "136���� �̻�"+"\n"
				+"���\t" + "|��������" +"\t" + "������" +"\t" + "�߻�����" +"\t"  +"|��������" +"\t" + "������" +"\t" + "�߻�����"  +"\t"+ "|��������" 
				+"\t" + "������" +"\t" + "�߻�����" +"\t"  +"|��������" +"\t" + "������" +"\t" + "�߻�����"+"\n"
				+"------------------------------------------------------------------------------------------------------");
		String category = "" + "���� " + city + "(���� : ����)" + "\n" + "," + "," + "40 ���� ����" + "," + "," + ","
				+ "41~85 ����" + "," + "," + "," + "86~135 ����" + "," + "," + "," + "136���� �̻�" + "\n" + "���" + "," + "��������"
				+ "," + "������" + "," + "�߻�����" + "," + "��������" + "," + "������" + "," + "�߻�����" + "," + "��������" + "," + "������"
				+ "," + "�߻�����" + "," + "��������" + "," + "������" + "," + "�߻�����";
		save.csv(category);
		while (month1 <= month2) {
			save.csv(call.intTypeArr(month1, month2, city));
			if (month1 % 100 >= 12) {
				month1 += 88;
			} else {
			}
			month1++;
		}
	}
}
