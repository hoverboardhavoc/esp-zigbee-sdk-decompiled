/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_continue_add_sub_device_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_commissioning_continue_add_sub_device_info(touchlink_disc_dev_info_t *dev_info)

{
  byte bVar1;
  ezb_err_t eVar2;
  
  if (dev_info == (touchlink_disc_dev_info_t *)0x0) {
    eVar2 = 0;
  }
  else {
    bVar1 = (dev_info->basic).subdev_count;
    if (bVar1 < (dev_info->basic).n_subdevs) {
      eVar2 = touchlink_send_device_info_req(bVar1,&(dev_info->basic).ieee_addr,0);
    }
    else {
      eVar2 = 0;
    }
  }
  return eVar2;
}

