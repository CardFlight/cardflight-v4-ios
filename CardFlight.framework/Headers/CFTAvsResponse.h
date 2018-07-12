/*!
 * @header CFTAvsResponse.h
 *
 * @brief The CFTAvsResponse object is a representation of a transaction's `AVS` result
 * The CFTAvsResponse object has no writable parameters.
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "CFTEnum.h"

@interface CFTAvsResponse : NSObject

/*!
 * @property streetAddressAvsResult
 * @brief Street address's AVS result
 * Added in 4.5.0
 */
@property (nonatomic, readonly, assign) CFTAvsResult streetAddressAvsResult;

/*!
 * @property zipAvsResult
 * @brief Zip's AVS result.
 * Added in 4.5.0
 */
@property (nonatomic, readonly, assign) CFTAvsResult zipAvsResult;

@end
