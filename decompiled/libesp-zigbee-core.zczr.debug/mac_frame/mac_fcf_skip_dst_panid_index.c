/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_fcf_skip_dst_panid_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mac_fcf_skip_dst_panid_index(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = mac_fcf_skip_seq_num_index();
  iVar2 = mac_fcf_has_dst_panid(param_1);
  if (iVar2 != 0) {
    uVar1 = uVar1 + 2 & 0xff;
  }
  return uVar1;
}

