package com.etsuya.java8;

import javax.swing.*;
import java.awt.*;

/**
 * ClassName: ETextArea
 * Package: com.etsuya.java8
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/5 13:01
 * @Version: 1.0
 */
public class ETextArea extends JFrame {
	public ETextArea() throws HeadlessException {
		setLayout(new FlowLayout());
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 500, 500);
		setTitle("Window");

		JTextArea textArea = new JTextArea("Please input here...",5,20);
		textArea.setLineWrap(true);
		textArea.setFont(new Font("Helvetica", Font.PLAIN, 16));
		JScrollPane jScrollPane = new JScrollPane(textArea);
		Dimension size = textArea.getSize();
		jScrollPane.setBounds(10, 10, size.width, size.height);
//		jScrollPane.add(textArea);


		add(jScrollPane);
//		add(textArea);

		pack();
		setVisible(true);
	}
}
