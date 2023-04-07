package com.etsuya.java4;

import org.junit.Test;

import java.io.*;
import java.net.*;
import java.util.Scanner;

/**
 * ClassName: NetReview
 * Package: com.etsuya.java4
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/19 21:36
 * @Version: 1.0
 */
public class NetReview {
	@Test
	public void server() throws IOException {
	    int port = 12535;
		ServerSocket serverSocket = new ServerSocket(port);

		Socket socket = serverSocket.accept();

		InputStream inputStream = socket.getInputStream();
		ByteArrayOutputStream baos = new ByteArrayOutputStream();
		byte[] buffer = new byte[8];
		int len;
		while((len = inputStream.read(buffer)) != -1){
			baos.write(buffer, 0, len);
		}
		System.out.println("Message Received: " + baos.toString());
		socket.shutdownInput();

		baos.close();
		inputStream.close();
		socket.close();
	}

	@Test
	public void client() throws IOException {
		InetAddress localHost = InetAddress.getLocalHost();
		Socket socket = new Socket(localHost, 12535);

		OutputStream os = socket.getOutputStream();

		System.out.println("Please enter your message: ");
		Scanner scan = new Scanner(System.in);
		os.write(scan.next().getBytes());
		scan.close();
		socket.shutdownOutput();

		os.close();
		socket.close();
	}
}
