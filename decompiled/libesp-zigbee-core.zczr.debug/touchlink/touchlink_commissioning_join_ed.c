/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_join_ed
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_commissioning_join_ed(touchlink_disc_dev_info_t *dev_info)

{
  _Bool _Var1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  ezb_err_t eVar2;
  
  _Var1 = touchlink_commissioning_task_is_idle();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    eVar2 = 2;
  }
  else {
    _Var1 = touchlink_commissioning_action_permission
                      (TOUCHLINK_ACTION_JOIN_ED,&(dev_info->basic).ieee_addr);
    if (CONCAT31(extraout_var_00,_Var1) == 0) {
      eVar2 = -1;
    }
    else {
      touchlink_commissioning_set_task('\x06');
      eVar2 = touchlink_send_join_ed_req(dev_info);
    }
  }
  return eVar2;
}

