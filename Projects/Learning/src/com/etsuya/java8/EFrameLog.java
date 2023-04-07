package com.etsuya.java8;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.io.IOException;

/**
 * ClassName: EFrameLog
 * Package: com.etsuya.java8
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/2 22:35
 * @Version: 1.0
 */
public class EFrameLog extends JFrame {
	public EFrameLog() throws HeadlessException {
		setTitle("JDialog Show Up");
//		System.out.println(this.getContentPane().getClass());
//		System.out.println(this.getLayout().getClass());
		setLayout(new FlowLayout());
		setBounds(200,200,500,100);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setVisible(true);
		setDefaultLookAndFeelDecorated(false);


		JLabel label = new JLabel();
		label.setText("Click the button below to show JDialog");
		label.setHorizontalAlignment(SwingConstants.CENTER);
		add(label);

		JLabel label1 = new JLabel();
		JDialog dialog = new JDialog(this);
		label1.setHorizontalAlignment(SwingConstants.CENTER);
		dialog.setLayout(new FlowLayout());
		dialog.add(label1);
		dialog.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		dialog.setBounds(300,300,300,200);

		JButton button2 = new JButton("Close");
		button2.addActionListener(new AbstractAction() {
			@Override
			public void actionPerformed(ActionEvent e) {
				dialog.dispose();
			}
		});
		dialog.add(button2);

		JButton button = new JButton("Modal JDialog");
		button.addActionListener(new AbstractAction() {
			@Override
			public void actionPerformed(ActionEvent e) {
				label1.setText("Modal JDialog");
				dialog.setVisible(true);
			}
		});

		JButton button1 = new JButton("Non-modal JDialog");
		button1.addActionListener(new AbstractAction() {
			@Override
			public void actionPerformed(ActionEvent e) {
				label1.setText("Non-Modal JDialog");
				dialog.setVisible(true);
			}
		});

		JButton button3 = new JButton("Open Spotify");
		button3.addActionListener(new AbstractAction() {
			@Override
			public void actionPerformed(ActionEvent e) {
				try {
					Runtime.getRuntime().exec("cmd /c start C:\\Users\\etsuy\\AppData\\Roaming\\Spotify\\Spotify.exe");
				} catch (IOException ex) {
					ex.printStackTrace();
					JDialog dialog1 = new JDialog();
					dialog1.setBounds(300,300,500,200);
					dialog1.add(new JLabel("E: Can't open this application!"));
//					dialog.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);
					dialog.setVisible(true);
				}
			}
		});

		add(button);
		add(button1);
		add(button3);
	}
}
