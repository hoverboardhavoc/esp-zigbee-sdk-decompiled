/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_core.o -> zcl_core_action_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_core_action_schedule(zcl_core_action_callback_id_t cb_id,void *message)

{
  _Bool _Var1;
  undefined3 extraout_var;
  ezb_err_t eVar2;
  int iVar3;
  
  _Var1 = zcl_has_core_action_handler();
  if (CONCAT31(extraout_var,_Var1) == 0) {
    eVar2 = 5;
  }
  else {
    iVar3 = core_globals_get();
    (**(code **)(iVar3 + 0xd1c))(cb_id,message,*(code **)(iVar3 + 0xd1c));
    eVar2 = 0;
  }
  return eVar2;
}

