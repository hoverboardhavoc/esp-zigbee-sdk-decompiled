/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_frame_need_ack
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

_Bool aps_frame_need_ack(aps_header_t *aps_hdr)

{
  byte bVar1;
  
  if (0xfff7 < (aps_hdr->addr_info).dst_addr) {
    return false;
  }
  bVar1 = aps_hdr->fcf;
  if (((bVar1 & 3) != 0) && ((bVar1 & 3) != 1)) {
    return false;
  }
  return (_Bool)(bVar1 >> 6 & 1);
}

