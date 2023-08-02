package com.etsuya.web;

import jakarta.servlet.FilterChain;
import jakarta.servlet.Servlet;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebFilter;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpFilter;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;

import java.io.IOException;

/**
 * ClassName: Filter
 * Package: com.etsuya.web
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/7/17 22:34
 * @Version: 1.0
 */
@WebFilter(urlPatterns = "/mq1")
public class Filter extends HttpFilter {
	@Override
	protected void doFilter(HttpServletRequest req, HttpServletResponse res, FilterChain chain) throws IOException, ServletException {
		if(getServletContext().getAttribute("stat") == null){
			getServletContext().setAttribute("stat", 1);
		} else {
			Integer stat = (Integer)getServletContext().getAttribute("stat");
			stat++;
			getServletContext().setAttribute("stat", stat);
		}
		System.out.println("Filtered");
		chain.doFilter(req, res);
	}
}
