package com.etsuya.web;

import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.Cookie;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.CharArrayReader;
import java.io.IOException;

/**
 * ClassName: Math1Displayer
 * Package: com.etsuya.web
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/7/17 21:06
 * @Version: 1.0
 */
@WebServlet(urlPatterns = "/math_display")
public class Math1Display extends HttpServlet {
	@Override
	protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		Cookie[] cookies = req.getCookies();
		String latestScore = "oops there's no score for u";
		for(Cookie cookie: cookies){
			if(cookie.getName().equals("latestScore")) latestScore = cookie.getValue();
		}
		resp.getWriter().println("<head><title>Math Test - " + req.getAttribute("lesson") + " - Result</title></head><body><h1>Accuracy: "
				+ req.getAttribute("accuracy")
				+ "<br/><h3>Last score: </h3>"
				+ latestScore
				+ "</h1></body><br/>"
				+ "This site has been entered " + getServletContext().getAttribute("stat") + "time(s).");

	}

	@Override
	protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
		doGet(req, resp);
	}
}
