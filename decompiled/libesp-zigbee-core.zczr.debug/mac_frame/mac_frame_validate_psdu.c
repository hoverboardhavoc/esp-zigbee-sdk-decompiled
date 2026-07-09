/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> mac_frame.o -> mac_frame_validate_psdu
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 mac_frame_validate_psdu(undefined4 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = mac_frame_find_payload_index();
  if (uVar1 == 0xff) {
    uVar2 = 0;
  }
  else {
    if ((*(ushort *)*param_1 & 7) == 3) {
      uVar1 = uVar1 + 1 & 0xff;
    }
    if ((uint)*(byte *)(param_1 + 1) < uVar1 + 2) {
      uVar2 = 0x10;
    }
    else {
      uVar2 = 0;
    }
  }
  return uVar2;
}

