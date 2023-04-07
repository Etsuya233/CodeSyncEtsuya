package com.etsuya.java8;

import javax.swing.*;
import java.awt.*;

/**
 * ClassName: EGridL
 * Package: com.etsuya.java8
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/4 19:04
 * @Version: 1.0
 */
public class EGridL extends JFrame {
	public EGridL() throws HeadlessException {
		setLayout(new GridLayout(3, 3));
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 500, 500);
		setTitle("Window");

		for(int i = 1; i <= 9; i++){
			add(new Button(i + ""));
		}

		setVisible(true);
	}
}
