/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_link_mngr.o -> nwk_ls_heap_shift_down
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ls_heap_shift_down(nwk_link_status_heap_ent *h,uint8_t n,uint8_t idx)

{
  uint8_t uVar1;
  ezb_shortaddr_t eVar2;
  undefined1 uVar3;
  undefined3 in_register_0000202d;
  uint uVar4;
  uint uVar5;
  nwk_link_status_heap_ent *pnVar6;
  uint uVar7;
  nwk_link_status_heap_ent *pnVar8;
  int iVar9;
  uint uVar10;
  
  uVar4 = CONCAT31(in_register_0000202d,n);
  uVar7 = 0;
  do {
    iVar9 = (uVar7 & 0x7f) * 2;
    uVar5 = iVar9 + 1U & 0xff;
    uVar10 = iVar9 + 2U & 0xff;
    if ((uVar5 < uVar4) && (h[uVar7].addr < h[uVar5].addr)) {
      if (uVar10 < uVar4) goto _L0;
_L0:
      uVar10 = uVar5;
    }
    else {
      uVar5 = uVar7;
      if (uVar4 <= uVar10) {
        return;
      }
_L0:
      if (h[uVar10].addr <= h[uVar5].addr) goto _L0;
    }
    if (uVar7 == uVar10) {
      return;
    }
    pnVar6 = h + uVar10;
    pnVar8 = h + uVar7;
    eVar2 = pnVar8->addr;
    pnVar8->addr = pnVar6->addr;
    uVar3 = pnVar6->field_0x3;
    uVar1 = pnVar8->link_status;
    pnVar8->link_status = pnVar6->link_status;
    pnVar8->field_0x3 = uVar3;
    pnVar6->addr = eVar2;
    pnVar6->link_status = uVar1;
    uVar7 = uVar10;
  } while( true );
}

