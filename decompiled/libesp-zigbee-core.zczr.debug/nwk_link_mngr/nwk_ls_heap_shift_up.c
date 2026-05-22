/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_ls_heap_shift_up
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ls_heap_shift_up(nwk_link_status_heap_ent *h,uint8_t idx)

{
  ushort uVar1;
  undefined1 uVar2;
  uint8_t uVar3;
  undefined1 uVar4;
  undefined3 in_register_0000202d;
  uint uVar5;
  nwk_link_status_heap_ent *pnVar6;
  uint uVar7;
  nwk_link_status_heap_ent *pnVar8;
  nwk_link_status_heap_ent tmp;
  
  uVar5 = CONCAT31(in_register_0000202d,idx);
  while( true ) {
    if (uVar5 == 0) {
      return;
    }
    uVar7 = (int)(uVar5 - 1) / 2;
    pnVar8 = h + (uVar7 & 0xff);
    uVar1 = pnVar8->addr;
    pnVar6 = h + uVar5;
    if (pnVar6->addr <= uVar1) break;
    uVar3 = pnVar8->link_status;
    uVar4 = pnVar8->field_0x3;
    pnVar8->addr = pnVar6->addr;
    uVar2 = pnVar6->field_0x3;
    pnVar8->link_status = pnVar6->link_status;
    pnVar8->field_0x3 = uVar2;
    pnVar6->addr = uVar1;
    pnVar6->link_status = uVar3;
    pnVar6->field_0x3 = uVar4;
    uVar5 = uVar7 & 0xff;
  }
  return;
}

