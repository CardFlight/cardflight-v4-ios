//
//  CFTCredentials.h
//  cardflight-sdk
//
//  Created by Paul Tower on 10/13/16.
//  Copyright © 2016 CardFlight. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CFTEnum.h"
#import "CFTConstants.h"

@interface CFTCredentials : NSObject

@property (nonatomic, readonly, strong, nonnull) NSURL *baseUrl;
@property (nonatomic, readonly, copy, nullable) NSString *apiKey;
@property (nonatomic, readonly, copy, nullable) NSString *accountToken;
@property (nonatomic, readonly, copy, nullable) NSString *merchantAccountName;

- (void)privateFunctionOne:(nullable id)parameter
NS_SWIFT_NAME(privateFunctionOne(_:));

- (void)setupWithApiKey:(nonnull NSString *)apiKey
           accountToken:(nonnull NSString *)accountToken
             completion:(nullable CFTBasicBlock)completion
NS_SWIFT_NAME(setup(apiKey:accountToken:completion:));

- (nullable NSError *)checkForValidationError
NS_SWIFT_NAME(checkForValidationError());

- (void)forceRefreshWithCompletion:(nullable CFTBasicBlock)completion
NS_SWIFT_NAME(forceRefresh(completion:));

@end
