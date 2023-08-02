package com.etsuya.java6;

import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;

import static java.lang.annotation.ElementType.*;

/**
 * ClassName: MyAnnotation
 * Package: com.etsuya.java6
 * Description:
 *
 * @Author: Etsuya
 * @Create: 2023/3/24 21:27
 * @Version: 1.0
 */
@Target({TYPE, FIELD, METHOD, PARAMETER, CONSTRUCTOR, LOCAL_VARIABLE, MODULE})
@Retention(RetentionPolicy.SOURCE)
public @interface MyAnnotation {
	String table() default "null";
}
