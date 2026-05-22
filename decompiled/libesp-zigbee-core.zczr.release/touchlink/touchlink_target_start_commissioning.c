/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> touchlink.o -> touchlink_target_start_commissioning
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
  int iVar3;
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
    iVar3 = touchlink_get_target_timeout();
    iVar2 = 0x3c;
    if (iVar3 != 0) {
      iVar2 = touchlink_get_target_timeout();
    }
    iVar3 = core_globals_get();
    milli_timer_stop(iVar3 + 0x13bc);
    iVar3 = core_globals_get();
    milli_timer_init(iVar3 + 0x13bc,touchlink_target_commissioning_timeout,0);
    iVar3 = core_globals_get();
    milli_timer_start(iVar3 + 0x13bc,iVar2 * 1000);
    eVar4 = 0;
  }
  return eVar4;
}

