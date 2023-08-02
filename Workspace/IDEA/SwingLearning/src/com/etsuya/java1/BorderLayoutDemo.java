package com.etsuya.java1;

import javax.swing.*;
import javax.swing.border.Border;
import java.awt.*;

/**
 * ClassName: BorderLayoutDemo
 * Package: com.etsuya.java1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/31 21:27
 * @Version: 1.0
 */
public class BorderLayoutDemo extends JFrame {
	public BorderLayoutDemo() throws HeadlessException {
		setSize(500,500);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setTitle("BorderLayout Test");
		setLayout(new BorderLayout(2, 2));
		setFont(new Font("Helvetica", Font.PLAIN, 14));
		getContentPane().add(new JButton("North"), "North");
		getContentPane().add(new JButton("South"), "South");
		getContentPane().add(new JButton("East"), "East");
		getContentPane().add(new JButton("West"), "West");
		pack();
		setVisible(true);
	}
}
