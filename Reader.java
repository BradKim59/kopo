package seoul;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;

public class Reader {
	static ArrayList<String> list = new ArrayList<String>();

	public static void csvReader(String[] args) {
		File dir = new File("C:\\project");
		File[] files = dir.listFiles();
		String line;
		try {
			for (int i = 0; i < files.length; i++) { // csv 파일 개수 만큼
				int cnt = 0;
				BufferedReader br = new BufferedReader(new FileReader(files[i]));
				for (int t = 1; (line = br.readLine()) != null; t++) {
					if (cnt > 16) { // 파일 17라인부터 읽어들일 수 있도록
						list.add(line + "\n");
					}
					cnt++;
				}
			}
			// for combine csvfile
			FileWriter writer = new FileWriter("C:\\project\\listout.csv", true);
			for (int j = 1; j < list.size(); j++) {
				writer.write(list.get(j));
			}
			writer.close();

		} catch (Exception e) {
			e.printStackTrace();
			// TODO: handle exception
		}
	}
}