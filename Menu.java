package seoul;

public class Menu {
	protected void introCity() {
		System.out.println("\"구\" 를 문자로 입력하세요.");
		System.out.println("1.종로구 2.중구 3.용산구 4.성동구 5.광진구\n6.동대문구 7.중랑구 8.성북구 9.강북구 10.도봉구\n11.노원구 12.은평구 13.서대문구 "
				+ "14.마포구 15.양천구\n16.강서구 17.구로구 18.금천구 19.영등포구 20.동작구\n21.관악구 22.서초구 23.강남구 24.송파구 25.강동구");
		System.out.print("->");
	}

	protected void firstMonth() {
		System.out.println("찾는 시작년도 및 월 을 숫자로 입력하세요.");
		System.out.println("ex) 200602");
		System.out.print("->");
	}

	protected void secondsMonth() {
		System.out.println("찾는 종료년도 및 월 을 숫자로 입력하세요.");
		System.out.print("->");
	}

}
