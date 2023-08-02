package com.etsuya.web;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

/**
 * ClassName: MyServlet2
 * Package: com.etsuya.web
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/7/17 20:34
 * @Version: 1.0
 */
@WebServlet(urlPatterns = "/ms2")
public class MyServlet2 extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		resp.getWriter().println("<head><title>MS2</title></head><body><h1>FUCK U BITCH</h1></body>");
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	}
}
