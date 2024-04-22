#include <jni.h>
#include <string>
#include "CapteurTemperature.h"
#include <iostream>
#include <string>
#include "LampeMulticolore.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_domotiquelucas_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_domotiquelucas_MainActivity_RecupererTemperatureSalleA7(JNIEnv *env,
                                                                         jobject thiz) {
    // TODO: implement RecupererTemperatureSalleA7()
    CapteurTemperature captTemp("172.20.21.22", "F276DD7951", "Temp A7-1");
    string Temp = captTemp.Temperature();
    if(Temp.length()==4)Temp.insert(2,",");
    if(Temp.length()==3)Temp.insert(1,",");
    Temp = Temp + "°C";



    return  env->NewStringUTF(Temp.c_str());

}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_domotiquelucas_MainActivity_RecupererPressSallA7(JNIEnv *env, jobject thiz) {
    // TODO: implement RecupererPressSallA7()
    CapteurTemperature captTemp1("172.20.21.22", "F276DD7951", "Temp A7-1");
    string Press = captTemp1.Pression();
    Press = Press + " hPa";

    return env->NewStringUTF(Press.c_str());


}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_domotiquelucas_MainActivity_RecupereHumidSallA7(JNIEnv *env, jobject thiz) {
    // TODO: implement RecupereHumidSallA7()
    CapteurTemperature captTemp2("172.20.21.22", "F276DD7951", "Temp A7-1");
    string Humid = captTemp2.Humidite();
    if(Humid.length()==4)Humid.insert(2,",");
    if(Humid.length()==3)Humid.insert(1,",");
    Humid = Humid + "%";

    return env->NewStringUTF(Humid.c_str());
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_domotiquelucas_MainActivity_AllumerLampeMulticoloreA7(JNIEnv *env, jobject thiz) {
    // TODO: implement AllumerLampeMulticoloreA7()
    LampeMulticolore Lampe("172.20.21.22","F276DD7951","Extended color Light 3","3");
    Lampe.Allumer("true");
}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_domotiquelucas_MainActivity_EteindreLampeMulticoloreA7(JNIEnv *env, jobject thiz) {
    // TODO: implement EteindreLampeMulticoloreA7()
    LampeMulticolore Lampe1("172.20.21.22","F276DD7951","Extended Lights 3","3");
    Lampe1.Allumer("false");

}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_domotiquelucas_MainActivity_ModifierBrillanceLampeMulticoloreA7(JNIEnv *env,
                                                                                 jobject thiz,
                                                                                 jstring valeur) {
    // TODO: implement ModifierBrillanceLampeMulticoloreA7()
    LampeMulticolore Lampe2("172.20.21.22","F276DD7951","Extended Color Light 3","3");
    string valeurBrillance = env->GetStringUTFChars(valeur, NULL);
    Lampe2.Intensite(valeurBrillance);



}
extern "C"
JNIEXPORT void JNICALL
Java_com_example_domotiquelucas_MainActivity_CouleurModifier(JNIEnv *env, jobject thiz,
                                                             jstring valeur) {
    // TODO: implement CouleurModifier()

    LampeMulticolore Lampe3("172.20.21.22","F276DD7951","Extended Color Light 3","3");
    Lampe3.Teinte(reinterpret_cast<basic_string<char> &&>(valeur));
}