/*!
 * @header CFTAmount.h
 *
 * @brief An Amount object is initialized with a number representing a US dollar amount to use. 
 * All amounts will be rounded according to banker’s rounding if needed.
 *
 * @copyright 2017 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@interface CFTAmount : NSObject

/*!
 * @property decimalValue
 * @brief Value the amount object is set to
 * Added in 4.0
 */
@property (nonatomic, readonly, strong, nonnull) NSDecimalNumber *decimalValue;

/*!
 * @brief Convenience initializer for a CFTAmount object
 * @param decimalNumber NSDecimalNumber - Value for amount (format: X.XX)
 * @return CFTAmount - The initalized CFTAmount object
 * @discussion Will construct a new CFTAmount object using the NSDecimalNumber value provided.
 * The value property will be populated with a bankers rounded representation of the double value.
 * If decimalNumber is less than 0 or NaN, decimalValue will be 0.
 * Added in 4.0
 */
+ (nonnull instancetype)amountWithDecimalNumber:(nonnull NSDecimalNumber *)decimalNumber;

/*!
 * @brief Initialize a CFTAmount object
 * @param decimalNumber NSDecimalNumber - Value for amount (format: X.XX)
 * @return CFTAmount - The initalized CFTAmount object
 * @discussion Will construct a new CFTAmount object using the NSDecimalNumber value provided.
 * The value property will be populated with a bankers rounded representation of the double value.
 * If decimalNumber is less than 0 or NaN, decimalValue will be 0.
 * Added in 4.0
 */
- (nonnull instancetype)initWithDecimalNumber:(nonnull NSDecimalNumber *)decimalNumber
NS_SWIFT_NAME(init(decimalNumber:));

@end
