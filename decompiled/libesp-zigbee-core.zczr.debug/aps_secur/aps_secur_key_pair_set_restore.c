/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_secur.o -> aps_secur_key_pair_set_restore
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_secur_key_pair_set_restore(void)

{
  ushort uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined1 *__s;
  bool bVar6;
  undefined4 uVar7;
  undefined1 auStack_54 [8];
  undefined1 auStack_4c [16];
  undefined1 auStack_3c [16];
  undefined4 uStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  undefined2 uStack_24;
  char cStack_22;
  
  uStack_24 = 0;
  cStack_22 = '\0';
  ds_aps_key_pair_itor_read(auStack_54);
  bVar2 = false;
  do {
    if (cStack_22 != '\0') {
      bVar6 = false;
_L0:
      if ((bVar2) || (bVar6)) {
        aps_secur_key_pair_set_refresh_stored_key_pairs();
      }
      return;
    }
    __s = (undefined1 *)aps_secur_get_key_pair_by_addr(auStack_54);
    if (__s == (undefined1 *)0x0) {
      iVar3 = core_globals_get();
      iVar3 = *(int *)(iVar3 + 0x9a0);
      iVar4 = core_globals_get();
      uVar7 = *(undefined4 *)(iVar4 + 0x9a4);
      iVar4 = core_globals_get();
      uVar1 = *(ushort *)(iVar4 + 0x9a8);
      uVar5 = mempool_alloc_idx(uVar7,(uint)uVar1);
      if (uVar1 <= uVar5) {
        bVar6 = true;
        goto _L0;
      }
      __s = (undefined1 *)(iVar3 + uVar5 * 0x38);
      if (__s == (undefined1 *)0x0) {
        bVar6 = true;
        goto _L0;
      }
    }
    else {
      bVar2 = true;
    }
    memset(__s,0,0x38);
    *__s = (char)auStack_54._0_4_;
    __s[1] = SUB41(auStack_54._0_4_,1);
    __s[2] = SUB41(auStack_54._0_4_,2);
    __s[3] = SUB41(auStack_54._0_4_,3);
    __s[4] = (char)auStack_54._4_4_;
    __s[5] = SUB41(auStack_54._4_4_,1);
    __s[6] = SUB41(auStack_54._4_4_,2);
    __s[7] = SUB41(auStack_54._4_4_,3);
    memcpy(__s + 0x12,auStack_4c,0x10);
    memcpy(__s + 0x22,auStack_3c,0x10);
    *(undefined4 *)(__s + 8) = uStack_2c;
    __s[0x32] = uStack_28;
    __s[0x33] = uStack_27;
    *(undefined2 *)(__s + 0x34) = uStack_26;
    ds_aps_key_pair_next(auStack_54);
  } while( true );
}

