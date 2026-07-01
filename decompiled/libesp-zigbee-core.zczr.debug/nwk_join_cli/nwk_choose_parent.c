/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_cli.o -> nwk_choose_parent
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

nwk_potential_parent_t * nwk_choose_parent(nwk_panid_ref_t panid_ref,_Bool is_ed,_Bool is_init_join)

{
  byte bVar1;
  nwk_potential_parent_t *first;
  _Bool _Var2;
  undefined3 in_register_00002029;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined3 in_register_0000202d;
  undefined3 in_register_00002031;
  uint uVar5;
  nwk_potential_parent_t *pnVar6;
  nwk_potential_parent_t *second;
  
  iVar3 = core_globals_get();
  uVar5 = 0;
  second = (nwk_potential_parent_t *)0x0;
  do {
    uVar5 = bitmap_find_next_bit(iVar3 + 0xba4,6,uVar5);
    uVar5 = uVar5 & 0xff;
    if (5 < uVar5) {
      return second;
    }
    first = (nwk_potential_parent_t *)(iVar3 + 0xb2c + uVar5 * 0x14);
    pnVar6 = second;
    if ((((uint)*(byte *)(uVar5 * 0x14 + iVar3 + 0x1000 + -0x4cc) ==
          CONCAT31(in_register_00002029,panid_ref)) &&
        (bVar1 = *(byte *)(uVar5 * 0x14 + iVar3 + 0x1000 + -0x4cb), iVar4 = core_globals_get(),
        *(byte *)(iVar4 + 0xa37) <= bVar1)) &&
       (iVar4 = *(int *)(iVar3 + uVar5 * 0x14 + 0xb3c), iVar4 << 2 < 0)) {
      if (CONCAT31(in_register_00002031,is_init_join) == 0) {
_L0:
        pnVar6 = first;
        if ((second != (nwk_potential_parent_t *)0x0) &&
           (_Var2 = nwk_compare_parent(first,second), pnVar6 = second,
           CONCAT31(extraout_var,_Var2) != 0)) {
          pnVar6 = first;
        }
      }
      else if (iVar4 << 1 < 0) {
        if (CONCAT31(in_register_0000202d,is_ed) == 0) {
          iVar4 = iVar4 << 0x11;
        }
        else {
          iVar4 = iVar4 << 0x10;
        }
        if (iVar4 < 0) goto _L0;
      }
    }
    uVar5 = uVar5 + 1 & 0xff;
    second = pnVar6;
  } while( true );
}

