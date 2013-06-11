/*
 * (C) 2001-2012 Marmalade. All Rights Reserved.
 *
 * This document is protected by copyright, and contains information
 * proprietary to Marmalade.
 *
 * This file consists of source code released by Marmalade under
 * the terms of the accompanying End User License Agreement (EULA).
 * Please do not use this program/source code before you have read the
 * EULA and have agreed to be bound by its terms.
 */
/*
 * WARNING: this is an autogenerated file and will be overwritten by
 * the extension interface script.
 */
#ifndef S3E_EXT_ISCHARTBOOST_H
#define S3E_EXT_ISCHARTBOOST_H

//	IsChartboost Extension: Provides basic marmalade bindings for the cross-promotion
//	advertising library library from www.charhoost.com
//	Copyright (C) 2012 by 1013 Limited.
//
//  ===================================================
//  IsChartboost v0.2
//  ===================================================
//	Chartboost Android Version: 3.1.3
//	Chartboost IOS Version: 3.2.1
//  Targetting Marmalade SDK: 6.3.0


#include <s3eTypes.h>


// IsChartboost Callbacks available for registering
enum IsChartboostCallback
{
	ISCHARTBOOST_CALLBACK_REQUEST_RESPONSE,
	ISCHARTBOOST_CALLBACK_AD_CLOSED,
	ISCHARTBOOST_CALLBACK_AD_DISMISSED,
	ISCHARTBOOST_CALLBACK_AD_CLICKED,
	ISCHARTBOOST_CALLBACK_MAX,

};
// \cond HIDDEN_DEFINES
S3E_BEGIN_C_DECL
// \endcond

/**
 * Returns S3E_TRUE if the IsChartboost extension is available.
 */
s3eBool IsChartboostAvailable();

/**
 * Registers a callback to be called for an operating system event.
 *
 * The available callback types are listed in @ref IsChartboostCallback.
 * @param cbid ID of the event for which to register.
 * @param fn callback function.
 * @param userdata Value to pass to the @e userdata parameter of @e NotifyFunc.
 * @return
 *  - @ref S3E_RESULT_SUCCESS if no error occurred.
 *  - @ref S3E_RESULT_ERROR if the operation failed.\n
 *
 * @see IsChartboostUnRegister
 * @note For more information on the system data passed as a parameter to the callback
 * registered using this function, see the @ref IsChartboostCallback enum.
 */
s3eResult IsChartboostRegister(IsChartboostCallback cbid, s3eCallback fn, void* userData);

/**
 * Unregister a callback for a given event.
 * @param cbid ID of the callback for which to register.
 * @param fn Callback Function.
 * @return
 * - @ref S3E_RESULT_SUCCESS if no error occurred.
 * - @ref S3E_RESULT_ERROR if the operation failed.\n
 * @note For more information on the systemData passed as a parameter to the callback
 * registered using this function, see the IsChartboostCallback enum.
 * @note It is not necessary to define a return value for any registered callback.
 * @see IsChartboostRegister
 */
s3eResult IsChartboostUnRegister(IsChartboostCallback cbid, s3eCallback fn);

/**
* Sets the Application ID which will be used for chartboost.
* @note alternatively this can be set by icf '[IsChartboost] AndroidAppID=', but this function call will take priority
* over the icf setting.
* @par Required Header Files
* IsChartboost.h
*/
void IsChartboostSetAppID(const char* id);

/**
* Sets the Application Signature which will be used for chartboost.
* @note alternatively this can be set by icf '[IsChartboost] AndroidAppSignature=', but this function call will take priority
* over the icf setting.
* @par Required Header Files
* @deprecated in 2.0 ICF Setting , see Documentation or /docs/app.config.txt
* IsChartboost.h
*/
void IsChartboostSetAppSignature(const char* signature);

/**
* Starts the IsChartboost session, should be called only once.
* @par Required Header Files
* IsChartboost.h
* @deprecated in 2.0 use ICF Setting , see Documentation or /docs/app.config.txt
*/
void IsChartboostStartSession();

/**
* Requests an advertisement from chartboost does not show it.
* @see IsChartboostCallback, S3E_CHARTBOOST_CALLBACK_REQUEST_RESPONSE
* @note IsChartboostShowInterstitial will be called internally, then the callback will be initiated.
* if an interstitial was given then IsChartboostCacheInterstitial will be called internally.
* 0 returned on success, 1 or highier on failure.
* @par Required Header Files
* IsChartboost.h
*/
void IsChartboostRequestAd();

/**
* Cache the interstial that was given.
* @param name interstitial name to cache.
* @note read help.chartboost.com/documentation for usage.
* @par Required Header Files
* IsChartboost.h
*/
void IsChartboostCacheInterstitial(const char* name);

/**
* Request and show an interstitial.
* @param name interstitial name to request.
* @note read help.chartboost.com/documentation for usage. If no name is given, a default interstitial will be shown
* @par Required Header Files
* IsChartboost.h
*/
void IsChartboostShowInterstitial(const char* name);

/**
* IsChartboostCacheMoreApps
* @par Required Header Files
* IsChartboost.h
*/
void IsChartboostCacheMoreApps();

/**
* IsChartboostShowMoreApps
* @par Required Header Files
* IsChartboost.h
*/
void IsChartboostShowMoreApps();

S3E_END_C_DECL

#endif /* !S3E_EXT_ISCHARTBOOST_H */
