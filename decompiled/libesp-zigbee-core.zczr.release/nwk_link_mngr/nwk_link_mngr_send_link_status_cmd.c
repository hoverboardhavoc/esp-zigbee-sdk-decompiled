/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> nwk_link_mngr.o -> nwk_link_mngr_send_link_status_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_link_mngr_send_link_status_cmd(void)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  undefined1 uVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  uint uVar15;
  ushort *puVar16;
  ushort *puVar17;
  uint uVar18;
  byte bVar19;
  undefined2 uVar20;
  undefined2 *puVar21;
  short *psVar23;
  undefined1 auStack_60 [12];
  undefined1 *local_54;
  undefined2 local_44;
  undefined1 local_42;
  undefined2 *puVar22;
  
  puVar5 = auStack_60;
  iVar10 = nwk_is_router_started();
  puVar6 = auStack_60;
  if (iVar10 != 0) goto _L0;
  while( true ) {
    __assert_func(0,0,0,0);
    puVar6 = puVar5;
_L0:
    iVar10 = zmsg_alloc(0x27);
    if (iVar10 == 0) break;
    iVar11 = core_globals_get();
    bVar19 = *(byte *)(iVar11 + 0xb06);
    iVar11 = core_globals_get();
    uVar2 = *(ushort *)(iVar11 + 0xb04);
    iVar11 = core_globals_get();
    local_54 = puVar6;
    zmsg_set_offset(iVar10,0);
    uVar12 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar10,uVar12,0xfffc,1,1,0);
    iVar13 = core_globals_get();
    cVar1 = *(char *)(iVar13 + 0x9d9);
    *(char *)(iVar13 + 0x9d9) = cVar1 + '\x01';
    local_44._0_1_ = cVar1;
    zmsg_write_bytes(iVar10,7,1,&local_44);
    local_44._0_1_ = 8;
    zmsg_append_bytes(iVar10,1,&local_44);
    local_44 = (ushort)local_44._1_1_ << 8;
    zmsg_append_bytes(iVar10,1,&local_44);
    puVar5 = puVar6 + -0x70;
    psVar23 = (short *)(puVar6 + -0x70);
    iVar13 = 0;
    uVar7 = 0;
_L0:
    iVar13 = nwk_router_table_next(iVar13);
    if (iVar13 == 0) {
      puVar21 = (undefined2 *)(puVar6 + uVar7 * 4 + -0x70);
      uVar18 = uVar7;
      while (puVar22 = puVar21 + -2, 1 < uVar18) {
        uVar20 = *(undefined2 *)(puVar6 + -0x70);
        uVar8 = puVar6[-0x6e];
        *(undefined2 *)(puVar6 + -0x70) = *puVar22;
        uVar18 = uVar18 - 1 & 0xff;
        *(undefined2 *)(puVar6 + -0x6e) = puVar21[-1];
        *puVar22 = uVar20;
        *(undefined1 *)(puVar21 + -1) = uVar8;
        nwk_ls_heap_shift_down_constprop_0(puVar6 + -0x70,uVar18);
        puVar21 = puVar22;
      }
      bVar19 = (uVar2 == 0) << 5;
      if (uVar7 < 0x1b) {
        bVar19 = bVar19 | 0x40;
        uVar20 = 0;
      }
      else {
        uVar7 = uVar7 - 1 & 0xff;
        uVar20 = *(undefined2 *)(puVar6 + uVar7 * 4 + -0x70);
      }
      for (uVar18 = 0; uVar18 != uVar7; uVar18 = uVar18 + 1 & 0xff) {
        local_44 = *psVar23;
        local_42 = (undefined1)psVar23[1];
        zmsg_append_bytes(iVar10,3,&local_44);
        psVar23 = psVar23 + 2;
      }
      sVar9 = zmsg_get_offset(iVar10);
      local_44 = CONCAT11(local_44._1_1_,bVar19 | (byte)uVar18 & 0x1f);
      zmsg_write_bytes(iVar10,sVar9 + 1,1,&local_44);
      *(undefined2 *)(iVar11 + 0xb04) = uVar20;
      nwk_fwd_send_msg_delayed(iVar10,0);
      break;
    }
    if ((*(uint *)(iVar13 + 0xc) & 3) < 2) goto _L0;
  }
  iVar10 = core_globals_get();
  if (*(short *)(iVar10 + 0xb04) == 0) {
    iVar10 = core_globals_get();
    iVar10 = nwk_mm_get_next_router_iface(iVar10 + 0xb06);
    if (iVar10 != 0) {
      iVar10 = core_globals_get();
      iVar11 = core_globals_get();
      uVar8 = *(undefined1 *)(iVar11 + 0xa24);
      goto _L0;
    }
  }
  iVar10 = core_globals_get();
  uVar8 = 0;
_L0:
  nwk_link_mngr_start_timer(iVar10 + 0xae4,uVar8,0x40);
  return;
_L0:
  if (((((*(uint *)(iVar13 + 0xc) >> 0xd & 0x1f) == (uint)bVar19) &&
       (iVar14 = nwk_neighbor_get_incoming_cost(), iVar14 != 0)) &&
      ((uVar18 = *(uint *)(iVar13 + 0xc) & 0x3c0, uVar18 == 0x80 || (uVar18 == 0x240)))) &&
     (uVar18 = nwk_neighbor_get_shortaddr(iVar13), uVar2 <= uVar18)) {
    if (uVar7 < 0x1b) {
      *(short *)(puVar6 + uVar7 * 4 + -0x70) = (short)uVar18;
      uVar8 = nwk_neighbor_get_link_status(iVar13);
      *(undefined1 *)((int)(puVar6 + uVar7 * 4 + -0x70) + 2) = uVar8;
      uVar18 = uVar7;
      while (uVar18 != 0) {
        uVar15 = (int)(uVar18 - 1) >> 1;
        puVar16 = (ushort *)(puVar6 + uVar15 * 4 + -0x70);
        puVar17 = (ushort *)(puVar6 + uVar18 * 4 + -0x70);
        uVar3 = *puVar16;
        if (*puVar17 <= uVar3) break;
        *puVar16 = *puVar17;
        uVar4 = puVar16[1];
        puVar16[1] = puVar17[1];
        *puVar17 = uVar3;
        *(char *)(puVar17 + 1) = (char)uVar4;
        uVar18 = uVar15 & 0xff;
      }
      uVar7 = uVar7 + 1 & 0xff;
    }
    else if (uVar18 < *(ushort *)(puVar6 + -0x70)) {
      *(short *)(puVar6 + -0x70) = (short)uVar18;
      uVar8 = nwk_neighbor_get_link_status(iVar13);
      puVar6[-0x6e] = uVar8;
      nwk_ls_heap_shift_down_constprop_0(puVar6 + -0x70,uVar7);
    }
  }
  goto _L0;
}

