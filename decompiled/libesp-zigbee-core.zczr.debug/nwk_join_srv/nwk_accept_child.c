/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_join_srv.o -> nwk_accept_child
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

mac_status_t
nwk_accept_child(uint8_t iface_id,ezb_extaddr_t *device_extaddr,mac_cap_info_t mac_cap,
                nwk_join_method_t join_method,ezb_shortaddr_t *device_shortaddr)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  mac_status_t mVar4;
  _Bool _Var5;
  short *psVar6;
  int *piVar7;
  int iVar8;
  undefined3 extraout_var;
  short *psVar9;
  undefined3 in_register_00002035;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  
  psVar6 = (short *)nwk_neighbor_table_get_by_extended(device_extaddr);
  bVar2 = (mac_cap & 2) != 0;
  uVar14 = (mac_cap & 8) >> 3;
  if ((psVar6 != (short *)0x0) && (*(int *)(psVar6 + 6) << 0x14 < 0)) {
    return 0xe2;
  }
  piVar7 = (int *)nwk_get_extended_address();
  if ((*piVar7 == *(int *)&device_extaddr->field_0) &&
     (piVar7[1] == *(int *)((int)&device_extaddr->field_0 + 4))) {
    return '\x02';
  }
  if (psVar6 == (short *)0x0) {
    psVar6 = (short *)nwk_neighbor_table_new(bVar2);
    if (psVar6 == (short *)0x0) {
      return '\x01';
    }
    if ((mac_cap & 2) == 0) {
      uVar12 = 2;
    }
    else {
      uVar12 = 1;
    }
    *(uint *)(psVar6 + 6) = uVar12 | *(uint *)(psVar6 + 6) & 0xfffffffc;
    bVar11 = true;
    bVar3 = true;
  }
  else {
    if ((*(uint *)(psVar6 + 6) & 3) == 0) {
      bVar11 = true;
    }
    else if ((*(uint *)(psVar6 + 6) & 3) == 1) {
      bVar11 = true;
    }
    else {
      bVar11 = false;
    }
    if (bVar2 == bVar11) {
      if ((*(uint *)(psVar6 + 6) >> 10 & 1) == uVar14) {
        uVar1 = *device_shortaddr;
        uVar12 = nwk_neighbor_get_shortaddr(psVar6);
        if (uVar1 == uVar12) {
          bVar11 = true;
        }
        else {
          bVar11 = false;
        }
      }
      else {
        bVar11 = false;
      }
    }
    else {
      bVar11 = false;
    }
    bVar3 = false;
  }
  if (CONCAT31(in_register_00002035,join_method) < 6) {
    uVar12 = 1 << (join_method & 0x1f);
    if ((uVar12 & 9) == 0) {
      if ((uVar12 & 0x24) == 0) {
        if ((uVar12 & 0x12) == 0) goto _L0;
        iVar8 = aps_secur_is_centralized();
        if (iVar8 == 0) {
          mVar4 = '\x02';
          goto _L0;
        }
        if (!bVar11) {
          mVar4 = '\x02';
          goto _L0;
        }
      }
    }
    else {
      iVar8 = core_globals_get();
      if (*(char *)(iVar8 + 0xb07) == '\0') {
        mVar4 = '\x02';
        goto _L0;
      }
    }
    if (*device_shortaddr == 0xfffe) {
      if (!bVar3) goto _L0;
      uVar12 = nwk_assign_shortaddr();
    }
    else {
      _Var5 = nwk_check_shortaddr_conflict(device_extaddr,*device_shortaddr);
      if (CONCAT31(extraout_var,_Var5) == 0) {
        nwk_assign_shortaddr();
        mVar4 = 0xf0;
        goto _L0;
      }
      uVar12 = (uint)*device_shortaddr;
    }
  }
  else {
_L0:
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_join_srv.c",0x8c,"nwk_accept_child",&_LC3);
_L0:
    uVar12 = nwk_neighbor_get_shortaddr(psVar6);
  }
  psVar9 = psVar6;
  if (!bVar3) {
    if ((*(uint *)(psVar6 + 6) & 3) == 0) {
      bVar11 = true;
    }
    else if ((*(uint *)(psVar6 + 6) & 3) == 1) {
      bVar11 = true;
    }
    else {
      bVar11 = false;
    }
    if (bVar2 != bVar11) {
      psVar9 = (short *)nwk_neighbor_table_new(bVar2);
      if (psVar9 == (short *)0x0) {
        mVar4 = '\x01';
        goto _L0;
      }
      nwk_neighbor_table_delete(psVar6);
    }
  }
  if (psVar9 == (short *)0x0) {
    __assert_func("//build/esp-zigbee/src/core/nwk/nwk_join_srv.c",0xa5,"nwk_accept_child",
                  "nbr != ((void *)0)");
_L0:
    nwk_address_unlock_ref();
  }
  else if (*psVar9 != -1) goto _L0;
  iVar8 = nwk_address_update(device_extaddr,uVar12,psVar9);
  psVar6 = psVar9;
  if (iVar8 == 0) {
    nwk_address_lock_ref(*psVar9);
    *(uint *)(psVar9 + 6) = *(uint *)(psVar9 + 6) & 0xfffc1fff | (iface_id & 0x1f) << 0xd;
    if ((mac_cap & 2) == 0) {
      uVar13 = 2;
    }
    else {
      uVar13 = 1;
    }
    uVar10 = *(uint *)(psVar9 + 6);
    *(uint *)(psVar9 + 6) = uVar13 | uVar10 & 0xfffffffc;
    uVar14 = uVar13 | uVar10 & 0xfffffbfc | uVar14 << 10;
    *(uint *)(psVar9 + 6) = uVar14;
    *(uint *)(psVar9 + 6) = uVar14 | 0x800;
    nwk_route_record_table_remove_by_dst(uVar12);
    nwk_route_table_remove_by_dst(uVar12);
    *device_shortaddr = (ezb_shortaddr_t)uVar12;
    mVar4 = '\0';
  }
  else {
    mVar4 = '\x01';
  }
_L0:
  if (((bVar3) && (psVar6 != (short *)0x0)) && (mVar4 != '\0')) {
    nwk_neighbor_table_delete(psVar6);
  }
  return mVar4;
}

