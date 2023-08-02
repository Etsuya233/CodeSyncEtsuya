package com.etsuya.exer3;

/**
 * ClassName: Gender
 * Package: com.etsuya.exer3
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/2/28 21:25
 * @Version: 1.0
 */
public enum Gender {
	MALE("male"),
	FEMALE("female"),
	OTHER("other");

	private final String gender;

	private Gender(String str){
		this.gender = str;
	}

	@Override
	public String toString(){
		return gender;
	}
}
