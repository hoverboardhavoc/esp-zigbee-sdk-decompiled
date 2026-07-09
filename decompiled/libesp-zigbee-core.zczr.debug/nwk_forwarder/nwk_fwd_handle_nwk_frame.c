/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_forwarder.o -> nwk_fwd_handle_nwk_frame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nwk_fwd_handle_nwk_frame(undefined4 param_1,int *param_2)

{
  byte bVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int *piVar12;
  ushort *puVar13;
  uint uVar14;
  int iStack_4c;
  int iStack_48;
  byte bStack_41;
  undefined2 uStack_40;
  ushort uStack_3e;
  ushort uStack_3c;
  ushort uStack_3a;
  undefined1 uStack_38;
  undefined1 uStack_37;
  char cStack_36;
  undefined2 auStack_32 [7];
  
  puVar13 = (ushort *)param_2[9];
  uVar3 = *puVar13;
  if ((char)param_2[1] != '\x02') {
    return 0x10;
  }
  if (*(char *)((int)param_2 + 0xe) != '\x02') {
    return 0x10;
  }
  uVar2 = *(ushort *)(param_2 + 4);
  if (0xfff7 < uVar2) {
    return 0x10;
  }
  bVar1 = *(byte *)(param_2 + 8);
  uVar4 = nwk_frame_find_payload_index(uVar3,puVar13);
  if (bVar1 <= uVar4) {
    return 0x10;
  }
  uStack_40 = *(undefined2 *)((int)param_2 + 6);
  uStack_3c = puVar13[1];
  uStack_3a = puVar13[2];
  uStack_38 = (undefined1)param_1;
  uStack_37 = *(undefined1 *)(*param_2 + 0x11);
  cStack_36 = *(char *)(*param_2 + 0x10);
  if (0xfff7 < uStack_3a) {
    return 0x12;
  }
  if ((char)puVar13[3] == '\0') {
    return 0x12;
  }
  uStack_3e = uVar2;
  iVar5 = nwk_neighbor_table_get_by_short(uVar2);
  if (((uVar3 & 0x2000) != 0) && ((iVar5 == 0 || ((*(uint *)(iVar5 + 0xc) & 3) != 2)))) {
    iVar5 = nwk_is_device_zczr();
    if (iVar5 != 0) {
      nwk_send_direct_leave(uStack_38,uStack_3e);
    }
    return 0x12;
  }
  iVar6 = zmsg_alloc(9);
  if (iVar6 == 0) {
    return 1;
  }
  iVar7 = zmsg_append_bytes((char)param_2[8],param_2[9]);
  if (iVar7 != 0) goto _L0;
  *(ushort *)(iVar6 + 0x16) = *(ushort *)(iVar6 + 0x16) | 8;
  iVar7 = nwk_process_receive_security(param_1,iVar6);
  if (iVar7 != 0) goto _L0;
  bStack_41 = 0;
  if ((uVar3 & 3) == 1) {
    uVar11 = zmsg_get_offset(iVar6);
    zmsg_read_bytes(iVar6,uVar11,1,&bStack_41);
  }
  iVar8 = nwk_secur_get_seclevel();
  uVar2 = uStack_3c;
  if ((iVar8 == 0) || ((*(ushort *)(iVar6 + 0x16) & 2) != 0)) {
_L0:
    uVar2 = uStack_3c;
    if (uStack_3c < 0xfff8) {
      iVar8 = core_globals_get();
      if (uVar2 == *(ushort *)(iVar8 + 0x9e2)) {
        iVar8 = 0;
        iVar9 = 1;
      }
      else {
        if (iVar5 == 0) {
          iVar7 = 0x12;
          goto _L0;
        }
        uVar4 = *(uint *)(iVar5 + 0xc) & 0x3c0;
        if ((uVar4 == 0x80) || (uVar4 == 0x240)) {
          if (*(char *)(iVar5 + 0x19) == -1) {
            iVar8 = 1;
            iVar9 = 0;
          }
          else {
            *(char *)(iVar5 + 0x19) = *(char *)(iVar5 + 0x19) + '\x01';
            iVar8 = 1;
            iVar9 = 0;
          }
        }
        else {
          iVar8 = 1;
          iVar9 = 0;
        }
      }
    }
    else {
      iVar9 = nwk_fwd_handle_bcast(&uStack_40,iVar6);
      iVar8 = iVar9;
    }
    if (bStack_41 == 5) {
      iVar8 = 0;
      iVar9 = 1;
    }
    else if (bStack_41 < 6) {
      if (bStack_41 == 1) {
        iVar8 = 0;
        iVar9 = 1;
      }
      else if (bStack_41 == 2) {
        iVar8 = 0;
      }
    }
    else if (bStack_41 == 8) {
      iVar8 = 0;
    }
    iVar10 = nwk_is_router_started();
    if (iVar10 == 0) {
      iVar8 = 0;
    }
    else if ((byte)puVar13[3] < 2) {
      iVar8 = 0;
    }
    iVar10 = nwk_frame_get_src_extaddr(iVar6,&iStack_4c);
    if (iVar10 == 0) {
      auStack_32[0] = 0;
      iVar10 = nwk_address_update(&iStack_4c,uStack_3a,auStack_32);
      if (iVar10 != 0xd) goto _L0;
      nwk_raise_address_conflict(uStack_3a);
_L0:
      iVar7 = 0x12;
    }
    else {
_L0:
      iVar10 = nwk_is_device_zczr();
      if (((iVar10 != 0) &&
          (uVar14 = (uint)uStack_3c, uVar4 = nwk_get_short_address(), uVar14 == uVar4)) &&
         (iVar10 = nwk_frame_get_dst_extaddr(iVar6,&iStack_4c), iVar10 == 0)) {
        piVar12 = (int *)nwk_get_extended_address();
        if ((iStack_4c != *piVar12) || (iStack_48 != piVar12[1])) {
          nwk_raise_address_conflict(uStack_3c);
          goto _L0;
        }
      }
      if (iVar5 != 0) {
        nwk_neighbor_update_lqa(iVar5,uStack_37,(int)cStack_36);
        iVar10 = nwk_is_router_started();
        if (iVar10 != 0) {
          iVar10 = nwk_neighbor_table_get_by_short(uStack_3a);
          if (((iVar10 != 0) && ((*(uint *)(iVar5 + 0xc) & 3) == 2)) &&
             ((uStack_3e != uStack_3a && ((uStack_3c < 0xfff8 || (iVar9 != 0)))))) {
            *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfffffc3f | 0x1c0;
          }
          if (((*(uint *)(iVar5 + 0xc) & 0x3c0) == 0x140) && ((*(ushort *)(iVar6 + 0x16) & 2) != 0))
          {
            nwk_neighbor_set_auth(iVar5);
          }
          if (((((uVar3 & 0x400) != 0) && (iVar5 = nwk_fwd_is_addr_in_realm(uStack_3c), iVar5 != 0))
              && (iVar5 = nwk_route_table_find(uStack_3a), iVar5 != 0)) &&
             (((*(ushort *)(iVar5 + 0xe) & 0x10) != 0 && ((*(uint *)(iVar5 + 0xc) >> 0x13 & 1) == 0)
              ))) {
            *(ushort *)(iVar5 + 0xe) = *(ushort *)(iVar5 + 0xe) & 0xffdf;
          }
        }
      }
      if (iVar8 != 0) {
        if (iVar9 == 0) {
          iVar5 = iVar6;
          iVar6 = 0;
        }
        else {
          iVar5 = zmsg_clone(iVar6);
        }
        if (iVar5 != 0) {
          iStack_4c = CONCAT31(iStack_4c._1_3_,(char)puVar13[3] + -1);
          zmsg_write_bytes(iVar5,6,1,&iStack_4c);
          nwk_fwd_send_msg_delayed(iVar5,0);
        }
      }
      if (iVar9 != 0) {
        iVar5 = nwk_handle_received_msg(iVar6,&uStack_40);
        return iVar5;
      }
    }
  }
  else if ((bStack_41 == 6) || (bStack_41 == 0xe)) {
    iVar8 = core_globals_get();
    if (uVar2 == *(ushort *)(iVar8 + 0x9e2)) goto _L0;
    iVar7 = 0x12;
  }
  else {
    iVar8 = nwk_is_joined_and_authed();
    if (iVar8 == 0) goto _L0;
    iVar7 = 0x12;
  }
_L0:
  if (iVar6 == 0) {
    return iVar7;
  }
_L0:
  zmsg_free(iVar6);
  return iVar7;
}

