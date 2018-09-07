/*
 *****************************************************************
 * CFTKeyedEntryContainer.h
 *
 * Copyright (c) 2018 CardFlight Inc. All rights reserved.
 *****************************************************************
 */

#import <UIKit/UIKit.h>
#import "CFTCardEntryView.h"
#import "CFTAvsEntryView.h"

@interface CFTKeyedEntryContainer : NSObject

/*!
 * @property cardEntryView
 * @brief view to present for card entry
 * Added in 4.6.0
 */
@property (nonnull, nonatomic, readonly) CFTCardEntryView *cardEntryView;

/*!
 * @property avsEntryView
 * @brief view to present for address entry. Only populated if AVS is supported
 * Added in 4.6.0
 */
@property (nullable, nonatomic, readonly) CFTAvsEntryView *avsEntryView;

@end
