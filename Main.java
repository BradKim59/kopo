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
				+"서울 " + city +" (단위 : 만원)" + "\n" 
				+"------------------------------------------------------------------------------------------------------" +"\n"
				+"   평수" + "\t|\t" + "40 평형 이하" +"\t"+"|"+"\t"  + "41~85 평형"
				+"\t"+"|" +"\t" + "86~135 평형"  +"\t"+"|"+ "\t" + "136평형 이상"+"\n"
				+"년월\t" + "|중하위값" +"\t" + "중위값" +"\t" + "중상위값" +"\t"  +"|중하위값" +"\t" + "중위값" +"\t" + "중상위값"  +"\t"+ "|중하위값" 
				+"\t" + "중위값" +"\t" + "중상위값" +"\t"  +"|중하위값" +"\t" + "중위값" +"\t" + "중상위값"+"\n"
				+"------------------------------------------------------------------------------------------------------");
		String category = "" + "서울 " + city + "(단위 : 만원)" + "\n" + "," + "," + "40 평형 이하" + "," + "," + ","
				+ "41~85 평형" + "," + "," + "," + "86~135 평형" + "," + "," + "," + "136평형 이상" + "\n" + "년월" + "," + "중하위값"
				+ "," + "중위값" + "," + "중상위값" + "," + "중하위값" + "," + "중위값" + "," + "중상위값" + "," + "중하위값" + "," + "중위값"
				+ "," + "중상위값" + "," + "중하위값" + "," + "중위값" + "," + "중상위값";
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
