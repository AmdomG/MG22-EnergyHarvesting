// This file is generated by Simplicity Studio.  Please do not edit manually.
//
//

// Enclosing macro to prevent multiple inclusion
#ifndef __GPD_CALLBACKS__
#define __GPD_CALLBACKS__


#include "gpd-components-common.h"
#include PLATFORM_HEADER
#include "hal/hal.h"
#include CONFIGURATION_HEADER
#include EMBER_AF_API_NVM3


/** @brief Called by framework from the application main enry to inform the user
 * as the first call to the main.
 *
* @param gpd pointer to gpd instance
 */
void emberGpdAfPluginMainCallback(EmberGpd_t * gpd);

/** @brief Called to get the application information payload from application. This callback
 *         helps application to filled up the application specefic application information
 *         that gets transmitted.
 *
 * @param messagePayload The pointer for the user to fillup.
 * @param maxLength maximum length.
 * @param last indicates the present application description packet is the last one.
 * Ver.: always
 *
 * @return the length writen by application.
 */
uint8_t emberGpdAfPluginGetApplicationDescriptionCallback(uint8_t * messagePayload,
                                                          uint8_t maxLength,
                                                          bool * last);

/** @brief This is called by framework to receive a contact status in case of generic switch
 *         info during commissioning request.
 *
 * @return a 8bit switch contact status.
 */
uint8_t emberGpdAfPluginGetSwitchContactStutusCallback(void);

/** @brief Called in interrupt context whenever a button
 * changes its state.
 *
 * @appusage Must be implemented by the application. This function should
 * contain the functionality to be executed in response to changes of state
 * in each of the buttons or callbacks to the appropriate functionality.
 *
 * @param button  The button which has changed state, either BUTTON0 or BUTTON1
 * as defined in the appropriate BOARD_HEADER.
 *
 * @param state   The new state of the button referenced by the button parameter,
 * either ::BUTTON_PRESSED if the button has been pressed or ::BUTTON_RELEASED if
 * the button has been released.
 */
void halButtonIsr(uint8_t button, uint8_t state);

/** @brief This is called by framework to initialise the NVM system
 *
 */
void emberGpdAfPluginNvInitCallback(void);

/** @brief Called to the application to give a chance to load or store the GPD Context
 *.        in a non volatile context. Thsi can help the application to use any other
 *         non volatile storage.
 *
 * @param gpd pointer to gpd instance
 * @param nvmData The pointer to the data that needs saving or retrieving to or from
 *                the non-volatile memory.
 * @param sizeOfNvmData The size of the data non-volatile data.
 * @param loadStore indication wether to load or store the context.
 * Ver.: always
 *
 * @return true if application handled it.
 */
bool emberGpdAfPluginNvSaveAndLoadCallback(EmberGpd_t * gpd,
                                           uint8_t * nvmData,
                                           uint8_t sizeOfNvmData,
                                           EmebrGpdNvLoadStore_t loadStore);

/** @brief Called from the incomming command handler context to let the application
 *         handle the channel configuration.
 *
 * @param channel channel.
 * Ver.: always
 *
 */
void emberGpdAfPluginCommissioningChannelConfigCallback(uint8_t channel);

/** @brief Called from the imcomming command handler context to let the application
 *         handle the commissioning reply.
 *
 * @param length Length of the commissioning reply payload.
 * @param commReplyPayload The pointer to the commissioning reply payload.
 * Ver.: always
 *
 */
void emberGpdAfPluginCommissioningReplyCallback(uint8_t length,
                                                uint8_t * commReplyPayload);

/** @brief Called from the imcomming command handler context for all the incoming
 *         command before the command handler handles it. based on the return code
 *         of this callback the internal command handler skips the processing.
 *
 * @param gpdCommand CommandId.
 * @param length length of the command
 * @param commandPayload The pointer to the commissioning reply payload.
 * Ver.: always
 *
 * @return true if application handled it.
 */
bool emberGpdAfPluginIncomingCommandCallback(uint8_t gpdCommand,
                                            uint8_t length,
                                            uint8_t * commandPayload);

/** @brief This is called by the application state machine to indicate when the GPD is going to sleep.
 *         Typically this will be called from rx-after-tx state machines and application state machine.
 *
 */
void emberGpdAfPluginSleepCallback(void);

/** @brief This is called by framework to get a random number. User should implement it appropriately
 * depending on the random number generation in the project.
 *
 * @return a 32bit random number.
 */
uint32_t emberGpdAfPluginGetRandomCallback(void);

/** @brief This is called by framework to get the IEEE (EUI64) address of the GPD.
 * Typically GPD application may have the IEEE address for each of the GPD programmed at a different
 * location or storage, so the framework obtains the address through this callback.
 *
 * @param eui pointer to collect the ieee
 * @param gpdEndpoint pointer to collect gpd endpoint
 */
void emberGpdAfPluginGetGpdIeeeCallback(uint8_t *eui,
                                        uint8_t *gpdEndpoint);

/**
 * @brief Called whenever the radio is powered on.
 */
void halRadioPowerUpHandler(void);

/**
 * @brief Called whenever the radio is powered off.
 */
void halRadioPowerDownHandler(void);

/**
 * @brief Called whenever the microcontroller enters/exits a idle/sleep mode
 *
 * @param enter        True if entering idle/sleep, False if exiting
 * @param sleepMode    Idle/sleep mode
 */
void halSleepCallback(boolean enter, SleepModes sleepMode);

// The NVM3 Callback function.
void halNvm3Callback(Ecode_t status);

#endif // __GPD_CALLBACKS__