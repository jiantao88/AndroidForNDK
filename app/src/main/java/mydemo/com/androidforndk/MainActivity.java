package mydemo.com.androidforndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("native-lib");
    }
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        boolean b= JNIUtils.booleanMethod(true);
        int square= JNIUtils.intMethod(33);
        String str= JNIUtils.stringMethod("dfffgf");
        int i=JNIUtils.intArrayMethod(new int[]{212,3445,1,2});
        TextView tv_javacallc= (TextView) findViewById(R.id.tv_javacallc);
        tv_javacallc.setText(b+","+square+","+str+","+i);
        JNIUtils jni=new JNIUtils();
        jni.ccallJava_add();
        jni.ccallJava_helloFromJava();
        jni.ccallJava_printString();
        jni.ccallJava_sayHello();
    }

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();
}
