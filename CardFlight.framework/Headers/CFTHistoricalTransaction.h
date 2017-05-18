/*!
 * @header CFTHistoricalTransaction.h
 *
 * @brief The Historical Transaction object is created (usually by a Transaction object) 
 * to represent the record of a past transaction.
 *
 * @copyright 2017 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "CFTEnum.h"
#import "CFTConstants.h"

@class CFTTransactionParameters;
@class CFTCardReaderInfo;
@class CFTCardInfo;
@class CFTAmount;

@interface CFTHistoricalTransaction : NSObject

/*!
 * @property uuid
 * @brief UUID of the Transaction
 * Added in 4.0
 */
@property (nonatomic, readonly, strong, nullable) NSUUID *uuid;

/*!
 * @property createdAt
 * @brief Date when the Transaction was created
 * Added in 4.0
 */
@property (nonatomic, readonly, strong, nonnull) NSDate *createdAt;

/*!
 * @property result
 * @brief Result of the Transaction
 * Added in 4.0
 */
@property (nonatomic, readonly, assign) CFTTransactionResult result;

/*!
 * @property declineMessage
 * @brief Decline message (Only populated if the result was declined)
 * Added in 4.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *declineMessage;

/*!
 * @property error
 * @brief Error that occurred (Only populated if the result was errored)
 * Added in 4.0
 */
@property (nonatomic, readonly, strong, nullable) NSError *error;

/*!
 * @property signatureUrl
 * @brief URL of the signature data
 * Added in 4.0
 */
@property (nonatomic, readonly, strong, nullable) NSURL *signatureUrl;

/*!
 * @property cardReaderInfo
 * @brief Card Reader Info used by the Transaction
 * Added in 4.0
 */
@property (nonatomic, readonly, strong, nullable) CFTCardReaderInfo *cardReaderInfo;

/*!
 * @property cardInfo
 * @brief Card Info used by the Transaction
 * Added in 4.0
 */
@property (nonatomic, readonly, strong, nullable) CFTCardInfo *cardInfo;

/*!
 * @property transactedAt
 * @brief Date when the Transaction was processed
 * Added in 4.0
 */
@property (nonatomic, readonly, strong, nullable) NSDate *transactedAt;

/*!
 * @property transactionParameters
 * @brief Transaction Parameters used by the Transaction
 * Added in 4.0
 */
@property (nonatomic, readonly, strong, nullable) CFTTransactionParameters *transactionParameters;

/*!
 * @property transactionType
 * @brief Type of Transaction
 * Added in 4.0
 */
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
