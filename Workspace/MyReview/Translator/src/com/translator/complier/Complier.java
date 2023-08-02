package com.translator.complier;

import com.translator.data.Data;

import java.util.HashMap;

/**
 * ClassName: Complier
 * Package: com.translator.complier
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/5 19:41
 * @Version: 1.0
 */
public class Complier {
	static HashMap alphabets = new HashMap();

	public Complier(){
		for(int i = 0; i < Data.getAlphabet().length; i++){
			alphabets.put(Data.getAlphabet()[i][0], Data.getAlphabet()[i][1]);
		}
	}

	public String alphabet(String str){
		StringBuilder stringBuilder = new StringBuilder(str);
		for(int i = 0; i < stringBuilder.length(); i++){
			Character atarashi = (Character) alphabets.get(stringBuilder.charAt(i));
			if(atarashi != null){
				stringBuilder.setCharAt(i, atarashi);
			}
		}
		return stringBuilder.toString();
	}

	public String special(String str){
		StringBuilder stringBuilder = new StringBuilder(str);
		char a = stringBuilder.charAt(0);
		char b = 'l';
		int i = 1;
		for( ; i < stringBuilder.length(); i++){
			b = a;
			a = stringBuilder.charAt(i);
			if(a == b){
				stringBuilder.setCharAt(i, 'é');
			}
			if(a == ' ' && b == 'f'){
				stringBuilder.setCharAt(i - 1, 'ß');
			}
		}
		if(a == 'f') stringBuilder.setCharAt(i - 1, 'ß');
		return stringBuilder.toString();
	}

	public String translate(String str){
		//这里可以公用一个StringBuilder
		str = alphabet(str);
		str = special(str);
		return str;
	}
}
