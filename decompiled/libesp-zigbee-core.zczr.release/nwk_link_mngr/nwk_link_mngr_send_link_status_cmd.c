/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_link_mngr.o -> nwk_link_mngr_send_link_status_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void nwk_link_mngr_send_link_status_cmd(void)

{
  char cVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  _Bool _Var8;
  undefined1 uVar9;
  short sVar10;
  undefined3 extraout_var;
  int iVar11;
  int iVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  uint8_t delay_s;
  undefined2 *puVar16;
  uint uVar17;
  ushort *puVar18;
  ushort *puVar19;
  uint uVar20;
  byte bVar21;
  undefined2 uVar22;
  undefined2 *puVar23;
  short *psVar25;
  undefined1 auStack_60 [12];
  undefined1 *local_54;
  undefined2 local_44;
  undefined1 local_42;
  nwk_link_status status;
  undefined2 *puVar24;
  
  puVar5 = auStack_60;
  _Var8 = nwk_is_router_started();
  puVar6 = auStack_60;
  if (CONCAT31(extraout_var,_Var8) != 0) goto _L0;
  while( true ) {
    __assert_func(0,0,0,0);
    puVar6 = puVar5;
_L0:
    iVar11 = zmsg_alloc(0x27);
    if (iVar11 == 0) break;
    iVar12 = core_globals_get();
    bVar21 = *(byte *)(iVar12 + 0xb06);
    iVar12 = core_globals_get();
    uVar2 = *(ushort *)(iVar12 + 0xb04);
    iVar12 = core_globals_get();
    local_54 = puVar6;
    zmsg_set_offset(iVar11,0);
    uVar13 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar11,uVar13,0xfffc,1,1,0);
    iVar14 = core_globals_get();
    cVar1 = *(char *)(iVar14 + 0x9d9);
    *(char *)(iVar14 + 0x9d9) = cVar1 + '\x01';
    local_44._0_1_ = cVar1;
    zmsg_write_bytes(iVar11,7,1,&local_44);
    local_44._0_1_ = 8;
    zmsg_append_bytes(iVar11,1,&local_44);
    puVar16 = &local_44;
    local_44 = (ushort)local_44._1_1_ << 8;
    zmsg_append_bytes(iVar11,1);
    puVar5 = puVar6 + -0x70;
    psVar25 = (short *)(puVar6 + -0x70);
    iVar14 = 0;
    uVar7 = 0;
_L0:
    iVar14 = nwk_router_table_next(iVar14);
    if (iVar14 == 0) {
      puVar23 = (undefined2 *)(puVar6 + uVar7 * 4 + -0x70);
      for (uVar20 = uVar7; puVar24 = puVar23 + -2, 1 < uVar20; uVar20 = uVar20 - 1 & 0xff) {
        uVar22 = *(undefined2 *)(puVar6 + -0x70);
        uVar9 = puVar6[-0x6e];
        *(undefined2 *)(puVar6 + -0x70) = *puVar24;
        *(undefined2 *)(puVar6 + -0x6e) = puVar23[-1];
        *puVar24 = uVar22;
        *(undefined1 *)(puVar23 + -1) = uVar9;
        nwk_ls_heap_shift_down
                  ((nwk_link_status_heap_ent *)(puVar6 + -0x70),(uint8_t)(uVar20 - 1),
                   (uint8_t)puVar16);
        puVar23 = puVar24;
      }
      bVar21 = (uVar2 == 0) << 5;
      if (uVar7 < 0x1b) {
        bVar21 = bVar21 | 0x40;
        uVar22 = 0;
      }
      else {
        uVar7 = uVar7 - 1 & 0xff;
        uVar22 = *(undefined2 *)(puVar6 + uVar7 * 4 + -0x70);
      }
      for (uVar20 = 0; uVar20 != uVar7; uVar20 = uVar20 + 1 & 0xff) {
        local_44 = *psVar25;
        local_42 = (undefined1)psVar25[1];
        zmsg_append_bytes(iVar11,3,&local_44);
        psVar25 = psVar25 + 2;
      }
      sVar10 = zmsg_get_offset(iVar11);
      local_44 = CONCAT11(local_44._1_1_,bVar21 | (byte)uVar20 & 0x1f);
      zmsg_write_bytes(iVar11,sVar10 + 1,1,&local_44);
      *(undefined2 *)(iVar12 + 0xb04) = uVar22;
      nwk_fwd_send_msg_delayed(iVar11,0);
      break;
    }
    if ((*(uint *)(iVar14 + 0xc) & 3) < 2) goto _L0;
  }
  iVar11 = core_globals_get();
  if (*(short *)(iVar11 + 0xb04) == 0) {
    iVar11 = core_globals_get();
    iVar11 = nwk_mm_get_next_router_iface(iVar11 + 0xb06);
    if (iVar11 != 0) {
      iVar11 = core_globals_get();
      iVar12 = core_globals_get();
      delay_s = *(uint8_t *)(iVar12 + 0xa24);
      goto _L0;
    }
  }
  iVar11 = core_globals_get();
  delay_s = '\0';
_L0:
  nwk_link_mngr_start_timer((milli_timer_t *)(iVar11 + 0xae4),delay_s,0x40);
  return;
_L0:
  if (((((*(uint *)(iVar14 + 0xc) >> 0xd & 0x1f) == (uint)bVar21) &&
       (iVar15 = nwk_neighbor_get_incoming_cost(), iVar15 != 0)) &&
      ((uVar20 = *(uint *)(iVar14 + 0xc) & 0x3c0, uVar20 == 0x80 || (uVar20 == 0x240)))) &&
     (uVar20 = nwk_neighbor_get_shortaddr(iVar14), uVar2 <= uVar20)) {
    if (uVar7 < 0x1b) {
      *(short *)(puVar6 + uVar7 * 4 + -0x70) = (short)uVar20;
      uVar9 = nwk_neighbor_get_link_status(iVar14);
      *(undefined1 *)((int)(puVar6 + uVar7 * 4 + -0x70) + 2) = uVar9;
      uVar20 = uVar7;
      while (uVar20 != 0) {
        uVar17 = (int)(uVar20 - 1) >> 1;
        puVar18 = (ushort *)(puVar6 + uVar17 * 4 + -0x70);
        puVar19 = (ushort *)(puVar6 + uVar20 * 4 + -0x70);
        uVar3 = *puVar18;
        puVar16 = (undefined2 *)(uint)*puVar19;
        if (puVar16 <= (undefined2 *)(uint)uVar3) break;
        *puVar18 = *puVar19;
        puVar16 = (undefined2 *)(uint)puVar19[1];
        uVar4 = puVar18[1];
        puVar18[1] = puVar19[1];
        *puVar19 = uVar3;
        *(char *)(puVar19 + 1) = (char)uVar4;
        uVar20 = uVar17 & 0xff;
      }
      uVar7 = uVar7 + 1 & 0xff;
    }
    else if (uVar20 < *(ushort *)(puVar6 + -0x70)) {
      *(short *)(puVar6 + -0x70) = (short)uVar20;
      uVar9 = nwk_neighbor_get_link_status(iVar14);
      puVar6[-0x6e] = uVar9;
      nwk_ls_heap_shift_down
                ((nwk_link_status_heap_ent *)(puVar6 + -0x70),(uint8_t)uVar7,(uint8_t)puVar16);
    }
  }
  goto _L0;
}

