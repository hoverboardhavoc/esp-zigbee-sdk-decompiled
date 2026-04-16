/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_neighbor.o -> nwk_neighbor_table_handle_link_status_period
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_neighbor_table_handle_link_status_period(void)

{
  uint8_t uVar1;
  uint16_t uVar2;
  nwk_neighbor_t *nbr;
  int iVar3;
  uint uVar4;
  
  nbr = (nwk_neighbor_t *)0x0;
  while (nbr = nwk_neighbor_table_next(nbr), nbr != (nwk_neighbor_t *)0x0) {
    uVar4 = *(uint *)&nbr->field_0xc & 3;
    if ((uVar4 == 0) || (uVar4 == 1)) {
      uVar1 = (nbr->dev).r.inbound_activity;
      if (uVar1 != '\0') {
        (nbr->dev).r.inbound_activity = uVar1 + 0xff;
      }
      uVar1 = (nbr->dev).r.outbound_activity;
      if (uVar1 != '\0') {
        (nbr->dev).r.outbound_activity = uVar1 + 0xff;
      }
      uVar4 = *(uint *)&nbr->field_0xc;
      iVar3 = core_globals_get();
      if ((uVar4 >> 0x12 & 0xff) < (uint)*(byte *)(iVar3 + 0xa25)) {
        *(uint *)&nbr->field_0xc =
             *(uint *)&nbr->field_0xc & 0xfc03ffff |
             ((*(uint *)&nbr->field_0xc >> 0x12 & 0xff) + 1 & 0xff) << 0x12;
        uVar2 = (nbr->dev).r.router_age;
        if (uVar2 != 0xffff) {
          (nbr->dev).r.router_age = uVar2 + 1;
        }
      }
      else {
        if ((*(uint *)&nbr->field_0xc >> 0x1a & 7) != 0) {
          nwk_neighbor_set_outgoing_cost(nbr,'\0');
          nwk_neighbor_clear_lqa(nbr);
        }
        if ((*(uint *)&nbr->field_0xc & 3) == 0) {
          iVar3 = core_globals_get();
          if ((*(byte *)(iVar3 + 0xa2a) & 8) != 0) {
            iVar3 = core_globals_get();
            *(byte *)(iVar3 + 0xa2a) = *(byte *)(iVar3 + 0xa2a) & 0xf7;
          }
        }
      }
    }
  }
  return;
}

