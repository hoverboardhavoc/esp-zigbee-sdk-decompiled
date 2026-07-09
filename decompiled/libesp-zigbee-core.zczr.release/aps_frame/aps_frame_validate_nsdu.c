/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_validate_nsdu
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool aps_frame_validate_nsdu(undefined4 param_1)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = zmsg_get_length();
  if (uVar2 < 2) {
    bVar1 = false;
  }
  else {
    uVar2 = zmsg_get_length(param_1);
    uVar3 = aps_frame_find_payload_offset(param_1);
    bVar1 = uVar3 <= uVar2;
  }
  return bVar1;
}

