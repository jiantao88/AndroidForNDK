//
// Created by jiantao on 2016/12/25.
//

#include <jni.h>
#include <string>

//extern "C"
//JNIEXPORT jstring JNICALL
//Java_mydemo_com_androidforndk_MainActivity_stringFromJNI(JNIEnv *env, jobject instance) {
//
//    // TODO
//    std::string hello = "hello jni ";
//
//    return env->NewStringUTF(hello.c_str());
//}

extern "C"
jstring Java_mydemo_com_androidforndk_MainActivity_stringFromJNI(JNIEnv *env, jobject instance) {
    std::string hello = "hello jni for c++ ";
    return env->NewStringUTF(hello.c_str());
}