/*!
 * @header CFTCredentials.h
 *
 * @brief The Credentials object is created to authenticate a Transaction object. 
 * Once setup, the object will remain valid for 6 hours.
 *
 * @copyright 2017 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "CFTEnum.h"
#import "CFTConstants.h"

@interface CFTCredentials : NSObject

/*!
 * @property baseUrl
 * @brief URL to optionally use a different API URL
 * Added in 4.0.0
 */
@property (nonatomic, readonly, strong, nonnull) NSURL *baseUrl;

/*!
 * @property apiKey
 * @brief API Key of CardFlight account
 * Added in 4.0.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *apiKey;

/*!
 * @property accountToken
 * @brief Account Token of merchant on CardFlight account
 * Added in 4.0.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *accountToken;

/*!
 * @property merchantAccountName
 * @brief Name of merchant on CardFlight account
 * Added in 4.0.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *merchantAccountName;

/*!
 * @brief Private method
 * @param parameter id - Parameter of the method
 * @discussion This is only to be used by clients who have made arrangements with CardFlight
 * Added in 4.0.0
 */
- (void)privateFunctionOne:(nullable id)parameter
NS_SWIFT_NAME(privateFunctionOne(_:));

/*!
 * @brief The current state of the transaction
 * @param apiKey API Key of CardFlight account
 * @param accountToken Account Token of merchant on CardFlight account
 * @param completion Block trigged upon upon completion of network request.
 * @discussion The setup method is used to assign an API Key and Account Token to the Credentials object. 
 * When this method is called, a network request is made to validate the parameters provided with the CardFlight Gateway.
 * Added in 4.0.0
 */
- (void)setupWithApiKey:(nonnull NSString *)apiKey
           accountToken:(nonnull NSString *)accountToken
             completion:(void(^ _Nullable)(CFTCredentials * _Nonnull credentials, BOOL success, NSError * _Nullable error))completion
NS_SWIFT_NAME(setup(apiKey:accountToken:completion:));

/*!
 * @brief Returns any current error with the credentials
 * @return NSError - current error, if there is one
 * @discussion - The Credentials object has a method to check for any errors that may have occurred during the last validation attempt. 
 * If the return value is populated, that is an indication that something went wrong during validation 
 * and the Credentials object should either be refreshed or corrected according to the error message.
 * Added in 4.0.0
 */
- (nullable NSError *)checkForValidationError
NS_SWIFT_NAME(checkForValidationError());

/*!
 * @brief Trigger a refresh of the credentials with the CardFlight Gateway
 * @param completion Block trigged upon upon completion of network request.
 * @discussion - Force the API Key and Account Token originally provided to be re-validated using the CardFlight Gateway.
 * This is useful if the Credentials object being used has timed out or has errored in some other way.
 * Added in 4.0.0
 */
- (void)forceRefreshWithCompletion:(void(^ _Nullable)(CFTCredentials * _Nonnull credentials, BOOL success, NSError * _Nullable error))completion
NS_SWIFT_NAME(forceRefresh(completion:));

@end
