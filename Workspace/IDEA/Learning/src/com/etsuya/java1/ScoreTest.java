import java.util.Scanner;

public class ScoreTest {
	public static void main(String[] args) {
		//�½�Scanner����
		Scanner scan = new Scanner(System.in);
		System.out.println("������ɼ�:");
		int score = scan.nextInt();
		String grade;
		//ʹ��switch���з�֧
		switch(score / 10) {
		case 10:
		case 9:
			grade = "����";
			break;
		case 8:
			grade = "����";
			break;
		case 7:
			grade = "һ��";
			break;
		case 6:
			grade = "����";
			break;
		default:
			grade = "������";
			break;
		}
		System.out.println("��ѧ���ķ���Ϊ" + score + "�֣��ɼ�Ϊ" + grade + "��");
	}
}
