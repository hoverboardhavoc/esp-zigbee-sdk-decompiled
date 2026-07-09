/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aes_ccm.o -> psa_to_ezb_error
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int psa_to_ezb_error(int param_1)

{
  int iVar1;
  
  if (param_1 == -0x87) {
    iVar1 = 2;
  }
  else {
    if (-0x87 < param_1) {
      return -(uint)(param_1 != 0);
    }
    iVar1 = 0x13;
    if ((param_1 != -0x95) && (iVar1 = 1, param_1 != -0x8a)) {
      return -1;
    }
  }
  return iVar1;
}

