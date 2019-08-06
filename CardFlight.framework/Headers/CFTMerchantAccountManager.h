/*!
 * @header CFTMerchantAccountManager.h
 *
 * @brief The MerchantAccountManager object is created to authenticate a MerchantAccount object.
 *
 * @copyright 2019 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "CFTEnum.h"
#import "CFTConstants.h"

@class CFTMerchantAccount;

@interface CFTMerchantAccountManager : NSObject

/*!
 * @brief Shared manager for the CFTMerchantAccountManager singleton.
 * @discussion This is used to create the singleton for the CFTMerchantAccountManager class.
 * Added in 4.7.0
 */
+ (nonnull instancetype)shared;

/*!
 * @brief Initializes a MerchantAccount object with a merchant account id and api key
 * @param merchantAccountId - Identifier for a merchant account
 * @param apiKey - ApiKey for a merchant account
 * @param error - Double pointer to an error that could be populated in the event that an unrecoverable error occurs. (In swift, it is a try-catch.)
 * @discussion This is used to create a MerchantAccount object using the merchantAccoutId and apiKey given
 * Added in 4.7.0
 */
- (nonnull CFTMerchantAccount *) createWithMerchantAccountId:(nonnull NSString *)merchantAccountId
                                                      apiKey:(nonnull NSString *)apiKey
                                                       error:(NSError * _Nullable * _Nullable)error
NS_SWIFT_NAME(create(merchantAccountId:apiKey:))
__attribute__((swift_error(nonnull_error)));

/*!
 * @brief Private method
 * @param merchantAccount - MerchantAccount
 * @param parameter id - Parameter of the method
 * @discussion This is only to be used by clients who have made arrangements with CardFlight
 * Added in 4.7.0
 */
- (void) privateFunctionOneWithMerchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
                                     parameter:(nullable id)parameter
NS_SWIFT_NAME(privateFunctionOne(merchantAccount:_:));

/*!
 * @brief Private method
 * @param parameter id - Parameter of the method
 * @param merchantAccount - MerchantAccount
 * @discussion This is only to be used by clients who have made arrangements with CardFlight
 * Added in 4.7.0
 */
- (void) privateFunctionTwoWithMerchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
                                     parameter:(nullable id)parameter
NS_SWIFT_NAME(privateFunctionTwo(merchantAccount:_:));

/*!
 * @brief Trigger a validation of the merchant account with the CardFlight Gateway
 * @param merchantAccount - MerchantAccount
 * @param completion Block trigged upon upon completion of network request.
 * @discussion - Force the API Key and Merchant Account ID originally provided to be re-validated using the CardFlight Gateway.
 * This is useful if the Merchant Account object being used has timed out or has errored in some other way.
 * Added in 4.7.0
 */
- (void) validateWithMerchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
                          completion:(void(^ _Nullable)(BOOL success, NSError * _Nullable error))completion
NS_SWIFT_NAME(validate(merchantAccount:completion:));

/*!
 * @brief Returns any current error with the merchant account
 * @param merchantAccount - MerchantAccount
 * @return NSError - current error, if there is one
 * @discussion - The Merchant Account object has a method to check for any errors that may have occurred during the last validation attempt.
 * If the return value is populated, that is an indication that something went wrong during validation
 * and the Merchant Account object should either be refreshed or corrected according to the error message.
 * Added in 4.7.0
 */
- (nullable NSError *) getValidationErrorWithMerchantAccount:(nonnull CFTMerchantAccount *)merchantAccount
NS_SWIFT_NAME(getValidationError(merchantAccount:));

/*!
* @brief Get capabilities of a merchant account.
* @param merchantAccount CFTMerchantAccount
* @param completion Completion block which will get called with capabilities.
* Added in 4.0.0
*/
- (void)getCapabilitiesWithMerchantAccount: (nonnull CFTMerchantAccount*)merchantAccount
                                completion: (void (^_Nonnull)(NSArray<NSNumber*> * _Nonnull capabilities))completion
NS_SWIFT_NAME(capabilities(merchantAccount:completion:));

@end
