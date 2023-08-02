package com.etsuya.db.view;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 * ClassName: ResultDisplay
 * Package: com.etsuya.db.view
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/1 16:42
 * @Version: 1.0
 */
public class ResultDisplay extends JFrame {

	public ResultDisplay(Object[] data, String database, String table) {
		UIManager.put("Label.font", new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		UIManager.put("TextField.font", new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		UIManager.put("Button.font", new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException | InstantiationException | IllegalAccessException |
				 UnsupportedLookAndFeelException e) {
			throw new RuntimeException(e);
		}
		BorderLayout root = new BorderLayout();
		setDefaultCloseOperation(DISPOSE_ON_CLOSE);
		setBounds(300, 300, 500, 500);
		setTitle("Result: " + database + " -> " + table);


		//Center:
		JTable tabel = new JTable((String[][]) data[1], (String[]) data[0]);
		JScrollPane scrollPane = new JScrollPane(tabel);

		//South:
		JPanel southRoot = new JPanel();
		JButton button = new JButton("Back");
		button.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				dispose();
			}
		});
		southRoot.add(button);



		setLayout(root);
		add(southRoot, BorderLayout.SOUTH);
		add(scrollPane, BorderLayout.CENTER);
		pack();
		setVisible(true);
	}
}
