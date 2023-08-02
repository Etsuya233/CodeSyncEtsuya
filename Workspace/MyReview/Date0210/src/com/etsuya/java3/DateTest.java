package com.etsuya.java3;

import org.junit.Test;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.time.*;
import java.time.format.DateTimeFormatter;
import java.time.temporal.TemporalAccessor;
import java.util.Calendar;
import java.util.Date;

/**
 * ClassName: DateTest
 * Package: com.etsuya.java3
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/22 21:52
 * @Version: 1.0
 */
public class DateTest {
	@Test
	public void test(){
		Date date1 = new Date();	//空参构造器：获取基于系统当前时间的Date对象(对象创建时间)，且时间不能再变
		System.out.println(date1);	//toString()方法：输出时间，如：Wed Feb 22 21:55:22 SGT 2023
		System.out.println(date1.getTime());	//getTime()方法：返回对应时间的时间戳 long型: 1677074348080

		Date date2 = new Date(1277074348080L);	//long构造器：创建时间戳为传入参数的Date对象
		System.out.println(date2);	//输出时间：如：Mon Jun 21 06:52:28 SGT 2010
	}

	@Test
	public void test2(){
		//java.sql.Date类没有空参的构造器！
	    java.sql.Date date3 = new java.sql.Date(1677074348080L);	//long型构造器
		System.out.println(date3);	//输出时间：2023-02-22，比较简短
	}

	@Test
	public void test3() {
		SimpleDateFormat sdf = new SimpleDateFormat(); //创建一个SimpleDateFormat类，空参，使用默认格式（2023/2/23 下午8:10）
		//接下来格式化Date：日期--》字符串
		Date date1 = new Date(); //获取当前时间对象：Thu Feb 23 20:10:14 SGT 2023
		String str1 = sdf.format(date1); //使用format()方法来格式化Date对象，返回一个格式化后的字符串
		System.out.println(str1); //输出：2023/2/23 下午8:10
		//接下来解析str1：字符串--》日期
		Date date2;
		try {
			date2 = sdf.parse(str1); //parse()函数用来解析字符串至Date对象（使用默认格式），同时方法抛出异常
		} catch (ParseException e) {
			throw new RuntimeException(e);
		}
		System.out.println(date1.equals(date2)); //false：为什么不一样？因为解析的字符串精度较低（没有毫米）

	}

	@Test
	public void test4(){
		Calendar cal = Calendar.getInstance();
		System.out.println(cal);
		int year = cal.get(Calendar.YEAR);
		int month = cal.get(Calendar.MONTH);
		cal.add(Calendar.YEAR, 1);
		Calendar cal1 = Calendar.getInstance();
		System.out.println(cal == cal1);
		System.out.println(cal.get(Calendar.YEAR));
		System.out.println(cal1.get(Calendar.YEAR));

	}
	
	@Test
	public void test5(){
		//实例化：
		//now()静态方法
		LocalDate localDate = LocalDate.now();
		LocalTime localTime = LocalTime.now();
		LocalDateTime localDateTime = LocalDateTime.now();
		//of()方法
		LocalDateTime localDateTime2 = LocalDateTime.of(2022, 12, 14, 12, 12, 12);

		//常用方法：
		//getXxx():获取
		System.out.println(localDateTime2.getHour()); //12
		System.out.println(localDateTime2.getYear()); //2022
		//withXxx():设置基于当前对象的时间并返回新的对象（体现了不可变性）
		LocalDateTime localDateTime3 = localDateTime2.withYear(2021);
		System.out.println(localDateTime3.getYear()); //2021
		//plusXxx(), minusXxx():再当前对象的时间基础之上加或减某一个值并返回新的对象（不可变性）
		LocalDateTime localDateTime4 = localDateTime2.plusYears(1);
		System.out.println(localDateTime4.getYear()); //2023


	}

	@Test
	public void test6(){
		//now()静态方法:返回基于当前格林尼治时间的Instant对象
		Instant instant = Instant.now();
		//ofEpochMilli()静态方法：返回基于long型时间戳得Instant对象
		Instant instant1 = Instant.ofEpochMilli(12123123124214L);
		//toEpochMilli()方法：放回当前Instant对象相应的时间戳
		System.out.println(instant.toEpochMilli());
		//atOffset()方法：设置时区偏移量
		instant.atOffset(ZoneOffset.ofHours(8));


		//方式三：自定义的方式（关注、重点）
		DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
		//格式化
		String strDateTime = dateTimeFormatter.format(LocalDateTime.now());
		System.out.println(strDateTime); //2022/12/04 21:05:42
		//解析
		TemporalAccessor accessor = dateTimeFormatter.parse("2022/12/04 21:05:42");
		LocalDateTime localDateTime = LocalDateTime.from(accessor);
		System.out.println(localDateTime); //2022-12-04T21:05:42
	}

	@Test
	public void test7(){
	    Calendar cal = Calendar.getInstance();
		cal.set(2004 - 1970,04,22);
		cal.add(Calendar.DAY_OF_YEAR, 100);

		LocalDateTime localDateTime = LocalDateTime.of(2004,4,22,12,12);

	}

	@Test
	public void test8() throws ParseException {
	    Date date1 = new Date();
		System.out.println(date1);
		System.out.println(date1.getTime());
		Date date2 = new Date(date1.getTime());
		System.out.println(date2);
		java.sql.Date date3 = new java.sql.Date(date1.getTime());
		SimpleDateFormat simpleDateFormat = new SimpleDateFormat("z yyyy MM dd HH mm ss");
		System.out.println(simpleDateFormat.format(date1));
		Date date4 = simpleDateFormat.parse("SGT 1988 02 12 12 12 12");
		System.out.println(date4);
		System.out.println("----------------");
		Calendar cal = Calendar.getInstance();
		cal.add(Calendar.MONTH, 2);
		System.out.println(cal);
		String qwq = "" + cal.get(Calendar.YEAR) + " " + cal.get(Calendar.MONTH) + " " + cal.get(Calendar.DAY_OF_MONTH);
		System.out.println(qwq);
		Date date5 = cal.getTime();
		System.out.println(date5);
		System.out.println("----------------");
		LocalDateTime localDateTime = LocalDateTime.now();
		LocalDateTime localDateTime1 = LocalDateTime.of(2004, 4, 22, 04, 21, 22);
		System.out.println("----------------");
		Instant instant = Instant.ofEpochMilli(date1.getTime());
		System.out.println(instant);
		System.out.println("----------------");
		DateTimeFormatter dateTimeFormatter = DateTimeFormatter.ofPattern("yyyy MM dd HH mm ss");
		String format = dateTimeFormatter.format(localDateTime);
		System.out.println(format);
		TemporalAccessor accessor = dateTimeFormatter.parse("2020 11 11 11 11 11");
		System.out.println(LocalDateTime.from(accessor));

		System.out.println("----------------");


	}
}
