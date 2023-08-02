package com.etsuya.java1;

import java.util.Random;

public class ArrayTest {
	public static void main(String[] args) {
		Random random = new Random();	//新建Random对象
		random.setSeed(System.currentTimeMillis());	//设下随机种子
		String[][] arr = new String[][]{	//显示初始化二维数组
				{"张三", "李四", "徐五", "老六", "琪亚娜", "芽衣", "浮华", "二狗", "儿子", "特兰普"},
				{"美国", "南极", "中国", "巴西", "地下沟", "肚子", "田纳西", "芜湖", "蚌埠", "台湾"},
				{"吃炸鸡", "吃汉堡", "吃薯条", "吃火锅", "吃麦当当", "吃疯狂星期四", "吃煲仔粥", "吃补品", "吃香香", "吃大嘴巴子"}
		};
		//生成三个随机数
		int x = random.nextInt(10), y = random.nextInt(10), z = random.nextInt(10);
		//输出
		System.out.println(arr[0][x] + "在" + arr[1][y] + arr[2][z]);
	}
}
