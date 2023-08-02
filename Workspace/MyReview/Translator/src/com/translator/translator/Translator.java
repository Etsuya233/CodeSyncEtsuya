package com.translator.translator;

import com.translator.complier.Complier;
import com.translator.data.Data;

import java.util.HashMap;
import java.util.Scanner;

/**
 * ClassName: Translator
 * Package: com.translator.translator
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/5 19:37
 * @Version: 1.0
 */
public class Translator {
	public static void main(String[] args) {
		Complier complier = new Complier();
		Scanner scan = new Scanner(System.in);
		String in = scan.nextLine();
		scan.close();
		in = complier.translate(in);
		System.out.println(in);
	}
}
