package com.etsuya.application;

import java.io.*;
import java.net.InetAddress;
import java.net.Socket;
import java.util.Scanner;

/**
 * ClassName: Client
 * Package: com.etsuya.application
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/19 22:31
 * @Version: 1.0
 */
public class Client {
	public static void main(String[] args) throws IOException, InterruptedException {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter your name: ");
		String name = scan.nextLine();
//		scan.close();

		InetAddress inetAddress = InetAddress.getLocalHost();
		int port = 8964;
		Socket socket = new Socket(inetAddress, port);

		Receive receive = new Receive(socket);
		Send send = new Send(socket);

		OutputStream os = socket.getOutputStream();
		PrintStream ps = new PrintStream(os);
		ps.println(name);
//		socket.shutdownOutput();


		receive.start();
		send.start();
		send.join();

		socket.close();
		scan.close();
	}

}

class Receive extends Thread{
	Socket socket;

	public Receive(Socket socket) {
		this.socket = socket;
	}

	@Override
	public void run() {
		try {
			InputStream is = socket.getInputStream();
//			//TODO 正确的流
//			Scanner input = new Scanner(is);
//
//			while (input.hasNextLine()) {
//				String line = input.nextLine();
//				System.out.println(line);
//			}

//			//TODO 不正确的流
			InputStreamReader isr = new InputStreamReader(is);
			BufferedReader br = new BufferedReader(isr);
			String msg;
			while((msg = br.readLine()) != null){
				System.out.println(msg);
			}
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			//TODO 需不需要关闭流
		}
	}
}

class Send extends Thread{
	Socket socket;

	public Send(Socket socket) {
		this.socket = socket;
	}

	@Override
	public void run() {
		Scanner scan = new Scanner(System.in);
		String msg;
		try {
			OutputStream os = socket.getOutputStream();
			PrintStream ps = new PrintStream(os);
			while (true) {
				msg = scan.nextLine();
				if(msg.equals("!Offline")){
					break;
				} else {
					ps.println(msg);
				}
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
		scan.close();
	}
}