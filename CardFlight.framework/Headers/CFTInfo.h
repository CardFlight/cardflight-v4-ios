/*!
 * @header CFTInfo.h
 *
 * @brief Returns general info about the SDK
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface CFTInfo : NSObject

/*!
 * @brief Get current version number
 * @discussion Retrieves the current version number of the SDk
 * Added in 4.0.1
 */
+ (nonnull NSString *)versionString;

/*!
 * @brief Get current build number
 * @discussion Retrieves the current build number of the SDk
 * Added in 4.0.1
 */
+ (nonnull NSString *)buldString;

@end
