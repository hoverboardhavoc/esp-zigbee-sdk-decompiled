/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_formation.o -> nwk_disc_table_lite_ent_add_pan
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_disc_table_lite_ent_add_pan(nwk_disc_table_lite_ent_t *ent,pan_descriptor_t *pan)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  ent->channel_page = pan->channel_page;
  ent->channel_number = pan->channel_number;
  uVar3 = 0;
  while( true ) {
    bVar1 = ent->pan_cnt;
    uVar2 = (uint)bVar1;
    if (uVar2 <= uVar3) {
      if (uVar2 < 0x1c) {
        ent->panids[uVar2] = pan->coord_panid;
        ent->pan_cnt = bVar1 + 1;
      }
      else {
        log_write(2,"nwk_formation.c","Too many PANs on channel: %d:%d");
      }
      return;
    }
    if (ent->panids[uVar3] == pan->coord_panid) break;
    uVar3 = uVar3 + 1 & 0xff;
  }
  return;
}

