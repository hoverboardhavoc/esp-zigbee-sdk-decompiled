/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_neighbor.o -> nwk_neighbor_set_auth
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_neighbor_set_auth(nwk_neighbor_t *nbr)

{
  ezb_shortaddr_t eVar1;
  int iVar2;
  uint uVar3;
  undefined4 uStack_24;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 aStack_20;
  uint uStack_18;
  undefined4 uStack_14;
  
  uVar3 = *(uint *)&nbr->field_0xc & 0xfffffc3f;
  if ((*(uint *)&nbr->field_0xc & 3) != 2) {
    *(uint *)&nbr->field_0xc = uVar3 | 0x80;
    iVar2 = core_globals_get();
    (nbr->dev).r.inbound_activity = *(uint8_t *)(iVar2 + 0xa25);
    iVar2 = core_globals_get();
    (nbr->dev).r.outbound_activity = *(uint8_t *)(iVar2 + 0xa25);
    return;
  }
  *(uint *)&nbr->field_0xc = uVar3 | 0x40;
  iVar2 = core_globals_get();
  nwk_neighbor_zed_set_timeout(nbr,*(uint8_t *)(iVar2 + 0xa29));
  if ((*(uint *)&nbr->field_0xc & 0x3c3) != 0x42) {
    nbr = (nwk_neighbor_t *)__assert_func(0,0,0,0);
  }
  uStack_24 = 0;
  aStack_20.u64._0_4_ = 0;
  aStack_20.u64._4_4_ = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  nwk_neighbor_table_remove_stored_child(nbr);
  eVar1 = nwk_neighbor_get_shortaddr(nbr);
  uStack_24 = CONCAT22(eVar1,(undefined2)uStack_24);
  nwk_neighbor_get_extaddr(nbr,(ezb_extaddr_t *)&aStack_20);
  uStack_14 = CONCAT31(uStack_14._1_3_,
                       (byte)(*(uint *)&nbr->field_0xc >> 6) & 0x10 |
                       (byte)(*(uint *)((int)&nbr->dev + 4) >> 0x14) & 0xf | (byte)uStack_14 & 0xe0)
  ;
  uStack_18 = CONCAT22(CONCAT11(nbr->key_seq,(char)(*(uint *)&nbr->field_0xc >> 0xd)),
                       (nbr->dev).r.router_info) & 0xff1fffff;
  ds_internal_add_entry(4,&uStack_24,0x14);
  return;
}

