/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_join_local_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_commissioning_join_local_network(touchlink_disc_dev_info_t *dev_info)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  
  _Var1 = touchlink_commissioning_task_is_idle();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    iVar2 = 2;
  }
  else if (dev_info == (touchlink_disc_dev_info_t *)0x0) {
    iVar2 = 5;
  }
  else {
    if (((dev_info->basic).zigbee_info & 3) == 1) {
      iVar2 = touchlink_commissioning_join_router(dev_info);
    }
    else {
      iVar2 = touchlink_commissioning_join_ed(dev_info);
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
  touchlink_commissioning_set_task('\0');
  return iVar2;
}

