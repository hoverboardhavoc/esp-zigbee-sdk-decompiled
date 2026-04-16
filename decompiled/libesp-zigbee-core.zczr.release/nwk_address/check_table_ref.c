/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> check_table_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

_Bool check_table_ref(uint16_t ref,bitmap_t *table_map,uint16_t table_size)

{
  char cVar1;
  bitmap_t *pbVar2;
  _Bool _Var3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined3 extraout_var;
  void *__dest;
  bitmap_t *table_map_00;
  uint uVar9;
  uint uVar10;
  int iVar11;
  
  pvVar4 = (void *)__assert_func(0,0,0,0);
  iVar5 = core_globals_get();
  uVar9 = 0;
  pbVar2 = (bitmap_t *)(iVar5 + 0xcaa);
  while( true ) {
    uVar9 = bitmap_find_next_bit(pbVar2,0x20,uVar9);
    uVar9 = uVar9 & 0xff;
    if (0x1f < uVar9) break;
    iVar6 = memcmp((void *)(uVar9 * 3 + 0xc4a + iVar5),(void *)((int)pvVar4 + 5),3);
    if (iVar6 == 0) goto _L0;
    uVar9 = uVar9 + 1 & 0xff;
  }
  uVar9 = bitmap_find_first_zero_bit(pbVar2,0x20);
  uVar9 = uVar9 & 0xff;
  if (0x1f < uVar9) {
    iVar6 = core_globals_get();
    iVar7 = core_globals_get();
    *(undefined1 *)(iVar6 + 0xcaa) = 0;
    *(undefined1 *)(iVar6 + 0xcab) = 0;
    *(undefined1 *)(iVar6 + 0xcac) = 0;
    *(undefined1 *)(iVar6 + 0xcad) = 0;
    uVar10 = 0;
    while( true ) {
      uVar9 = bitmap_find_next_bit(*(undefined4 *)(iVar7 + 0xcb0),*(undefined2 *)(iVar7 + 0xcb8));
      if (*(ushort *)(iVar7 + 0xcb8) <= uVar9) break;
      iVar11 = *(int *)(iVar7 + 0xcb4) + uVar9 * 0x10;
      if ((*(ushort *)(iVar11 + 0xe) >> 10 & 1) == 0) {
        test_and_set_bitmap((uint)*(byte *)(iVar11 + 5),(bitmap_t *)(iVar6 + 0xcaa));
      }
      uVar10 = uVar9 + 1 & 0xffff;
    }
    uVar8 = bitmap_find_first_zero_bit(pbVar2,0x20);
    uVar9 = uVar8 & 0xff;
    if (0x1f < uVar9) {
      pbVar2 = table_map_00;
      _Var3 = check_table_ref((uint16_t)uVar8,table_map_00,(uint16_t)uVar10);
      iVar6 = (int)pbVar2 * 0x10 + CONCAT31(extraout_var,_Var3);
      iVar5 = CONCAT31(extraout_var,_Var3) + uVar10 * 0x10;
      cVar1 = *(char *)(iVar6 + 0xe);
      *(short *)(iVar5 + 0xc) = (short)pbVar2;
      *(char *)(iVar5 + 0xe) = *(char *)(iVar5 + 0xe) + cVar1;
      *(short *)(iVar6 + 0xc) = (short)uVar10;
      *(byte *)(iVar6 + 0xf) = *(byte *)(iVar6 + 0xf) | 4;
      return SUB41(iVar5,0);
    }
  }
_L0:
  test_and_set_bitmap(uVar9,pbVar2);
  memcpy((void *)(uVar9 * 3 + 0xc4a + iVar5),(void *)((int)pvVar4 + 5),3);
  *(char *)((int)__dest + 5) = (char)uVar9;
  pvVar4 = memcpy(__dest,pvVar4,5);
  return SUB41(pvVar4,0);
}

