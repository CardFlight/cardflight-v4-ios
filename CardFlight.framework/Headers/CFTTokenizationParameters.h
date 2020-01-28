/*!
 * @header CFTTokenizationParameters.h
 *
 * @brief The Tokenize Parameters object is used to pass parameters to a tokenization request.
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

@class CFTCredentials;

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
@property (nonatomic, readonly, strong, nonnull) CFTCredentials *credentials;

- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

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
NS_SWIFT_NAME(parameters(customerId:credentials:));;

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
NS_SWIFT_NAME(init(customerId:credentials:));

@end
