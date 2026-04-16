/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_extaddr_compress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_extaddr_compress(ezb_extaddr_t *extaddr,nwk_extaddr_c_t *extaddr_c)

{
  char cVar1;
  bitmap_t *pbVar2;
  _Bool _Var3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  undefined3 extraout_var;
  bitmap_t *table_map;
  uint uVar8;
  uint uVar9;
  int iVar10;
  void *__s2;
  
  __s2 = (void *)((int)&extaddr->field_0 + 5);
  iVar4 = core_globals_get();
  uVar8 = 0;
  pbVar2 = (bitmap_t *)(iVar4 + 0xcaa);
  while( true ) {
    uVar8 = bitmap_find_next_bit(pbVar2,0x20,uVar8);
    uVar8 = uVar8 & 0xff;
    if (0x1f < uVar8) break;
    iVar5 = memcmp((void *)(uVar8 * 3 + 0xc4a + iVar4),__s2,3);
    if (iVar5 == 0) goto _L0;
    uVar8 = uVar8 + 1 & 0xff;
  }
  uVar8 = bitmap_find_first_zero_bit(pbVar2,0x20);
  uVar8 = uVar8 & 0xff;
  if (0x1f < uVar8) {
    iVar5 = core_globals_get();
    iVar6 = core_globals_get();
    *(undefined1 *)(iVar5 + 0xcaa) = 0;
    *(undefined1 *)(iVar5 + 0xcab) = 0;
    *(undefined1 *)(iVar5 + 0xcac) = 0;
    *(undefined1 *)(iVar5 + 0xcad) = 0;
    uVar9 = 0;
    while( true ) {
      uVar8 = bitmap_find_next_bit(*(undefined4 *)(iVar6 + 0xcb0),*(undefined2 *)(iVar6 + 0xcb8));
      if (*(ushort *)(iVar6 + 0xcb8) <= uVar8) break;
      iVar10 = *(int *)(iVar6 + 0xcb4) + uVar8 * 0x10;
      if ((*(ushort *)(iVar10 + 0xe) >> 10 & 1) == 0) {
        test_and_set_bitmap((uint)*(byte *)(iVar10 + 5),(bitmap_t *)(iVar5 + 0xcaa));
      }
      uVar9 = uVar8 + 1 & 0xffff;
    }
    uVar7 = bitmap_find_first_zero_bit(pbVar2,0x20);
    uVar8 = uVar7 & 0xff;
    if (0x1f < uVar8) {
      pbVar2 = table_map;
      _Var3 = check_table_ref((uint16_t)uVar7,table_map,(uint16_t)uVar9);
      iVar5 = (int)pbVar2 * 0x10 + CONCAT31(extraout_var,_Var3);
      iVar4 = CONCAT31(extraout_var,_Var3) + uVar9 * 0x10;
      cVar1 = *(char *)(iVar5 + 0xe);
      *(short *)(iVar4 + 0xc) = (short)pbVar2;
      *(char *)(iVar4 + 0xe) = *(char *)(iVar4 + 0xe) + cVar1;
      *(short *)(iVar5 + 0xc) = (short)uVar9;
      *(byte *)(iVar5 + 0xf) = *(byte *)(iVar5 + 0xf) | 4;
      return;
    }
  }
_L0:
  test_and_set_bitmap(uVar8,pbVar2);
  memcpy((void *)(uVar8 * 3 + 0xc4a + iVar4),__s2,3);
  extaddr_c->oui_ref = (nwk_oui_ref_t)uVar8;
  memcpy(extaddr_c,extaddr,5);
  return;
}

