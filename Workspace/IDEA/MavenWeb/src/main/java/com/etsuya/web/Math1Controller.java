package com.etsuya.web;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

/**
 * ClassName: Math1Servlet
 * Package: com.etsuya.web
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/7/17 20:44
 * @Version: 1.0
 */

@WebServlet(urlPatterns = "/mq1")
public class Math1Controller extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {


		int right_number = 0;
		if(req.getParameter("q1_a").trim().equals("8")) right_number++;
		if(req.getParameter("q2_a").trim().equals("5")) right_number++;
		if(req.getParameter("q3_a").trim().equals("18")) right_number++;
		if(req.getParameter("q4_a").trim().equals("4")) right_number++;

		int accuracy = (int)(right_number / 4.0 * 100);

		req.setAttribute("lesson", 1);
		req.setAttribute("accuracy", accuracy);

		Cookie latestScore = new Cookie("latestScore", String.valueOf(accuracy));
		latestScore.setPath("/");
		latestScore.setMaxAge(25000);
		resp.addCookie(latestScore);

		req.getRequestDispatcher("/math_display").forward(req, resp);
	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	}
}
