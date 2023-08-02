package com.etsuya.java8;

import javax.swing.*;
import java.awt.*;

/**
 * ClassName: EBorderL
 * Package: com.etsuya.java8
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/4 18:54
 * @Version: 1.0
 */
public class EBorderL extends JFrame {
	public EBorderL() {
		setLayout(new BorderLayout());
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 500, 500);
		setTitle("EBorderTest");

		JPanel panelNorth = new JPanel();
		JPanel panelSouth = new JPanel();
		JPanel panelEast = new JPanel();
		JPanel panelWest = new JPanel();
		JPanel panelCenter = new JPanel();

		for(int i = 0; i < 4; i++){
			panelNorth.add(new JButton("north"));
		}
		for(int i = 0; i < 4; i++){
			panelSouth.add(new JButton("south"));
		}
		for(int i = 0; i < 4; i++){
			panelEast.add(new JButton("east"));
		}
		for(int i = 0; i < 4; i++){
			panelWest.add(new JButton("west"));
		}
		for(int i = 0; i < 4; i++){
			panelCenter.add(new JButton("center"));
		}

		add(panelNorth, BorderLayout.NORTH);
		add(panelSouth, BorderLayout.SOUTH);
		add(panelEast, BorderLayout.EAST);
		add(panelWest, BorderLayout.WEST);
		add(panelCenter, BorderLayout.CENTER);

		setVisible(true);
	}
}
