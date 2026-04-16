/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zcl_core.o -> zcl_core_action_schedule
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_core_action_schedule(zcl_core_action_callback_id_t cb_id,void *message)

{
  int iVar1;
  ezb_err_t eVar2;
  
  iVar1 = core_globals_get();
  eVar2 = 5;
  if (*(int *)(iVar1 + 0xd80) != 0) {
    iVar1 = core_globals_get();
    (**(code **)(iVar1 + 0xd80))(cb_id,message,*(code **)(iVar1 + 0xd80));
    eVar2 = 0;
  }
  return eVar2;
}

