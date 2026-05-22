/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_ls_heap_shift_down
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ls_heap_shift_down(nwk_link_status_heap_ent *h,uint8_t n,uint8_t idx)

{
  ezb_shortaddr_t eVar1;
  undefined1 uVar2;
  uint8_t uVar3;
  undefined1 uVar4;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  nwk_link_status_heap_ent *pnVar5;
  uint uVar6;
  nwk_link_status_heap_ent *pnVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  nwk_link_status_heap_ent tmp;
  
  uVar6 = CONCAT31(in_register_00002031,idx);
  while( true ) {
    uVar10 = (uVar6 & 0x7f) * 2 + 1 & 0xff;
    uVar8 = (uVar6 + 1) * 2 & 0xff;
    uVar9 = uVar6;
    if ((uVar10 < CONCAT31(in_register_0000202d,n)) &&
       (uVar9 = uVar10, h[uVar10].addr <= h[uVar6].addr)) {
      uVar9 = uVar6;
    }
    if ((uVar8 < CONCAT31(in_register_0000202d,n)) && (h[uVar9].addr < h[uVar8].addr)) {
      uVar9 = uVar8;
    }
    if (uVar6 == uVar9) break;
    pnVar5 = h + uVar6;
    eVar1 = pnVar5->addr;
    uVar3 = pnVar5->link_status;
    uVar4 = pnVar5->field_0x3;
    pnVar7 = h + uVar9;
    pnVar5->addr = pnVar7->addr;
    uVar2 = pnVar7->field_0x3;
    pnVar5->link_status = pnVar7->link_status;
    pnVar5->field_0x3 = uVar2;
    pnVar7->addr = eVar1;
    pnVar7->link_status = uVar3;
    pnVar7->field_0x3 = uVar4;
    uVar6 = uVar9;
  }
  return;
}

