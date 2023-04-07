package com.etsuya.java8;

import javax.swing.*;
import javax.swing.border.Border;
import javax.swing.border.EmptyBorder;
import java.awt.*;
import java.util.List;

/**
 * ClassName: EList
 * Package: com.etsuya.java8
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/6 16:06
 * @Version: 1.0
 */
public class EList extends JFrame {
	public EList() throws HeadlessException {
//		setLayout();

		JPanel panel = new JPanel();
		JLabel ret = new JLabel();
		panel.setBorder(new EmptyBorder(5, 5, 5, 5));
		panel.setLayout(new BorderLayout());
		JLabel label = new JLabel("Choose your country: ");
		String[] items = {"China", "USA", "Japan", "South Korea", "UK", "Poland", "Iceland"};
		JList<String> list = new JList<>(items);
		list.addListSelectionListener(e -> {
			StringBuilder temp = new StringBuilder("You have choose");
			List<String> selectedValuesList = list.getSelectedValuesList();
			for(String str: selectedValuesList){
				temp.append(" ");
				temp.append(str);
			}
			temp.append(".");
			ret.setText(temp.toString());
		});
		panel.add(ret, BorderLayout.SOUTH);
		JScrollPane scrollPane = new JScrollPane(list);
		panel.add(label, BorderLayout.NORTH);
		panel.add(scrollPane);

		setContentPane(panel);
		pack();
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 350, 200);
		setTitle("Window");
		setVisible(true);

	}
}
