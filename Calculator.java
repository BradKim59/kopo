package seoul;

import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Collections;

public class Calculator {
	static ArrayList<String> raw = new ArrayList<String>(); // split으로 나눈 배열
	static ArrayList<String> list4 = new ArrayList<String>(); // 거래금액 "," 지우기
	static ArrayList<String> sortRegion = new ArrayList<String>(); // 구 정보만 뽑아온 배열
	static ArrayList<String> sortMonth = new ArrayList<String>(); // 구 다음 월별 정보 뽑아온 배열
	static ArrayList<String> sizeValue = new ArrayList<String>(); // 평형, 거래금액 배열

	public void calc(String[] args) {
		ArrayList<String> list1 = new ArrayList<String>(); // 기본 배열
		ArrayList<String> list2 = new ArrayList<String>(); // 컴마 @로 변경
		ArrayList<String> list3 = new ArrayList<String>(); // @로 문자열 자르기

		BufferedReader br = null;
		String line;
		Reader.csvReader(args);
		try {
			br = new BufferedReader(new FileReader("C:\\project\\listout.csv"));
			while ((line = br.readLine()) != null) {
				list1.add(line);
			}
			for (int i = 17; i < list1.size(); i++) {
				String comma = list1.get(i).replaceAll("\",\"", "@");
				list2.add(comma);
				// System.out.println(comma);
			}
			for (int i = 0; i < list2.size(); i++) {
				String collon = list2.get(i).replaceAll("\"", "");
				list3.add(collon);
			} // System.out.println(list3);
			for (int i = 0; i < list3.size(); i++) {
				String[] arr = list3.get(i).replaceAll(",", "").split("@");
				list4.add(arr[0] + "," + arr[5] + "," + arr[6] + "," + arr[8]);
			} // System.out.println(list4);

		} catch (Exception e) {
			e.printStackTrace();
			// TODO: handle exception
		}
	}

	public void selectCity(String city) {
		for (int i = 0; i < list4.size(); i++) {
			if (list4.get(i).contains(city)) {// 구별로 검색하기
				sortRegion.add(list4.get(i));
			}
		}
	}

	public void selectMonth(int month1, int month2) { // 기간 별 배열 출력
		for (int j = month1; j <= month2; j++) {
			for (int i = 0; i < sortRegion.size(); i++) {
				if (sortRegion.get(i).contains(Integer.toString(j))) {
					sortMonth.add(sortRegion.get(i));
				}
			}
		}
	}

	String intTypeArr(int month1, int month2, String city) { // 도시, 월까지 sorting
		ArrayList<Integer> lower40 = new ArrayList<Integer>(); // 40평 이하 거래금액
		ArrayList<Integer> lower85 = new ArrayList<Integer>(); // 85평 이하
		ArrayList<Integer> lower135 = new ArrayList<Integer>(); // 135평 이하
		ArrayList<Integer> upper135 = new ArrayList<Integer>(); // 135평 이상
		String[] arr = null;
		for (int i = 0; i < sortMonth.size(); i++) {
			arr = sortMonth.get(i).split(","); // 1번 평형, 2번 날짜, 3번 거래금액
			if (Double.parseDouble(arr[2]) == month1) { // 날짜 일치 확인
				for (int j = 0; j < arr.length; j++) {
					if (Double.parseDouble(arr[1]) <= 40.0) {
						lower40.add(Integer.parseInt(arr[3]));
					} else if (Double.parseDouble(arr[1]) <= 85.0 && Double.parseDouble(arr[3]) > 40.0) {
						lower85.add(Integer.parseInt(arr[3]));
					} else if (Double.parseDouble(arr[1]) <= 135.0 && Double.parseDouble(arr[3]) > 85.0) {
						lower135.add(Integer.parseInt(arr[3]));
					} else if (Double.parseDouble(arr[1]) > 135.0) {
						upper135.add(Integer.parseInt(arr[3]));
					} else {
						System.out.println("error");
					}
				}
			} else {
				continue;
			}
		}
		System.out.println(month1 + "\t" +(int)get25Quantile(lower40)+"\t"+ (int)getMedian(lower40) + "\t"+(int)get75Quantile(lower40)+"\t"
				+ (int)get25Quantile(lower85)+"\t"+ (int)getMedian(lower85) + "\t"+(int)get75Quantile(lower85)+"\t"
				+ (int)get25Quantile(lower135)+"\t"+ (int)getMedian(lower135) +"\t"+ (int)get75Quantile(lower135)+"\t"
				+ (int)get25Quantile(upper135)+"\t"+ (int)getMedian(upper135) +"\t" +(int)get75Quantile(upper135));
		String result = "" + month1 + "," 
				+ get25Quantile(lower40)+","+ getMedian(lower40) + ","+get75Quantile(lower40)+","
				+ get25Quantile(lower85)+"," + getMedian(lower85) + ","+get75Quantile(lower85)+","
				+ get25Quantile(lower135)+"," + getMedian(lower135)	+ "," + get75Quantile(lower135)+","
				+ get25Quantile(upper135)+","+ getMedian(upper135)+","+ get75Quantile(upper135)+",";
		return result;
	}

	public double getMedian(ArrayList<Integer> arrayInt) { // 중위값 구하기
		Collections.sort(arrayInt);// 오름차순 정렬
		int size = arrayInt.size();
		double result = 0;
		if (size == 0) {
			return result;
		} else if (size == 1) {
			return arrayInt.get(0);
		} else if (size % 2 == 0) { // 배열크기가 짝수일경우
			int m = size / 2;
			int n = size / 2 - 1;
			result = (double)((arrayInt.get(m) + arrayInt.get(n)) / 2); // 중앙값 2개의 평균
		} else { // 배열크기가 홀수인경우
			int m = size / 2;
			result = arrayInt.get(m); // 중앙값
		}
		return result;
	}
	
	public double get25Quantile(ArrayList<Integer> arrayInt) { // 하위값 구하기
		Collections.sort(arrayInt);// 오름차순 정렬
		double size = 0.25*(arrayInt.size()-1);
		int lower = (int)Math.floor(size);
		if (lower < 0) {
			return 0;
		}
		if (lower >= arrayInt.size()-2) { // 배열이 1개일때
			return arrayInt.get(0);
		}
		double fraction = size - lower;
		double result = arrayInt.get(lower) + (0.25*(arrayInt.get(lower+1)-arrayInt.get(lower)));
		return result;
	}
	
	public double get75Quantile(ArrayList<Integer> arrayInt) { // 상위값 구하기
		Collections.sort(arrayInt);// 오름차순 정렬
		double size = 0.75*(arrayInt.size()-1);
		int lower = (int)Math.floor(size);
		if (lower < 0) {
			return 0;
		}
		if (lower >= arrayInt.size()-1) { // 배열이 1개일때
			return arrayInt.get(0);
		}
		double fraction = size - lower;
		double result = arrayInt.get(lower) +(0.75*(arrayInt.get(lower+1)-arrayInt.get(lower)));
		return result;
	}

}
