/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_accept_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 nwk_accept_child(uint param_1,int *param_2,uint param_3,uint param_4,ushort *param_5)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  short *psVar5;
  int *piVar6;
  int iVar7;
  short *psVar8;
  uint uVar9;
  undefined4 uVar10;
  uint uVar11;
  int local_38;
  int iStack_34;
  
  psVar5 = (short *)nwk_neighbor_table_get_by_extended(param_2);
  if ((psVar5 != (short *)0x0) && (*(int *)(psVar5 + 6) << 0x14 < 0)) {
    return 0xe2;
  }
  piVar6 = (int *)nwk_get_extended_address();
  if ((*piVar6 == *param_2) && (piVar6[1] == param_2[1])) {
    return 2;
  }
  uVar4 = (param_3 & 2) >> 1;
  uVar11 = param_3 >> 3 & 1;
  if (psVar5 != (short *)0x0) goto _L0;
  if ((param_3 & 2) == 0) {
    uVar9 = nwk_neighbor_table_get_ed_num();
    iVar7 = core_globals_get();
    if (*(byte *)(iVar7 + 0x9db) <= uVar9) {
      return 1;
    }
  }
  psVar5 = (short *)nwk_neighbor_table_new(uVar4);
  if (psVar5 == (short *)0x0) {
    return 1;
  }
  bVar2 = true;
  *(uint *)(psVar5 + 6) = *(uint *)(psVar5 + 6) & 0xfffffffc | -uVar4 & 3 ^ 2;
  bVar3 = true;
  do {
    if (param_4 < 6) {
      uVar9 = 1 << (param_4 & 0x1f);
      if ((uVar9 & 9) != 0) {
        iVar7 = core_globals_get();
        if (*(char *)(iVar7 + 0xb07) != '\0') goto _L0;
        goto _L46;
      }
      if ((uVar9 & 0x24) != 0) goto _L0;
      if ((uVar9 & 0x12) != 0) break;
    }
    __assert_func(0,0,0,0);
_L0:
    bVar2 = false;
    if (((*(uint *)(psVar5 + 6) & 3) < 2 == uVar4) && ((*(uint *)(psVar5 + 6) >> 10 & 1) == uVar11))
    {
      uVar1 = *param_5;
      uVar9 = nwk_neighbor_get_shortaddr(psVar5);
      bVar2 = uVar1 == uVar9;
    }
    bVar3 = false;
  } while( true );
  iVar7 = aps_secur_is_centralized();
  if ((iVar7 == 0) || (!bVar2)) {
_L46:
    uVar10 = 2;
    goto _L0;
  }
_L0:
  if (*param_5 == 0xfffe) {
    if (bVar3) {
      uVar9 = nwk_assign_shortaddr();
    }
    else {
      uVar9 = nwk_neighbor_get_shortaddr(psVar5);
_L0:
      if ((*(uint *)(psVar5 + 6) & 3) < 2 != uVar4) {
        psVar8 = (short *)nwk_neighbor_table_new(uVar4);
        if (psVar8 == (short *)0x0) {
          return 1;
        }
        nwk_neighbor_table_delete(psVar5);
        psVar5 = psVar8;
      }
    }
  }
  else {
    iVar7 = nwk_address_extended_by_short(&local_38);
    if ((iVar7 == 0) && ((local_38 != *param_2 || (iStack_34 != param_2[1])))) {
      nwk_assign_shortaddr();
      uVar10 = 0xf0;
      goto _L0;
    }
    uVar9 = (uint)*param_5;
    if (!bVar3) goto _L0;
  }
  if (*psVar5 != -1) {
    nwk_address_unlock_ref();
  }
  iVar7 = nwk_address_update(param_2,uVar9,psVar5);
  uVar10 = 1;
  if (iVar7 == 0) {
    nwk_address_lock_ref(*psVar5);
    *(uint *)(psVar5 + 6) =
         -uVar4 & 3 ^ 2 | 0x800 | uVar11 << 10 | (param_1 & 0x1f) << 0xd |
         *(uint *)(psVar5 + 6) & 0xfffc13fc;
    nwk_route_record_table_remove_by_dst(uVar9);
    nwk_route_table_remove_by_dst(uVar9);
    *param_5 = (ushort)uVar9;
    return 0;
  }
_L0:
  if (bVar3) {
    nwk_neighbor_table_delete(psVar5);
    return uVar10;
  }
  return uVar10;
}

