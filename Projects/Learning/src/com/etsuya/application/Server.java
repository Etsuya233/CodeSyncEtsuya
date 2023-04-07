package com.etsuya.application;

import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * ClassName: Server
 * Package: com.etsuya.application
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/19 22:31
 * @Version: 1.0
 */
public class Server {
	static ArrayList<Socket> online = new ArrayList<Socket>();

	public static void main(String[] args) throws IOException {

		int port = 8964;
		ServerSocket serverSocket = new ServerSocket(port);

		System.out.println("Server Running...");

		while(true){
			Socket accept = serverSocket.accept();

			InputStream is = accept.getInputStream();
			Scanner readName = new Scanner(is);
			String name = readName.nextLine();
//			readName.close();
//			accept.shutdownInput();

			//将加入用户的Socket放入online列表中
			online.add(accept);
			//针对每一个对话，都提供一个MessageHandler线程来转发与接收消息
			MessageHandler messageHandler = new MessageHandler(accept, name);
			messageHandler.start();
		}
	}


	//内部静态类
	static class MessageHandler extends Thread{
		String ip;
		Socket socket;
		String name;

		public MessageHandler(Socket socket, String name){
			super();
			this.name = name;
			this.socket = socket;
		}

		public void run(){
			ip = socket.getInetAddress().getHostAddress();

			SendToOther(ip + " (" + name + ") " + " is online.");

			try {
				InputStream is = socket.getInputStream();
				InputStreamReader isr = new InputStreamReader(is);
				BufferedReader br = new BufferedReader(isr);
				//readLine进行整行输入
				String msg;
				while ((msg = br.readLine()) != null) {
					SendToOther(msg);
				}
				SendToOther(ip + " (" + name + ") " + " is offline.");
			} catch (IOException e) {
				//若无法运行到try内最后一句，则判定为掉线
				SendToOther(ip + " (" + name + ") " + " is offline accidentally.");
			} finally {
				online.remove(socket);
			}

		}

		//信息转发器
		void SendToOther(String msg) {
			try {
				for(Socket people : online){
					OutputStream os = people.getOutputStream();
					PrintStream ps = new PrintStream(os);
					ps.println(ip + " (" + name + ") " + ": " + msg);
				}
			} catch (IOException e){
				e.printStackTrace();
			}
		}
	}
}
