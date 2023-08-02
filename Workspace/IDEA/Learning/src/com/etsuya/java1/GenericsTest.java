package com.etsuya.java1;

/**
 * ClassName: GenericsTest
 * Package: com.etsuya.java1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/9 16:16
 * @Version: 1.0
 */
public class GenericsTest {

}

class Father<T>{
	//Father是一个泛型类，因为名字那里有<>（更详细地，是因为有不确定的类型T）
	public void show(T t){
		System.out.println(t);
	}
}

class SubClass1 extends Father{
	//SubClass1不是泛型类，因为名字那里没有<>
	// （因为继承的是Father，且Father的泛型没有写，所以一律看作Object，这样子类型就确定了，是Object）
}

class SubClass2 extends Father<Integer>{
	//SubClass2不是泛型类，因为名字那里没有<>（因为继承的是Father<Integer>，这样子就没有不确定的类型了）
}

class SubClass3<T> extends Father<T>{
	//SubClass3是泛型类，因为名字那里有<>（有不确定的类型T）
}

class SubClass4<E> extends Father<Integer>{
	//SubClass4是泛型类，因为名字那里有<>，注意：继承的是Father<Integer>，Father继承下来的东西都是明确类型的。
	//但是这里有另外声明了另一个泛型类型E
}