/*!
 * @header CFTMerchantAccount.h
 *
 * @brief The MerchantAccount object is created to authenticate a Transaction object.
 *
 * @copyright 2019 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import "CFTEnum.h"
#import "CFTConstants.h"

@class CFTPermissions;

@interface CFTMerchantAccount : NSObject

/*!
 * @property baseV1Url
 * @brief URL to optionally use a different v1 API URL
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nonnull) NSURL *baseV1Url;

/*!
 * @property baseV2Url
 * @brief URL to optionally use a different v2 API URL
 * Added in 4.7.0
 */
@property (nonatomic, readonly, strong, nonnull) NSURL *baseV2Url;

/*!
 * @property apiKey
 * @brief API Key of CardFlight account
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *apiKey;

/*!
 * @property merchantAccountId
 * @brief ID of merchant on CardFlight account
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *merchantAccountId;

/*!
 * @property merchantAccountName
 * @brief Name of merchant account on CardFlight account
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *merchantAccountName;

/*!
 * @property mid
 * @brief Merchant account id.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *mid;

/*!
 * @property tid
 * @brief Terminal id.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) NSString *tid;

/*!
 * @property permissions
 * @brief Permissions of the merchant account.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nullable) CFTPermissions *permissions;

@end
