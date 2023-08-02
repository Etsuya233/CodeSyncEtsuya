package com.etsuya.java11;

/**
 * ClassName: Country
 * Package: com.etsuya.java11
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/13 16:20
 * @Version: 1.0
 */
public enum Country {
	CHINA("China", "中国"),
	AMERICA("America", "美国");

	private final String engName;
	private final String cnName;

	private Country(String engName, String cnName){
		this.engName = engName;
		this.cnName = cnName;
	}
}
