/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ezb_zcl_ota_upgrade_set_download_retry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_ota_upgrade_set_download_retry(undefined1 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = ota_upgrade_downloading_context_get();
  if (iVar1 == 0) {
    uVar2 = 5;
  }
  else if (param_2 == 0) {
    uVar2 = 2;
  }
  else {
    *(undefined1 *)(iVar1 + 0x31) = param_1;
    *(int *)(iVar1 + 0x34) = param_2;
    uVar2 = 0;
  }
  return uVar2;
}

