/*!
 * @header CFTTransaction.h
 *
 * @brief The Transaction object is used to process any charges you want to make. 
 * It is the main point of interaction with the CardFlight SDK.
 *
 * @copyright 2018 CardFlight Inc. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import "CFTEnum.h"
#import "CFTConstants.h"

@class CFTCardInfo;
@class CFTCardReaderInfo;
@class CFTCardAID;
@class CFTAmount;
@class CFTKeyedEntryView;
@class CFTMerchantAccount;
@class CFTMessage;
@class CFTKeyedEntryContainer;
@class CFTTransactionRecord;
@class CFTAdjustment;

@protocol CFTTransactionDelegate;

@interface CFTTransaction : NSObject

/*!
 * @property delegate
 * @brief Delegate to receive callbacks during a transaction
 * Added in 4.0.0
 */
@property (nonatomic, readwrite, weak, nullable) id <CFTTransactionDelegate> delegate;

/*!
 * @property amount
 * @brief Amount to process
 * Added in 4.8.8
 */
@property (nonatomic, readonly, strong, nullable) CFTAmount *amount;

/*!
 * @property merchant account
 * @brief MerchantAccount to use for processing
 * Added in 4.8.8
 */
@property (nonatomic, readonly, strong, nullable) CFTMerchantAccount *merchantAccount;

/*!
 * @property callbackUrl
 * @brief If a callback url is specified, the CardFlight Gateway will provide that url with all transaction details.
 * Added in 4.8.8
 */
@property (nonatomic, readonly, strong, nullable) NSURL *callbackUrl;

/*!
 * @property isSignatureRequired
 * @brief The boolean for requesting a signature is only honored for keyed and swiped transactions.
 * The CardFlight Gateway decides whether to request a signature for all other card input methods used.
 * Added in 4.8.8
 */
@property (nonatomic, readonly, assign) BOOL isSignatureRequired;

/*!
 * @property isQuickChipEnabled
 * @brief The boolean is for weather or not quick chip is enabled.
 * Added in 4.8.8
 */
@property (nonatomic, readonly, assign) BOOL isQuickChipEnabled;

/*!
 * @property metadata
 * @brief The metadata hash is used to store any additional information with a Transaction on the CardFlight Gateway.
 * This data will also be sent to the callback url if one was provided.
 * Added in 4.8.8
 */
@property (nonatomic, readonly, strong, nullable) NSDictionary<NSString *, id> *metadata;

/*!
 * @property cardInfo
 * @brief Card Info used by the Transaction.
 * Added in 4.8.8
 */
@property (nonatomic, readonly, strong, nullable) CFTCardInfo *cardInfo;

/*!
 * @property cvm
 * @brief Cardholder verification method used by the Transaction.
 * Added in 4.8.8
 */
@property (nonatomic, readonly, assign) CFTCVM cvm;

/*!
 * @property message
 * @brief Message object containing the message from the result of Transaction.
 * Added in 4.8.8
 */
@property (nonatomic, readonly, strong, nullable) CFTMessage *message;

/*!
 * @property transactionRecord
 * @brief Transaction record created after the Transaction is complete.
 * Added in 4.8.8
 */
@property (nonatomic, readonly, strong, nullable) CFTTransactionRecord *transactionRecord;

/*!
 * @property adjustment
 * @brief Adjustment applied to the Transaction.
 * Added in 4.8.8
 */
@property (nonatomic, readonly, strong, nullable) CFTAdjustment *adjustment;

/*!
 * @property reachability
 * @brief Current reachability of the transaction
 * Added in 4.1.0
 */
@property (nonatomic, readonly) CFTReachability reachability;

/**
  Network type used for the transaction.
 */
@property (nonatomic, readonly) CFTNetworkType networkType;


- (nonnull instancetype)init NS_UNAVAILABLE;
+ (nonnull instancetype)new NS_UNAVAILABLE;

/*!
 * @brief Initialize with a delegate
 * @param delegate id<CFTTransactionDelegate> - Delegate to be assigned
 * @return CFTTransaction - Initialized with the passed delegate, or nil if the SDK is in a state where a transaction cannot be started
 * @discussion Convenience class initializer that accepts a delegate so that 
 * callbacks can be received immediately.
 * Added in 4.0.0
 */
+ (nullable instancetype)transactionWithDelegate:(nonnull id<CFTTransactionDelegate>)delegate;

/*!
 * @brief Initialize with a delegate
 * @param delegate id<CFTTransactionDelegate> - Delegate to be assigned
 * @return CFTTransaction - Initialized with the passed delegate, or nil if the SDK is in a state where a transaction cannot be started
 * @discussion Initializer that accepts a delegate so that callbacks
 * can be received immediately.
 * Added in 4.0.0
 */
- (nullable instancetype)initWithDelegate:(nonnull id<CFTTransactionDelegate>)delegate
NS_SWIFT_NAME(init(delegate:));

/*!
 * @brief Update the reachability of the transaction
 * @param reachability CFTReachability
 * @discussion Updates the reachability for the transaction. New
 * transactions default to CFTReachabilityFull
 * Added in 4.1.0
 */
- (void)updateReachability:(CFTReachability)reachability
NS_SWIFT_NAME(update(reachability:));

/*!
 * @brief Scan for compatible Bluetooth card readers
 * @discussion Initiates a scan for compatible Bluetooth card readers
 * Added in 4.0.0
 */
- (void)scanBluetoothCardReaders
NS_SWIFT_NAME(scanBluetoothCardReaders());

/*!
 * @brief Select a CFTCardReader
 * @param cardReaderInfo CFTCardReaderInfo
 * @param cardReaderModel CFTCardReaderModel
 * @discussion Will connect with the supplied reader.
 * Added in 4.0.0
 */
- (void)selectCardReaderInfo:(nullable CFTCardReaderInfo *)cardReaderInfo
             cardReaderModel:(CFTCardReaderModel)cardReaderModel
NS_SWIFT_NAME(select(cardReaderInfo:cardReaderModel:));

/*!
 * @brief Use a keyed entry view
 * @param zipEnabled BOOL
 * @return CFTKeyedEntryView - Returned with passed zipEnabled
 * @discussion Will return a keyed entry view if state is CFTTransactionStatePendingTransactionParameters or CFTTransactionStatePendingCardInput
 * Added in 4.0.0
 */
- (nullable CFTKeyedEntryView *)keyedEntryViewWithZipEnabled:(BOOL)zipEnabled
NS_SWIFT_NAME(keyedEntryView(zipEnabled:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.6.0. Use `keyedEntryContainer` instead");

/*!
 * @brief Use a card or address entry view
 * @return CFTKeyedEntryContainer - Returned entry view container
 * @discussion Will return an entry container if state is CFTTransactionStatePendingTransactionParameters or CFTTransactionStatePendingCardInput
 * Container will have its avsEntryView property populated if AVS is supported
 * Added in 4.6.0
 */
- (nullable CFTKeyedEntryContainer*)keyedEntryContainer
NS_SWIFT_NAME(keyedEntryContainer());


/*!
 * @brief Use card and avs info generated from keyed entry views
 * @discussion Will use information input into keyed entry views for card and avs info
 * Added in 4.0.0
 */
- (void)useKeyedCardInfo
NS_SWIFT_NAME(useKeyedCardInfo());

/*!
 * @brief Select a CFTCardAID to use for the transaction
 * @param cardAid CFTCardAID
 * @discussion Will use the card application identifier.
 * Added in 4.0.0
 */
- (void)selectCardAid:(nonnull CFTCardAID *)cardAid
NS_SWIFT_NAME(select(cardAid:));


/**
 * Attach an adjustment to the transaction. This should only be called after receiving the
 * `CFTTransaction`'s `didRequestAdjustment:` callback.
 *
 * @param adjustment Adjustment containing all adjustment information for the transaction.
 */
- (void)attachAdjustment:(nonnull CFTAdjustment*)adjustment
NS_SWIFT_NAME(attach(adjustment:));

/*!
 * @brief Specify how to process the transaction
 * @param processOption CFTProcessOption
 * @discussion Will attempt to use the process option for transaction continuation. If the state is not
 * CFTTransactionStatePendingProcessOption, the transactionDidUpdateState:error callback will respond with an error.
 * Added in 4.0.0
 */
- (void)selectProcessOption:(CFTProcessOption)processOption
NS_SWIFT_NAME(select(processOption:));

/*!
 * @brief Attach signature CVM to transaction
 * @param signatureImage png of signature to be attached
 * @discussion Will attempt to attach signature. If the state is not
 * CFTTransactionStateCompleted, the transactionDidUpdateState:error callback will respond with an error.
 * Added in 4.1.0
 */
- (void)attachSignature:(nullable UIImage *)signatureImage
NS_SWIFT_NAME(attach(signature:));

@end

@protocol CFTTransactionDelegate <NSObject>

@required

/*!
 * @brief The current state of the transaction
 * @param transaction CFTTransaction
 * @param state CFTTransactionState
 * @param error NSError
 * @discussion Required callback telling the transaction changed state. If an illegal state
 * change was attempted, an error will be returned.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didUpdateState:(CFTTransactionState)state error:(nullable NSError *)error
NS_SWIFT_NAME(transaction(_:didUpdate:error:));

/*!
 * @brief A message to display to users
 * @param transaction CFTTransaction
 * @param message NSString
 * @discussion Required callback containing a message to be displayed to users.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didRequestDisplayMessages:(nonnull CFTMessage *)message
NS_SWIFT_NAME(transaction(_:didRequestDisplay:));

/*!
 * @brief The card info to use for the transaction
 * @param transaction CFTTransaction
 * @param cardInfo CFTCardInfo
 * @discussion Required callback containing a representation of the card used for the transaction.
 * Pass the desired CFTProcessOption into selectProcessOption.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didRequestProcessOptionWithCardInfo:(nonnull CFTCardInfo *)cardInfo
NS_SWIFT_NAME(transaction(_:didRequestProcessOption:));

/*!
 * @brief The deferred transaction data
 * @param transaction CFTTransaction
 * @param transactionData NSData
 * @discussion Required callback containing a data representation of a transaction
 * if CFTProcessOptionDefer was used for selectProcessOption.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didDeferWithData:(nonnull NSData *)transactionData
NS_SWIFT_NAME(transaction(_:didDefer:));

/*!
 * @brief The cardholder verification method requested
 * @param transaction CFTTransaction
 * @param cvm CFTCVM
 * @discussion Required callback containing he cardholder verification method requested
 * for the transaction. If CFTCVMSignature is requested, pass
 * a base64 encoded image as NSData into attachCvmData.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didRequestCvm:(CFTCVM)cvm
NS_SWIFT_NAME(transaction(_:didRequest:));

/*!
 * @brief A transaction record from a completed transaction
 * @param transaction CFTTransaction
 * @param transactionRecord CFTTransactionRecord
 * @discussion Required callback containing the resulting transaction record
 * from a transaction in the CFTTransactionStateCompleted state.
 * Added in 4.7.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didCompleteWithTransactionRecord:(nonnull CFTTransactionRecord *)transactionRecord
NS_SWIFT_NAME(transaction(_:didComplete:));

@optional

/*!
 * @brief A historical transaction from a completed transaction
 * @param transaction CFTTransaction
 * @param historicalTransaction CFTHistoricalTransaction
 * @discussion Optional callback containing the resulting historical transaction
 * from a transaction in the CFTTransactionStateCompleted state.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didCompleteWithHistoricalTransaction:(nonnull CFTHistoricalTransaction *)historicalTransaction
NS_SWIFT_NAME(transaction(_:didComplete:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.7.0. Use `didCompleteWithTransactionRecord` instead");

/*!
 * @brief A card reader event was received
 * @param transaction CFTTransaction
 * @param cardReaderEvent CFTCardReaderEvent
 * @param cardReaderInfo CFTCardReaderInfo
 * @discussion Optional callback triggered when a card reader encounters an event.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didReceiveCardReaderEvent:(CFTCardReaderEvent)cardReaderEvent
     cardReaderInfo:(nullable CFTCardReaderInfo *)cardReaderInfo
NS_SWIFT_NAME(transaction(_:didReceive:cardReaderInfo:));

/*!
 * @brief A keyed entry event was received
 * @param transaction CFTTransaction
 * @param keyedEntryEvent CFTKeyedEntryEvent
 * @discussion Optional callback triggered when a keyed entry view encounters an event.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didReceiveKeyedEntryEvent:(CFTKeyedEntryEvent)keyedEntryEvent
NS_SWIFT_NAME(transaction(_:didReceive:))
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 4.6.0. Use `didReceiveKeyedEntryContainerEvent` instead");

/*!
 * @brief An entry event was received
 * @param transaction CFTTransaction
 * @param keyedEntryContainerEvent CFTKeyedEntryContainerEvent
 * @discussion Optional callback triggered when the keyed entry container encounters an event.
 * Added in 4.6.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didReceiveKeyedEntryContainerEvent:(CFTKeyedEntryContainerEvent)keyedEntryContainerEvent
NS_SWIFT_NAME(transaction(_:didReceive:));

/*!
 * @brief The card readers available for use
 * @param transaction CFTTransaction
 * @param cardReaderArray NSArray<CFTCardReaderInfo *>
 * @discussion Optional callback with the available card readers that can
 * be used to obtain card data. Pass the desired card reader into selectCardReaderInfo.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didUpdateCardReaderArray:(nonnull NSArray<CFTCardReaderInfo *> *)cardReaderArray
NS_SWIFT_NAME(transaction(_:didUpdate:));

/*!
 * @brief The card input methods available for use
 * @param transaction CFTTransaction
 * @param cardInputMethodArray NSArray<NSNumber *>
 * @discussion Optional callback with the available card input methods for the connected reader
 * that can be used to process a transaction. The integerValue of a respective card input method
 * matches directly with a CFTCardInputMethod enum value.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didUpdateCardInputMethodArray:(nonnull NSArray<NSNumber *> *)cardInputMethodArray
NS_SWIFT_NAME(transaction(_:didUpdate:));

/*!
 * @brief The card application identifiers available for use
 * @param transaction CFTTransaction
 * @param cardAidArray NSArray<CFTCardAID *>
 * @discussion Optional callback with the available card application identifiers to use for the transaction.
 * Pass the desired card application identifier into selectCardAid.
 * Added in 4.0.0
 */
- (void)transaction:(nonnull CFTTransaction *)transaction didRequestCardAidSelection:(nonnull NSArray<CFTCardAID *> *)cardAidArray
NS_SWIFT_NAME(transaction(_:didRequestCardAidSelection:));


/**
 Adjustment requested.

 @param transaction `CFTTransaction` this method needs to add adjustment for.
 */
- (void)didRequestAdjustmentForTransaction:(nonnull CFTTransaction*)transaction
NS_SWIFT_NAME(didRequestAdjustmentFor(transaction:));

@end
