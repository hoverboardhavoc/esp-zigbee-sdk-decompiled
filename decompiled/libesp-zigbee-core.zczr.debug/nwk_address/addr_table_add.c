/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_address.o -> addr_table_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: unknown_extaddr */
/* WARNING: Unknown calling convention */

nwk_addr_ref_t
addr_table_add(nwk_addr_table_t *tbl,ezb_shortaddr_t shortaddr,ezb_extaddr_t *extaddr)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined3 uVar3;
  undefined4 uVar4;
  nwk_addr_ref_t nVar5;
  undefined2 extraout_var;
  uint uVar6;
  undefined2 extraout_var_00;
  nwk_addr_table_ent_t *pnVar7;
  undefined1 local_18 [4];
  ezb_extaddr_t unknown_extaddr;
  
  local_18 = (undefined1  [4])0xffffffff;
  unknown_extaddr.field_0.u64._0_4_ = 0xffffffff;
  nVar5 = addr_table_new(tbl);
  uVar6 = CONCAT22(extraout_var,nVar5);
  if (tbl->ent_nr <= uVar6) {
    nVar5 = addr_table_lru_reuse(tbl);
    uVar6 = CONCAT22(extraout_var_00,nVar5);
  }
  if (uVar6 < tbl->ent_nr) {
    pnVar7 = tbl->ents + uVar6;
    pnVar7->shortaddr = shortaddr;
    if (extaddr == (ezb_extaddr_t *)0x0) {
      extaddr = (ezb_extaddr_t *)local_18;
    }
    uVar2 = *(undefined4 *)&extaddr->field_0;
    puVar1 = (undefined4 *)((int)&extaddr->field_0 + 4);
    uVar3 = *(undefined3 *)puVar1;
    uVar4 = *puVar1;
    (pnVar7->extaddr).field_0.u8[0] = (uint8_t)*(undefined3 *)&extaddr->field_0;
    (pnVar7->extaddr).field_0.u8[1] = (uint8_t)((uint)uVar2 >> 8);
    (pnVar7->extaddr).field_0.u8[2] = (uint8_t)((uint)uVar2 >> 0x10);
    (pnVar7->extaddr).field_0.u8[3] = (uint8_t)((uint)uVar2 >> 0x18);
    (pnVar7->extaddr).field_0.u8[4] = (uint8_t)uVar3;
    (pnVar7->extaddr).field_0.u8[5] = (uint8_t)((uint)uVar4 >> 8);
    (pnVar7->extaddr).field_0.u8[6] = (uint8_t)((uint)uVar4 >> 0x10);
    (pnVar7->extaddr).field_0.u8[7] = (uint8_t)((uint)uVar4 >> 0x18);
  }
  return (nwk_addr_ref_t)uVar6;
}

