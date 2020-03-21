#include <oqs/oqs.h>
#include "KeyEncapsulation.h"
#include "handle.h"

/*
 * Class:     org_openquantumsafe_KeyEncapsulation
 * Method:    get_new_KEM
 * Signature: (Ljava/lang/String;)Loqs/KeyEncapsulation/KeyEncapsulationDetails;
 */
JNIEXPORT void JNICALL Java_org_openquantumsafe_KeyEncapsulation_create_1KEM_1new
  (JNIEnv *env, jobject obj, jstring java_str)
{
    // Create get a liboqs::OQS_KEM pointer 
    const char *_nativeString = (*env)->GetStringUTFChars(env, java_str, 0);
    OQS_KEM *kem = OQS_KEM_new(_nativeString);
    (*env)->ReleaseStringUTFChars(env, java_str, _nativeString);
    // Stow the native OQS_KEM pointer in the Java handle.
    char kem_handle_field_[] = "native_kem_handle_";
    setHandle(env, obj, kem, kem_handle_field_);
}

/*
 * Class:     org_openquantumsafe_KeyEncapsulation
 * Method:    get_KEM_details
 * Signature: ()Lorg/openquantumsafe/KeyEncapsulation/KeyEncapsulationDetails;
 */
JNIEXPORT jobject JNICALL Java_org_openquantumsafe_KeyEncapsulation_get_1KEM_1details
  (JNIEnv *env, jobject obj)
{
    jclass cls = (*env)->FindClass(env, "org/openquantumsafe/KeyEncapsulation$KeyEncapsulationDetails");
    if (cls == NULL) { fprintf(stderr, "\nCould not find class\n"); return NULL; }
    
    // Get the Method ID of the constructor
    jmethodID org_openquantumsafe_oqs_ = (*env)->GetMethodID(env, cls, "<init>", "(Lorg/openquantumsafe/KeyEncapsulation;)V");
    if (NULL == org_openquantumsafe_oqs_) { fprintf(stderr, "\nCould not initialize class\n"); return NULL; }
    
    // Call back constructor to allocate a new instance, with an int argument
    jobject _nativeKED = (*env)->NewObject(env, cls, org_openquantumsafe_oqs_);
    
    char kem_handle_field_[] = "native_kem_handle_";
    OQS_KEM *kem = (OQS_KEM *) getHandle(env, obj, kem_handle_field_);
    
    // Copy fields from C struct to Java class
    // String method_name;
    jfieldID _method_name = (*env)->GetFieldID(env, cls, "method_name", "Ljava/lang/String;");
    jstring j_method_name = (*env)->NewStringUTF(env, kem->method_name);
    (*env)->SetObjectField(env, _nativeKED, _method_name, j_method_name);
    
    // String alg_version;
    jfieldID _alg_version = (*env)->GetFieldID(env, cls, "alg_version", "Ljava/lang/String;");
    jstring j_alg_version = (*env)->NewStringUTF(env, kem->alg_version);
    (*env)->SetObjectField(env, _nativeKED, _alg_version, j_alg_version);
    
    // byte claimed_nist_level;
    jfieldID _claimed_nist_level = (*env)->GetFieldID(env, cls, "claimed_nist_level", "B");
    (*env)->SetByteField(env, _nativeKED, _claimed_nist_level, (jbyte) kem->claimed_nist_level);
    
    // boolean ind_cca;
    jfieldID _ind_cca = (*env)->GetFieldID(env, cls, "ind_cca", "Z");
    (*env)->SetBooleanField(env, _nativeKED, _ind_cca, (jboolean) kem->ind_cca);
    
    // long length_public_key;
    jfieldID _length_public_key = (*env)->GetFieldID(env, cls, "length_public_key", "J");
    (*env)->SetLongField(env, _nativeKED, _length_public_key, (jlong) kem->length_public_key);
    
    // long length_secret_key;
    jfieldID _length_secret_key = (*env)->GetFieldID(env, cls, "length_secret_key", "J");
    (*env)->SetLongField(env, _nativeKED, _length_secret_key, (jlong) kem->length_secret_key);
    
    // long length_ciphertext;
    jfieldID _length_ciphertext = (*env)->GetFieldID(env, cls, "length_ciphertext", "J");
    (*env)->SetLongField(env, _nativeKED, _length_ciphertext, (jlong) kem->length_ciphertext);
    
    // long length_shared_secret;
    jfieldID _length_shared_secret = (*env)->GetFieldID(env, cls, "length_shared_secret", "J");
    (*env)->SetLongField(env, _nativeKED, _length_shared_secret, (jlong) kem->length_shared_secret);
    
    return _nativeKED;
}

