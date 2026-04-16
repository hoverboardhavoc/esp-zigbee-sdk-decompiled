/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> datasets.o -> ds_log
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void ds_log(ds_action_t action,ezb_err_t error,ds_key_t key,void *value)

{
  undefined3 in_register_00002029;
  uint uVar1;
  char *pcVar2;
  char *pcVar3;
  
  uVar1 = CONCAT31(in_register_00002029,action);
  if (error == 0) {
    return;
  }
  if (uVar1 != 3) {
    if (uVar1 < 4) {
      if (uVar1 == 0) {
        return;
      }
      goto _L0;
    }
    if (1 < (uVar1 - 5 & 0xff)) goto _L0;
  }
  if (error == 5) {
    return;
  }
_L0:
  pcVar2 = ds_action_to_str(action);
  pcVar3 = ds_key_to_str(key);
  log_write(2,"datasets.c","%s %s failed: %d",pcVar2,pcVar3,error);
  return;
}

