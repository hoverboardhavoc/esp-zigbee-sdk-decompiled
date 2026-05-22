/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_ed_mngr.o -> nwk_ed_mngr_handle_ed_tmo_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_ed_mngr_handle_ed_tmo_req(zmsg_t *msg,nwk_rx_info_t *rx_info)

{
  int iVar1;
  _Bool _Var2;
  short sVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  undefined1 uStack_29;
  byte bStack_28;
  byte bStack_27;
  nwk_ed_tmo_req_cmd_t req;
  nwk_ed_tmo_rsp_cmd_t rsp;
  
  _Var2 = nwk_is_router_started();
  iVar1 = CONCAT31(extraout_var,_Var2);
  if (iVar1 == 0) {
_L0:
    if (msg == (zmsg_t *)0x0) {
      return;
    }
_L0:
    zmsg_free(msg);
    return;
  }
  iVar4 = nwk_secur_get_seclevel();
  if (((msg->flags & 2) != 0) != (iVar4 != 0)) goto _L0;
  if (rx_info->mac_src_addr != rx_info->nwk_src_addr) goto _L0;
  req.request_timeout = '\0';
  iVar4 = core_globals_get();
  req.ed_configuration = *(uint8_t *)(iVar4 + 0xa28);
  sVar3 = zmsg_get_offset(msg);
  zmsg_read_bytes(msg,sVar3 + 1,2,&bStack_28);
  if (0xe < bStack_28) {
    req.request_timeout = '\x01';
    goto _L0;
  }
  if (bStack_27 != 0) {
    req.request_timeout = '\x02';
    goto _L0;
  }
  iVar4 = nwk_neighbor_table_get_by_short(rx_info->nwk_src_addr);
  if ((iVar4 == 0) || ((*(uint *)(iVar4 + 0xc) & 0x3c0) != 0x40)) goto _L0;
  iVar7 = nwk_get_keepalive_mode();
  if (iVar7 == 3) {
    if ((*(uint *)(iVar4 + 0xc) & 0x400) == 0) {
      req.ed_configuration = req.ed_configuration & 0xfd;
    }
    else {
      req.ed_configuration = req.ed_configuration & 0xfe;
    }
  }
  if (*(ushort *)(iVar4 + 0x14) == (ushort)bStack_27) {
    iVar1 = 0;
  }
  else {
    *(ushort *)(iVar4 + 0x14) = (ushort)bStack_27;
  }
  if ((*(uint *)(iVar4 + 0x18) >> 0x14 & 0xf) == (uint)bStack_28) {
    if (iVar1 != 0) goto _L0;
  }
  else {
    *(uint *)(iVar4 + 0x18) = (bStack_28 & 0xf) << 0x14 | *(uint *)(iVar4 + 0x18) & 0xff0fffff;
_L0:
    nwk_neighbor_table_store_child(iVar4);
  }
  nwk_neighbor_zed_keepalive(iVar4);
_L0:
  zmsg_free(msg);
  uVar5 = zmsg_alloc(0x2f);
  zmsg_set_offset(0);
  uVar6 = nwk_get_short_address();
  nwk_frame_write_hdr(uVar5,uVar6,rx_info->nwk_src_addr,1,1,0);
  uStack_29 = 0xc;
  zmsg_append_bytes(uVar5,1,&uStack_29);
  zmsg_append_bytes(uVar5,2,&req);
  nwk_fwd_send_msg_delayed(uVar5,0);
  return;
}

