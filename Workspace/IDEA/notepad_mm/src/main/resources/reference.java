import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;

import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuBar;
import javax.swing.JMenuItem;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;
import javax.swing.UIManager;
import javax.swing.UnsupportedLookAndFeelException;

/**
 * 记事本
 * @author Hercules
 *
 */
public class Notepad extends JFrame{

	public Notepad() {
		init();
	}

	private JTextArea textArea;

	private File curFile;//当前打开的文件

	public void init() {
		setTitle("记事本");
		setSize(400, 500);
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		textArea = new JTextArea();
		textArea.addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				super.keyPressed(e);
				if(e.isControlDown()) {//ctrl按下
					if(e.getKeyCode() == KeyEvent.VK_O) {//按下了o
						open();
					}else if(e.getKeyCode() == KeyEvent.VK_S) {
						save();
					}
				}
			}
		});
		//添加一个滚动条
		JScrollPane jScrollPane = new JScrollPane(textArea);
		add(jScrollPane);
		//上面的菜单栏
		JMenuBar menuBar = new JMenuBar();
		setJMenuBar(menuBar);
		JMenu file = new JMenu("file");
		menuBar.add(file);
		//打开
		JMenuItem open = new JMenuItem("open");
		open.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				open();
			}
		});
		file.add(open);
		//保存
		JMenuItem save = new JMenuItem("save");
		save.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				save();
			}
		});
		file.add(save);
		//另存为
		JMenuItem saveAs = new JMenuItem("saveAs");
		saveAs.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				saveAs();
			}
		});
		file.add(saveAs);
		setVisible(true);
	}
	/**
	 * 打开
	 */
	public void open() {
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.showOpenDialog(null);
		File file = fileChooser.getSelectedFile();
		if(file != null) {
			curFile = file;//打开的时候，当前打开的文件就是选中的文件
			Reader reader = null;
			BufferedReader br = null;
			StringBuilder sb = new StringBuilder();
			try {
				reader = new FileReader(file);
				br = new BufferedReader(reader);
				String str = null;
				while ((str = br.readLine()) != null) {
					sb.append(str);
					sb.append("\n");
				}
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			} catch (IOException e) {
				e.printStackTrace();
			} finally {
				if(br != null) {
					try {
						br.close();
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
				if(reader != null) {
					try {
						reader.close();
					} catch (IOException e) {
						e.printStackTrace();
					}
				}
			}
			textArea.setText(sb.toString());
		}
	}
	/**
	 * 保存
	 */
	public void save() {
		if(curFile != null) {
			writeFile(curFile);
		}else {
			saveAs();
		}
	}

	/**
	 * 另存为
	 */
	public void saveAs() {
		JFileChooser fileChooser = new JFileChooser();
		fileChooser.showSaveDialog(null);
		File file = fileChooser.getSelectedFile();
		if(file != null) {
			//另存为的时候，另存为的文件就是当前打开的文件
			curFile = file;
			writeFile(file);
		}
	}



	/**
	 * 文件写出
	 * @param file
	 */
	private void writeFile(File file) {
		Writer writer = null;
		BufferedWriter bw = null;
		try {
			writer = new FileWriter(file);
			bw = new BufferedWriter(writer);
			bw.write(textArea.getText());
		} catch (IOException e) {
			e.printStackTrace();
		} finally {
			if(bw != null) {
				try {
					bw.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			if(writer != null) {
				try {
			writer.close();
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
		}
	}




	public static void main(String[] args) {
		try {
			//设置windows自带的主题
			UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		} catch (InstantiationException e) {
			e.printStackTrace();
		} catch (IllegalAccessException e) {
			e.printStackTrace();
		} catch (UnsupportedLookAndFeelException e) {
			e.printStackTrace();
		}
		new Notepad();
	}
}