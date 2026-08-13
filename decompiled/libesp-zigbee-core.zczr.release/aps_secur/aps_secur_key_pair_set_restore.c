/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> aps_secur.o -> aps_secur_key_pair_set_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_restore(void)

{
  ushort uVar1;
  bool bVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  undefined1 auStack_54 [8];
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [16];
  undefined4 uStack_2c;
  undefined2 uStack_28;
  undefined2 uStack_26;
  short sStack_24;
  char cStack_22;
  
  sStack_24 = 0;
  cStack_22 = '\0';
  bVar2 = false;
  ds_aps_key_pair_itor_read(auStack_54);
  while (cStack_22 == '\0') {
    puVar3 = (undefined1 *)aps_secur_get_key_pair_by_addr(auStack_54);
    if (puVar3 == (undefined1 *)0x0) {
      iVar4 = core_globals_get();
      iVar4 = *(int *)(iVar4 + 0x9a0);
      iVar5 = core_globals_get();
      uVar7 = *(undefined4 *)(iVar5 + 0x9a4);
      iVar5 = core_globals_get();
      uVar1 = *(ushort *)(iVar5 + 0x9a8);
      uVar6 = mempool_alloc_idx(uVar7,(uint)uVar1);
      if ((uVar1 <= uVar6) ||
         (puVar3 = (undefined1 *)(iVar4 + uVar6 * 0x38), puVar3 == (undefined1 *)0x0)) goto _L0;
    }
    else {
      bVar2 = true;
    }
    memset(puVar3 + 0xc,0,0x2c);
    *puVar3 = (char)auStack_54._0_4_;
    puVar3[1] = SUB41(auStack_54._0_4_,1);
    puVar3[3] = SUB41(auStack_54._0_4_,3);
    puVar3[4] = (char)auStack_54._4_4_;
    puVar3[5] = SUB41(auStack_54._4_4_,1);
    puVar3[6] = SUB41(auStack_54._4_4_,2);
    puVar3[7] = SUB41(auStack_54._4_4_,3);
    puVar3[2] = SUB41(auStack_54._0_4_,2);
    secur_key_copy(puVar3 + 0x12,auStack_4c);
    secur_key_copy(puVar3 + 0x22,auStack_3c);
    *(undefined4 *)(puVar3 + 8) = uStack_2c;
    *(undefined2 *)(puVar3 + 0x10) = 0xffff;
    *(undefined2 *)(puVar3 + 0x32) = uStack_28;
    *(undefined2 *)(puVar3 + 0x34) = uStack_26;
    if (cStack_22 == '\0') {
      sStack_24 = sStack_24 + 1;
      ds_aps_key_pair_itor_read(auStack_54);
    }
  }
  if (bVar2) {
_L0:
    iVar4 = ds_internal_remove_entry(9,0xffffffff,0);
    if (iVar4 == 0) {
      iVar4 = core_globals_get();
      uVar6 = 0;
      while ((uVar6 = bitmap_find_next_bit
                                (*(undefined4 *)(iVar4 + 0x9a4),*(undefined2 *)(iVar4 + 0x9a8),uVar6
                                ), uVar6 < *(ushort *)(iVar4 + 0x9a8) &&
             (iVar5 = aps_secur_store_key_pair(uVar6 * 0x38 + *(int *)(iVar4 + 0x9a0)), iVar5 == 0))
            ) {
        uVar6 = uVar6 + 1 & 0xffff;
      }
    }
  }
  return;
}

