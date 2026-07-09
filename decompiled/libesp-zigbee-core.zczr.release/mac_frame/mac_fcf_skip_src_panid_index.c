/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_fcf_skip_src_panid_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char mac_fcf_skip_src_panid_index(undefined4 param_1)

{
  char cVar1;
  char cVar2;
  
  cVar1 = mac_fcf_skip_dstaddr_index();
  cVar2 = mac_fcf_has_src_panid(param_1);
  return cVar2 * '\x02' + cVar1;
}

