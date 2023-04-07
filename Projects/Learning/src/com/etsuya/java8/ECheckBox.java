package com.etsuya.java8;

import javax.security.auth.callback.LanguageCallback;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionListener;

/**
 * ClassName: ECheckBox
 * Package: com.etsuya.java8
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/5 13:24
 * @Version: 1.0
 */
public class ECheckBox extends JFrame {
	public ECheckBox() throws HeadlessException {
//		setLayout();
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 500, 500);
		setTitle("Upsanta Installer");

		JPanel panel = new JPanel();
		BorderLayout borderLayout = new BorderLayout();
		panel.setLayout(borderLayout);

		JPanel centerPanel = new JPanel();
		JCheckBox checkBox = new JCheckBox("Register");
		JCheckBox checkBox1 = new JCheckBox("Login");
		JCheckBox checkBox2 = new JCheckBox("Tools");
		JCheckBox checkBox3 = new JCheckBox("Samples");
		JCheckBox checkBox4 = new JCheckBox("Orbit");
		centerPanel.add(checkBox);
		centerPanel.add(checkBox1);
		centerPanel.add(checkBox2);
		centerPanel.add(checkBox3);
		centerPanel.add(checkBox4);
		panel.add(centerPanel, BorderLayout.CENTER);

//		borderLayout.addLayoutComponent(checkBox1, BorderLayout.CENTER);
//		borderLayout.addLayoutComponent(checkBox2, BorderLayout.CENTER);
//		borderLayout.addLayoutComponent(checkBox3, BorderLayout.CENTER);
//		borderLayout.addLayoutComponent(checkBox4, BorderLayout.CENTER);

		JDialog dialog = new JDialog(this, "Result");
		dialog.setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		JLabel label = new JLabel();
		dialog.setBounds(300, 300, 300, 100);

		JPanel dialogPanel = new JPanel();
		dialogPanel.add(label);

		JButton button = new JButton("Accept");
		button.addActionListener(e -> {
			boolean added = false;
			String ret = "You have choose";
			if(checkBox.isSelected()){
				if(added){
					ret += ",";
				} else {
					added = true;
				}
				ret += " " + checkBox.getText();
			}
			if(checkBox1.isSelected()){
				if(added){
					ret += ",";
				} else {
					added = true;
				}
				ret += " " + checkBox1.getText();
			}
			if(checkBox2.isSelected()){
				if(added){
					ret += ",";
				} else {
					added = true;
				}
				ret += " " + checkBox2.getText();
			}
			if(checkBox3.isSelected()){
				if(added){
					ret += ",";
				} else {
					added = true;
				}
				ret += " " + checkBox3.getText();
			}
			if(checkBox4.isSelected()){
				if(added){
					ret += ",";
				} else {
					added = true;
				}
				ret += " " + checkBox4.getText();
			}
			ret += ".";
			label.setText(ret);
			dialog.setVisible(true);
		});
		JButton button1 = new JButton("Close");
		button1.addActionListener(e -> {
			dialog.dispose();
		});
		dialogPanel.add(button1);
		panel.add(button, BorderLayout.SOUTH);

		dialog.add(dialogPanel);

		add(panel);
		pack();
		setVisible(true);


	}
}
