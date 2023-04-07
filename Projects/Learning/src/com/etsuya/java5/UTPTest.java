package com.etsuya.java5;

import java.io.IOException;
import java.net.*;

/**
 * ClassName: UTPTest
 * Package: com.etsuya.java5
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/22 22:10
 * @Version: 1.0
 */
public class UTPTest {
	public static void main(String[] args) {
		//1，创建一个DatagramSocket用来接受（或发出）数据。
		DatagramSocket datagramSocket = null;
		try {
			//2，创建DatagramSocket对象（发送器）
			datagramSocket = new DatagramSocket();
			//3，创建要发出的资源（一定要是byte数组）（信息的载体）
			byte data[] = "this is a message".getBytes();
			//4，创建数据包（信息载体的马甲）
			DatagramPacket datagramPacket = new DatagramPacket(data, 0, data.length, InetAddress.getLocalHost(), 13652);
			//5，使用DatagramSocket的方法来发送数据（发送！！！）
			datagramSocket.send(datagramPacket);
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if(datagramSocket != null)
				datagramSocket.close();
		}
	}
}
