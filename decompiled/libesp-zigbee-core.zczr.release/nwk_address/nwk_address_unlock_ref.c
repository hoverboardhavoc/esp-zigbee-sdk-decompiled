/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_address.o -> nwk_address_unlock_ref
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_address_unlock_ref(nwk_addr_ref_t ref)

{
  ushort uVar1;
  undefined2 uVar2;
  ushort ref_00;
  _Bool _Var3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined2 in_register_0000202a;
  int iVar4;
  uint n;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  
  iVar4 = core_globals_get();
  do_unlock_ref((nwk_addr_table_t *)(iVar4 + 0xcb0),ref);
  iVar8 = *(int *)(iVar4 + 0xcb4) + CONCAT22(in_register_0000202a,ref) * 0x10;
  if ((*(byte *)(iVar8 + 0xf) & 4) == 0) {
    return;
  }
  ref_00 = *(ushort *)(iVar8 + 0xc);
  n = (uint)ref_00;
  _Var3 = check_table_ref(ref_00,((nwk_addr_table_t *)(iVar4 + 0xcb0))->ent_in_use,
                          *(uint16_t *)(iVar4 + 0xcb8));
  if (CONCAT31(extraout_var_00,_Var3) != 0) {
    iVar8 = *(int *)(iVar4 + 0xcb4) + n * 0x10;
    uVar7 = (uint)*(byte *)(iVar8 + 0xe);
    if (uVar7 == 0) {
      __assert_func(0,0,0,0);
    }
    *(char *)(iVar8 + 0xe) = (char)(uVar7 - 1);
    if ((uVar7 - 1 & 0xff) == 0) {
      if ((*(ushort *)(iVar8 + 0xe) >> 10 & 3) == 0) {
        iVar8 = *(int *)(iVar4 + 0xcb4);
        iVar6 = n * 0x10 + iVar8;
        if ((*(short *)(iVar6 + 8) == -1) || (*(short *)(iVar6 + 10) == -1)) {
          if ((uint)*(ushort *)(iVar4 + 0xcba) < (uint)*(ushort *)(iVar4 + 0xcb8)) {
            uVar1 = *(ushort *)((uint)*(ushort *)(iVar4 + 0xcba) * 0x10 + iVar8 + 8);
            iVar5 = (uint)uVar1 * 0x10 + iVar8;
            uVar2 = *(undefined2 *)(iVar5 + 10);
            *(ushort *)(iVar6 + 8) = uVar1;
            *(undefined2 *)(iVar6 + 10) = uVar2;
            if (uVar1 != 0xffff) {
              *(ushort *)(iVar5 + 10) = ref_00;
            }
            if (*(ushort *)(iVar6 + 10) != 0xffff) {
              *(ushort *)(iVar8 + (uint)*(ushort *)(iVar6 + 10) * 0x10 + 8) = ref_00;
            }
          }
          else {
            *(ushort *)(iVar6 + 8) = ref_00;
            *(ushort *)(iVar6 + 10) = ref_00;
          }
          *(ushort *)(iVar4 + 0xcba) = ref_00;
        }
        return;
      }
      iVar4 = core_globals_get();
      _Var3 = check_table_ref(ref_00,*(bitmap_t **)(iVar4 + 0xcb0),*(uint16_t *)(iVar4 + 0xcb8));
      if (CONCAT31(extraout_var,_Var3) != 0) {
        iVar8 = *(int *)(iVar4 + 0xcb4) + n * 0x10;
        if (*(char *)(iVar8 + 0xe) == '\0') {
          test_and_clr_bitmap(n,*(bitmap_t **)(iVar4 + 0xcb0));
          addr_table_lru_remove((nwk_addr_table_t *)(iVar4 + 0xcb0),ref_00);
          memset((void *)(*(int *)(iVar4 + 0xcb4) + n * 0x10),0,0x10);
          return;
        }
        *(byte *)(iVar8 + 0xf) = *(byte *)(iVar8 + 0xf) | 8;
      }
      return;
    }
  }
  return;
}

