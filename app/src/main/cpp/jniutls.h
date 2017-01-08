//
// Created by jiantao on 2016/12/25.
//
#include <jni.h>

#ifndef _Included_mydemo_com_androidforndk_JNIUtils
#define _Included_mydemo_com_androidforndk_JNIUtils
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    intMethod
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_mydemo_com_androidforndk_JNIUtils_intMethod
        (JNIEnv *, jclass, jint);

/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    booleanMethod
 * Signature: (Z)Z
 */
JNIEXPORT jboolean JNICALL Java_mydemo_com_androidforndk_JNIUtils_booleanMethod
        (JNIEnv *, jclass, jboolean);

/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    stringMethod
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_mydemo_com_androidforndk_JNIUtils_stringMethod
        (JNIEnv *, jclass, jstring);

/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    intArrayMethod
 * Signature: ([I)I
 */
JNIEXPORT jint JNICALL Java_mydemo_com_androidforndk_JNIUtils_intArrayMethod
        (JNIEnv *, jclass, jintArray);

/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    ccallJava_helloFromJava
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_mydemo_com_androidforndk_JNIUtils_ccallJava_1helloFromJava
        (JNIEnv *, jobject);

/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    ccallJava_add
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_mydemo_com_androidforndk_JNIUtils_ccallJava_1add
        (JNIEnv *, jobject);

/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    ccallJava_printString
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_mydemo_com_androidforndk_JNIUtils_ccallJava_1printString
        (JNIEnv *, jobject);

/*
 * Class:     mydemo_com_androidforndk_JNIUtils
 * Method:    ccallJava_sayHello
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_mydemo_com_androidforndk_JNIUtils_ccallJava_1sayHello
        (JNIEnv *, jobject);

#ifdef __cplusplus
}
#endif
#endif