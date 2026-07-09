/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_link_mngr.o -> nwk_link_mngr_handle_link_status
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_link_mngr_handle_link_status(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  short sVar9;
  byte bVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  ushort uStack_3c;
  byte bStack_3a;
  ushort uStack_36;
  ushort uStack_34;
  byte bStack_32;
  char acStack_31 [13];
  
  acStack_31[0] = '\0';
  iVar4 = nwk_is_router_started();
  if (iVar4 == 0) {
    return;
  }
  iVar4 = nwk_secur_get_seclevel();
  if ((iVar4 != 0) != ((*(ushort *)(param_1 + 0x16) & 2) != 0)) {
    return;
  }
  iVar4 = zmsg_get_offset(param_1);
  iVar5 = zmsg_read_bytes(param_1,iVar4,1,acStack_31);
  uVar11 = iVar4 + iVar5 & 0xffff;
  iVar4 = zmsg_read_bytes(param_1,uVar11,1,&bStack_32);
  uVar11 = uVar11 + iVar4 & 0xffff;
  uVar12 = (uint)bStack_32;
  bVar1 = bStack_32 & 0x1f;
  if (acStack_31[0] == '\b') {
    if (*(short *)(param_2 + 2) != *(short *)(param_2 + 6)) {
      return;
    }
    uVar6 = zmsg_get_length(param_1);
    if (uVar6 < (uVar12 & 0x1f) * 3 + uVar11) {
      return;
    }
    zmsg_remove_header(param_1,uVar11);
    uVar11 = (uint)*(ushort *)(param_2 + 6);
    iVar4 = nwk_neighbor_table_get_by_short(uVar11);
    if (iVar4 == 0) goto _L0;
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/nwk/nwk_link_mngr.c",0x10f,
                  "nwk_link_mngr_handle_link_status","cmd_id == 0x08U");
_L0:
    iVar4 = nwk_neighbor_table_new(1);
    if (iVar4 == 0) {
      return;
    }
    iVar5 = nwk_address_by_short(uVar11,1,iVar4);
    if (iVar5 != 0) {
      return;
    }
    *(uint *)(iVar4 + 0xc) =
         *(uint *)(iVar4 + 0xc) & 0xfffc1fff | (*(byte *)(param_2 + 8) & 0x1f) << 0xd;
    iVar5 = core_globals_get();
    *(undefined1 *)(iVar4 + 0x19) = *(undefined1 *)(iVar5 + 0xa25);
    iVar5 = core_globals_get();
    *(undefined1 *)(iVar4 + 0x18) = *(undefined1 *)(iVar5 + 0xa25);
    nwk_neighbor_update_lqa(iVar4,*(undefined1 *)(param_2 + 9),(int)*(char *)(param_2 + 10));
    if ((bVar1 == 0) && (iVar5 = core_globals_get(), *(short *)(iVar5 + 0xb04) == 0)) {
      iVar5 = milli_timer_get_now();
      iVar7 = core_globals_get();
      iVar7 = milli_timer_get_fire_time(iVar7 + 0xae4);
      if (1000 < (uint)(iVar7 - iVar5)) {
        iVar7 = random_add_jitter(500,1000);
        iVar8 = core_globals_get();
        milli_timer_stop(iVar8 + 0xae4);
        iVar8 = core_globals_get();
        milli_timer_fire_at(iVar8 + 0xae4,iVar5 + iVar7);
      }
    }
  }
  if ((*(uint *)(iVar4 + 0xc) & 3) == 3) {
    *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) & 0xfffffffc | (uint)(uVar11 != 0);
  }
  if ((*(uint *)(iVar4 + 0xc) & 0x3c0) == 0xc0) {
    *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) & 0xfffffc3f | 0x80;
  }
  *(uint *)(iVar4 + 0xc) = *(uint *)(iVar4 + 0xc) & 0xfc03ffff;
  zmsg_read_bytes(param_1,0,2,&uStack_34);
  zmsg_read_bytes(param_1,(bStack_32 & 0x1f) * '\x03' + -3,2,&uStack_36);
  if ((((bStack_32 & 0x20) == 0) || (uVar11 = nwk_get_short_address(), uStack_34 <= uVar11)) &&
     (((bStack_32 & 0x40) == 0 || (uVar11 = nwk_get_short_address(), uVar11 <= uStack_36)))) {
    if ((bStack_32 & 0x20) != 0) {
      *(undefined1 *)(iVar4 + 0x15) = 0;
      *(undefined1 *)(iVar4 + 0x17) = 0;
    }
    sVar9 = 0;
    for (uVar11 = 0; uVar11 < (uVar12 & 0x1f); uVar11 = uVar11 + 1 & 0xff) {
      sVar3 = zmsg_read_bytes(param_1,sVar9,3,&uStack_3c);
      sVar9 = sVar9 + sVar3;
      uVar13 = (uint)uStack_3c;
      bVar10 = bStack_3a & 7;
      bVar1 = bStack_3a >> 4;
      bVar2 = bVar1 & 7;
      uVar6 = nwk_get_short_address();
      if (uVar13 == uVar6) {
        nwk_neighbor_set_outgoing_cost(iVar4,bVar10);
      }
      if ((bVar1 & 7) != 0) {
        if (bVar10 < bVar2) {
          bVar10 = bVar2;
        }
        *(byte *)(iVar4 + 0x15) = *(char *)(iVar4 + 0x15) + ('\a' - bVar10);
        iVar5 = nwk_neighbor_table_get_by_short(uStack_3c);
        if ((iVar5 == 0) || ((*(uint *)(iVar5 + 0xc) >> 0x1a & 7) == 0)) {
          *(byte *)(iVar4 + 0x17) = *(char *)(iVar4 + 0x17) + ('\a' - bVar10);
        }
      }
    }
    if ((bStack_32 & 0x40) != 0) {
      *(undefined1 *)(iVar4 + 0x14) = *(undefined1 *)(iVar4 + 0x15);
      *(undefined1 *)(iVar4 + 0x16) = *(undefined1 *)(iVar4 + 0x17);
      goto _L0;
    }
  }
  else {
    nwk_neighbor_set_outgoing_cost(iVar4,0);
  }
  if (iVar4 == 0) {
    return;
  }
_L0:
  if (((*(uint *)(iVar4 + 0xc) & 3) == 0) && ((*(uint *)(iVar4 + 0xc) >> 0x1a & 7) != 0)) {
    iVar4 = core_globals_get();
    *(byte *)(iVar4 + 0xa2a) = *(byte *)(iVar4 + 0xa2a) | 8;
  }
  return;
}

