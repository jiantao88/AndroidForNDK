//
// Created by jiantao on 2016/12/25.
//
#include "jniutls.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <android/log.h>

/**
 * 把一个jstring转换成一个c++语言的char* 类型.
 */
char *_JString2CStr(JNIEnv *env, jstring jstr) {
    char *rtn = NULL;
    jclass jclass1 = env->FindClass("java/lang/String");
    jstring jstrencode = env->NewStringUTF("GB2312");
    //GetMethodID需要传三个参数，第一个是很显然jclass，第二个参数是java方法名，也就是你想取的method ID的那个方法的方法名（有些绕口 ），第三个参数是方法签名
    //http://hubeihuyanwei.blog.163.com/blog/static/28205284201282911925396/
    jmethodID mid = env->GetMethodID(jclass1, "getBytes", "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, jstrencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
//        分配长度为num_bytes字节的内存块
        rtn = (char *) malloc((size_t) (alen + 1));
        //void *memcpy(void*dest, const void *src, size_t n);
        //由src指向地址为起始地址的连续n个字节的数据复制到以destin指向地址为起始地址的空间内。
        memcpy(rtn, ba, (size_t) alen);
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return 0;
}

JNIEXPORT jint JNICALL
Java_mydemo_com_androidforndk_JNIUtils_intArrayMethod(JNIEnv *env, jclass type, jintArray arr_) {
//    jint *arr = env->GetIntArrayElements(arr_, NULL);

    // TODO
    int sum = 0;
    jsize len = env->GetArrayLength(arr_);
    jint *arr = env->GetIntArrayElements(arr_, 0);
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    env->ReleaseIntArrayElements(arr_, arr, 0);
    return sum;
}

JNIEXPORT jstring JNICALL
Java_mydemo_com_androidforndk_JNIUtils_stringMethod(JNIEnv *env, jclass type, jstring str_) {
//    const char *str = env->GetStringUTFChars(str_, 0);
    char *fromjava = _JString2CStr(env, str_);
    char *fromC = (char *) "add I am from C!! ";

//字符串的拼接函数，会把拼接后的结果放在第一个参数里面
    strcat(fromjava, fromC);
    env->ReleaseStringUTFChars(str_, fromjava);

    return env->NewStringUTF(fromjava);
}

JNIEXPORT jboolean JNICALL
Java_mydemo_com_androidforndk_JNIUtils_booleanMethod(JNIEnv *env, jclass type, jboolean b) {

    // TODO
    return (jboolean) !b;
}

JNIEXPORT jint JNICALL
Java_mydemo_com_androidforndk_JNIUtils_intMethod(JNIEnv *env, jclass type, jint num) {

    // TODO
    return num * num;
}

JNIEXPORT void JNICALL
Java_mydemo_com_androidforndk_JNIUtils_ccallJava_1helloFromJava(JNIEnv *env, jobject jobj) {
    jclass jclazz;
    jclazz = env->FindClass("mydemo/com/androidforndk/JNIUtils");
    jmethodID jmethodid = env->GetMethodID(jclazz, "helloFromJava", "()V");
    jobject jobjs = env->AllocObject(jclazz);
    env->CallVoidMethod(jobjs, jmethodid);
};

/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    ccallJava_add
 * Signature: ()V
 */
JNIEXPORT void JNICALL
Java_mydemo_com_androidforndk_JNIUtils_ccallJava_1add(JNIEnv *env, jobject){
    //1.得到类对应的字节码
//全类名，把.改成/
//jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = env->FindClass("mydemo/com.androidforndk/JNIUtils");
    jmethodID jmethodid = env->GetMethodID(jclazz, "add",
                                           "(II)I");

//3.得到要调用的方法对应的类的实例
// jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobjs = env->AllocObject(jclazz);
//4.调用方法
// jint        (*CallIntMethod)(JNIEnv*, jobject, jmethodID, ...);
    int reusle = env->CallIntMethod(jobjs, jmethodid, 99, 1);
};
/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    ccallJava_printString
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_mydemo_com_androidforndk_JNIUtils_ccallJava_1printString
        (JNIEnv *env, jobject){
    //1.得到类对应的字节码
//全类名，把.改成/
//jclass      (*FindClass)(JNIEnv*, const char*);
    jclass jclazz = env->FindClass("mydemo/com.androidforndk/JNIUtils");

//2.得到要调用的方法名
//第三个参数：方法名
//第四个但是：方法签名
//jmethodID   (*GetMethodID)(JNIEnv*, jclass, const char*, const char*);
    jmethodID jmethodid = env->GetMethodID(jclazz, "printString",
                                           "(Ljava/lang/String;)V");

//3.得到要调用的方法对应的类的实例
// jobject     (*AllocObject)(JNIEnv*, jclass);
    jobject jobjs = env->AllocObject(jclazz);
//4.调用方法
// void        (*CallVoidMethod)(JNIEnv*, jobject, jmethodID, ...);
    jstring text = env->NewStringUTF("I am from C!!");
    env->CallVoidMethod(jobjs, jmethodid, text); //成功调用了Java中JNI里面的printString(String s);
};

/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    ccallJava_sayHello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_mydemo_com_androidforndk_JNIUtils_ccallJava_1sayHello
        (JNIEnv *env, jobject){
//1.得到字节码
    jclass jclazz = env->FindClass("mydemo/com.androidforndk/JNIUtils");
//2.得到方法
    jmethodID jmethodid = env->GetStaticMethodID(jclazz, "sayHello", "(Ljava/lang/String;)V");

//3.调用
//void        (*CallStaticVoidMethod)(JNIEnv*, jclass, jmethodID, ...);
    jstring text = env->NewStringUTF("I am from C!! I am static method !!!");
    env->CallStaticVoidMethod(jclazz, jmethodid, text);//成功调用了Java中JNI类的静态方法sayHello(String text)
};