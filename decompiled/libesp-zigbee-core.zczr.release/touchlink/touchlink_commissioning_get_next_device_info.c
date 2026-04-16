/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_commissioning_get_next_device_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_commissioning_get_next_device_info(touchlink_disc_dev_info_t *dev_info)

{
  ezb_err_t eVar1;
  
  eVar1 = 5;
  while (dev_info = (touchlink_disc_dev_info_t *)touchlink_get_next_disc_device(dev_info),
        dev_info != (touchlink_disc_dev_info_t *)0x0) {
    if (1 < (dev_info->basic).n_subdevs) {
      touchlink_set_intrp_channel((dev_info->basic).intrp_channel);
      touchlink_set_transaction_id((dev_info->basic).transaction_id);
      eVar1 = touchlink_send_device_info_req(0,&(dev_info->basic).ieee_addr,dev_info);
    }
  }
  return eVar1;
}

