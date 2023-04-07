package com.etsuya.java5;

import javax.xml.crypto.Data;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.SocketException;

/**
 * ClassName: UDPTest1
 * Package: com.etsuya.java5
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/22 22:26
 * @Version: 1.0
 */
public class UDPTest1 {
	public static void main(String[] args) {
		//1，创建一个DatagramSocket用来接受（或发出）数据。
		DatagramSocket datagramSocket = null;
		try {
			//2，创建对象（接收器）
			datagramSocket = new DatagramSocket(13652);
			//3，创建data数组以来转载数据（信息的载体）
			//为什么是1026*64呢？这是因为这正好是64K（UDP数据的一般最大限制）
			byte[] data = new byte[1024 * 64];
			//4，创建DatagramPacket对象以来作为载体（信息载体的马甲）
			DatagramPacket datagramPacket = new DatagramPacket(data, data.length);
			//5，使用datagramSocket的receive()方法来接受信息，DatagramPacket作为参数
			datagramSocket.receive(datagramPacket);
			//6，输出信息
			//为什么使用datagramPacket.getLength()，而不使用data.length？
			//这是因为该方法返回的是数据的真实大小，而data.length返回的是数组长度即1024*64
			String str = new String(data, 0, datagramPacket.getLength());
			System.out.println(str);
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if(datagramSocket != null)
				datagramSocket.close();
		}
	}
}
