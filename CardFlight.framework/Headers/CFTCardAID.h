/*!
 * @header CCFTCardAID.h
 *
 * @brief The AID (Application Identifier) of a card is used
 * to determine which payment system to use.
 *
 * @copyright 2017 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface CFTCardAID : NSObject

/*!
 * @property name
 * @brief Name of the AID
 * Added in 4.0.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *name;

@end
