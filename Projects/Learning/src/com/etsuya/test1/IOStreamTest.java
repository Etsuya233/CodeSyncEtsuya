package com.etsuya.test1;

import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintStream;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Scanner;

/**
 * ClassName: IOStreamTest
 * Package: com.etsuya.test1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/21 12:56
 * @Version: 1.0
 */
public class IOStreamTest {
	public static void main(String[] args) throws IOException {
		InetAddress host = InetAddress.getLocalHost();
		Socket socket = new Socket(host, 23321);

		Scanner scan = new Scanner(System.in);
		String msg = scan.nextLine();

		OutputStream os = socket.getOutputStream();
		PrintStream ps = new PrintStream(os);
		ps.println(msg);
		socket.shutdownOutput();

		OutputStream os1 = socket.getOutputStream();
		PrintStream ps1 = new PrintStream(os1);
		ps1.println(msg);
		socket.shutdownOutput();

	}
}
