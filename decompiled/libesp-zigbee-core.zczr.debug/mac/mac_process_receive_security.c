/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac.o -> mac_process_receive_security
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mac_process_receive_security(int param_1)

{
  uint uVar1;
  
  if ((*(ushort *)(param_1 + 0x1c) & 8) != 0) {
    if ((*(ushort *)(param_1 + 0x1c) & 0x3000) == 0) {
      uVar1 = 0xde;
    }
    else {
      uVar1 = 0xdf;
    }
    return uVar1 | 0x100;
  }
  return 0;
}

