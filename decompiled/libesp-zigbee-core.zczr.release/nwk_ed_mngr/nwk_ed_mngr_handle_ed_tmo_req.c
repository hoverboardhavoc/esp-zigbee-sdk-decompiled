/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> nwk_ed_mngr.o -> nwk_ed_mngr_handle_ed_tmo_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ed_mngr_handle_ed_tmo_req(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  _Bool _Var1;
  short sVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined1 uStack_29;
  undefined1 uStack_28;
  byte bStack_27;
  nwk_ed_tmo_rsp_cmd_t rsp;
  nwk_ed_tmo_req_cmd_t req;
  
  _Var1 = nwk_is_router_started();
  iVar7 = CONCAT31(extraout_var,_Var1);
  if (iVar7 == 0) {
    if (msg == (zmsg_t *)0x0) {
      return;
    }
_L0:
    zmsg_free(msg);
    return;
  }
  iVar3 = nwk_secur_get_seclevel();
  if (((ushort)(iVar3 != 0) != (msg->flags >> 1 & 1)) ||
     (rx_info->mac_src_addr != rx_info->nwk_src_addr)) goto _L0;
  uStack_28 = 0;
  iVar3 = core_globals_get();
  bStack_27 = *(byte *)(iVar3 + 0xa28);
  sVar2 = zmsg_get_offset(msg);
  zmsg_read_bytes(msg,sVar2 + 1,2,&rsp);
  if (0xe < rsp.status) {
    uStack_28 = 1;
    goto _L0;
  }
  if (rsp.parent_information != '\0') {
    uStack_28 = 2;
    goto _L0;
  }
  iVar3 = nwk_neighbor_table_get_by_short(rx_info->nwk_src_addr);
  if ((iVar3 == 0) || ((*(uint *)(iVar3 + 0xc) & 0x3c0) != 0x40)) goto _L0;
  iVar6 = nwk_get_keepalive_mode();
  if (iVar6 == 3) {
    if ((*(uint *)(iVar3 + 0xc) & 0x400) == 0) {
      bStack_27 = bStack_27 & 0xfd;
    }
    else {
      bStack_27 = bStack_27 & 0xfe;
    }
  }
  if (*(ushort *)(iVar3 + 0x14) == (ushort)rsp.parent_information) {
    iVar7 = 0;
  }
  else {
    *(ushort *)(iVar3 + 0x14) = (ushort)rsp.parent_information;
  }
  if ((*(uint *)(iVar3 + 0x18) >> 0x14 & 0xf) == (uint)rsp.status) {
    if (iVar7 != 0) goto _L0;
  }
  else {
    *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0xff0fffff | (rsp.status & 0xf) << 0x14;
_L0:
    nwk_neighbor_table_store_child(iVar3);
  }
  nwk_neighbor_zed_keepalive(iVar3);
_L0:
  zmsg_free(msg);
  uVar4 = zmsg_alloc(0x2f);
  zmsg_set_offset(0);
  uVar5 = nwk_get_short_address();
  nwk_frame_write_hdr(uVar4,uVar5,rx_info->nwk_src_addr,1,1,0);
  uStack_29 = 0xc;
  zmsg_append_bytes(uVar4,1,&uStack_29);
  zmsg_append_bytes(uVar4,2,&uStack_28);
  nwk_fwd_send_msg_delayed(uVar4,0);
  return;
}

