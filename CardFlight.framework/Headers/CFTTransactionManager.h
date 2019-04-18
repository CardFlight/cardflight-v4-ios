/*!
 * @header CFTTransactionManager.h
 *
 * @brief The Transaction Manager object is created (usually by a Transaction object)
 * to represent actions that can be taken on a transaction record.
 *
 * @copyright 2019 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "CFTConstants.h"

@class CFTAmount;
@class CFTMerchantAccount;
@class CFTTransactionParameters;
@class CFTTokenizationParameters;
@class CFTTransaction;

@protocol CFTTransactionDelegate;

@interface CFTTransactionManager : NSObject

/*!
 * @brief Shared manager for the CFTTransactionManager singleton.
 * @discussion This is used to create the singleton for the CFTTransactionManager class.
 * Added in 4.7.0
 */
+ (nonnull instancetype)shared;

/*!
 * @brief Attempt to begin a sale for an amount
 * @param transactionParameters CFTTransactionParameters - TransactionParameters used for sale
 * @param delegate CFTTransactionDelegate - TransactionDelegate used to report events to the transaction
 * @return CFTTransaction - containing the data of the created sale transaction.
 * @throws NSError - Throws error if create sale is failed.
 * @discussion Will attempt to begin a sale. If the state is not CFTTransactionStatePendingTransactionParameters,
 * the transactionDidUpdateState:error callback will respond with an error.
 * Added in 4.7.0
 */
- (nullable CFTTransaction *)createSaleWithTransactionParameters:(nonnull CFTTransactionParameters *)transactionParameters
                                                        delegate:(nonnull id<CFTTransactionDelegate>)delegate
                                                           error:(NSError *_Nullable *_Nullable)error
NS_SWIFT_NAME(createSale(transactionParameters:delegate:))
__attribute__((swift_error(nonnull_error)));

/*!
 * @brief Attempt to authorize an amount
 * @param transactionParameters CFTTransactionParameters - TransactionParameters used for authorization
 * @param delegate CFTTransactionDelegate - TransactionDelegate used to report events to the transaction
 * @return CFTTransaction - containing the data of the created authorization transaction
 * @throws NSError - Throws error if create auth is failed.
 * @discussion Will attempt to begin an authorization. If the state is not CFTTransactionStatePendingTransactionParameters,
 * the transactionDidUpdateState:error callback will respond with an error.
 * Added in 4.7.0
 */
- (nullable CFTTransaction *)createAuthWithTransactionParameters:(nonnull CFTTransactionParameters *)transactionParameters
                                                        delegate:(nonnull id<CFTTransactionDelegate>)delegate
                                                           error:(NSError *_Nullable *_Nullable)error
NS_SWIFT_NAME(createAuth(transactionParameters:delegate:))
__attribute__((swift_error(nonnull_error)));

/*!
 * @brief Attempt to tokenize a card
 * @param tokenizationParameters CFTTokenizationParameters - TokenizationParameters used for tokenize
 * @param delegate CFTTransactionDelegate - TransactionDelegate used to report events to the transaction
 * @return CFTTransaction - containing the data of the created tokenized transaction
 * @throws NSError - Throws error if create tokenization is failed.
 * @discussion Will attempt to begin the process of tokenizing. If the state is not CFTTransactionStatePendingTransactionParameters,
 * the transactionDidUpdateState:error callback will respond with an error.
 * Updated in 4.7.0
 */
- (nullable CFTTransaction *)createTokenizationWithParameters:(nonnull CFTTokenizationParameters *)tokenizationParameters
                                                     delegate:(nonnull id<CFTTransactionDelegate>)delegate
                                                        error:(NSError *_Nullable *_Nullable)error
NS_SWIFT_NAME(createTokenization(tokenizationParameters:delegate:))
__attribute__((swift_error(nonnull_error)));

/*!
 * @brief Refund an amount
 * @param amount CFTAmount - Amount to refund
 * @param transactionRecord CFTTransactionRecord is the transaction record that is being refunded
 * @param completion CFTTransactionBlock - Block to handle the result of the refund, contains CFTTransactionRecord and NSError
 * @discussion Will attempt to refund with the specified amount against the current transaction. Upon completion,
 * the completion block is triggered indicating the refund attempt has finished and potentially an error if the
 * refund did not complete successfully
 * Added in 4.7.0
 */
- (void)createRefundWithAmount:(nonnull CFTAmount *)amount
             transactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
                    completion:(nullable CFTTransactionBlock)completion
NS_SWIFT_NAME(refundTransaction(amount:transactionRecord:completion:));

/*!
 * @brief Attempt to void the current transaction
 * @param transactionRecord CFTTransactionRecord is the transaction record that is being voided
 * @param completion CFTStandardBlock - Block to handle the result of the void, contains BOOL and NSError
 * @discussion Will attempt to void the current transaction. Upon completion, the completion block is triggered
 * indicating the void attempt has finished and potentially an error if the void did not complete successfully
 * Added in 4.7.0
 */
- (void)attemptVoidWithTransactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
                              completion:(nullable CFTStandardBlock)completion
NS_SWIFT_NAME(attemptVoid(transactionRecord:completion:));

/*!
 * @brief Capture an authorized transaction
 * @param amount CFTAmount - Amount to capture
 * @param transactionRecord CFTTransactionRecord is the transaction record that is being captured
 * @param completion CFTStandardBlock - Block to handle the result of the capture, contains BOOL and NSError
 * @discussion Will attempt to capture a previously authorized transaction. Upon completion, the completion block is triggered
 * indicating the capture attempt has finished and potentially an error if the capture did not complete successfully
 * Added in 4.7.0
 */
- (void)captureAuthWithAmount:(nonnull CFTAmount *)amount
            transactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
                   completion:(nullable CFTStandardBlock)completion
NS_SWIFT_NAME(captureAuth(amount:transactionRecord:completion:));

/*!
 * @brief Retrieve the transaction record for a charge token
 * @param chargeId NSString - Charge token used to retrieve the transaction
 * @param merchantAccount - CFTMerchantAccount
 * @param completion CFTTransactionBlock - Block to handle the result, contains the retrieved CFTTransactionRecord
 * if successful. On failure, contains an NSError describing the error that occurred.
 * @discussion Retrieves a transaction record by querying the Cardflight API
 * Added in 4.7.0
 */
- (void)fetchTransactionRecordFromChargeId:(nonnull NSString *)chargeId
                           merchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
                                completion:(nonnull CFTTransactionBlock)completion
NS_SWIFT_NAME(fetchTransactionRecord(chargeId:merchantAccount:completion:));

/*!
 * @brief Refresh the transaction record
 * @param transactionRecord CFTTransactionRecord is the transaction record that is being refreshed
 * @param completion CFTStandardBlock - Block to handle the result, contains true on success and false
 * on failure. In the case of a failure, contains an NSError describing the error that occurred.
 * @discussion Will refresh the transaction record to reflect any server-side updates since the object was retrieved
 * Added in 4.7.0
 */
- (void)refreshWithTransactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
                          completion:(nullable CFTStandardBlock)completion
NS_SWIFT_NAME(refresh(transactionRecord:completion:));

@end
