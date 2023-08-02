package com.etsuya.main;

import javax.swing.*;
import javax.swing.plaf.FontUIResource;
import java.awt.*;
import java.io.*;
import java.util.Enumeration;

public class Notepad extends JFrame {
	private String fileName = "untitled";
	private JTextArea textArea = null;
	private File thisFile = null;

	public Notepad(){
		//Init
		//出错把17-22行注释掉！！！
		InitGlobalFont(new Font("微软雅黑", Font.PLAIN, 16));
		try {
			UIManager.setLookAndFeel("com.sun.java.swing.plaf.windows.WindowsLookAndFeel");
		} catch (Exception e) {
			throw new RuntimeException(e);
		}
		BorderLayout rootLayout = new BorderLayout();
		setLayout(rootLayout);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		setBounds(300, 300, 500, 370);
		setTitle("Notepad - " + fileName);

		//TextArea
		textArea = new JTextArea();
		JScrollPane scrollPane = new JScrollPane(textArea);
		add(scrollPane, BorderLayout.CENTER);

		//Menu bar
		JMenuBar menuBar = new JMenuBar();
		JMenu menuFile = new JMenu("File");
		JMenuItem menuFileSave = new JMenuItem("Save");
		menuFileSave.addActionListener(e -> save());
		menuFile.add(menuFileSave);
		JMenuItem menuNew = new JMenuItem("New");
		menuNew.addActionListener(e -> newFile());
		menuFile.add(menuNew);
		JMenuItem menuFileOpen = new JMenuItem("Open");
		menuFileOpen.addActionListener(e -> open());
		menuFile.add(menuFileOpen);
		menuBar.add(menuFile);
		JMenu menuAbout = new JMenu("About");
		JMenuItem menuAboutAuthor = new JMenuItem("Author");
		menuAboutAuthor.addActionListener(e -> showAbout());
		menuAbout.add(menuAboutAuthor);
		menuBar.add(menuAbout);
		add(menuBar, BorderLayout.NORTH);

		//Function bar
		JButton stat = new JButton("Stat");
		stat.addActionListener(e -> stat());
		JButton clear = new JButton("Clear");
		clear.addActionListener(e -> clear());
		JPanel functionBar = new JPanel();
		functionBar.setAlignmentX(Component.CENTER_ALIGNMENT);
		functionBar.setAlignmentY(Component.CENTER_ALIGNMENT);
		functionBar.add(stat, BorderLayout.SOUTH);
		functionBar.add(clear, BorderLayout.SOUTH);
		add(functionBar, BorderLayout.SOUTH);

		//Finally
		setVisible(true);
	}

	private void newFile(){
		textArea.setText("");
		updateFileName("untitled");
		thisFile = null;
	}

	private void open(){
		BufferedReader bufferedReader = null;
		FileReader fileReader = null;
		try {
			JFileChooser fileChooser = new JFileChooser();
			fileChooser.showOpenDialog(this);
			thisFile = fileChooser.getSelectedFile();
			fileReader = new FileReader(thisFile);
			bufferedReader = new BufferedReader(fileReader);
			StringBuilder sb = new StringBuilder();
			String thisRow = null;
			while((thisRow = bufferedReader.readLine()) != null){
				sb.append(thisRow);
				sb.append("\n");
			}
			textArea.setText(sb.toString());
			updateFileName(thisFile.getName());
		} catch (IOException e) {
			throw new RuntimeException(e);
		} finally {
			try {
				if(bufferedReader != null)
					bufferedReader.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(fileReader != null)
					fileReader.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private void save(){
		String text = textArea.getText();

		if(thisFile == null){
			JFileChooser fileChooser = new JFileChooser();
			fileChooser.showSaveDialog(this);
			thisFile = fileChooser.getSelectedFile();
		}

		Writer writer = null;
		BufferedWriter bufferedWriter = null;
		try {
			writer = new FileWriter(thisFile);
			bufferedWriter = new BufferedWriter(writer);
			bufferedWriter.write(text);
			updateFileName(thisFile.getName());
		} catch (IOException e) {
			throw new RuntimeException(e);
		} finally {
			try {
				if(bufferedWriter != null)
					bufferedWriter.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			try {
				if(writer != null)
					writer.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}

	private void updateFileName(String newName){
		fileName = newName;
		this.setTitle("Notepad - " + fileName);
	}

	private void showAbout(){
		JOptionPane.showMessageDialog(this, "Author: 龚毅 Etsuya.",
				"Notepad - Author", JOptionPane.INFORMATION_MESSAGE);
	}

	private void stat(){
		int length = textArea.getText().length();
		JOptionPane.showMessageDialog(this, "Length: " + length + ".",
				this.getTitle() + " - Stat", JOptionPane.INFORMATION_MESSAGE);
	}

	private void clear(){
		textArea.setText("");
	}

	private static void InitGlobalFont(Font font) {
		FontUIResource fontRes = new FontUIResource(font);
		for (Enumeration<Object> keys = UIManager.getDefaults().keys(); keys.hasMoreElements();) {
			Object key = keys.nextElement();
			Object value = UIManager.get(key);
			if (value instanceof FontUIResource) {
				UIManager.put(key, fontRes);
			}
		}
	}

	public static void main(String[] args) {
		new Notepad();
	}
}