package com.etsuya.db.view;

import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;

/**
 * ClassName: MainMenu
 * Package: com.etsuya.db.view
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/5/1 15:55
 * @Version: 1.0
 */
public class MainMenu extends JFrame {

	public MainMenu() throws HeadlessException {
		UIManager.put("Label.font", new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		UIManager.put("TextField.font", new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		UIManager.put("Button.font", new Font("Microsoft YaHei UI", Font.PLAIN, 15));
		try {
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException | InstantiationException | IllegalAccessException |
				 UnsupportedLookAndFeelException e) {
			throw new RuntimeException(e);
		}

		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 500, 500);
		setTitle("EDBird");

		BorderLayout root = new BorderLayout();

		String[] data = new String[6];

		//North:
		JPanel northRoot = new JPanel();
		GridBagLayout northLayout = new GridBagLayout();
		northRoot.setLayout(northLayout);
		GridBagConstraints c = new GridBagConstraints();
		//ip address
		JLabel label1 = new JLabel("IP address: ");
		JTextField textField1 = new JTextField(30);
		c.gridx = 0;
		c.gridy = 0;
		c.anchor = GridBagConstraints.WEST;
		northRoot.add(label1, c);
		c.gridx = 1;
		c.gridy = 0;
		c.gridwidth = GridBagConstraints.REMAINDER;
		c.fill = GridBagConstraints.HORIZONTAL;
		northRoot.add(textField1, c);
		//port
		JLabel label2 = new JLabel("Port: ");
		JTextField textField2 = new JTextField(30);
		c.gridx = 0;
		c.gridy = 1;
		c.anchor = GridBagConstraints.WEST;
		northRoot.add(label2, c);
		c.gridx = 1;
		c.gridy = 1;
		c.gridwidth = GridBagConstraints.REMAINDER;
		c.fill = GridBagConstraints.HORIZONTAL;
		northRoot.add(textField2, c);
		//database
		JLabel label3 = new JLabel("Database name: ");
		JTextField textField3 = new JTextField(30);
		c.gridx = 0;
		c.gridy = 2;
		c.anchor = GridBagConstraints.WEST;
		northRoot.add(label3, c);
		c.gridx = 1;
		c.gridy = 2;
		c.gridwidth = GridBagConstraints.REMAINDER;
		c.fill = GridBagConstraints.HORIZONTAL;
		northRoot.add(textField3, c);
		//user
		JLabel label4 = new JLabel("User name: ");
		JTextField textField4 = new JTextField(30);
		c.gridx = 0;
		c.gridy = 3;
		c.anchor = GridBagConstraints.WEST;
		northRoot.add(label4, c);
		c.gridx = 1;
		c.gridy = 3;
		c.gridwidth = GridBagConstraints.REMAINDER;
		c.fill = GridBagConstraints.HORIZONTAL;
		northRoot.add(textField4, c);
		//password
		JLabel label5 = new JLabel("Password: ");
		JTextField textField5 = new JTextField(30);
		c.gridx = 0;
		c.gridy = 4;
		c.anchor = GridBagConstraints.WEST;
		northRoot.add(label5, c);
		c.gridx = 1;
		c.gridy = 4;
		c.gridwidth = GridBagConstraints.REMAINDER;
		c.fill = GridBagConstraints.HORIZONTAL;
		northRoot.add(textField5, c);
		//table
		JLabel label6 = new JLabel("Table name: ");
		JTextField textField6 = new JTextField(30);
		c.gridx = 0;
		c.gridy = 5;
		c.anchor = GridBagConstraints.WEST;
		northRoot.add(label6, c);
		c.gridx = 1;
		c.gridy = 5;
		c.gridwidth = GridBagConstraints.REMAINDER;
		c.fill = GridBagConstraints.HORIZONTAL;
		northRoot.add(textField6, c);

		//South:
		JButton southButton = new JButton("Search");
		southButton.addActionListener(new ActionListener() {
			@Override
			public void actionPerformed(ActionEvent e) {
				data[0] = textField1.getText();
				data[1] = textField2.getText();
				data[2] = textField3.getText();
				data[3] = textField4.getText();
				data[4] = textField5.getText();
				data[5] = textField6.getText();

				try {
					new ResultDisplay(ResultGetter.getFromDB(data[0], data[1], data[2], data[3], data[4], data[5]), data[2], data[5]);
				} catch (ClassNotFoundException ex) {
					throw new RuntimeException(ex);
				} catch (SQLException ex) {
					JDialog dialog = new JDialog(MainMenu.this, "Error", true);
					dialog.setBounds(400, 400, 300, 200);
					dialog.setLayout(new BorderLayout());
					JLabel label = new JLabel("Error: \nPlease correct your information!\n" + ex.getMessage());
					label.setHorizontalAlignment(SwingConstants.CENTER);
					dialog.add(label, BorderLayout.CENTER);
					JButton button = new JButton("OK");
					button.addActionListener(e1 -> dialog.dispose());
					JPanel panel = new JPanel();
					panel.add(button);
					dialog.add(panel, BorderLayout.SOUTH);
					dialog.setVisible(true);

					throw new RuntimeException(ex);
				}

			}
		});
		JPanel southRoot = new JPanel();
		southRoot.add(southButton);

		setLayout(root);
		this.add(northRoot, BorderLayout.NORTH);
		this.add(southRoot, BorderLayout.SOUTH);
		pack();
		setVisible(true);
	}
}
