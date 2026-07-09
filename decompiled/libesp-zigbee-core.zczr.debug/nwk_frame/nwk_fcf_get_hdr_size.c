/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_frame.o -> nwk_fcf_get_hdr_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_fcf_get_hdr_size(uint param_1)

{
  int iVar1;
  
  if ((param_1 & 0x800) == 0) {
    iVar1 = 8;
  }
  else {
    iVar1 = 0x10;
  }
  if ((param_1 & 0x1000) != 0) {
    iVar1 = iVar1 + 8;
  }
  if ((param_1 & 0x100) != 0) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

