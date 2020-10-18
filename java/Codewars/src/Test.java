import java.util.Arrays;
import java.util.stream.*;

public class Test {

	// In this little assignment you are given a string
	// of space separated numbers, and have to return the
	// highest and lowest number

	public static void main(String[] args) {

		System.out.println(highAndLow("1 2 3 4 5")); // return "5 1"
		System.out.println(toCamelCase("the-Stealth-Warrior"));

		System.out.println("Digital root " + digital_root(456));

		System.out.println(validate("1741"));
		
		solution("abcde");

	}

	static String highAndLow(String numbers) {
		// Code here or
		int high = 2, low = 9;

		for (var i : numbers.split(" ")) {
			high = high < Integer.parseInt(i) ? high = Integer.parseInt(i) : high;
			low = low > Integer.parseInt(i) ? low = Integer.parseInt(i) : low;
		}
		return String.format("%d %d", high, low);
	}

	static String toCamelCase(String s) {
		String result = "";
		var str = s.split("(\\_|\\s|\\W)");
		for (int i = 0; i < str.length; i++)
			result += i != 0 ? Character.toUpperCase(str[i].charAt(0)) + str[i].substring(1) : str[i];
		return result;
	}

	public static int digital_root(int n) {
		/*
		 * final int result = String.valueOf(n).chars().reduce(0, (acc, curr) -> acc +
		 * (curr - '0')); return result < 10 ? result : digital_root(result);
		 */
		var num = String.valueOf(n);
		int sum = 0;
		if (num.length() == 1)
			return n;
		for (var str : num.split(""))
			sum += Integer.parseInt(str);

		return String.valueOf(sum).length() > 1 ? digital_root(sum) : sum;
	}

	public static boolean validate(String n) {

		var n1 = n.split("");
		for (var i = n1.length - 2; i >= 0; i -= 2) {
			var res = String.valueOf(Integer.parseInt(n1[i]) * 2).split("");
			n1[i] = res.length > 1 ? String.valueOf(Integer.parseInt(res[0]) + Integer.parseInt(res[1])) : res[0];
		}
		int sum = Arrays.asList(n1).stream().mapToInt(Integer::parseInt).sum();
		System.out.println(sum);
		return sum % 10 == 0 || sum % 10 == 10;
	}

	public static String[] solution(String s) {
		//or split((?<=\\G.{2}))
		s =s.length() % 2 == 1 ? s+"_" : "";
		String t[] = new String[s.length() / 2];
		int index = 0;
		for (int i = 0; i < s.length(); i += 2) {
			t[index] = s.substring(i, i + 2);
			++index;
		}
		return t;
	}
}
