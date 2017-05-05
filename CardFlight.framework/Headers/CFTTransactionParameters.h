//
//  CFTTransactionParameters.h
//  cardflight-sdk
//
//  Created by Paul Tower on 11/8/16.
//  Copyright © 2016 CardFlight. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CFTCredentials;
@class CFTAmount;

@interface CFTTransactionParameters : NSObject

@property (nonatomic, readonly, strong, nonnull) CFTAmount *amount;
@property (nonatomic, readonly, strong, nonnull) CFTCredentials *credentials;
@property (nonatomic, readwrite, strong, nullable) NSURL *callbackUrl;

/*!
 * @property requireSignature
 * @brief Used by keyed or swiped transactions. EMV transactions determine
 * the requirement of signature independently.
 */
@property (nonatomic, readwrite, assign) BOOL requireSignature;
@property (nonatomic, readwrite, strong, nullable) NSDictionary *metadata;

/*!
 * @brief Convenience initializer for a CFTTransactionParameters object
 * @param amount CFTAmount
 * @param credentials CFTCredentials
 * @return CFTTransactionParameters - The initalized CFTTransactionParameters object
 * @discussion Will construct a new CFTTransactionParameters object using amount provided.
 * Added in 4.0
 */
+ (nonnull instancetype)parametersWithAmount:(nonnull CFTAmount *)amount
                                 credentials:(nonnull CFTCredentials *)credentials;

/*!
 * @brief Initialize a CFTTransactionParameters object
 * @param amount CFTAmount
 * @param credentials CFTCredentials
 * @return CFTTransactionParameters - The initalized CFTTransactionParameters object
 * @discussion Will construct a new CFTTransactionParameters object using amount provided.
 * Added in 4.0
 */
- (nonnull instancetype)initWithAmount:(nonnull CFTAmount *)amount
                           credentials:(nonnull CFTCredentials *)credentials
NS_SWIFT_NAME(init(amount:credentials:));

@end
