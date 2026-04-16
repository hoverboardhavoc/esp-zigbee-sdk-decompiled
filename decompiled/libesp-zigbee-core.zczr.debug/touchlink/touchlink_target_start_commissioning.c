/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> touchlink.o -> touchlink_target_start_commissioning
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t touchlink_target_start_commissioning(touchlink_commissioning_callback_t cb)

{
  _Bool _Var1;
  undefined3 extraout_var;
  int iVar2;
  touchlink_commissioning_t *ptVar3;
  ezb_err_t eVar4;
  
  _Var1 = touchlink_commissioning_task_is_idle();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    eVar4 = 2;
  }
  else {
    touchlink_set_initiator_device(0);
    touchlink_reset_transaction();
    touchlink_commissioning_set_task('\0');
    touchlink_commissioning_set_role(TL_COMM_ROLE_TARGET,cb);
    iVar2 = touchlink_is_factory_new();
    if (iVar2 != 0) {
      touchlink_assign_nwk_info();
    }
    iVar2 = touchlink_get_target_timeout();
    if (iVar2 == 0) {
      iVar2 = 0x3c;
    }
    else {
      iVar2 = touchlink_get_target_timeout();
    }
    ptVar3 = touchlink_commissioning_get();
    milli_timer_stop((undefined1 *)((int)&ptVar3->u + 4));
    ptVar3 = touchlink_commissioning_get();
    milli_timer_init((undefined1 *)((int)&ptVar3->u + 4),touchlink_target_commissioning_timeout,0);
    ptVar3 = touchlink_commissioning_get();
    milli_timer_start((undefined1 *)((int)&ptVar3->u + 4),iVar2 * 1000);
    eVar4 = 0;
  }
  return eVar4;
}

