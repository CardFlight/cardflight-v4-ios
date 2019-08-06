//
//  CFTDeviceManager.h
//  CardFlight
//
//  Created by Rosy Sunuwar on 7/26/19.
//  Copyright © 2019 CardFlight Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CFTDeviceManager : NSObject

/*!
 * @brief Get capabilities of a device used.
 * @param completion Completion block which will get called with capabilities.
 * Added in 4.8.5
 */
+ (void)getCapabilitiesWithCompletion: (void (^_Nonnull)(NSArray<NSNumber*> * _Nonnull capabilities))completion
NS_SWIFT_NAME(capabilities(completion:));

@end
