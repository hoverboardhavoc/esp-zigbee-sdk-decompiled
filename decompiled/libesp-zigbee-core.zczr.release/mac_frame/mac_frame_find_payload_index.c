/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> mac_frame.o -> mac_frame_find_payload_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

uint mac_frame_find_payload_index(undefined4 *param_1)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = *(ushort *)*param_1;
  uVar2 = 0xff;
  if (((uVar1 & 0x200) == 0) && (uVar2 = mac_fcf_skip_src_panid_index(uVar1), 0x3fff < uVar1)) {
    if ((uVar1 & 0xc000) == 0x8000) {
      uVar2 = uVar2 + 2;
    }
    else {
      if ((uVar1 & 0xc000) != 0xc000) {
        return uVar2;
      }
      uVar2 = uVar2 + 8;
    }
    uVar2 = uVar2 & 0xff;
  }
  return uVar2;
}

