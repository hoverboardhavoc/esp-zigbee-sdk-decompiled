/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_app_join.o -> zdo_comm_handle_device_left
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zdo_comm_handle_device_left(_Bool rejoin)

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_14 [8];
  
  iVar1 = core_globals_get();
  if (*(char *)(iVar1 + 0xd24) == '\0') {
    iVar1 = core_globals_get();
    auStack_14[0] = rejoin;
    (**(code **)(iVar1 + 0xd3c))(1,auStack_14,*(code **)(iVar1 + 0xd3c));
    return;
  }
  iVar1 = core_globals_get();
  uVar2 = (uint)*(byte *)(iVar1 + 0xd24);
  if (9 < uVar2) {
    zdo_comm_op_to_str((zdo_comm_operation_t)iVar1);
  }
  log_write(1,"zdo_app_join.c","Device left in when %s",
            *(undefined4 *)(operation_string_0 + uVar2 * 4));
  return;
}

