/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_remove_ota_file
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_ota_upgrade_remove_ota_file(void *param_1)

{
  byte *pbVar1;
  void *__s;
  uint uVar2;
  
  pbVar1 = (byte *)ota_upgrade_get_file_table();
  if (pbVar1 != (byte *)0x0) {
    for (uVar2 = 0; uVar2 < *pbVar1; uVar2 = uVar2 + 1 & 0xff) {
      __s = (void *)(*(int *)(pbVar1 + 4) + uVar2 * 0x4c);
      if (__s == param_1) {
        memset(__s,0,0x4c);
        return;
      }
    }
  }
  return;
}

