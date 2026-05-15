#pragma once


#ifdef _WIN32
#ifdef SECRET_EXPORTS
#define SECRET_API __declspec(dllexport)
#else
#define SECRET_API __declspec(dllimport)
#endif
#else
#define SECRET_API
#endif


#ifdef __cplusplus
extern "C" {
#endif


SECRET_API const char* getSecretString();


#ifdef __cplusplus
}
#endif
