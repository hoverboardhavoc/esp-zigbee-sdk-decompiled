/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_start_new_network
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_commissioning_start_new_network(touchlink_disc_dev_info_t *dev_info)

{
  ezb_err_t eVar1;
  _Bool _Var2;
  uint8_t logic_channel;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar3;
  
  if (dev_info == (touchlink_disc_dev_info_t *)0x0) {
    eVar1 = 2;
  }
  else {
    _Var2 = touchlink_commissioning_task_is_idle();
    if (CONCAT31(extraout_var,_Var2) == 0) {
      eVar1 = 2;
    }
    else {
      _Var2 = touchlink_commissioning_action_permission
                        (TOUCHLINK_ACTION_START_NEW_NETWORK,&(dev_info->basic).ieee_addr);
      if (CONCAT31(extraout_var_00,_Var2) == 0) {
        eVar1 = -1;
      }
      else {
        uVar3 = touchlink_touchlink_info();
        if ((uVar3 & 2) != 0) {
          touchlink_commissioning_set_task('\x03');
          logic_channel = touchlink_get_logical_channel();
          touchlink_commissioning_set_logic_channel(logic_channel);
          touchlink_zdo_network_discovery();
          return 0;
        }
        touchlink_commissioning_set_task('\x04');
        eVar1 = touchlink_send_network_start_req(dev_info);
        if (eVar1 == 0) {
          return 0;
        }
      }
    }
  }
  touchlink_commissioning_set_task('\0');
  return eVar1;
}

