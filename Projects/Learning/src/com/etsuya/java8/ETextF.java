package com.etsuya.java8;

import javax.swing.*;
import java.awt.*;

/**
 * ClassName: ETextF
 * Package: com.etsuya.java8
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/5 12:55
 * @Version: 1.0
 */
public class ETextF extends JFrame {
	public ETextF() throws HeadlessException {
		setLayout(new FlowLayout());
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 500, 500);
		setTitle("Window");


		JTextField textField = new JTextField(30);

		add(textField);

		pack();
		setVisible(true);
	}
}
