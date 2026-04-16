/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> aps_dup.o -> aps_dup_need_check
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_dup_need_check(aps_header_t *aps_hdr)

{
  uint8_t uVar1;
  
  if ((aps_hdr->fcf & 3) == 2) {
    return false;
  }
  uVar1 = aps_hdr->cmd_id;
  if (uVar1 == '\x0e') {
    return false;
  }
  if (uVar1 == '\x12') {
    return false;
  }
  if (uVar1 != '\x11') {
    return true;
  }
  return false;
}

