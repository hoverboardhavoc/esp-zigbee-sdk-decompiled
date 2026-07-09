/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_file_table_get_empty_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ota_upgrade_file_table_get_empty_entry(byte *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (param_1 == (byte *)0x0) {
      return 0;
    }
    if (*param_1 <= uVar2) break;
    iVar1 = *(int *)(param_1 + 4) + uVar2 * 0x4c;
    if (*(int *)(iVar1 + 0x34) == 0) {
      return iVar1;
    }
    uVar2 = uVar2 + 1 & 0xff;
  }
  return 0;
}

