/*!
 * @header CFTCardReaderInfo.h
 *
 * @brief The Card Reader Info object is a representation of the 
 * card reader hardware used to capture card information. 
 * The Card Reader Info object has no writable parameters.
 *
 * @copyright 2017 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "CFTEnum.h"

@interface CFTCardReaderInfo : NSObject

/*!
 * @property name
 * @brief Name of the card reader
 * Added in 4.0
 */
@property (nonatomic, readonly, copy, nonnull) NSString *name;

/*!
 * @property cardReaderType
 * @brief Card Reader Type
 * Added in 4.0
 */
@property (nonatomic, readonly, assign) CFTCardReaderType cardReaderType;

/*!
 * @property cardReaderModel
 * @brief Card Reader Model
 * Added in 4.0
 */
@property (nonatomic, readonly, assign) CFTCardReaderModel cardReaderModel;

/*!
 * @property batteryStatus
 * @brief Battery Status
 * Added in 4.0
 */
@property (nonatomic, readonly, assign) CFTBatteryStatus batteryStatus;

@end
