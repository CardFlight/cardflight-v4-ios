/*!
 * @header CFTTokenizationParameters.h
 *
 * @brief The Tokenize Parameters object is used to pass parameters to a tokenization request.
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class CFTCredentials;
@class CFTMerchantAccount;

DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.8.1. Use `CFTTransactionManager` to create tokenization without `CFTTokenizationParameters`")
@interface CFTTokenizationParameters : NSObject

/*!
 * @property customerId
 * @brief An optional unique customer identifier to attach to the tokenization.
 * Added in 4.3.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *customerId;

/*!
 * @property credentials
 * @brief Credentials to use for processing.
 * Added in 4.3.0
 */
@property (nonatomic, readonly, strong, nonnull) CFTCredentials *credentials
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.7.0. Use `merchantAccount` instead");

- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

/*!
 * @property merchantAccount
 * @brief MerchantAccount to use for processing.
 * Added in 4.9.0
 */
@property (nonatomic, readonly, strong, nonnull) CFTMerchantAccount *merchantAccount;

/*!
 * @brief Convenience initializer for a CFTTokenizationParameters object
 * @param customerId NSString
 * @param credentials CFTCredentials
 * @return CFTTokenizationParameters - The initalized CFTTokenizationParameters object
 * @discussion Will construct a new CFTTokenizationParameters object using the customerId and credentials provided.
 * Added in 4.3.0
 */
+ (nonnull instancetype)parametersWithCustomerId:(nullable NSString *)customerId
                                     credentials:(nonnull CFTCredentials *)credentials
NS_SWIFT_NAME(parameters(customerId:credentials:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.7.0. Use `parameters(customerId:merchantAccount:)` instead");

/*!
 * @brief Convenience initializer for a CFTTokenizationParameters object
 * @param customerId NSString
 * @param merchantAccount CFTMerchantAccount
 * @return CFTTokenizationParameters - The initalized CFTTokenizationParameters object
 * @discussion Will construct a new CFTTokenizationParameters object using the customerId and merchantAccount provided.
 * Added in 4.9.0
 */
+ (nonnull instancetype)parametersWithCustomerId:(nullable NSString *)customerId
                                 merchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
NS_SWIFT_NAME(parameters(customerId:merchantAccount:));;

/*!
 * @brief Initialize a CFTTokenizationParameters object
 * @param customerId NSString
 * @param credentials CFTCredentials
 * @return CFTTokenizationParameters - The initalized CFTTokenizationParameters object
 * @discussion Will construct a new CFTTokenizationParameters object using the customerId and credentials provided.
 * Added in 4.3.0
 */
- (nonnull instancetype)initWithCustomerId:(nullable NSString *)customerId
                               credentials:(nonnull CFTCredentials *)credentials
NS_SWIFT_NAME(init(customerId:credentials:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.7.0. Use `init(customerId:merchantAccount:)` instead");

/*!
 * @brief Initialize a CFTTokenizationParameters object
 * @param customerId NSString
 * @param merchantAccount CFTMerchantAccount
 * @return CFTTokenizationParameters - The initalized CFTTokenizationParameters object
 * @discussion Will construct a new CFTTokenizationParameters object using the customerId and merchantAccount provided.
 * Added in 4.9.0
 */
- (nonnull instancetype)initWithCustomerId:(nullable NSString *)customerId
                           merchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
NS_SWIFT_NAME(init(customerId:merchantAccount:));

@end
