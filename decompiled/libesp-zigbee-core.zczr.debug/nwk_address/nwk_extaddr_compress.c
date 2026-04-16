/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> nwk_extaddr_compress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_extaddr_compress(ezb_extaddr_t *extaddr,nwk_extaddr_c_t *extaddr_c)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint uVar5;
  nwk_oui_ref_t nVar6;
  nwk_addr_ref_t nVar7;
  undefined3 extraout_var;
  nwk_addr_table_t *tbl;
  undefined2 extraout_var_00;
  undefined2 extraout_var_01;
  ezb_shortaddr_t extraout_a1;
  nwk_addr_table_ent_t *pnVar8;
  char *extaddr_00;
  anon_union_8_2_c961180f_for_ezb_eui64_s_0 aaStack_38 [2];
  
  nVar6 = oui_table_set_oui((uint8_t (*) [3])((int)&extaddr->field_0 + 5));
  if (CONCAT31(extraout_var,nVar6) < 0x20) {
    extaddr_c->oui_ref = nVar6;
    uVar1 = (extaddr->field_0).u8[1];
    uVar2 = (extaddr->field_0).u8[2];
    uVar3 = (extaddr->field_0).u8[3];
    uVar4 = (extaddr->field_0).u8[4];
    extaddr_c->device_id[0] = (extaddr->field_0).u8[0];
    extaddr_c->device_id[1] = uVar1;
    extaddr_c->device_id[2] = uVar2;
    extaddr_c->device_id[3] = uVar3;
    extaddr_c->device_id[4] = uVar4;
    return;
  }
  extaddr_00 = "nwk_extaddr_compress";
  tbl = (nwk_addr_table_t *)
        __assert_func("//build/esp-zigbee/src/core/nwk/nwk_address.c",0x105,"oui_ref < 32");
  aaStack_38[0].u64._0_4_ = 0xffffffff;
  aaStack_38[0].u64._4_4_ = 0xffffffff;
  nVar7 = addr_table_new(tbl);
  uVar5 = CONCAT22(extraout_var_00,nVar7);
  if (tbl->ent_nr <= uVar5) {
    nVar7 = addr_table_lru_reuse(tbl);
    uVar5 = CONCAT22(extraout_var_01,nVar7);
  }
  if (uVar5 < tbl->ent_nr) {
    pnVar8 = tbl->ents;
    pnVar8[uVar5].shortaddr = extraout_a1;
    if ((anon_union_8_2_c961180f_for_ezb_eui64_s_0 *)extaddr_00 ==
        (anon_union_8_2_c961180f_for_ezb_eui64_s_0 *)0x0) {
      extaddr_00 = (char *)aaStack_38;
    }
    nwk_extaddr_compress((ezb_extaddr_t *)extaddr_00,&pnVar8[uVar5].extaddr_c);
  }
  return;
}

