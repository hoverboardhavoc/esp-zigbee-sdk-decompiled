/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_frame_skip_sroute_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint nwk_frame_skip_sroute_index(uint param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = nwk_fcf_get_hdr_size();
  if ((param_1 & 0x400) != 0) {
    uVar1 = uVar1 + (*(byte *)(param_2 + uVar1) + 1) * 2 & 0xff;
  }
  return uVar1;
}

