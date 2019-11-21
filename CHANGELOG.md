### 4.11.0
  * Changed
    * Transaction record indicates network transaction was processed over.
  * Fixed
    * Rename abort to cancel.
    
### 4.10.1
  * Fixed
    * Various bug fixes and performance improvements

### 4.10.0
  * Changed
    * All instances of CFTError are now CFTGeneralError instances

### 4.9.0
  * Added
    * Merchant Settlement Scheme on CFTMerchantAccount

### 4.8.8
  * Added
    * More properties available on CFTTransaction
    * Adjustment object
    * Attaching an adjustment to a transaction
    * Pending Adjustment transaction state

### 4.8.7
  * Added
    * Simplify merchant capabilities.

### 4.8.6
 * Added
    * Added external transaction state of PendingAdjustment.
    * Added DeviceManager.
    * Added Debit routing.
 * Fixed
      * Resume deferred transaction crash.

### 4.8.5
 * Added
    * Updated metadata's type in CFTTransactionManager methods.

### 4.8.4
 * Added
    * Interface updates.
    * Bug fixes.

### 4.8.0
 * Changed
     * Interface updates
 * Added
     * Can keep reader connection alive using Reader utilities.
     * EMV receipt details.
     * CVV keyed entry validation

### 4.6.4
* Fixed
* Credential validation(regression from 4.6.3) for devices running  **< iOS 10.3**

### 4.6.3
* Fixed
  * Credential validation for devices running  **< iOS 10.3**

### 4.6.2
* Fixed
  * Change process prompt for tokenization transactions
  * Authorizations fixed
  * Various bug fixes and performance improvements

### 4.6.1
* Fixed
  * Crash when connecting A100
  * Improved messaging during a transaction

### 4.6.0
* Added
  * Accept AVS details on keyed transactions
* Changed
  * Keyed transactions can be disabled
* Fixed
  * Multiple tokenizations can be run in a row
  * Connected audio jack readers will now show in the available readers list

### 4.5.0
* Added
  * Card ID on card info
* Fixed
  * Accurate dates on Historical Transactions
* Changed
  * Improved Bold reader detection

### 4.4.2
* Changed
    * Improved reader error behavior

### 4.4.1
* Changed
  * Improved reader disconnection behavior

### 4.4.0
* Added
  * CVV optional on keyed transactions
* Changed
  * Improved handling of declined dip transactions

### 4.3.3
* Changed
  * Improved reader connection error handling

### 4.3.2
* Fixed
  * Incorrect transaction result in some cases
  * Improved TLV parsing

### 4.3.1
* Added
  * Additional logging around reader connections
* Fixed
  * Issues around switching between bluetooth readers

### 4.3.0
* Added
  * Tokenize with existing Braintree customer ID
* Fixed
  * Reference ID on CFTHistoricalTransaction
  * Better handling of transactions with cards that can't be processed

### 4.2.0
* Added
  * Ability to create Historical Transactions from charge IDs
  * Additional field to Historical Transactions
  * NFC support for Bold B550
  * Utility class to allow reader connection outside of Transaction
* Changed
  * Improved log messages
* Fixed
  * Warning for accessing the wrong thread
  * Fallback behavior on Swift readers

### 4.1.0
* Added
  * Tokenization support
  * Reachability support
  * Defer and Resume transaction
  * Card Reader Connecting events
  * Card Reader Battery events
  * Strip architectures script (for App Store uploading)
* Changed
  * Transaction messaging format
* Fixed
  * Unsupported AID handling

### 4.0.3
* Fixed
  * referenceID crash on transactions

### 4.0.2
* Fixed
  * referenceId on approved transactions

### 4.0.1
* Added
  * referenceId to CFTHistoricalTransaction
  * support for A100 card readers
  * CFTInfo class for framework version information
* Changed
  * Removed mandatory card removal in chip transactions
* Fixed
  * Base URL points to correct location

### 4.0
* Initial Release
