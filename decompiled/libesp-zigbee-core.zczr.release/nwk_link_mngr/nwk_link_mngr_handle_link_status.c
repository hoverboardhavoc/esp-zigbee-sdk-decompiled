/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_link_mngr.o -> nwk_link_mngr_handle_link_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_link_mngr_handle_link_status(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  byte bVar11;
  uint uVar12;
  byte bVar13;
  char cStack_3a;
  byte bStack_39;
  ushort uStack_38;
  ushort uStack_36;
  ushort uStack_34;
  byte bStack_32;
  
  cStack_3a = '\0';
  iVar5 = nwk_is_router_started();
  if (iVar5 == 0) {
    return;
  }
  iVar5 = nwk_secur_get_seclevel();
  if ((ushort)(iVar5 != 0) != (*(ushort *)(param_1 + 0x16) >> 1 & 1)) {
    return;
  }
  iVar5 = zmsg_get_offset(param_1);
  iVar6 = zmsg_read_bytes(param_1,iVar5,1,&cStack_3a);
  uVar2 = iVar5 + iVar6 & 0xffff;
  iVar5 = zmsg_read_bytes(param_1,uVar2,1,&bStack_39);
  if (cStack_3a != '\b') {
    iVar5 = __assert_func(0,0,0,0);
  }
  if (*(short *)(param_2 + 2) != *(short *)(param_2 + 6)) {
    return;
  }
  uVar12 = (uint)bStack_39;
  bVar1 = bStack_39 & 0x1f;
  uVar2 = uVar2 + iVar5 & 0xffff;
  uVar7 = zmsg_get_length(param_1);
  if (uVar7 < (uVar12 & 0x1f) * 3 + uVar2) {
    return;
  }
  zmsg_remove_header(param_1,uVar2);
  sVar4 = *(short *)(param_2 + 6);
  iVar5 = nwk_neighbor_table_get_by_short(sVar4);
  if (iVar5 == 0) {
    iVar5 = nwk_neighbor_table_new(1);
    if (iVar5 == 0) {
      return;
    }
    iVar6 = nwk_address_by_short(sVar4,1,iVar5);
    if (iVar6 != 0) {
      return;
    }
    *(uint *)(iVar5 + 0xc) =
         *(uint *)(iVar5 + 0xc) & 0xfffc1fff | (*(byte *)(param_2 + 8) & 0x1f) << 0xd;
    iVar6 = core_globals_get();
    *(undefined1 *)(iVar5 + 0x19) = *(undefined1 *)(iVar6 + 0xa25);
    iVar6 = core_globals_get();
    *(undefined1 *)(iVar5 + 0x18) = *(undefined1 *)(iVar6 + 0xa25);
    nwk_neighbor_update_lqa(iVar5,*(undefined1 *)(param_2 + 9),(int)*(char *)(param_2 + 10));
    if ((bVar1 == 0) && (iVar6 = core_globals_get(), *(short *)(iVar6 + 0xb04) == 0)) {
      iVar6 = milli_timer_get_now();
      iVar8 = core_globals_get();
      iVar8 = milli_timer_get_fire_time(iVar8 + 0xae4);
      if (1000 < (uint)(iVar8 - iVar6)) {
        iVar8 = random_add_jitter(500);
        iVar9 = core_globals_get();
        milli_timer_stop(iVar9 + 0xae4);
        iVar9 = core_globals_get();
        milli_timer_fire_at(iVar9 + 0xae4,iVar6 + iVar8);
      }
    }
  }
  if ((*(uint *)(iVar5 + 0xc) & 3) == 3) {
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfffffffc | (uint)(sVar4 != 0);
  }
  if ((*(uint *)(iVar5 + 0xc) & 0x3c0) == 0xc0) {
    *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfffffc3f | 0x80;
  }
  *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfc03ffff;
  zmsg_read_bytes(param_1,0,2,&uStack_38);
  zmsg_read_bytes(param_1,(bStack_39 & 0x1f) * '\x03' + -3,2,&uStack_36);
  if ((((bStack_39 & 0x20) == 0) || (uVar2 = nwk_get_short_address(), uStack_38 <= uVar2)) &&
     (((bStack_39 & 0x40) == 0 || (uVar2 = nwk_get_short_address(), uVar2 <= uStack_36)))) {
    if ((bStack_39 & 0x20) != 0) {
      *(undefined1 *)(iVar5 + 0x15) = 0;
      *(undefined1 *)(iVar5 + 0x17) = 0;
    }
    sVar4 = 0;
    for (uVar2 = 0; uVar2 != (uVar12 & 0x1f); uVar2 = uVar2 + 1 & 0xff) {
      sVar3 = zmsg_read_bytes(param_1,sVar4,3,&uStack_34);
      uVar10 = (uint)uStack_34;
      sVar4 = sVar3 + sVar4;
      bVar13 = bStack_32 & 7;
      bVar1 = bStack_32 >> 4;
      bVar11 = bVar1 & 7;
      uVar7 = nwk_get_short_address();
      if (uVar10 == uVar7) {
        nwk_neighbor_set_outgoing_cost(iVar5,bVar13);
      }
      if ((bVar1 & 7) != 0) {
        if (bVar13 < bVar11) {
          bVar13 = bVar11;
        }
        *(byte *)(iVar5 + 0x15) = *(char *)(iVar5 + 0x15) + ('\a' - bVar13);
        iVar6 = nwk_neighbor_table_get_by_short(uStack_34);
        if ((iVar6 == 0) || ((*(uint *)(iVar6 + 0xc) >> 0x1a & 7) == 0)) {
          *(byte *)(iVar5 + 0x17) = ('\a' - bVar13) + *(char *)(iVar5 + 0x17);
        }
      }
    }
    if ((bStack_39 & 0x40) != 0) {
      *(undefined1 *)(iVar5 + 0x14) = *(undefined1 *)(iVar5 + 0x15);
      *(undefined1 *)(iVar5 + 0x16) = *(undefined1 *)(iVar5 + 0x17);
    }
  }
  else {
    nwk_neighbor_set_outgoing_cost(iVar5,0);
  }
  if (((*(uint *)(iVar5 + 0xc) & 3) == 0) && ((*(uint *)(iVar5 + 0xc) >> 0x1a & 7) != 0)) {
    iVar5 = core_globals_get();
    *(byte *)(iVar5 + 0xa2a) = *(byte *)(iVar5 + 0xa2a) | 8;
  }
  return;
}

