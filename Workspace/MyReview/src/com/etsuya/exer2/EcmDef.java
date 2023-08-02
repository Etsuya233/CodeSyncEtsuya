package com.etsuya.exer2;

public class EcmDef {
	public static void main(String[] args) {
		try {
			int a = Integer.parseInt(args[0]);
			int b = Integer.parseInt(args[1]);
			int c = calc(a, b);
			System.out.print("结果：" + c);
		} catch (ArrayIndexOutOfBoundsException e){
			System.out.println("缺少命令行参数！");
		} catch (NumberFormatException e){
			System.out.println("数据类型不一致！");
		} catch (ArithmeticException e){
			System.out.println("不能除以0！");
		} catch (EcDef e){
			e.getMessage();
		}
		Object a = new Object();
		
	}

	public static int calc(int a, int b) throws EcDef{
		if(a < 0 || b < 0) throw new EcDef("不能输入负数！");
		else return a / b;
	}
}

class EcDef extends Exception{
	@java.io.Serial
	static final long serialVersionUID = -703121245766939L;

	public EcDef(){

	}

	public EcDef(String msg){
		super(msg);
	}
}