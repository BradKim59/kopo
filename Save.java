package seoul;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class Save {
	public static void csv(String result) {

		File csv = new File("C:\\project\\Test.csv");
		BufferedWriter bw = null;
		try {

			bw = new BufferedWriter(new FileWriter(csv, true));
			bw.write(result);
			bw.newLine();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if (bw != null) {
					bw.flush();
					bw.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
}
