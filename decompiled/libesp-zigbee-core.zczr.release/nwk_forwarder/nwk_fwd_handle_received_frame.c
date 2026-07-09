/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
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
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 uVar10;
  int iVar11;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  int iVar15;
  uint uVar16;
  ushort *puVar17;
  uint uVar18;
  int iVar19;
  void *__s;
  byte bStack_57;
  undefined2 uStack_56;
  uint local_54;
  uint uStack_50;
  undefined2 uStack_4c;
  ushort uStack_4a;
  ushort uStack_48;
  ushort uStack_46;
  undefined1 uStack_44;
  undefined1 uStack_43;
  char acStack_42 [10];
  int iStack_38;
  undefined1 uStack_34;
  undefined1 uStack_33;
  undefined1 uStack_32;
  
  puVar17 = (ushort *)param_2[9];
  if (puVar17 == (ushort *)0x0) {
    return;
  }
  bVar1 = *(byte *)(param_2 + 8);
  if (bVar1 < 3) {
    return;
  }
  uVar2 = *puVar17;
  uVar4 = (uint)uVar2;
  if ((uVar4 & 0x3c) != 8) {
    return;
  }
  if ((uVar4 & 3) == 3) {
    memcpy(&uStack_4c,param_2 + 1,10);
    memcpy(acStack_42,(void *)((int)param_2 + 0xe),10);
    iStack_38 = param_2[6];
    uStack_33 = *(undefined1 *)(*param_2 + 0x11);
    uStack_32 = *(undefined1 *)(*param_2 + 0x10);
    uStack_34 = (char)param_1;
    iVar7 = zmsg_alloc(9);
    if (iVar7 == 0) {
      return;
    }
    iVar8 = zmsg_append_bytes((char)param_2[8],param_2[9]);
    if (iVar8 != 0) {
      return;
    }
    *(ushort *)(iVar7 + 0x16) = *(ushort *)(iVar7 + 0x16) | 8;
    nwk_handle_received_intrp_msg(iVar7,&uStack_4c);
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
  uVar6 = nwk_fcf_get_hdr_size(uVar4);
  if ((uVar2 & 0x400) != 0) {
    uVar6 = uVar6 + (*(byte *)((int)puVar17 + uVar6) + 1) * 2 & 0xff;
  }
  if ((uVar2 & 0x200) != 0) {
    uVar6 = uVar6 + 0xe & 0xff;
  }
  if (bVar1 <= uVar6) {
    return;
  }
  uStack_4c = *(undefined2 *)((int)param_2 + 6);
  uStack_48 = puVar17[1];
  uStack_46 = puVar17[2];
  uStack_43 = *(undefined1 *)(*param_2 + 0x11);
  acStack_42[0] = *(char *)(*param_2 + 0x10);
  if (0xfff7 < uStack_46) {
    return;
  }
  if ((char)puVar17[3] == '\0') {
    return;
  }
  uStack_4a = uVar3;
  uStack_44 = (char)param_1;
  iVar7 = nwk_neighbor_table_get_by_short(uVar3);
  if (((int)(uVar4 << 0x12) < 0) && ((iVar7 == 0 || ((*(uint *)(iVar7 + 0xc) & 3) != 2)))) {
    iVar7 = nwk_is_device_zczr();
    if (iVar7 == 0) {
      return;
    }
    nwk_send_direct_leave(uStack_44,uStack_4a);
    return;
  }
  iVar8 = zmsg_alloc(9);
  if (iVar8 == 0) {
    return;
  }
  iVar9 = zmsg_append_bytes((char)param_2[8],param_2[9]);
  iVar5 = iVar8;
  if (iVar9 != 0) goto _L0;
  *(ushort *)(iVar8 + 0x16) = *(ushort *)(iVar8 + 0x16) | 8;
  iVar9 = nwk_process_receive_security(param_1,iVar8);
  if (iVar9 != 0) goto _L0;
  bStack_57 = 0;
  if ((uVar4 & 3) == 1) {
    uVar10 = zmsg_get_offset(iVar8);
    zmsg_read_u8_isra_0(iVar8,uVar10,&bStack_57);
  }
  iVar9 = nwk_secur_get_seclevel();
  uVar3 = uStack_48;
  if ((iVar9 != 0) && ((*(ushort *)(iVar8 + 0x16) & 2) == 0)) {
    if ((bStack_57 & 0xf7) == 6) {
      iVar9 = core_globals_get();
      if (*(ushort *)(iVar9 + 0x9e2) != uVar3) goto _L0;
    }
    else {
      iVar9 = nwk_is_joined();
      if ((iVar9 != 0) && (iVar9 = nwk_is_authed(), iVar9 != 0)) goto _L0;
    }
  }
  uVar3 = uStack_48;
  if (uStack_48 < 0xfff8) {
    iVar9 = core_globals_get();
    if (*(ushort *)(iVar9 + 0x9e2) != uVar3) {
      if (iVar7 == 0) goto _L0;
      uVar4 = *(uint *)(iVar7 + 0xc) & 0x3c0;
      if (((uVar4 == 0x80) || (uVar4 == 0x240)) && (*(char *)(iVar7 + 0x19) != -1)) {
        *(char *)(iVar7 + 0x19) = *(char *)(iVar7 + 0x19) + '\x01';
      }
      uVar6 = 1;
      goto _L0;
    }
    uVar4 = 1;
    uVar6 = 0;
  }
  else {
    core_globals_get();
    iVar9 = nwk_is_device_in_bcast_group(uStack_48);
    if (iVar9 != 0) {
      zmsg_read_u8_isra_0(iVar8,7,&local_54);
      puVar13 = &s_nwk_fwd;
      puVar14 = &s_nwk_fwd;
      iVar15 = 0;
      do {
        if ((*(ushort *)(puVar14 + 0xf) == uStack_46) &&
           ((uint)*(byte *)((int)puVar14 + 0x3e) == (local_54 & 0xff))) {
          iVar9 = 0;
          goto _L0;
        }
        iVar15 = iVar15 + 1;
        puVar14 = puVar14 + 2;
      } while (iVar15 != 0x5a);
      iVar15 = 0;
_L0:
      if (*(char *)((int)puVar13 + 0x3f) != '\0') goto _L0;
      iVar19 = (iVar15 + 6) * 8;
      *(ushort *)(iVar19 + 0x113f4) = uStack_46;
      *(undefined1 *)(iVar19 + 0x113f6) = (undefined1)local_54;
      *(undefined1 *)(iVar19 + 0x113f7) = 9;
      time_ticker_register_receiver(0);
      __s = *(void **)(iVar19 + 0x113f8);
      iVar19 = nwk_neighbor_table_get_capacity();
      memset(__s,0,iVar19 + 7U >> 3);
      iVar19 = 0;
      while (iVar19 = nwk_router_table_next(iVar19), iVar19 != 0) {
        iVar11 = nwk_neighbor_get_incoming_cost();
        if ((iVar11 != 0) && (iVar11 = nwk_neighbor_get_outgoing_cost(iVar19), iVar11 != 0)) {
          uVar4 = nwk_neighbor_table_get_nbr_idx(iVar19);
          __atomic_fetch_or_1((uVar4 >> 3) + *(int *)((iVar15 + 6) * 8 + 0x113f8),
                              1 << (uVar4 & 7) & 0xff,5);
        }
      }
_L0:
      iVar19 = nwk_neighbor_table_get_by_short(uStack_4a);
      if (iVar19 != 0) {
        uVar4 = nwk_neighbor_table_get_nbr_idx();
        __atomic_fetch_and_1
                  ((uVar4 >> 3) + (&DAT_00011428)[iVar15 * 2],~(1 << (uVar4 & 7)) & 0xff,5);
      }
      if (iVar9 == 0) goto _L0;
      uVar4 = (uint)uStack_46;
      uVar6 = nwk_get_short_address();
      uVar4 = (uint)(uVar4 != uVar6);
      uVar6 = uVar4;
      goto _L0;
    }
_L0:
    uVar6 = 0;
_L0:
    uVar4 = 0;
  }
_L0:
  uVar16 = (uint)bStack_57;
  if (uVar16 == 5) {
    uVar6 = 0;
    uVar4 = 1;
  }
  else {
    if (uVar16 < 6) {
      if (uVar16 == 1) {
        uVar6 = 0;
        uVar4 = 1;
        goto _L0;
      }
      iVar9 = uVar16 - 2;
    }
    else {
      iVar9 = uVar16 - 8;
    }
    uVar6 = uVar6 & iVar9 != 0;
  }
_L0:
  uVar16 = nwk_is_router_started();
  if (uVar16 != 0) {
    uVar16 = uVar6 & 1 < (byte)puVar17[3];
  }
  iVar9 = nwk_frame_get_src_extaddr(iVar8,&local_54);
  if (iVar9 == 0) {
    uStack_56 = 0;
    iVar9 = nwk_address_update(&local_54,uStack_46,&uStack_56);
    uVar3 = uStack_46;
    if (iVar9 != 0xd) goto _L0;
_L0:
    nwk_raise_address_conflict(uVar3);
  }
  else {
_L0:
    iVar9 = nwk_is_device_zczr();
    if (((iVar9 != 0) &&
        (uVar18 = (uint)uStack_48, uVar6 = nwk_get_short_address(), uVar18 == uVar6)) &&
       (iVar9 = nwk_frame_get_dst_extaddr(iVar8,&local_54), iVar9 == 0)) {
      puVar12 = (uint *)nwk_get_extended_address();
      uVar3 = uStack_48;
      if ((local_54 != *puVar12) || (uStack_50 != puVar12[1])) goto _L0;
    }
    if (iVar7 != 0) {
      nwk_neighbor_update_lqa(iVar7,uStack_43,(int)acStack_42[0]);
      iVar9 = nwk_is_router_started();
      if (iVar9 != 0) {
        iVar9 = nwk_neighbor_table_get_by_short(uStack_46);
        if ((((iVar9 != 0) && ((*(uint *)(iVar7 + 0xc) & 3) == 2)) && (uStack_4a != uStack_46)) &&
           ((uStack_48 < 0xfff8 || (uVar4 != 0)))) {
          *(uint *)(iVar7 + 0xc) = *(uint *)(iVar7 + 0xc) & 0xfffffc3f | 0x1c0;
        }
        if (((*(uint *)(iVar7 + 0xc) & 0x3c0) == 0x140) && ((*(ushort *)(iVar8 + 0x16) & 2) != 0)) {
          nwk_neighbor_set_auth(iVar7);
        }
        if (((((uVar2 & 0x400) != 0) && (iVar7 = nwk_fwd_is_addr_in_realm(uStack_48), iVar7 != 0))
            && (iVar7 = nwk_route_table_find(uStack_46), iVar7 != 0)) &&
           (((*(ushort *)(iVar7 + 0xe) & 0x10) != 0 && (-1 < *(int *)(iVar7 + 0xc) << 0xc)))) {
          *(ushort *)(iVar7 + 0xe) = *(ushort *)(iVar7 + 0xe) & 0xffdf;
        }
      }
    }
    if (uVar16 == 0) {
      if (uVar4 != 0) goto _L0;
    }
    else {
      if (uVar4 == 0) {
        iVar5 = 0;
        iVar7 = iVar8;
      }
      else {
        iVar7 = zmsg_clone();
        if (iVar7 == 0) goto _L0;
      }
      local_54 = CONCAT31(local_54._1_3_,(char)puVar17[3] + -1);
      zmsg_write_bytes(6,1,&local_54);
      nwk_fwd_send_msg_delayed(iVar7,0);
      iVar8 = iVar5;
      if (uVar4 != 0) {
_L0:
        nwk_handle_received_msg(iVar8,&uStack_4c);
        return;
      }
      if (iVar5 == 0) {
        return;
      }
    }
  }
_L0:
  zmsg_free(iVar5);
  return;
_L0:
  iVar15 = iVar15 + 1;
  puVar13 = puVar13 + 2;
  if (iVar15 == 0x5a) goto _L0;
  goto _L0;
}

