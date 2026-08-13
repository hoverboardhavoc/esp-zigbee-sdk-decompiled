/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.release -> nwk_forwarder.o -> nwk_fwd_handle_received_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_fwd_handle_received_frame(undefined4 param_1,int *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  undefined1 uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  undefined2 *puVar12;
  int iVar13;
  uint *puVar14;
  undefined4 *puVar15;
  uint uVar16;
  ushort *puVar17;
  int iVar18;
  uint uVar19;
  int iVar20;
  void *__s;
  byte bStack_67;
  undefined2 uStack_66;
  uint local_64;
  uint uStack_60;
  undefined2 uStack_5c;
  ushort uStack_5a;
  ushort uStack_58;
  ushort uStack_56;
  undefined1 uStack_54;
  undefined1 uStack_53;
  char acStack_52 [10];
  int iStack_48;
  undefined1 uStack_44;
  undefined1 uStack_43;
  undefined1 uStack_42;
  
  puVar17 = (ushort *)param_2[9];
  if (puVar17 == (ushort *)0x0) {
    return;
  }
  bVar1 = *(byte *)(param_2 + 8);
  if (bVar1 < 3) {
    return;
  }
  uVar2 = *puVar17;
  uVar5 = (uint)uVar2;
  if ((uVar5 & 0x3c) != 8) {
    return;
  }
  if ((uVar5 & 3) == 3) {
    memcpy(&uStack_5c,param_2 + 1,10);
    memcpy(acStack_52,(void *)((int)param_2 + 0xe),10);
    iStack_48 = param_2[6];
    uStack_43 = *(undefined1 *)(*param_2 + 0x11);
    uStack_42 = *(undefined1 *)(*param_2 + 0x10);
    uStack_44 = (char)param_1;
    iVar8 = zmsg_alloc(9);
    if (iVar8 == 0) {
      return;
    }
    iVar9 = zmsg_append_bytes((char)param_2[8],param_2[9]);
    if (iVar9 != 0) {
      return;
    }
    *(ushort *)(iVar8 + 0x16) = *(ushort *)(iVar8 + 0x16) | 8;
    nwk_handle_received_intrp_msg(iVar8,&uStack_5c);
    return;
  }
  if ((char)param_2[1] != '\x02') {
    return;
  }
  if (*(char *)((int)param_2 + 0xe) != '\x02') {
    return;
  }
  uVar3 = *(ushort *)(param_2 + 4);
  if (0xfff7 < uVar3) {
    return;
  }
  uVar7 = nwk_fcf_get_hdr_size(uVar5);
  if ((uVar2 & 0x400) != 0) {
    uVar7 = uVar7 + (*(byte *)((int)puVar17 + uVar7) + 1) * 2 & 0xff;
  }
  if ((uVar2 & 0x200) != 0) {
    uVar7 = uVar7 + 0xe & 0xff;
  }
  if (bVar1 <= uVar7) {
    return;
  }
  uStack_5c = *(undefined2 *)((int)param_2 + 6);
  uStack_58 = puVar17[1];
  uStack_56 = puVar17[2];
  uStack_53 = *(undefined1 *)(*param_2 + 0x11);
  acStack_52[0] = *(char *)(*param_2 + 0x10);
  if (0xfff7 < uStack_56) {
    return;
  }
  if ((char)puVar17[3] == '\0') {
    return;
  }
  uStack_5a = uVar3;
  uStack_54 = (char)param_1;
  iVar8 = nwk_neighbor_table_get_by_short(uVar3);
  if (((int)(uVar5 << 0x12) < 0) && ((iVar8 == 0 || ((*(uint *)(iVar8 + 0xc) & 3) != 2)))) {
    iVar8 = nwk_is_device_zczr();
    if (iVar8 == 0) {
      return;
    }
    nwk_send_direct_leave(uStack_54,uStack_5a);
    return;
  }
  iVar9 = zmsg_alloc(9);
  if (iVar9 == 0) {
    return;
  }
  iVar10 = zmsg_append_bytes((char)param_2[8],param_2[9]);
  iVar6 = iVar9;
  if (iVar10 != 0) goto _L0;
  *(ushort *)(iVar9 + 0x16) = *(ushort *)(iVar9 + 0x16) | 8;
  iVar10 = nwk_process_receive_security(param_1,iVar9);
  if (iVar10 != 0) goto _L0;
  bStack_67 = 0;
  if ((uVar5 & 3) == 1) {
    uVar11 = zmsg_get_offset(iVar9);
    zmsg_read_u8_isra_0(iVar9,uVar11,&bStack_67);
  }
  iVar10 = nwk_secur_get_seclevel();
  uVar3 = uStack_58;
  if ((iVar10 != 0) && ((*(ushort *)(iVar9 + 0x16) & 2) == 0)) {
    if ((bStack_67 & 0xf7) == 6) {
      iVar10 = core_globals_get();
      if (*(ushort *)(iVar10 + 0x9e2) != uVar3) goto _L0;
    }
    else {
      iVar10 = nwk_is_joined();
      if ((iVar10 != 0) && (iVar10 = nwk_is_authed(), iVar10 != 0)) goto _L0;
    }
  }
  uVar3 = uStack_58;
  if (uStack_58 < 0xfff8) {
    iVar10 = core_globals_get();
    if (*(ushort *)(iVar10 + 0x9e2) != uVar3) {
      if (iVar8 == 0) goto _L0;
      uVar5 = *(uint *)(iVar8 + 0xc) & 0x3c0;
      if (((uVar5 == 0x80) || (uVar5 == 0x240)) && (*(char *)(iVar8 + 0x19) != -1)) {
        *(char *)(iVar8 + 0x19) = *(char *)(iVar8 + 0x19) + '\x01';
      }
      uVar7 = 1;
      goto _L0;
    }
    uVar5 = 1;
    uVar7 = 0;
  }
  else {
    core_globals_get();
    iVar10 = nwk_is_device_in_bcast_group(uStack_58);
    if (iVar10 != 0) {
      zmsg_read_u8_isra_0(iVar9,7,&local_64);
      uVar3 = uStack_56;
      uVar4 = (undefined1)local_64;
      puVar12 = (undefined2 *)nwk_btt_find(uStack_56,local_64 & 0xff);
      if (puVar12 == (undefined2 *)0x0) {
        puVar15 = &s_nwk_fwd;
        iVar18 = 0;
_L0:
        if (*(char *)((int)puVar15 + 0x3f) != '\0') goto _L0;
        iVar20 = (iVar18 + 6) * 8;
        *(undefined1 *)(iVar20 + 0x11403) = 9;
        *(ushort *)(iVar20 + 0x11400) = uVar3;
        *(undefined1 *)(iVar20 + 0x11402) = uVar4;
        time_ticker_register_receiver(0);
        __s = *(void **)(iVar20 + 0x11404);
        iVar20 = nwk_neighbor_table_get_capacity();
        memset(__s,0,iVar20 + 7U >> 3);
        iVar20 = 0;
        while (iVar20 = nwk_router_table_next(iVar20), iVar20 != 0) {
          iVar13 = nwk_neighbor_get_incoming_cost();
          if ((iVar13 != 0) && (iVar13 = nwk_neighbor_get_outgoing_cost(iVar20), iVar13 != 0)) {
            uVar5 = nwk_neighbor_table_get_nbr_idx(iVar20);
            __atomic_fetch_or_1((uVar5 >> 3) + *(int *)((iVar18 + 6) * 8 + 0x11404),
                                1 << (uVar5 & 7) & 0xff,5);
          }
        }
        puVar12 = &DAT_00011430 + iVar18 * 4;
        goto _L0;
      }
      iVar10 = 0;
_L0:
      iVar18 = nwk_neighbor_table_get_by_short(uStack_5a);
      if (iVar18 != 0) {
        uVar5 = nwk_neighbor_table_get_nbr_idx();
        __atomic_fetch_and_1(*(int *)(puVar12 + 2) + (uVar5 >> 3),~(1 << (uVar5 & 7)) & 0xff,5);
      }
      if (iVar10 != 0) {
        uVar5 = (uint)uStack_56;
        uVar7 = nwk_get_short_address();
        uVar5 = (uint)(uVar5 != uVar7);
        uVar7 = uVar5;
        goto _L0;
      }
    }
_L0:
    uVar7 = 0;
_L0:
    uVar5 = 0;
  }
_L0:
  uVar16 = (uint)bStack_67;
  if (uVar16 == 5) {
    uVar7 = 0;
    uVar5 = 1;
  }
  else {
    if (uVar16 < 6) {
      if (uVar16 == 1) {
        uVar7 = 0;
        uVar5 = 1;
        goto _L0;
      }
      iVar10 = uVar16 - 2;
    }
    else {
      iVar10 = uVar16 - 8;
    }
    uVar7 = uVar7 & iVar10 != 0;
  }
_L0:
  uVar16 = nwk_is_router_started();
  if (uVar16 != 0) {
    uVar16 = uVar7 & 1 < (byte)puVar17[3];
  }
  iVar10 = nwk_frame_get_src_extaddr(iVar9,&local_64);
  if (iVar10 == 0) {
    uStack_66 = 0;
    iVar10 = nwk_address_update(&local_64,uStack_56,&uStack_66);
    uVar3 = uStack_56;
    if (iVar10 != 0xd) goto _L0;
_L0:
    nwk_raise_address_conflict(uVar3);
  }
  else {
_L0:
    iVar10 = nwk_is_device_zczr();
    if (((iVar10 != 0) &&
        (uVar19 = (uint)uStack_58, uVar7 = nwk_get_short_address(), uVar19 == uVar7)) &&
       (iVar10 = nwk_frame_get_dst_extaddr(iVar9,&local_64), iVar10 == 0)) {
      puVar14 = (uint *)nwk_get_extended_address();
      uVar3 = uStack_58;
      if ((local_64 != *puVar14) || (uStack_60 != puVar14[1])) goto _L0;
    }
    if (iVar8 != 0) {
      nwk_neighbor_update_lqa(iVar8,uStack_53,(int)acStack_52[0]);
      iVar10 = nwk_is_router_started();
      if (iVar10 != 0) {
        iVar10 = nwk_neighbor_table_get_by_short(uStack_56);
        if ((((iVar10 != 0) && ((*(uint *)(iVar8 + 0xc) & 3) == 2)) && (uStack_5a != uStack_56)) &&
           ((uStack_58 < 0xfff8 || (uVar5 != 0)))) {
          *(uint *)(iVar8 + 0xc) = *(uint *)(iVar8 + 0xc) & 0xfffffc3f | 0x1c0;
        }
        if (((*(uint *)(iVar8 + 0xc) & 0x3c0) == 0x140) && ((*(ushort *)(iVar9 + 0x16) & 2) != 0)) {
          nwk_neighbor_set_auth(iVar8);
        }
        if (((((uVar2 & 0x400) != 0) && (iVar8 = nwk_fwd_is_addr_in_realm(uStack_58), iVar8 != 0))
            && (iVar8 = nwk_route_table_find(uStack_56), iVar8 != 0)) &&
           (((*(ushort *)(iVar8 + 0xe) & 0x10) != 0 && (-1 < *(int *)(iVar8 + 0xc) << 0xc)))) {
          *(ushort *)(iVar8 + 0xe) = *(ushort *)(iVar8 + 0xe) & 0xffdf;
        }
      }
    }
    if (uVar16 == 0) {
      if (uVar5 != 0) goto _L0;
    }
    else {
      if (uVar5 == 0) {
        iVar6 = 0;
        iVar8 = iVar9;
      }
      else {
        iVar8 = zmsg_clone();
        if (iVar8 == 0) goto _L0;
      }
      local_64 = CONCAT31(local_64._1_3_,(char)puVar17[3] + -1);
      zmsg_write_bytes(6,1,&local_64);
      nwk_fwd_send_msg_delayed(iVar8,0);
      iVar9 = iVar6;
      if (uVar5 != 0) {
_L0:
        nwk_handle_received_msg(iVar9,&uStack_5c);
        return;
      }
      if (iVar6 == 0) {
        return;
      }
    }
  }
_L0:
  zmsg_free(iVar6);
  return;
_L0:
  iVar18 = iVar18 + 1;
  puVar15 = puVar15 + 2;
  if (iVar18 == 0x5a) goto _L0;
  goto _L0;
}

