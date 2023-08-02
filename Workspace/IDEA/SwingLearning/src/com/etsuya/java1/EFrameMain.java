package com.etsuya.java1;

import javax.swing.*;
import java.awt.*;

/**
 * ClassName: EFrame
 * Package: com.etsuya.java1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/31 16:23
 * @Version: 1.0
 */
public class EFrameMain extends JFrame {
	public EFrameMain(String title) {
		super(title);
		this.setLayout(new FlowLayout());
		this.setSize(500, 400);
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLocation(300, 300);
		this.setVisible(true);

		Container container = this.getContentPane();

		JButton button = new JButton("Click me!");
		button.setSize(120,20);
		button.setBounds(12,12,120,20);
		button.setHorizontalAlignment(SwingConstants.CENTER);
		container.add(button);

		JLabel label = new JLabel("Hey! I'ma application!");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		container.add(label);
	}
}
