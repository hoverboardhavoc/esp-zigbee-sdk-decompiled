/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_zed_set_timeout
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_zed_set_timeout(nwk_neighbor_t *nbr,uint8_t timeout)

{
  ezb_shortaddr_t eVar1;
  undefined2 extraout_var;
  undefined3 in_register_0000202d;
  uint uVar2;
  uint extraout_a1;
  uint uVar3;
  
  uVar2 = CONCAT31(in_register_0000202d,timeout);
  if (((*(uint *)&nbr->field_0xc & 3) != 2) && ((*(uint *)&nbr->field_0xc & 0x3c0) != 0)) {
    eVar1 = nwk_neighbor_get_shortaddr(nbr);
    nbr = (nwk_neighbor_t *)CONCAT22(extraout_var,eVar1);
    uVar2 = extraout_a1;
  }
  *(uint *)((int)&nbr->dev + 4) = *(uint *)((int)&nbr->dev + 4) & 0xff0fffff | (uVar2 & 0xf) << 0x14
  ;
  uVar3 = 10;
  if (uVar2 != 0) {
    uVar3 = 0x3c << (uVar2 & 0x1f);
  }
  *(uint *)((int)&nbr->dev + 4) = uVar3 & 0xfffff | *(uint *)((int)&nbr->dev + 4) & 0xfff00000;
  return;
}

