package com.etsuya.test1;

import com.etsuya.application.Server;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

/**
 * ClassName: IOStream
 * Package: com.etsuya.test1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/21 12:57
 * @Version: 1.0
 */
public class IOStream {
	public static void main(String[] args) throws IOException {
		ServerSocket serverSocket = new ServerSocket(23321);
		Socket accept = serverSocket.accept();

		InputStream is = accept.getInputStream();
		InputStreamReader isr = new InputStreamReader(is);
		BufferedReader br = new BufferedReader(isr);

		String msg;
		while((msg = br.readLine()) != null){
			System.out.println(msg);
		}

	}
}
