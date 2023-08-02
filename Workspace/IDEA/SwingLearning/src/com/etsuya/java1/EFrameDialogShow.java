package com.etsuya.java1;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.lang.reflect.Constructor;

/**
 * ClassName: EFrameDialogTest
 * Package: com.etsuya.java1
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/31 20:56
 * @Version: 1.0
 */
public class EFrameDialogShow extends JFrame {
	public EFrameDialogShow() throws HeadlessException {
		this.setTitle("Dialog Presentation");
		this.setDefaultCloseOperation(EXIT_ON_CLOSE);
		this.setLayout(new FlowLayout());
		this.setSize(500, 400);
		this.setVisible(true);

		JButton button = new JButton("Free");
		JButton button1 = new JButton("Non-Free");

		JLabel label = new JLabel();

		JDialog dialog = new JDialog(this, "Free");
		dialog.setSize(150, 150);
		dialog.setLayout(new FlowLayout());
		JButton button2 = new JButton("OK");
		dialog.add(label);
		dialog.add(button2);


		Container container = this.getContentPane();
		container.add(button);
		container.add(button1);

		button.addActionListener(new AbstractAction() {
			@Override
			public void actionPerformed(ActionEvent e) {
				dialog.setModal(false);
				label.setText("It's a modal dialog!");
				dialog.setVisible(true);
			}
		});

		button1.addActionListener(new AbstractAction() {
			@Override
			public void actionPerformed(ActionEvent e) {
				dialog.setModal(true);
				label.setText("It's a non-modal dialog!");
				dialog.setVisible(true);
			}
		});

		button2.addActionListener(new AbstractAction() {
			@Override
			public void actionPerformed(ActionEvent e) {
				dialog.dispose();
			}
		});
	}
}
