package com.etsuya.java4;

import java.util.Objects;

/**
 * ClassName: SetTest
 * Package: com.etsuya.java4
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/2 21:29
 * @Version: 1.0
 */
public class SetTest {
	public static void main(String[] args) {

	}
}

class People{
	int age;
	String name;

	public People(int i, String tony) {
	}

	@Override
	public boolean equals(Object o) {
		if (this == o) return true;
		if (o == null || getClass() != o.getClass()) return false;
		People people = (People) o;
		return age == people.age && Objects.equals(name, people.name);
	}

	@Override
	public int hashCode() {
		return Objects.hash(age, name);
	}
}