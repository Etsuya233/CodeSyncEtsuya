package com.etsuya.java8;

import javax.swing.*;
import java.awt.*;

/**
 * ClassName: EGridBagL
 * Package: com.etsuya.java8
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/4 19:13
 * @Version: 1.0
 */
public class EGridBagL extends JFrame {
	public EGridBagL() throws HeadlessException {
		GridBagLayout layout = new GridBagLayout();
		setLayout(layout);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 500, 500);
		setTitle("Window");

		GridBagConstraints constraints = new GridBagConstraints();

		JButton[] buttons = new JButton[11];
		for(int i = 1; i <= 10; i++){
			buttons[i] = new JButton("Button " + i);
		}


		JPanel panel = new JPanel();
		constraints.gridwidth = GridBagConstraints.REMAINDER;
		JLabel label = new JLabel("Grid Layout Test:");
		layout.addLayoutComponent(panel, constraints);
		panel.add(label);
		add(panel);


		constraints.gridwidth = 1;
		constraints.fill = GridBagConstraints.BOTH;
		layout.addLayoutComponent(buttons[1], constraints);
		add(buttons[1]);
		layout.addLayoutComponent(buttons[2], constraints);
		add(buttons[2]);
		layout.addLayoutComponent(buttons[3], constraints);
		add(buttons[3]);
		constraints.gridwidth = GridBagConstraints.REMAINDER;
		layout.addLayoutComponent(buttons[4], constraints);
		add(buttons[4]);

		constraints.fill = GridBagConstraints.BOTH;
		layout.addLayoutComponent(buttons[5], constraints);
		add(buttons[5]);
		constraints.gridheight = 2;
		constraints.gridwidth = GridBagConstraints.RELATIVE;
		layout.addLayoutComponent(buttons[6], constraints);
		add(buttons[6]);
		constraints.gridheight = 1;
		constraints.gridwidth = GridBagConstraints.REMAINDER;
		layout.addLayoutComponent(buttons[7], constraints);
		add(buttons[7]);
		layout.addLayoutComponent(buttons[8], constraints);
		add(buttons[8]);


		pack();
		setVisible(true);
	}
}
