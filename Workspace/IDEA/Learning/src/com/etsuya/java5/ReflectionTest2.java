package com.etsuya.java5;

import org.junit.Test;

import java.io.*;
import java.lang.annotation.Annotation;
import java.lang.reflect.*;
import java.util.Properties;

/**
 * ClassName: ReflectionTest2
 * Package: com.etsuya.java5
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/24 19:59
 * @Version: 1.0
 */
public class ReflectionTest2 {
	public static void main(String[] args) throws IOException {
		//1，创建流
		InputStream is;
		//2，这句话记住
		is = ClassLoader.getSystemClassLoader().getResourceAsStream("personInfo.properties");
		//3，新建Properties对象
		Properties properties = new Properties();
		//4，加载流
		properties.load(is);
		//5，读取
		String name = properties.getProperty("name");
		String age = properties.getProperty("age");
		System.out.println(name + " " + age);
	}

	@Test
	public void test() throws InstantiationException, IllegalAccessException, NoSuchMethodException, InvocationTargetException {
		Class<Person> clazz = Person.class;
		//方式1：Class类的newInstance()已Deprecated
		Person p1 = clazz.newInstance();
		//方式2：
		Constructor<Person> emptyConstructor = clazz.getDeclaredConstructor();
		Person p2 = emptyConstructor.newInstance();




	}

	//获取属性
	@Test
	public void test2() throws ClassNotFoundException, InvocationTargetException, InstantiationException, IllegalAccessException, NoSuchMethodException, NoSuchFieldException {
		Class<Person> clazz = Person.class;
		Constructor<Person> emptyConstructor = clazz.getDeclaredConstructor();
		Person p1 = emptyConstructor.newInstance();

		//1，获取已声明的属性对象
		Field ageField = clazz.getDeclaredField("age");
		Field innerVoice = clazz.getDeclaredField("innerVoice");
		//2，设置属性的值
		ageField.set(p1, 12);
		//3，设置权限，否则无法修改被修饰为private的属性
		innerVoice.setAccessible(true);
		innerVoice.set(p1, "I wanna fuck you");

		//其他：
		//①获取所有属性：
		//所有属性
		Field[] declaredFields = clazz.getDeclaredFields();
		//仅限public的属性
		Field[] fields = clazz.getFields();
		for(Field field : declaredFields){
			//一条示例： java.lang.String com.etsuya.java5.Person.name
			System.out.println(field);
			//②获取修饰符，数据类型，名字
			//关于为什么直接运行getModifiers().toString()返回的是数字：因为通过数字的特征来获取权限的值
			System.out.println(Modifier.toString(field.getModifiers()));
			System.out.println(field.getType());
			System.out.println(field.getName());
		}
	}
	
	@Test
	public void test3() throws InvocationTargetException, InstantiationException, IllegalAccessException, NoSuchMethodException {
		Class<Person> clazz = Person.class;
		Constructor<Person> emptyConstructor = clazz.getDeclaredConstructor();
		Person p1 = emptyConstructor.newInstance();

		//1，获取指定方法
		Method sayMethod = clazz.getDeclaredMethod("say", String.class, int.class);
		//2，执行方法
		sayMethod.invoke(p1, "WHat?", 4);
		Method fuck = clazz.getDeclaredMethod("fuck");
		fuck.setAccessible(true);
		fuck.invoke(p1);

		//3，其他
		//①获取所有方法
		Method[] declaredMethods = clazz.getDeclaredMethods();
		//②获取详细信息
		System.out.println(sayMethod.getName());
		System.out.println(Modifier.toString(sayMethod.getModifiers()));
		System.out.println(sayMethod.getReturnType());
		Class<?>[] parameterTypes = sayMethod.getParameterTypes();
		Class<?>[] exceptionTypes = sayMethod.getExceptionTypes();
		Annotation[] annotations = sayMethod.getAnnotations();
		//etc
	}

	@Test
	public void test4() throws InvocationTargetException, InstantiationException, IllegalAccessException, NoSuchMethodException {
		Class<Person> clazz = Person.class;
		Constructor<Person> emptyConstructor = clazz.getDeclaredConstructor();
		Person p1 = emptyConstructor.newInstance();

		//获取父类
		System.out.println(clazz.getSuperclass());
		//class java.lang.Object（Class对象）
		//获取带泛型父类
		System.out.println(clazz.getGenericSuperclass());
		//例如：com.atguigu.java1.Creature<java.lang.String>
		//获取包
		System.out.println(clazz.getPackage());
		//package com.etsuya.java5（Package对象）
		//获取接口
		Class<?>[] interfaces = clazz.getInterfaces();
		//获取注解
		Annotation[] annotations = clazz.getAnnotations();
	}

	@Test
	public void test5() throws NoSuchFieldException, IllegalAccessException, NoSuchMethodException, InvocationTargetException {
		Class<Person> clazz = Person.class;
		Field gradeField = clazz.getDeclaredField("grade");
		//static参数列表的obj可以写null
		Object o = gradeField.get(null);
		Method sleepMethod = clazz.getDeclaredMethod("sleep");
		////static参数列表的obj可以写null
		sleepMethod.invoke(null);
	}
}
