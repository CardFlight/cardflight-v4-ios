//
//  CFTGeneralError.h
//  CardFlight
//
//  Created by Rosy Sunuwar on 9/23/19.
//  Copyright © 2019 CardFlight Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CFTGeneralError : NSError

- (instancetype _Nonnull)initWithMessage:(NSString *_Nonnull)message code:(NSInteger)code;

- (NSString *_Nonnull)message;

- (NSString *_Nonnull)description;

@end
