/*!
 * @header CFTTransactionParameters.h
 *
 * @brief Handles the parameters set on an individual transaction
 * Required to start a transaction.
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class CFTCredentials;
@class CFTAmount;
@class CFTMerchantAccount;

DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.1. Use `CFTTransactionManager` to create transaction without `CFTTransactionParameters`.")
@interface CFTTransactionParameters : NSObject

/*!
 * @property amount
 * @brief Amount to process
 * Added in 4.0.0
 */
@property (nonatomic, readonly, strong, nonnull) CFTAmount *amount;

/*!
 * @property credentials
 * @brief Credentials to use for processing
 * Added in 4.0.0
 */
@property (nonatomic, readonly, strong, nullable) CFTCredentials *credentials
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.7.0. Use `merchantAccount` instead");

/*!
 * @property merchant account
 * @brief MerchantAccount to use for processing
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nonnull) CFTMerchantAccount *merchantAccount;

/*!
 * @property callbackUrl
 * @brief If a callback url is specified, the CardFlight Gateway will provide that url with all transaction details.
 * Added in 4.0.0
 */
@property (nonatomic, readwrite, strong, nullable) NSURL *callbackUrl;

/*!
 * @property requireSignature
 * @brief The boolean for requesting a signature is only honored for keyed and swiped transactions.
 * The CardFlight Gateway decides whether to request a signature for all other card input methods used.
 * Added in 4.0.0
 */
@property (nonatomic, readwrite, assign) BOOL requireSignature;

/*!
 * @property isQuickChipEnabled
 * @brief The boolean is for weather or not quick chip is enabled.
 * Added in 4.8.0
 */
@property (nonatomic, readwrite, assign) BOOL isQuickChipEnabled;


/*!
 * @property metadata
 * @brief The metadata hash is used to store any additional information with a Transaction on the CardFlight Gateway.
 * This data will also be sent to the callback url if one was provided.
 * Added in 4.0.0
 */
@property (nonatomic, readwrite, strong, nullable) NSDictionary *metadata;

/*!
 * @brief Convenience initializer for a CFTTransactionParameters object
 * @param amount CFTAmount
 * @param credentials CFTCredentials
 * @return CFTTransactionParameters - The initalized CFTTransactionParameters object
 * @discussion Will construct a new CFTTransactionParameters object using amount provided.
 * Added in 4.0.0
 */
+ (nonnull instancetype)parametersWithAmount:(nonnull CFTAmount *)amount
                                 credentials:(nonnull CFTCredentials *)credentials
DEPRECATED_MSG_ATTRIBUTE("Deprecated as of 4.7.0. Use `parametersWithAmount` instead");

/*!
 * @brief Convenience initializer for a CFTTransactionParameters object
 * @param amount CFTAmount
 * @param merchantAccount CFTMerchantAccount
 * @return CFTTransactionParameters - The initalized CFTTransactionParameters object
 * @discussion Will construct a new CFTTransactionParameters object using amount provided.
 * Added in 4.7.0
 */
+ (nonnull instancetype)parametersWithAmount:(nonnull CFTAmount *)amount
                             merchantAccount:(nonnull CFTMerchantAccount *)merchantAccount;

/*!
 * @brief Initialize a CFTTransactionParameters object
 * @param amount CFTAmount
 * @param credentials CFTCredentials
 * @return CFTTransactionParameters - The initalized CFTTransactionParameters object
 * @discussion Will construct a new CFTTransactionParameters object using amount provided.
 * Added in 4.0.0
 */
- (nonnull instancetype)initWithAmount:(nonnull CFTAmount *)amount
                           credentials:(nonnull CFTCredentials *)credentials
NS_SWIFT_NAME(init(amount:credentials:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated as of 4.7.0. Use `initWithAmount` instead");

/*!
 * @brief Initialize a CFTTransactionParameters object
 * @param amount CFTAmount
 * @param merchantAccount CFTMerchantAccount
 * @return CFTTransactionParameters - The initalized CFTTransactionParameters object
 * @discussion Will construct a new CFTTransactionParameters object using amount provided.
 * Added in 4.7.0
 */
- (nonnull instancetype)initWithAmount:(nonnull CFTAmount *)amount
                       merchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
NS_SWIFT_NAME(init(amount:merchantAccount:));

@end
