/*!
 * @header CFTMessage.h
 *
 * @brief Contains messages that should be displayed to the user during a transaction.
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface CFTMessage : NSObject

/*!
 * @property primary
 * @brief High priority message, should be displayed to the user
 * Added in 4.1.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *primary;

/*!
 * @property secondary
 * @brief Lower priority message, should be displayed to the user
 * Added in 4.1.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *secondary;

@end
