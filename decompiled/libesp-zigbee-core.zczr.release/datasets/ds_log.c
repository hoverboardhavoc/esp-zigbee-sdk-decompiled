/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> datasets.o -> ds_log
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ds_log(ds_action_t action,ezb_err_t error,ds_key_t key,void *value)

{
  undefined3 in_register_00002029;
  int iVar1;
  undefined2 in_register_00002032;
  
  iVar1 = CONCAT31(in_register_00002029,action);
  if ((error != 0) && (((iVar1 != 3 && (1 < (iVar1 - 5U & 0xff))) || (error != 5)))) {
    log_write(2,"datasets.c",0x10000,*(undefined4 *)(action_string_1 + iVar1 * 4),
              *(undefined4 *)(key_string_0 + CONCAT22(in_register_00002032,key) * 4));
    return;
  }
  return;
}

