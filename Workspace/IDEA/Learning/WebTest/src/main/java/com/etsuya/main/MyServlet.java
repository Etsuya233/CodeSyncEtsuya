package com.etsuya.main;

import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;

/**
 * ClassName: MyServlet
 * Package: com.etsuya.main
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/7/16 19:55
 * @Version: 1.0
 */
public class MyServlet extends HttpServlet {
	@Override
	protected void service(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		super.service(req, resp);
		System.out.println("fuck u boy");
	}
}
