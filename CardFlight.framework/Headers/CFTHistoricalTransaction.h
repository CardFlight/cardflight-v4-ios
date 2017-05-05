//
//  CFTHistoricalTransaction.h
//  cardflight-sdk
//
//  Created by Paul Tower on 11/7/16.
//  Copyright © 2016 CardFlight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CFTEnum.h"
#import "CFTConstants.h"

@class CFTTransactionParameters;
@class CFTCardReaderInfo;
@class CFTCardInfo;
@class CFTAmount;

@interface CFTHistoricalTransaction : NSObject

@property (nonatomic, readonly, strong, nullable) NSUUID *uuid;
@property (nonatomic, readonly, strong, nonnull) NSDate *createdAt;
@property (nonatomic, readonly, assign) CFTTransactionResult result;
@property (nonatomic, readonly, copy, nullable) NSString *declineMessage;
@property (nonatomic, readonly, strong, nullable) NSError *error;
@property (nonatomic, readonly, strong, nullable) NSURL *signatureUrl;
@property (nonatomic, readonly, strong, nullable) CFTCardReaderInfo *cardReaderInfo;
@property (nonatomic, readonly, strong, nullable) CFTCardInfo *cardInfo;
@property (nonatomic, readonly, strong, nullable) NSDate *transactedAt;
@property (nonatomic, readonly, strong, nullable) CFTTransactionParameters *transactionParameters;
@property (nonatomic, readonly, assign) CFTTransactionType transactionType;

/*!
 * @brief Attempt to void the current transaction
 * @param completion CFTStandardBlock - Block to handle the result of the void, contains BOOL and NSError
 * @discussion Will attempt to void the current transaction. Upon completion, the completion block is triggered
 * indicating the void attempt has finished and potentially an error if the void did not complete successfully
 * Added in 4.0
 */
- (void)voidTransactionWithCompletion:(nullable CFTStandardBlock)completion
NS_SWIFT_NAME(voidTransaction(completion:));

/*!
 * @brief Capture an authorized transaction
 * @param amount CFTAmount - Amount to capture
 * @param completion CFTStandardBlock - Block to handle the result of the void, contains BOOL and NSError
 * @discussion Will attempt to capture a previously authorized transaction. Upon completion, the completion block is triggered
 * indicating the capture attempt has finished and potentially an error if the capture did not complete successfully
 * Added in 4.0
 */
- (void)captureTransactionWithAmount:(nonnull CFTAmount *)amount
                          completion:(nullable CFTStandardBlock)completion
NS_SWIFT_NAME(captureTransaction(amount:completion:));

/*!
 * @brief Refund an amount
 * @param amount CFTAmount - Amount to refund
 * @param completion CFTTransactionBlock - Block to handle the result of the refund, contains CFTHistoricalTransaction and NSError
 * @discussion Will attempt to refund with the specified amount against the current transaction. Upon completion,
 * the completion block is triggered indicating the refund attempt has finished and potentially an error if the
 * refund did not complete successfully
 * Added in 4.0
 */
- (void)refundTransactionWithAmount:(nonnull CFTAmount *)amount
                         completion:(nullable CFTTransactionBlock)completion
NS_SWIFT_NAME(refundTransaction(amount:completion:));

@end
