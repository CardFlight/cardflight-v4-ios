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
 * @brief Attempt to void the current transaction
 * @param transactionRecord CFTTransactionRecord is the transaction record that is being voided
 * @param completion CFTStandardBlock - Block to handle the result of the void, contains BOOL and NSError
 * @discussion Will attempt to void the current transaction. Upon completion, the completion block is triggered
 * indicating the void attempt has finished and potentially an error if the void did not complete successfully
 * Added in 4.7.0
 */
- (void)attemptVoidWithTransactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
                              completion:(nullable CFTStandardBlock)completion
NS_SWIFT_NAME(attemptVoid(transactionRecord:completion:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.1. Use `attemptVoid(transactionRecord:delegate:completion:)` instead");

/*!
 * @brief Attempt to create the void transaction
 * @param transactionRecord CFTTransactionRecord is the transaction record that needs to be voided.
 * @param completion CFTTransactionBlock - Block to handle the result of the void transaction creation, will be called with CFTTransaction and NSError
 * @discussion Will attempt to create a void transaction for the current transaction. Upon completion, the completion block is triggered
 * with the void transaction created and potentially an error if there is failure. `Will only succeed if transaction is in current open batch`
 * Added in 4.8.1
 */
- (void)attemptVoidWithTransactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
                     transactionDelegate:(nonnull id<CFTTransactionDelegate>)delegate
                              completion:(nullable CFTTransactionBlock)completion
NS_SWIFT_NAME(attemptVoid(transactionRecord:delegate:completion:));

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
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.1. Use `createAuth(amount:merchantAccount:delegate:completion)` or  `createAuth(amount:merchantAccount:callbackUrl:metadata:isSignatureRequired:isQuickChipEnabled:delegate:completion:)` instead")
__attribute__((swift_error(nonnull_error)));


/*!
 * @brief Creates a new transaction with transaction type authorization.
 * @param amount CFTAmount - Amount used for authorization
 * @param merchantAccount CFTMerchantAccount - Merchant account used for an authorization
 * @param delegate CFTTransactionDelegate - TransactionDelegate used to report events to the transaction
 * @param completion CFTTransactionBlock - Completion block which will be called with CFTTransaction or NSError upon completion.
 * @discussion Will attempt to begin an authorization.
 * Added in 4.8.1
 */
- (void)createAuthWithAmount:(nonnull CFTAmount *)amount
             merchantAccount:(nonnull CFTMerchantAccount*)merchantAccount
                    delegate:(nonnull id<CFTTransactionDelegate>)delegate
                  completion:(nonnull CFTTransactionBlock)completion
NS_SWIFT_NAME(createAuth(amount:merchantAccount:delegate:completion:));

/*!
 * @brief Creates a new transaction with transaction type authorization.
 * @param amount CFTAmount - Amount used for authorization
 * @param merchantAccount CFTMerchantAccount - Merchant account used for an authorization
 * @param callbackUrl NSURL - If provided, will be called back with transaction details.
 * @param metadata Any additional information you want saved along with the transaction.
 * @param isSignatureRequired Whether or not you want signature requested on `key`and `swiped`transactions.
 * @param isQuickChipEnabled Whether or not you want `quick chip` transactions enabled.
 * @param delegate CFTTransactionDelegate - TransactionDelegate used to report events to the transaction
 * @param completion CFTTransactionBlock - Completion block which will be called with CFTTransaction or NSError upon completion.
 * @discussion Will attempt to begin an authorization.
 * Added in 4.8.1
 */
- (void)createAuthWithAmount:(nonnull CFTAmount *)amount
             merchantAccount:(nonnull CFTMerchantAccount*)merchantAccount
                 callbackUrl:(nullable NSURL*)callbackUrl
                    metadata:(nullable NSDictionary<NSString*, NSString*>*)metadata
         isSignatureRequired:(BOOL)isSignatureRequired
          isQuickChipEnabled:(BOOL)isQuickChipEnabled
                    delegate:(nonnull id<CFTTransactionDelegate>)delegate
                  completion:(nonnull CFTTransactionBlock)completion
NS_SWIFT_NAME(createAuth(amount:merchantAccount:callbackUrl:metadata:isSignatureRequired:isQuickChipEnabled:delegate:completion:));

/*!
 * @brief Creates a new transaction with transaction type refund.
 * @param amount CFTAmount - Amount to refund
 * @param transactionRecord CFTTransactionRecord is the transaction record that is being refunded
 * @param completion CFTTransactionRecordBlock - Block to handle the result of the refund, contains CFTTransactionRecord and NSError
 * @discussion Will attempt to refund with the specified amount against the current transaction. Upon completion,
 * the completion block is triggered indicating the refund attempt has finished and potentially an error if the
 * refund did not complete successfully
 * Added in 4.7.0
 */
- (void)createRefundWithAmount:(nonnull CFTAmount *)amount
             transactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
                    completion:(nullable CFTTransactionRecordBlock)completion
NS_SWIFT_NAME(refundTransaction(amount:transactionRecord:completion:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.1. Use `createRefund(amount:transactionRecord:transactionDelegate:completion:)` or `createRefund(amount:callbackUrl:metadata:transactionRecord:transactionDelegate:completion:)` instead");

/*!
 * @brief Creates a refund transaction.
 * @param amount CFTAmount - Amount to refund
 * @param transactionRecord CFTTransactionRecord - Transaction record that needs to be refunded
 * @param delegate CFTTransactionDelegate - Delegate, which will be set to recieve callbacks during the created refund transaction's flow.
 * @param completion CFTTransactionBlock - Completion block which will be called with a transaction or an error after creating a refund transaction.
 * @discussion Will attempt to create a refund transaction with with the specified amount against the specified transaction record with transaction delegate set. Upon completion,
 * the completion block is triggered indicating that refund transaction is created.
 * Added in 4.8.1
 */
- (void)createRefundWithAmount:(nonnull CFTAmount *)amount
             transactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
           transactionDelegate:(nonnull id<CFTTransactionDelegate>)delegate
                    completion:(nullable CFTTransactionBlock)completion
NS_SWIFT_NAME(createRefund(amount:transactionRecord:transactionDelegate:completion:));

/*!
 * @brief Creates a refund transaction.
 * @param amount CFTAmount - Amount to refund
 * @param callbackUrl NSURL - If a callback url is provided, the cardflight gateway will provide that url with the refund transaction details.
 * @param metadata Any additional information you want saved along with the transaction.
 * @param transactionRecord CFTTransactionRecord - Transaction record that needs to be refunded
 * @param delegate CFTTransactionDelegate - Delegate, which will be set to recieve callbacks during the created refund transaction's flow.
 * @param completion CFTTransactionBlock - Completion block which will be called with a transaction or an error after creating a refund transaction.
 * @discussion Will attempt to create a refund transaction with with the specified amount against the specified transaction record with transaction delegate set. Upon completion,
 * the completion block is triggered indicating that refund transaction is created.
 * Added in 4.8.1
 */
- (void)createRefundWithAmount:(nonnull CFTAmount *)amount
                   callbackUrl:(nullable NSURL *)callbackUrl
                      metadata:(nullable NSDictionary<NSString*, NSString*>*)metadata
             transactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
           transactionDelegate:(nonnull id<CFTTransactionDelegate>)delegate
                    completion:(nullable CFTTransactionBlock)completion
NS_SWIFT_NAME(createRefund(amount:callbackUrl:metadata:transactionRecord:transactionDelegate:completion:));

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
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.1. Use `createSale(amount:merchantAccount:delegate:completion:)` or `createSale(amount:merchantAccount:callbackUrl:metadata:isSignatureRequired:isQuickChipEnabled:delegate:completion:)` instead")
__attribute__((swift_error(nonnull_error)));

/*!
 * @brief Creates a new transaction with transaction type sale.
 * @param amount CFTAmount - Amount used for transaction
 * @param merchantAccount CFTMerchantAccount - Merchant account used for transaction.
 * @param delegate CFTTransactionDelegate - TransactionDelegate used to report events to the transaction
 * @param completion CFTTransactionBlock - Completion block which will be called with CFTTransaction or NSError upon completion.
 * @discussion Will attempt to begin a sale. If the state is not CFTTransactionStatePendingTransactionParameters,
 * the transactionDidUpdateState:error callback will respond with an error.
 * Added in 4.8.1
 */
- (void)createSaleWithAmount:(nonnull CFTAmount *)amount
             merchantAccount:(nonnull CFTMerchantAccount*)merchantAccount
                    delegate:(nonnull id<CFTTransactionDelegate>)delegate
                  completion:(nonnull CFTTransactionBlock)completion
NS_SWIFT_NAME(createSale(amount:merchantAccount:delegate:completion:));

/*!
 * @brief Creates a new transaction with transaction type sale.
 * @param amount CFTAmount - Amount used for transaction
 * @param merchantAccount CFTMerchantAccount - Merchant account used for an transaction.
 * @param callbackUrl NSURL - If provided, will be called back with transaction details.
 * @param metadata Any additional information you want saved along with the transaction.
 * @param isSignatureRequired Whether or not you want signature requested on `key`and `swiped`transactions.
 * @param isQuickChipEnabled Whether or not you want `quick chip` transactions enabled.
 * @param delegate CFTTransactionDelegate - TransactionDelegate used to report events to the transaction
 * @param completion CFTTransactionBlock - Completion block which will be called with `CFTTransaction` or NSError upon completion.
 * @discussion Will attempt to begin an authorization.
 * Added in 4.8.1
 */
- (void)createSaleWithAmount:(nonnull CFTAmount *)amount
             merchantAccount:(nonnull CFTMerchantAccount*)merchantAccount
                 callbackUrl:(nullable NSURL*)callbackUrl
                    metadata:(nullable NSDictionary<NSString*, NSString*>*)metadata
         isSignatureRequired:(BOOL) isSignatureRequired
          isQuickChipEnabled:(BOOL) isQuickChipEnabled
                    delegate:(nonnull id<CFTTransactionDelegate>)delegate
                  completion:(nonnull CFTTransactionBlock)completion
NS_SWIFT_NAME(createSale(amount:merchantAccount:callbackUrl:metadata:isSignatureRequired:isQuickChipEnabled:delegate:completion:));

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
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.1. Use `createTokenization(merchantAccount:delegate:completion:)` or `createTokenization(merchantAccount:customerId:delegate:completion:)` instead")
__attribute__((swift_error(nonnull_error)));

/*!
 * @brief  Creates a new transaction with transaction type tokenization.
 * @param merchantAccount CFTMerchantAccount -  Merchant account to associate to the card.
 * @param delegate CFTTransactionDelegate - TransactionDelegate used to report events to the transaction
 * @param completion CFTTransactionBlock - Completion block which will be called with CFTTransaction or NSError upon completion.
 * @discussion Will attempt to begin the process of tokenizing.
 * Updated in 4.8.1
 */
- (void)createTokenizationWithMerchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
                                     delegate:(nonnull id<CFTTransactionDelegate>)delegate
                                   completion:(nonnull CFTTransactionBlock)completion
NS_SWIFT_NAME(createTokenization(merchantAccount:delegate:completion:));

/*!
 * @brief  Creates a new transaction with transaction type tokenization.
 * @param merchantAccount CFTMerchantAccount -  Merchant account to associate to the card.
 * @param customerId Customer ID to associate to card. If one is not specified, a new customer will be created.
 * @param delegate CFTTransactionDelegate - TransactionDelegate used to report events to the transaction
 * @param completion CFTTransactionBlock - Completion block which will be called with CFTTransaction or NSError upon completion.
 * @discussion Will attempt to begin the process of tokenizing.
 * Updated in 4.8.1
 */
- (void)createTokenizationWithMerchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
                                   customerId:(nullable NSString*)customerId
                                     delegate:(nonnull id<CFTTransactionDelegate>)delegate
                                   completion:(nonnull CFTTransactionBlock)completion
NS_SWIFT_NAME(createTokenization(merchantAccount:customerId:delegate:completion:));

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
                                completion:(nonnull CFTTransactionRecordBlock)completion
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

/**
 Resumes a previously deferred `CFTTransaction`

 @param transactionData `NSData` representation of `CFTTransaction`.
 @param delegate `CFTTransactionDelegate` to attach `to CFTTransaction`.
 @param completion Completion block which will be called with `CFTTransaction` or `NSError` upon completion.
 */
- (void)resumeDeferredTransaction:(nonnull NSData *)transactionData
                         delegate:(nonnull id<CFTTransactionDelegate>)delegate
                       completion:(nonnull CFTTransactionBlock)completion;
NS_SWIFT_NAME(resumeDeferredTransaction(data:delegate:completion));

/*!
 * @brief Get capabilities of a transaction.
 * @param transactionRecord CFTTransactionRecord
 * @param completion Completion block which will get called with capabilities.
 * Added in 4.9.0
 */
- (void)getCapabilitiesWithTransactionRecord: (nullable CFTTransactionRecord*)transactionRecord
                                completion: (void (^_Nonnull)(NSArray<NSNumber*> * _Nonnull capabilities))completion
NS_SWIFT_NAME(capabilities(trasactionRecord:completion:));


@end
