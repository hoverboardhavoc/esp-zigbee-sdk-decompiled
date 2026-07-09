/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_fcf_get_hdr_size
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char aps_fcf_get_hdr_size(uint param_1)

{
  char cVar1;
  int iVar2;
  
  iVar2 = aps_fcf_has_address();
  if (iVar2 == 0) {
    cVar1 = '\x02';
  }
  else {
    cVar1 = ((param_1 & 0xc) == 0xc) + '\b';
  }
  return cVar1;
}

