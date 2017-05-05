//
//  CFTAmount.h
//  cardflight-sdk
//
//  Created by Adam Duflo on 12/7/16.
//  Copyright © 2016 CardFlight. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CFTAmount : NSObject

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
