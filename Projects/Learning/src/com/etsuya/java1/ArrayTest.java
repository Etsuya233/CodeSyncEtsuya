package com.etsuya.java1;

import java.util.Random;

public class ArrayTest {
	public static void main(String[] args) {
		Random random = new Random();	//�½�Random����
		random.setSeed(System.currentTimeMillis());	//�����������
		String[][] arr = new String[][]{	//��ʾ��ʼ����ά����
				{"����", "����", "����", "����", "������", "ѿ��", "����", "����", "����", "������"},
				{"����", "�ϼ�", "�й�", "����", "���¹�", "����", "������", "�ߺ�", "����", "̨��"},
				{"��ը��", "�Ժ���", "������", "�Ի��", "���󵱵�", "�Է��������", "��������", "�Բ�Ʒ", "������", "�Դ������"}
		};
		//�������������
		int x = random.nextInt(10), y = random.nextInt(10), z = random.nextInt(10);
		//���
		System.out.println(arr[0][x] + "��" + arr[1][y] + arr[2][z]);
	}
}
