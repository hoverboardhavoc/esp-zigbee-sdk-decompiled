/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_frame_skip_sroute_index
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

uint8_t nwk_frame_skip_sroute_index(uint16_t fcf,uint8_t *msdu)

{
  uint8_t uVar1;
  undefined3 extraout_var;
  uint uVar2;
  
  uVar1 = nwk_fcf_get_hdr_size(fcf);
  uVar2 = CONCAT31(extraout_var,uVar1);
  if ((fcf & 0x400) != 0) {
    uVar2 = uVar2 + (msdu[uVar2] + 1) * 2 & 0xff;
  }
  return (uint8_t)uVar2;
}

