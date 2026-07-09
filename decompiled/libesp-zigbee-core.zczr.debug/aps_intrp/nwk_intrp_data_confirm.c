/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_intrp.o -> nwk_intrp_data_confirm
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_intrp_data_confirm(int *param_1)

{
  uint uVar1;
  byte abStack_11 [9];
  
  abStack_11[0] = 0;
  zmsg_read_bytes(*param_1,0,1,abStack_11);
  if ((abStack_11[0] & 3) == 3) {
    if ((abStack_11[0] & 0xc) == 0xc) {
      zmsg_remove_header(*param_1,7);
    }
    else {
      zmsg_remove_header(*param_1,5);
    }
    if (*(byte *)(param_1 + 1) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(byte *)(param_1 + 1) | 0x200;
    }
    aps_intrp_data_sent(*param_1,uVar1);
  }
  else if (*param_1 != 0) {
    zmsg_free();
  }
  return;
}

