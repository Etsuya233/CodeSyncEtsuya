import java.util.Scanner;

public class ScoreTest {
	public static void main(String[] args) {
		//新建Scanner对象
		Scanner scan = new Scanner(System.in);
		System.out.println("请输入成绩:");
		int score = scan.nextInt();
		String grade;
		//使用switch进行分支
		switch(score / 10) {
		case 10:
		case 9:
			grade = "优秀";
			break;
		case 8:
			grade = "良好";
			break;
		case 7:
			grade = "一般";
			break;
		case 6:
			grade = "及格";
			break;
		default:
			grade = "不及格";
			break;
		}
		System.out.println("该学生的分数为" + score + "分，成绩为" + grade + "。");
	}
}
