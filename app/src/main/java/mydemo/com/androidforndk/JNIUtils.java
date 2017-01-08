package mydemo.com.androidforndk;

import android.util.Log;

/**
 * Created by jiantao on 2016/12/25.
 */

public class JNIUtils {

    static {
        System.loadLibrary("jniutils");
    }
    public static native int intMethod(int num);
    public static native boolean booleanMethod(boolean b);
    public static native String stringMethod(String str);
    public static native int intArrayMethod(int[]arr);
    /**
     * C调用java空方法,并且没有返回值的方法
     */
    public void helloFromJava(){
        Log.e("JNI", "I am helloFromJava(),我被C调用了！！！");
    }
    /**
     * C调用java中的带两个int参数的方法
     * @param x
     * @param y
     * @return
     */
    public int add(int x,int y) {
        int result = x + y;
        Log.e("JNI", "I am add(int x,int y),我被C调用了！！！result=="+result);
        return result;
    }
    /**
     * C调用java中参数为string的方法
     * @param s
     */
    public void printString(String s){
        Log.e("JNI", "I am printString(String s),我被C调用了！！！s=="+s);
    }


    /**
     * C语言调用下面静态方法.
     * @param text
     */
    public static void sayHello(String text) {
        System.out.println("I am:  sayHello(String text)==" + text);
        Log.e("JNI", "I am:  sayHello(String text)==" + text);
    }
    /**  ========================== c call java======================================**/

    /**
     * 让C代码的某个方法，来回调Java中JNI类的 helloFromJava()方法
     */
    public native void ccallJava_helloFromJava();

    /**
     * 让C代码的某个方法，来回调Java中JNI类的 add(int x,int y)方法
     */
    public native void ccallJava_add();


    /**
     * 让C代码的某个方法，来回调Java中JNI类的 printString(String s)方法
     */
    public native void ccallJava_printString();

    /**
     * 让C代码的某个方法，来回调Java中JNI类的sayHello(String text)静态方法
     */
    public native void ccallJava_sayHello();
    /**  ========================== c call java======================================**/

}
