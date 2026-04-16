/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> aps_frame.o -> aps_frame_validate_nsdu
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_frame_validate_nsdu(zmsg_t *msg)

{
  bool bVar1;
  uint16_t uVar2;
  uint uVar3;
  undefined2 extraout_var;
  
  uVar3 = zmsg_get_length();
  if (uVar3 < 2) {
    bVar1 = false;
  }
  else {
    uVar3 = zmsg_get_length(msg);
    uVar2 = aps_frame_find_payload_offset(msg);
    bVar1 = CONCAT22(extraout_var,uVar2) <= uVar3;
  }
  return bVar1;
}

