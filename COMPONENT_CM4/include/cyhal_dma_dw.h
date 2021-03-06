/***************************************************************************//**
* \file cyhal_dma_dw.h
*
* \brief
* Defines a high level interface for interacting with the Cypress Datawire DMA.
*
********************************************************************************
* \copyright
* Copyright 2018-2021 Cypress Semiconductor Corporation
* SPDX-License-Identifier: Apache-2.0
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

#include "cyhal_dma.h"

/**
 * \addtogroup group_hal_impl_dma_dw DW (Datawire)
 * \ingroup group_hal_impl_dma
 * \{
 * Implementation specific interface for using the Datawire DMA peripheral
 */

#pragma once

#ifdef CY_IP_M4CPUSS_DMA

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/** Initialize the Datawire peripheral.
 *
 * @param[out] obj          The DMA object to initialize
 * @param[in]  src          An optional, input signal to connect to.
 * @param[in]  dest         An optional, output target to drive.
 * @param[in]  priority     The priority of this DMA operation relative to others. Values must be between 0-3 with 0 being the highest priority.
 * @return The status of the init request
 */
cy_rslt_t _cyhal_dma_dw_init(cyhal_dma_t *obj, cyhal_source_t *src, cyhal_dest_t *dest, uint8_t priority);

/** Frees the Datawire specific DMA object. This expects that common resources will be freed by caller.
 *
 * @param[in,out] obj The DMA object
 */
void _cyhal_dma_dw_free(cyhal_dma_t *obj);

/** Setup a Datawire descriptor for the dma resource
 *
 * @param[in] obj    The DMA object
 * @param[in] cfg    Configuration prameters for the transfer
 * @return The status of the configure request
 */
cy_rslt_t _cyhal_dma_dw_configure(cyhal_dma_t *obj, const cyhal_dma_cfg_t *cfg);

/** Start a Datawire transfer
 *
 * Initiates DMA channel transfer for specified DMA object
 * @param[in] obj    The DMA object
 * @return The status of the start_transfer request
 */
cy_rslt_t _cyhal_dma_dw_start_transfer(cyhal_dma_t *obj);

/** Configure Datawire event enablement.
 *
 * @param[in] obj            The DMA object
 * @param[in] event          The DMA event type
 * @param[in] intr_priority  The priority for NVIC interrupt events. The priority from the most recent call will take precedence, i.e all events will have the same priority.
 * @param[in] enable         True to turn on interrupts, False to turn off
 */
void _cyhal_dma_dw_enable_event(cyhal_dma_t *obj, cyhal_dma_event_t event, uint8_t intr_priority, bool enable);

/** Checks whether a transfer is pending or running on the DMA channel
 *
 * @param[in] obj    The DMA object
 * @return True if DMA channel is busy
 */
bool _cyhal_dma_dw_is_busy(cyhal_dma_t *obj);

/** Connects a source signal and enables the specified input to the DMA
 * channel
 *
 * @param[in] obj         The DMA object
 * @param[in] source      Source signal obtained from another driver's cyhal_<PERIPH>_enable_output
 * @param[in] input       Which input to enable
 * @return The status of the connection
 * */
cy_rslt_t _cyhal_dma_dw_connect_digital(cyhal_dma_t *obj, cyhal_source_t source, cyhal_dma_input_t input);

/** Enables the specified output signal from a DMA channel that is triggered when a transfer is completed
 *
 * @param[in]  obj         The DMA object
 * @param[in]  output      Which event triggers the output
 * @param[out] source      Pointer to user-allocated source signal object which
 * will be initialized by enable_output. source should be passed to
 * (dis)connect_digital functions to (dis)connect the associated endpoints.
 * @return The status of the output enable
 * */
cy_rslt_t _cyhal_dma_dw_enable_output(cyhal_dma_t *obj, cyhal_dma_output_t output, cyhal_source_t *source);

/** Disconnects a source signal and disables the specified input to the DMA channel
 *
 * @param[in] obj         The DMA object
 * @param[in] source      Source signal from cyhal_<PERIPH>_enable_output to disable
 * @param[in] input       Which input to disable
 * @return The status of the disconnect
 * */
cy_rslt_t _cyhal_dma_dw_disconnect_digital(cyhal_dma_t *obj, cyhal_source_t source, cyhal_dma_input_t input);

/** Disables the specified output signal from a DMA channel
 *
 * @param[in]  obj         The DMA object
 * @param[in]  output      Which output to disable
 * @return The status of the disablement
 * */
cy_rslt_t _cyhal_dma_dw_disable_output(cyhal_dma_t *obj, cyhal_dma_output_t output);

#if defined(__cplusplus)
}
#endif /* __cplusplus */

#endif /* CY_IP_M4CPUSS_DMA */

/** \} group_hal_impl_dma_dw */
