/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_remove_stored_key_pair
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_remove_stored_key_pair(int *param_1)

{
  int iStack_44;
  int iStack_40;
  short sStack_14;
  char cStack_12;
  
  sStack_14 = 0;
  cStack_12 = '\0';
  while( true ) {
    ds_aps_key_pair_itor_read(&iStack_44);
    if (cStack_12 != '\0') {
      return;
    }
    if ((*param_1 == iStack_44) && (param_1[1] == iStack_40)) break;
    sStack_14 = sStack_14 + 1;
  }
  ds_internal_remove_entry(9,&iStack_44);
  return;
}

