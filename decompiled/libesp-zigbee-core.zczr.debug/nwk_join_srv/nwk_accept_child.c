/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_accept_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_accept_child(uint param_1,int *param_2,uint param_3,uint param_4,ushort *param_5)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  short *psVar4;
  int *piVar5;
  int iVar6;
  short *psVar7;
  uint uVar8;
  bool bVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  psVar4 = (short *)nwk_neighbor_table_get_by_extended(param_2);
  uVar12 = param_3 & 2;
  bVar2 = uVar12 != 0;
  uVar11 = param_3 >> 3 & 1;
  if ((psVar4 != (short *)0x0) && (*(int *)(psVar4 + 6) << 0x14 < 0)) {
    return 0xe2;
  }
  piVar5 = (int *)nwk_get_extended_address();
  if ((*piVar5 == *param_2) && (piVar5[1] == param_2[1])) {
    return 2;
  }
  if (psVar4 == (short *)0x0) {
    if (uVar12 == 0) {
      uVar10 = nwk_neighbor_table_get_ed_num();
      iVar6 = core_globals_get();
      if (*(byte *)(iVar6 + 0x9db) <= uVar10) {
        return 1;
      }
    }
    psVar4 = (short *)nwk_neighbor_table_new(bVar2);
    if (psVar4 == (short *)0x0) {
      return 1;
    }
    if (uVar12 == 0) {
      uVar10 = 2;
    }
    else {
      uVar10 = 1;
    }
    *(uint *)(psVar4 + 6) = uVar10 | *(uint *)(psVar4 + 6) & 0xfffffffc;
    bVar9 = true;
    bVar3 = true;
  }
  else {
    if ((*(uint *)(psVar4 + 6) & 3) == 0) {
      bVar9 = true;
    }
    else if ((*(uint *)(psVar4 + 6) & 3) == 1) {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
    if (bVar2 == bVar9) {
      if ((*(uint *)(psVar4 + 6) >> 10 & 1) == uVar11) {
        uVar1 = *param_5;
        uVar10 = nwk_neighbor_get_shortaddr(psVar4);
        if (uVar1 == uVar10) {
          bVar9 = true;
        }
        else {
          bVar9 = false;
        }
      }
      else {
        bVar9 = false;
      }
    }
    else {
      bVar9 = false;
    }
    bVar3 = false;
  }
  if (param_4 < 6) {
    uVar10 = 1 << (param_4 & 0x1f);
    if ((uVar10 & 9) == 0) {
      if ((uVar10 & 0x24) == 0) {
        if ((uVar10 & 0x12) == 0) goto _L0;
        iVar6 = aps_secur_is_centralized();
        if (iVar6 == 0) {
          iVar6 = 2;
          goto _L0;
        }
        if (!bVar9) {
          iVar6 = 2;
          goto _L0;
        }
      }
    }
    else {
      iVar6 = core_globals_get();
      if (*(char *)(iVar6 + 0xb07) == '\0') {
        iVar6 = 2;
        goto _L0;
      }
    }
    if (*param_5 == 0xfffe) {
      if (!bVar3) goto _L0;
      uVar10 = nwk_assign_shortaddr();
    }
    else {
      iVar6 = nwk_check_shortaddr_conflict(param_2);
      if (iVar6 == 0) {
        nwk_assign_shortaddr();
        iVar6 = 0xf0;
        goto _L0;
      }
      uVar10 = (uint)*param_5;
    }
  }
  else {
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0x8d,
                  "nwk_accept_child",&_L0);
_L0:
    uVar10 = nwk_neighbor_get_shortaddr(psVar4);
  }
  psVar7 = psVar4;
  if (!bVar3) {
    if ((*(uint *)(psVar4 + 6) & 3) == 0) {
      bVar9 = true;
    }
    else if ((*(uint *)(psVar4 + 6) & 3) == 1) {
      bVar9 = true;
    }
    else {
      bVar9 = false;
    }
    if (bVar2 != bVar9) {
      psVar7 = (short *)nwk_neighbor_table_new(bVar2);
      if (psVar7 == (short *)0x0) {
        iVar6 = 1;
        goto _L0;
      }
      nwk_neighbor_table_delete(psVar4);
    }
  }
  if (psVar7 == (short *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_join_srv.c",0xa6,
                  "nwk_accept_child","nbr != ((void *)0)");
_L0:
    nwk_address_unlock_ref();
  }
  else if (*psVar7 != -1) goto _L0;
  iVar6 = nwk_address_update(param_2,uVar10,psVar7);
  psVar4 = psVar7;
  if (iVar6 == 0) {
    nwk_address_lock_ref(*psVar7);
    *(uint *)(psVar7 + 6) = *(uint *)(psVar7 + 6) & 0xfffc1fff | (param_1 & 0x1f) << 0xd;
    if (uVar12 == 0) {
      uVar12 = 2;
    }
    else {
      uVar12 = 1;
    }
    uVar8 = *(uint *)(psVar7 + 6);
    *(uint *)(psVar7 + 6) = uVar12 | uVar8 & 0xfffffffc;
    uVar11 = uVar12 | uVar8 & 0xfffffbfc | uVar11 << 10;
    *(uint *)(psVar7 + 6) = uVar11;
    *(uint *)(psVar7 + 6) = uVar11 | 0x800;
    nwk_route_record_table_remove_by_dst(uVar10);
    nwk_route_table_remove_by_dst(uVar10);
    *param_5 = (ushort)uVar10;
    iVar6 = 0;
  }
  else {
    iVar6 = 1;
  }
_L0:
  if (((bVar3) && (psVar4 != (short *)0x0)) && (iVar6 != 0)) {
    nwk_neighbor_table_delete(psVar4);
  }
  return iVar6;
}

