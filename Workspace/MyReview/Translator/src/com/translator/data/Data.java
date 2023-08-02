package com.translator.data;

/**
 * ClassName: Data
 * Package: com.translator.data
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/5 19:03
 * @Version: 1.0
 */
public class Data {
	private static char alphabet[][] = new char[][]{
			{'a', 'e'},
			{'b', 'p'},
			{'d', 'p'},
			{'e', 'a'},
			{'f', 't'},
			{'g', 'l'},
			{'h', 'k'},
			{'i', 'o'},
			{'k', 'h'},
			{'l', 'g'},
			{'m', 'w'},
			{'n', 'u'},
			{'o', 'i'},
			{'p', 'b'},
			{'q', 'd'},
			{'t', 'f'},
			{'u', 'n'},
			{'w', 'm'}
	};

	private static String words[][] = new String[][]{
			{"I", "eso"},
			{"the", "la"},
	};

	public static char[][] getAlphabet() {
		return alphabet;
	}

	public static String[][] getWords() {
		return words;
	}
}
