package com.etsuya.java4;

import org.junit.Test;

import java.io.*;
import java.net.InetAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.UnknownHostException;

/**
 * ClassName: Net
 * Package: com.etsuya.java4
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/18 16:07
 * @Version: 1.0
 */
public class Net {
	//实现文件从客户端传输到服务端，服务端接受文件后给客户端反馈
	@Test
	public void server() {
		//提前创建好流变量及文件对象，服务器套接字等待请求通过网络传入。
		File file = new File("D:\\Etsuya\\Programming\\Test\\Receive\\hello_receive.txt");
		int port = 8989;
		ServerSocket serverSocket = null;
		FileOutputStream fos = null;
		InputStream is = null;
		OutputStream os = null;
		Socket socket = null;

		try {
			//1，在服务端实现TCP服务器套接字
			serverSocket = new ServerSocket(port);
			//2，服务端调用accept()侦听并接受到此套接字的连接，返回一个Socket对象
			socket = serverSocket.accept();
			//3，获取客户端的信息
			System.out.println("Received " + socket.getInetAddress().getHostAddress() + "'s request.");
			System.out.println("Connecting ...");

			//4，传输文件
			//①返回此套接字的输入流，可以用于接收消息
			is = socket.getInputStream();
			fos = new FileOutputStream(file);
			byte[] buffer = new byte[64];
			int len;
			while((len = is.read(buffer)) != -1){
				fos.write(buffer, 0, len);
			}
			//②返回 EOF（文件结束符），导致接受的那边得到len=-1
			socket.shutdownInput();
			System.out.println("File received!");
			//5，服务端发出反馈
			os = socket.getOutputStream();
			os.write("We have received your picture! We'll check it as soon as possible!".getBytes());

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			System.out.println("Disconnecting...");
			try {
				if(fos != null) {
					fos.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(is != null) {
					is.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(socket != null) {
					socket.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(serverSocket != null) {
					serverSocket.close();
				}
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(os != null)
					os.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		System.out.println("Disconnected.");
	}

	@Test
	public void client() {
		//1，客户端初始化
		File file = new File("D:\\Etsuya\\Programming\\Test\\Receive\\hello.txt");
		InetAddress inetAddress = null;
		int port = 8989;
		Socket socket = null;
		FileInputStream fis = null;
		OutputStream os = null;
		InputStream is = null;
		ByteArrayOutputStream baos = null;

		try {
			//2，创建套接字，实现客户端套接字
			inetAddress = InetAddress.getByName("127.0.0.1");
			socket = new Socket(inetAddress, 8989);
			fis = new FileInputStream(file);
			os = socket.getOutputStream();
			byte[] buffer = new byte[64];
			int len;
			while((len = fis.read(buffer)) != -1){
				os.write(buffer, 0, len);
			}
			socket.shutdownOutput();
			is = socket.getInputStream();

			//3，为什么用ByteArrayOutputStream？ 为了解决乱码问题（byte数组太小，装汉字的话可能会截断并输出导致乱码）
			//注意其使用方法！
			baos = new ByteArrayOutputStream();
			while((len = is.read(buffer)) != -1){
				baos.write(buffer, 0, len);
			}
			System.out.println("Message from server: " + baos.toString());

		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			try {
				if(os != null)
					os.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(fis != null)
					fis.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(baos != null)
					baos.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(is != null)
					is.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
		System.out.println("Sent");
	}
}
