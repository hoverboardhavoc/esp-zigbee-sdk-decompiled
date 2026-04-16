/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_commissioning_scan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_commissioning_scan(void)

{
  ezb_err_t eVar1;
  _Bool _Var2;
  undefined3 extraout_var;
  touchlink_commissioning_t *ptVar3;
  uint32_t uVar4;
  
  _Var2 = touchlink_commissioning_task_is_idle();
  if (CONCAT31(extraout_var,_Var2) == 0) {
    eVar1 = 2;
  }
  else {
    touchlink_commissioning_set_task('\x01');
    ptVar3 = touchlink_commissioning_get();
    uVar4 = touchlink_commissioning_get_channel_mask();
    (ptVar3->u).initiator.scan_channel_mask = uVar4;
    ptVar3 = touchlink_commissioning_get();
    (ptVar3->u).initiator.scan_count = '\x05';
    eVar1 = touchlink_commissioning_scan_next_channel();
    if (eVar1 == 0) {
      return 0;
    }
  }
  touchlink_commissioning_set_task('\0');
  return eVar1;
}

