package com.etsuya.java8;

import javax.swing.*;
import javax.swing.border.EmptyBorder;
import javax.swing.event.ChangeEvent;
import javax.swing.event.ChangeListener;
import java.awt.*;
import java.awt.event.ItemEvent;
import java.awt.event.ItemListener;

/**
 * ClassName: EComboBoxT
 * Package: com.etsuya.java8
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/4/6 16:27
 * @Version: 1.0
 */
public class EComboBoxT extends JFrame {
	int fontSize = 24;
	Font font = new Font("Helvatica", Font.BOLD, 24);

	public EComboBoxT() throws HeadlessException {
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 1000, 500);
		setTitle("Window");

		BorderLayout borderLayout = new BorderLayout();
		JTextArea textArea = new JTextArea("Meteors created a sky-symphony of light.");
		JPanel showTextArea = new JPanel();
		JPanel fontChange = new JPanel();
		JPanel selectFontPanel = new JPanel();
		JPanel selectSizePanel = new JPanel();

		//showTextArea
		showTextArea.setLayout(new BorderLayout());
		showTextArea.setBorder(new EmptyBorder(5, 5, 5, 5));
		textArea.setFont(font);
		textArea.setLineWrap(true);
		showTextArea.add(textArea);

		//selectFont
		selectFontPanel.add(new JLabel("Fonts:"));
		String[] fonts = {"Helvetica", "Comic Sans MS", "Inter", "Cascadia Code","BIZ UDMincho", "Arial",
				"Microsoft YaHei UI", "MSGothic", "宋体", "黑体", "等线", "新宋体"};
		JComboBox<String> stringJComboBox = new JComboBox<>(fonts);
		stringJComboBox.addItemListener(e -> {
			font = new Font(stringJComboBox.getItemAt(stringJComboBox.getSelectedIndex()), Font.BOLD, fontSize);
			textArea.setFont(font);
		});
		selectFontPanel.add(stringJComboBox);

		//selectSize
		selectSizePanel.add(new JLabel("Size:"));
		JSlider slider = new JSlider(2, 128, 24);
		slider.setMajorTickSpacing(20);
		slider.setMinorTickSpacing(10);
		slider.setPaintLabels(true);
		slider.setPaintTicks(true);
		JLabel fontSizeShow = new JLabel();
		fontSizeShow.setText("  24");
		slider.addChangeListener(e -> {
			fontSize = slider.getValue();
			fontSizeShow.setText("  " + fontSize);
			font = new Font(stringJComboBox.getItemAt(stringJComboBox.getSelectedIndex()), Font.BOLD, fontSize);
			textArea.setFont(font);
		});
		selectSizePanel.add(slider);
		selectSizePanel.add(fontSizeShow);


		fontChange.setPreferredSize(new Dimension(500, 70));
		fontChange.add(selectFontPanel);
		fontChange.add(selectSizePanel);

		setLayout(borderLayout);
		add(showTextArea, BorderLayout.CENTER);
		add(fontChange, BorderLayout.SOUTH);
		setVisible(true);
	}
}
