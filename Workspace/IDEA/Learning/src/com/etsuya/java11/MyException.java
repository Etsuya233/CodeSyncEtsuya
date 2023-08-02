package com.etsuya.java11;

/**
 * ClassName: MyException
 * Package: com.etsuya.java11
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/6/13 17:47
 * @Version: 1.0
 */
public class MyException extends Exception{
	@java.io.Serial
	static final long serialVersionUID = -3387516229948L;

	public MyException(){
	}

	public MyException(String msg){
		super(msg);
	}
}
