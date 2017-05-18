/*!
 * @header CFTEnum.h
 *
 * @brief Enumerations used with the SDK
 *
 * @copyright 2017 CardFlight Inc. All rights reserved.
 */

#import <Foundation/Foundation.h>

/*!
 * @typedef CFTTransactionState
 * @brief Current state of the transaction
 * @constant CFTTransactionStateUnknown Transaction is in an unknown state, should not occur in normal operation
 * @constant CFTTransactionStatePendingTransactionParameters Transaction has no transaction parameters and is not ready to begin
 * @constant CFTTransactionStatePendingCardInput Transaction has been set up and is waiting for card input
 * @constant CFTTransactionStatePendingProcessOption Transaction has payment attached and is waiting for process option selection
 * @constant CFTTransactionStateProcessing Transaction is currently processing the payment
 * @constant CFTTransactionStateCompleted Transaction has finished processing
 * @constant CFTTransactionStateDeferred Transaction has been deferred and must be resumed using deferred transaction data
 * @discussion Current public state of the transaction
 * Most transactions will proceed through all 5 states in linear order.
 * The current state can be used to determine the flow of control in the host application.
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTTransactionState) {
    CFTTransactionStateUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTTransactionStatePendingTransactionParameters NS_SWIFT_NAME(pendingTransactionParameters) = 1,
    CFTTransactionStatePendingCardInput NS_SWIFT_NAME(pendingCardInput) = 2,
    CFTTransactionStatePendingProcessOption NS_SWIFT_NAME(pendingProcessOption) = 3,
    CFTTransactionStateProcessing NS_SWIFT_NAME(processing) = 4,
    CFTTransactionStateCompleted NS_SWIFT_NAME(completed) = 5,
    CFTTransactionStateDeferred NS_SWIFT_NAME(deferred) = 6
};

/*!
 * @typedef CFTCardReaderEvent
 * @brief Events triggered by the card reader
 * @constant CFTCardReaderEventUnknown Unknown event, should not occur in normal operation
 * @constant CFTCardReaderEventDisconnected A reader was disconnected
 * @constant CFTCardReaderEventConnected A reader was connected
 * @constant CFTCardReaderEventConnectionErrored A reader connection attempt failed
 * @constant CFTCardReaderEventSwiped A swipe was received by the reader
 * @constant CFTCardReaderEventSwipeErrored A bad swipe was received by the reader
 * @constant CFTCardReaderEventInserted A card was inserted into the reader
 * @constant CFTCardReaderEventInsertErrored A card was inserted into the reader but could not be read
 * @constant CFTCardReaderEventCardRemoved The inserted card was removed from the reader
 * @constant CFTCardReaderEventTapped A card tap was received by the reader
 * @constant CFTCardReaderEventTapErrored A card tap was received by the reader but could not be read
 * @constant CFTCardReaderEventUpdateStarted The reader started updating
 * @constant CFTCardReaderEventUpdateCompleted The reader completed updating
 * @constant CFTCardReaderEventAudioRecordingPermissionNotGranted Audio recording permissions were not granted
 * @discussion Specifies the events pertaining to the card reader
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTCardReaderEvent) {
    CFTCardReaderEventUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardReaderEventDisconnected NS_SWIFT_NAME(disconnected) = 1,
    CFTCardReaderEventConnected NS_SWIFT_NAME(connected) = 2,
    CFTCardReaderEventConnectionErrored NS_SWIFT_NAME(connectionErrored) = 3,
    CFTCardReaderEventCardSwiped NS_SWIFT_NAME(cardSwiped) = 4,
    CFTCardReaderEventCardSwipeErrored NS_SWIFT_NAME(cardSwipeErrored) = 5,
    CFTCardReaderEventCardInserted NS_SWIFT_NAME(cardInserted) = 6,
    CFTCardReaderEventCardInsertErrored NS_SWIFT_NAME(cardInsertErrored) = 7,
    CFTCardReaderEventCardRemoved NS_SWIFT_NAME(cardRemoved) = 8,
    CFTCardReaderEventCardTapped NS_SWIFT_NAME(cardTapped) = 9,
    CFTCardReaderEventCardTapErrored NS_SWIFT_NAME(cardTapErrored) = 10,
    CFTCardReaderEventUpdateStarted NS_SWIFT_NAME(updateStarted) = 11,
    CFTCardReaderEventUpdateCompleted NS_SWIFT_NAME(updateCompleted) = 12,
    CFTCardReaderEventAudioRecordingPermissionNotGranted NS_SWIFT_NAME(audioRecordingPermissionNotGranted) = 13
};

/*!
 * @typedef CFTKeyedEntryEvent
 * @brief Events triggered by key entered card information
 * @constant CFTKeyedEntryEventUnknown
 * @constant CFTKeyedEntryEventCardIncomplete The card information provided is not yet complete
 * @constant CFTKeyedEntryEventCardComplete The card information provided has completed card number, expiration date, and CVV value
 * @discussion Specifies whether or not complete key entered card information was provided
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTKeyedEntryEvent) {
    CFTKeyedEntryEventUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTKeyedEntryEventCardIncomplete NS_SWIFT_NAME(cardIncomplete) = 1,
    CFTKeyedEntryEventCardComplete NS_SWIFT_NAME(cardComplete) = 2
};

/*!
 * @typedef CFTCardInputMethod
 * @brief Method by which card info was captured
 * @constant CFTCardInputMethodUnknown Unknown method, should not occur in normal operation
 * @constant CFTCardInputMethodKey Card info generated from key entry
 * @constant CFTCardInputMethodSwipe Card info generated from swipe data
 * @constant CFTCardInputMethodDip Card info generated from dipped data
 * @constant CFTCardInputMethodTap Card info generated from NFC tapped data
 * @constant CFTCardInputMethodSwipeFallback Card info generated from a swipe following failed dip attempts
 * @discussion Specifies the method by which card info was generated
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTCardInputMethod) {
    CFTCardInputMethodUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardInputMethodKey NS_SWIFT_NAME(key) = 1,
    CFTCardInputMethodSwipe NS_SWIFT_NAME(swipe) = 2,
    CFTCardInputMethodDip NS_SWIFT_NAME(dip) = 3,
    CFTCardInputMethodTap NS_SWIFT_NAME(tap) = 4,
    CFTCardInputMethodSwipeFallback NS_SWIFT_NAME(swipeFallback) = 5
};

/*!
 * @typedef CFTProcessOption
 * @brief Options for processing a transaction
 * @constant CFTProcessOptionUnknown Unknown option, should not occur in normal operation
 * @constant CFTProcessOptionProcess Process the transaction online normally
 * @constant CFTProcessOptionDefer Save the transaction to process at a later date
 * @constant CFTProcessOptionAbort Cancel the transaction without processing
 * @discussion Transactions can either be processed online, saved for later processing, or canceled without processing.
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTProcessOption) {
    CFTProcessOptionUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTProcessOptionProcess NS_SWIFT_NAME(process) = 1,
    CFTProcessOptionDefer NS_SWIFT_NAME(defer) = 2,
    CFTProcessOptionAbort NS_SWIFT_NAME(abort) = 3
};

/*!
 * @typedef CFTCVM
 * @brief Supported cardholder verification methods
 * @constant CFTCVMUnknown Unknown CVM, should not occur in normal operation
 * @constant CFTCVMNone No CVM requested
 * @constant CFTCVMSignature Signature CVM requested
 * @discussion All currently supported cardholder verification methods
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTCVM) {
    CFTCVMUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCVMNone NS_SWIFT_NAME(none) = 1,
    CFTCVMSignature NS_SWIFT_NAME(signature) = 2
};

/*!
 * @typedef CFTTransactionResult
 * @brief Outcome of a transaction
 * @constant CFTTransactionResultUnknown Unknown result, should not occur in normal operation
 * @constant CFTTransactionResultApproved Transaction was approved online
 * @constant CFTTransactionResultDeclined Transaction was declined online
 * @constant CFTTransactionResultErrored Transaction encountered an error
 * @constant CFTTransactionResultAborted Transaction was cancelled before processing
 * @discussion The final outcome of a transaction
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTTransactionResult) {
    CFTTransactionResultUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTTransactionResultApproved NS_SWIFT_NAME(approved) = 1,
    CFTTransactionResultDeclined NS_SWIFT_NAME(declined) = 2,
    CFTTransactionResultErrored NS_SWIFT_NAME(errored) = 3,
    CFTTransactionResultAborted NS_SWIFT_NAME(aborted) = 4,
};

/*!
 * @typedef CFTTransactionType
 * @bried The type of transaction being performed
 * @constant CFTTransactionTypeUnknown Unknown type, should not occur in normal operation
 * @constant CFTTransactionTypeSale Standard sale
 * @constant CFTTransactionTypeRefund A refunded sale
 * @constant CFTTransactionTypeVoid A cancelled sale or refund
 * @constant CFTTransactionTypeAuthorization An authorized but not yet captured transaction
 * @discussion Valid types of transactions that can be performed
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTTransactionType) {
    CFTTransactionTypeUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTTransactionTypeSale NS_SWIFT_NAME(sale) = 1,
    CFTTransactionTypeRefund NS_SWIFT_NAME(refund) = 2,
    CFTTransactionTypeVoid NS_SWIFT_NAME(void) = 3,
    CFTTransactionTypeAuthorization NS_SWIFT_NAME(authorization) = 4
};

/*!
 * @typedef CFTCardBrand
 * @brief All recognized card brands
 * @constant CFTCardBrandUnknown Card doesn't match any known configuration
 * @constant CFTCardBrandAmericanExpress Supported, Range: 34, 37
 * @constant CFTCardBrandChinaUnionPay Not supported, Range: 56
 * @constant CFTCardBrandDinersClubCarteBlanche Not supported, Range: 300-305
 * @constant CFTCardBrandDinersClubInternational Not supported, Range: 309, 36, 38-39
 * @constant CFTCardBrandDiscoverCard Supported, Range: 6011, 622126-622925, 644-649, 65
 * @constant CFTCardBrandInterpayment Not supported, Range: 636
 * @constant CFTCardBrandInstapayment Not supported, Range: 637-639
 * @constant CFTCardBrandJCB Not supported, Range: 3528-3589
 * @constant CFTCardBrandMaestro Not supported, Range: 50, 56-69
 * @constant CFTCardBrandDankort Not supported, Range: 5019
 * @constant CFTCardBrandMastercard Supported, Range: 2221-2720, 51-55
 * @constant CFTCardBrandVisa Supported, Range: 4
 * @constant CFTCardBrandUATP Not supported, Range: 1
 * @constant CFTCardBrandVerve Not supported, Range: 16, 19
 * @constant CFTCardBrandCardGuard Not supported, Range: 5392
 * @discussion All card brands recognized by the SDK. Not all recognized cards
 * are supported for running transactions. Credit card numbers starting within the
 * specified range are considered part of that card brand
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTCardBrand) {
    CFTCardBrandUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardBrandAmericanExpress NS_SWIFT_NAME(americanExpress) = 1,
    CFTCardBrandChinaUnionPay NS_SWIFT_NAME(chinaUnionPay) = 2,
    CFTCardBrandDinersClubCarteBlanche NS_SWIFT_NAME(dinersClubCarteBlanche) = 3,
    CFTCardBrandDinersClubInternational NS_SWIFT_NAME(dinersClubInternational) = 4,
    CFTCardBrandDiscoverCard NS_SWIFT_NAME(discoverCard) = 5,
    CFTCardBrandInterpayment NS_SWIFT_NAME(interpayment) = 6,
    CFTCardBrandInstapayment NS_SWIFT_NAME(instapayment) = 7,
    CFTCardBrandJCB NS_SWIFT_NAME(JCB) = 8,
    CFTCardBrandMaestro NS_SWIFT_NAME(maestro) = 9,
    CFTCardBrandDankort NS_SWIFT_NAME(dankort) = 10,
    CFTCardBrandMastercard NS_SWIFT_NAME(mastercard) = 11,
    CFTCardBrandVisa NS_SWIFT_NAME(visa) = 12,
    CFTCardBrandUATP NS_SWIFT_NAME(UATP) = 13,
    CFTCardBrandVerve NS_SWIFT_NAME(verve) = 14,
    CFTCardBrandCardGuard NS_SWIFT_NAME(cardguard) = 15
};

/*!
 * @typedef CFTCardReaderModel
 * @brief Compatible card readers
 * @constant CFTCardReaderModelUnknown Reader type is unknown or no reader is present
 * @constant CFTCardReaderModelShuttle Audio jack, swipe only
 * @constant CFTCardReaderModelBTMag Bluetooth, swipe only
 * @constant CFTCardReaderModelA100 Audio jack, swipe only
 * @constant CFTCardReaderModelA200 Audio jack, swipe and dip
 * @constant CFTCardReaderModelB550 Bluetooth, swipe, dip, and tap
 * @constant CFTCardReaderModelB500 Bluetooth, swipe and dip
 * @constant CFTCardReaderModelA250 Audio jack, swipe, dip, and tap
 * @constant CFTCardReaderModelB200 Bluetooth, swipe and dip
 * @constant CFTCardReaderModelB250 Bluetooth, swipe, dip, and tap
 * @discussion All compatible card readers, with their interface and supported input methods
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTCardReaderModel) {
    CFTCardReaderModelUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardReaderModelShuttle NS_SWIFT_NAME(shuttle) = 1,
    CFTCardReaderModelBTMag NS_SWIFT_NAME(btMag) = 2,
    CFTCardReaderModelA100 NS_SWIFT_NAME(A100) = 3,
    CFTCardReaderModelA200 NS_SWIFT_NAME(A200) = 4,
    CFTCardReaderModelB550 NS_SWIFT_NAME(B550) = 5,
    CFTCardReaderModelB500 NS_SWIFT_NAME(B500) = 6,
    CFTCardReaderModelA250 NS_SWIFT_NAME(A250) = 7,
    CFTCardReaderModelB200 NS_SWIFT_NAME(B200) = 8,
    CFTCardReaderModelB250 NS_SWIFT_NAME(B250) = 9
};

/*!
 * @typedef CFTBatteryStatus
 * @brief Card reader battery status
 * @constant CFTBatteryStatusUnknown Unknown battery status
 * @constant CFTBatteryStatusLow Low battery, charge immediately
 * @constant CFTBatteryStatusNominal Sufficent battery to run transactions
 * @constant CFTBatteryStatusPluggedIn Card reader running off AC power
 * @discussion Status of battery in card readers that contain a rechargable battery
 * Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTBatteryStatus) {
    CFTBatteryStatusUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTBatteryStatusLow NS_SWIFT_NAME(low) = 1,
    CFTBatteryStatusNominal NS_SWIFT_NAME(nominal) = 2,
    CFTBatteryStatusPluggedIn NS_SWIFT_NAME(pluggedIn) = 3
};

/*!
 * @typedef CFTCardReaderType
 * @brief Card reader type
 * @constant CFTCardReaderTypeUnknown Uknown reader
 * @constant CFTCardReaderTypeAudioJack Audio jack reader type
 * @constant CFTCardReaderTypeBluetooth Bluetooth reader type
 * @discussion Added in 4.0
 */
typedef NS_ENUM(NSInteger, CFTCardReaderType) {
    CFTCardReaderTypeUnknown NS_SWIFT_NAME(unknown) = 0,
    CFTCardReaderTypeAudioJack NS_SWIFT_NAME(audioJack) = 1,
    CFTCardReaderTypeBluetooth NS_SWIFT_NAME(bluetooth) = 2
};
