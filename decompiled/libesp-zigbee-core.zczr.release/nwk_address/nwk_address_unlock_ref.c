/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
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
  ushort ref_00;
  _Bool _Var2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined2 in_register_0000202a;
  int iVar3;
  uint n;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  iVar3 = core_globals_get();
  do_unlock_ref((nwk_addr_table_t *)(iVar3 + 0xc4c),ref);
  iVar7 = *(int *)(iVar3 + 0xc50) + CONCAT22(in_register_0000202a,ref) * 0x12;
  if ((*(byte *)(iVar7 + 0x11) & 4) == 0) {
    return;
  }
  ref_00 = *(ushort *)(iVar7 + 0xe);
  n = (uint)ref_00;
  _Var2 = check_table_ref(ref_00,((nwk_addr_table_t *)(iVar3 + 0xc4c))->ent_in_use,
                          *(uint16_t *)(iVar3 + 0xc54));
  if (CONCAT31(extraout_var_00,_Var2) != 0) {
    iVar7 = *(int *)(iVar3 + 0xc50) + n * 0x12;
    uVar6 = (uint)*(byte *)(iVar7 + 0x10);
    if (uVar6 == 0) {
      __assert_func(0,0,0,0);
    }
    *(char *)(iVar7 + 0x10) = (char)(uVar6 - 1);
    if ((uVar6 - 1 & 0xff) == 0) {
      if ((*(ushort *)(iVar7 + 0x10) >> 10 & 3) == 0) {
        iVar7 = *(int *)(iVar3 + 0xc50);
        iVar5 = n * 0x12 + iVar7;
        if ((*(short *)(iVar5 + 10) == -1) || (*(short *)(iVar5 + 0xc) == -1)) {
          if ((uint)*(ushort *)(iVar3 + 0xc56) < (uint)*(ushort *)(iVar3 + 0xc54)) {
            uVar1 = *(ushort *)((uint)*(ushort *)(iVar3 + 0xc56) * 0x12 + iVar7 + 10);
            *(ushort *)(iVar5 + 10) = uVar1;
            iVar4 = (uint)uVar1 * 0x12 + iVar7;
            *(undefined2 *)(iVar5 + 0xc) = *(undefined2 *)(iVar4 + 0xc);
            if (uVar1 != 0xffff) {
              *(ushort *)(iVar4 + 0xc) = ref_00;
            }
            if (*(ushort *)(iVar5 + 0xc) != 0xffff) {
              *(ushort *)(iVar7 + (uint)*(ushort *)(iVar5 + 0xc) * 0x12 + 10) = ref_00;
            }
          }
          else {
            *(ushort *)(iVar5 + 10) = ref_00;
            *(ushort *)(iVar5 + 0xc) = ref_00;
          }
          *(ushort *)(iVar3 + 0xc56) = ref_00;
        }
        return;
      }
      iVar3 = core_globals_get();
      _Var2 = check_table_ref(ref_00,*(bitmap_t **)(iVar3 + 0xc4c),*(uint16_t *)(iVar3 + 0xc54));
      if (CONCAT31(extraout_var,_Var2) != 0) {
        iVar7 = *(int *)(iVar3 + 0xc50) + n * 0x12;
        if (*(char *)(iVar7 + 0x10) == '\0') {
          test_and_clr_bitmap(n,*(bitmap_t **)(iVar3 + 0xc4c));
          addr_table_lru_remove((nwk_addr_table_t *)(iVar3 + 0xc4c),ref_00);
          memset((void *)(*(int *)(iVar3 + 0xc50) + n * 0x12),0,0x12);
          return;
        }
        *(byte *)(iVar7 + 0x11) = *(byte *)(iVar7 + 0x11) | 8;
      }
      return;
    }
  }
  return;
}

