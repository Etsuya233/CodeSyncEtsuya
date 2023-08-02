package com.etsuya.experiment6;

import java.io.*;
import java.util.*;

public class Experiment6 {
	public static void main(String[] args) {
		File words = new File("src/com/etsuya/experiment6/cet4words.txt");
		File result = new File("src/com/etsuya/experiment6/result.txt");
		HashMap<Character, Integer> hashmap = new HashMap<>();
		FileReader fr = null;
		BufferedReader br = null;
		FileWriter fw = null;
		BufferedWriter bw = null;

		try{
			fr = new FileReader(words);
			br = new BufferedReader(fr);
			String row;
			while((row = br.readLine()) != null){
				if(row.indexOf('/') != -1 ||  row.indexOf('[') != -1){
					char[] charArray = row.toLowerCase().toCharArray();
					for(char a: charArray){
						if(a >= 'a' && a <= 'z'){
							hashmap.put(a, hashmap.getOrDefault(a, 0) + 1);
						} else {
							break;
						}
					}
				}
			}

			fw = new FileWriter(result);
			bw = new BufferedWriter(fw);
			Set<Map.Entry<Character, Integer>> entries = hashmap.entrySet();
			List<Map.Entry<Character, Integer>> list = new ArrayList<>(entries.stream().toList());
			list.sort((a, b) -> b.getValue().compareTo(a.getValue()));
			for(Map.Entry<Character, Integer> a: list){
				bw.write(a.getKey() + ": " + a.getValue());
				bw.newLine();
			}

		} catch (IOException e) {
			throw new RuntimeException(e);
		} finally {
			try {
				if(bw != null)
					bw.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(fw != null)
					fw.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(br != null)
					br.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(fr != null)
					fr.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}

	}

}
