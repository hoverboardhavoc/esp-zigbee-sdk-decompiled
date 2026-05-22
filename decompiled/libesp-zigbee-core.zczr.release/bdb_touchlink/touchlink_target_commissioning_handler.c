/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> bdb_touchlink.o -> touchlink_target_commissioning_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void touchlink_target_commissioning_handler(uint8_t task,uint8_t status)

{
  bool bVar1;
  undefined3 in_register_00002029;
  int iVar2;
  undefined3 in_register_0000202d;
  
  if (CONCAT31(in_register_00002029,task) == 0) {
    iVar2 = core_globals_get();
  }
  else {
    if ((CONCAT31(in_register_00002029,task) - 4U & 0xff) < 3) {
      bVar1 = CONCAT31(in_register_0000202d,status) != 0;
      if (bVar1) {
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xd4c) = 3;
      }
      else {
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xd4c) = 0;
      }
      zdo_dev_set_joined(!bVar1);
      goto _L0;
    }
    iVar2 = core_globals_get();
  }
  *(undefined1 *)(iVar2 + 0xd4c) = 4;
_L0:
  touchlink_target_stop_commissioning();
  bdb_comm_finish_step();
  iVar2 = core_globals_get();
  bdb_comm_put_app_signal(0x107,*(undefined1 *)(iVar2 + 0xd4c));
  bdb_comm_perform_next_step();
  return;
}

