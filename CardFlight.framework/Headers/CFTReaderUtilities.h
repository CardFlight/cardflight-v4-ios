//
//  CFTReaderUtilities.h
//  CardFlight
//
//  Created by Daniel Panzer on 11/2/17.
//  Copyright © 2017 CardFlight Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "CFTCardReaderInfo.h"

@protocol CFTReaderUtilitiesDelegate;

@interface CFTReaderUtilities : NSObject

+ (nonnull instancetype)shared;

@property (nonatomic, weak, readwrite, nullable) NSObject<CFTReaderUtilitiesDelegate> *delegate;


/**
 @property shouldKeepReaderConnectionAlive
 @brief Flag indicating if reader should stay connected or not between transactions. Reader would still be disconnected when session closes.
 Added in 4.6.3
 */
@property (nonatomic, assign) BOOL shouldKeepReaderConnectionAlive;

/*!
 * @brief Opens a utilities session
 * @discussion Will request a utilities session in order to scan or connect to card readers
 * Added in 4.1.0
 */
- (void)openSessionWithDelegate:(nullable NSObject<CFTReaderUtilitiesDelegate>*)delegate
NS_SWIFT_NAME(openSession(with:));

/*!
 * @brief Closes the current utilities session
 * @discussion Will request to close the current utilities session. Will disconnect any currently connected reader
 * Added in 4.1.0
 */
- (void)closeSession
NS_SWIFT_NAME(closeSession());

/*!
 * @brief Scan for compatible Bluetooth card readers
 * @discussion Initiates a scan for compatible Bluetooth card readers
 * Added in 4.1.0
 */
- (void)scanBluetoothCardReaders
NS_SWIFT_NAME(scanBluetoothCardReaders());

/*!
 * @brief Select a CFTCardReader
 * @param cardReaderInfo CFTCardReaderInfo
 * @param cardReaderModel CFTCardReaderModel
 * @discussion Will connect with the supplied reader.
 * Added in 4.1.0
 */
- (void)selectCardReaderInfo:(nullable CFTCardReaderInfo *)cardReaderInfo
             cardReaderModel:(CFTCardReaderModel)cardReaderModel
NS_SWIFT_NAME(select(cardReaderInfo:cardReaderModel:));

/*!
 * @brief Disconnect a CFTCardReader
 * @discussion Will disconnect the currently connected CFTCardReader
 * Added in 4.1.0
 */
- (void)disconnectCardReader
NS_SWIFT_NAME(disconnectCardReader());

@end

@protocol CFTReaderUtilitiesDelegate <NSObject>

@optional

/*!
 * @brief A session was opened or closed
 * @param utilities CFTReaderUtilities
 * @param status CFTReaderUtilitiesSessionStatus
 * @param error NSError
 * @discussion Optional callback triggered when a session is opened or closed.
 * Added in 4.1.0
 */
- (void)utilities:(nonnull CFTReaderUtilities *)utilities didUpdateSessionStatusTo:(CFTReaderUtilitiesSessionStatus)status withError:(nullable NSError *)error
NS_SWIFT_NAME(utilities(_:didUpdateSessionStatusTo:withError:));

/*!
 * @brief A card reader event was received
 * @param utilities CFTReaderUtilities
 * @param cardReaderEvent CFTCardReaderEvent
 * @param cardReaderInfo CFTCardReaderInfo
 * @discussion Optional callback triggered when a card reader encounters an event.
 * Added in 4.1.0
 */
- (void)utilities:(nonnull CFTReaderUtilities *)utilities didReceiveCardReaderEvent:(CFTCardReaderEvent)cardReaderEvent
     cardReaderInfo:(nullable CFTCardReaderInfo *)cardReaderInfo
NS_SWIFT_NAME(utilities(_:didReceive:cardReaderInfo:));

/*!
 * @brief The card readers available for use
 * @param utilities CFTReaderUtilities
 * @param cardReaderArray NSArray<CFTCardReaderInfo *>
 * @discussion Optional callback with the available card readers that can
 * be used to obtain card data. Pass the desired card reader into selectCardReaderInfo.
 * Added in 4.1.0
 */
- (void)utilities:(nonnull CFTReaderUtilities *)utilities didUpdateCardReaderArray:(nonnull NSArray<CFTCardReaderInfo *> *)cardReaderArray
NS_SWIFT_NAME(utilities(_:didUpdate:));

@end
