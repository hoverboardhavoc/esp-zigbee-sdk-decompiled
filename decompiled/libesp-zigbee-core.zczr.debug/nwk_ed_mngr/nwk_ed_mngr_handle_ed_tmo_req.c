/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_mngr_handle_ed_tmo_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nwk_ed_mngr_handle_ed_tmo_req(int param_1,int param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 uStack_29;
  byte bStack_28;
  byte bStack_27;
  undefined1 uStack_24;
  byte bStack_23;
  
  iVar2 = nwk_is_router_started();
  if (iVar2 == 0) {
_L0:
    if (param_1 == 0) {
      return;
    }
_L0:
    zmsg_free(param_1);
    return;
  }
  iVar3 = nwk_secur_get_seclevel();
  if (((*(ushort *)(param_1 + 0x16) & 2) != 0) != (iVar3 != 0)) goto _L0;
  if (*(short *)(param_2 + 2) != *(short *)(param_2 + 6)) goto _L0;
  uStack_24 = 0;
  iVar3 = core_globals_get();
  bStack_23 = *(byte *)(iVar3 + 0xa28);
  sVar1 = zmsg_get_offset(param_1);
  zmsg_read_bytes(param_1,sVar1 + 1,2,&bStack_28);
  if (0xe < bStack_28) {
    uStack_24 = 1;
    goto _L0;
  }
  if (bStack_27 != 0) {
    uStack_24 = 2;
    goto _L0;
  }
  iVar3 = nwk_neighbor_table_get_by_short(*(undefined2 *)(param_2 + 6));
  if ((iVar3 == 0) || ((*(uint *)(iVar3 + 0xc) & 0x3c0) != 0x40)) goto _L0;
  iVar6 = nwk_get_keepalive_mode();
  if (iVar6 == 3) {
    if ((*(uint *)(iVar3 + 0xc) & 0x400) == 0) {
      bStack_23 = bStack_23 & 0xfd;
    }
    else {
      bStack_23 = bStack_23 & 0xfe;
    }
  }
  if (*(ushort *)(iVar3 + 0x10) == (ushort)bStack_27) {
    iVar2 = 0;
  }
  else {
    *(ushort *)(iVar3 + 0x10) = (ushort)bStack_27;
  }
  if ((*(uint *)(iVar3 + 0x14) >> 0x14 & 0xf) == (uint)bStack_28) {
    if (iVar2 != 0) goto _L0;
  }
  else {
    *(uint *)(iVar3 + 0x14) = (bStack_28 & 0xf) << 0x14 | *(uint *)(iVar3 + 0x14) & 0xff0fffff;
_L0:
    nwk_neighbor_table_store_child(iVar3);
  }
  nwk_neighbor_zed_keepalive(iVar3);
_L0:
  zmsg_free(param_1);
  uVar4 = zmsg_alloc(0x2f);
  zmsg_set_offset(0);
  uVar5 = nwk_get_short_address();
  nwk_frame_write_hdr(uVar4,uVar5,*(undefined2 *)(param_2 + 6),1,1,0);
  uStack_29 = 0xc;
  zmsg_append_bytes(uVar4,1,&uStack_29);
  zmsg_append_bytes(uVar4,2,&uStack_24);
  nwk_fwd_send_msg_delayed(uVar4,0);
  return;
}

