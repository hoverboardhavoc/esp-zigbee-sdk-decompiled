/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_join_srv.o -> nwk_accept_child
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
  uint uVar4;
  short *psVar5;
  int *piVar6;
  int iVar7;
  short *psVar8;
  undefined3 in_register_00002035;
  uint uVar9;
  mac_status_t mVar10;
  uint uVar11;
  int local_38;
  ezb_extaddr_t local_extaddr;
  
  psVar5 = (short *)nwk_neighbor_table_get_by_extended(device_extaddr);
  if ((psVar5 != (short *)0x0) && (*(int *)(psVar5 + 6) << 0x14 < 0)) {
    return 0xe2;
  }
  piVar6 = (int *)nwk_get_extended_address();
  if ((*piVar6 == *(int *)&device_extaddr->field_0) &&
     (piVar6[1] == *(int *)((int)&device_extaddr->field_0 + 4))) {
    return '\x02';
  }
  uVar4 = (mac_cap & 2) >> 1;
  uVar11 = (mac_cap & 8) >> 3;
  if (psVar5 != (short *)0x0) goto _L0;
  psVar5 = (short *)nwk_neighbor_table_new(uVar4);
  if (psVar5 == (short *)0x0) {
    return '\x01';
  }
  bVar2 = true;
  *(uint *)(psVar5 + 6) = *(uint *)(psVar5 + 6) & 0xfffffffc | -uVar4 & 3 ^ 2;
  bVar3 = true;
  do {
    if (CONCAT31(in_register_00002035,join_method) < 6) {
      uVar9 = 1 << (join_method & 0x1f);
      if ((uVar9 & 9) != 0) {
        iVar7 = core_globals_get();
        if (*(char *)(iVar7 + 0xb07) != '\0') goto _L0;
        goto _L39;
      }
      if ((uVar9 & 0x24) != 0) goto _L0;
      if ((uVar9 & 0x12) != 0) break;
    }
    __assert_func(0,0,0,0);
_L0:
    bVar2 = false;
    if (((*(uint *)(psVar5 + 6) & 3) < 2 == uVar4) && ((*(uint *)(psVar5 + 6) >> 10 & 1) == uVar11))
    {
      uVar1 = *device_shortaddr;
      uVar9 = nwk_neighbor_get_shortaddr(psVar5);
      bVar2 = uVar1 == uVar9;
    }
    bVar3 = false;
  } while( true );
  iVar7 = aps_secur_is_centralized();
  if ((iVar7 == 0) || (!bVar2)) {
_L39:
    mVar10 = '\x02';
    goto _L0;
  }
_L0:
  if (*device_shortaddr == 0xfffe) {
    if (bVar3) {
      uVar9 = nwk_assign_shortaddr();
    }
    else {
      uVar9 = nwk_neighbor_get_shortaddr(psVar5);
_L0:
      if ((*(uint *)(psVar5 + 6) & 3) < 2 != uVar4) {
        psVar8 = (short *)nwk_neighbor_table_new(uVar4);
        if (psVar8 == (short *)0x0) {
          return '\x01';
        }
        nwk_neighbor_table_delete(psVar5);
        psVar5 = psVar8;
      }
    }
  }
  else {
    iVar7 = nwk_address_extended_by_short(&local_38);
    if ((iVar7 == 0) &&
       ((local_38 != *(int *)&device_extaddr->field_0 ||
        (local_extaddr.field_0.u64._0_4_ != *(int *)((int)&device_extaddr->field_0 + 4))))) {
      nwk_assign_shortaddr();
      mVar10 = 0xf0;
      goto _L0;
    }
    uVar9 = (uint)*device_shortaddr;
    if (!bVar3) goto _L0;
  }
  if (*psVar5 != -1) {
    nwk_address_unlock_ref();
  }
  iVar7 = nwk_address_update(device_extaddr,uVar9,psVar5);
  mVar10 = '\x01';
  if (iVar7 == 0) {
    nwk_address_lock_ref(*psVar5);
    *(uint *)(psVar5 + 6) =
         -uVar4 & 3 ^ 2 | 0x800 | uVar11 << 10 | (iface_id & 0x1f) << 0xd |
         *(uint *)(psVar5 + 6) & 0xfffc13fc;
    nwk_route_record_table_remove_by_dst(uVar9);
    nwk_route_table_remove_by_dst(uVar9);
    *device_shortaddr = (ezb_shortaddr_t)uVar9;
    return '\0';
  }
_L0:
  if (bVar3) {
    nwk_neighbor_table_delete(psVar5);
  }
  return mVar10;
}

