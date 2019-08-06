//
//  CFTPermissions.h
//  CardFlight
//
//  Created by Radhika Dayal on 4/1/19.
//  Copyright © 2019 CardFlight Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CFTPermissions : NSObject

/*!
 * @property dipEnabledReaders
 * @brief Array of allowed emv readers.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nonnull) NSArray<NSNumber *> *dipEnabledReaders;

/*!
 * @property quickChipEnabledReaders
 * @brief Array of allowed quick chip readers.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, copy, nonnull) NSArray<NSNumber *> *quickChipEnabledReaders;

/*!
 * @property isAvsEnabled
 * @brief Boolean to determine whether AVS is allowed or not.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, assign) BOOL isAvsEnabled;

/*!
 * @property isKeyedEntryEnabled
 * @brief Boolean to determine whether keyed entry is allowed or not.
 * Added in 4.7.0
 */
@property (nonatomic, readonly, assign) BOOL isKeyedEntryEnabled;

/*!
 * @property allowDebit
 * @brief Boolean to determine whether transactions can process over the debit network.
 * Added in 4.9.0
 */
@property (nonatomic, readonly, assign) BOOL allowDebit;

@end
