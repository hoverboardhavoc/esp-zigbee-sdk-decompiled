/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
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
        *(undefined1 *)(iVar2 + 0xda0) = 3;
      }
      else {
        iVar2 = core_globals_get();
        *(undefined1 *)(iVar2 + 0xda0) = 0;
      }
      zdo_dev_set_joined(!bVar1);
      goto _L0;
    }
    iVar2 = core_globals_get();
  }
  *(undefined1 *)(iVar2 + 0xda0) = 4;
_L0:
  touchlink_target_stop_commissioning();
  bdb_comm_finish_step();
  iVar2 = core_globals_get();
  bdb_comm_put_app_signal(0x107,*(undefined1 *)(iVar2 + 0xda0));
  bdb_comm_perform_next_step();
  return;
}

