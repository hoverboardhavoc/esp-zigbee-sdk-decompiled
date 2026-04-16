/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_set_auth
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_set_auth(nwk_neighbor_t *nbr)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = *(uint *)&nbr->field_0xc & 3;
  if (uVar2 == 2) {
    iVar1 = 1;
  }
  else {
    iVar1 = 2;
  }
  *(uint *)&nbr->field_0xc = *(uint *)&nbr->field_0xc & 0xfffffc3f | iVar1 << 6;
  if (uVar2 == 2) {
    iVar1 = core_globals_get();
    nwk_neighbor_zed_set_timeout(nbr,*(uint8_t *)(iVar1 + 0xa29));
    nwk_neighbor_table_store_child(nbr);
  }
  else {
    iVar1 = core_globals_get();
    (nbr->dev).r.inbound_activity = *(uint8_t *)(iVar1 + 0xa25);
    iVar1 = core_globals_get();
    (nbr->dev).r.outbound_activity = *(uint8_t *)(iVar1 + 0xa25);
  }
  return;
}

