/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> aps_main.o -> aps_send_msg_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: req */
/* WARNING: Unknown calling convention */

void aps_send_msg_task(aps_context *ctx)

{
  bool bVar1;
  ezb_shortaddr_t eVar2;
  uint16_t uVar3;
  zmsg_t *msg;
  int iVar4;
  undefined2 extraout_var;
  uint uVar5;
  ezb_err_t error;
  int iVar6;
  zmsg_t *msg_00;
  uint uVar7;
  ushort uStack_5e;
  uint16_t uStack_5c;
  ezb_shortaddr_t dst_addr;
  aps_addr_t addr;
  aps_header_t aps_hdr;
  aps_apsde_data_req_t req;
  
  msg = (zmsg_t *)zmsg_queue_get_head(&ctx->tx_q);
  if (msg == (zmsg_t *)0x0) {
    return;
  }
  iVar4 = core_globals_get();
  zmsg_queue_dequeue(iVar4 + 0x2c,msg);
  zmsg_get_footer(msg,&uStack_5e);
  zmsg_remove_footer(msg,2);
  zmsg_get_footer(msg,&aps_hdr.rssi,0x1c);
  uVar3 = aps_get_max_asdu(false,(_Bool)((byte)req._20_4_ & 1),
                           (_Bool)((byte)((uint)req._20_4_ >> 3) & 1));
  uVar7 = CONCAT22(extraout_var,uVar3);
  uVar5 = zmsg_get_length(msg);
  bVar1 = uVar7 < uVar5;
  if (bVar1) {
    uVar7 = uVar7 - 2 & 0xffff;
  }
  uStack_5c = req.profile_id;
  if ((req._20_4_ & 0x10) == 0) {
    iVar4 = nwk_get_short_address();
    uStack_5c = 0xfffe;
    if (iVar4 != 0xffff) {
      uStack_5c = nwk_get_short_address();
    }
  }
  dst_addr = uStack_5e;
  addr.src_addr = 0;
  if ((char)req.asdu == '\x01') {
    addr.src_addr = req.asdu._2_2_;
  }
  zmsg_set_offset(msg,0);
  error = aps_frame_prepend_data_hdr
                    (msg,&uStack_5c,(uint)req._20_4_ >> 1 & 1,req._20_4_ & 1,bVar1,
                     (uint)req._20_4_ >> 3 & 1);
  if (error == 0) {
    uVar5 = (uint)uStack_5e;
    if (uVar5 < 0xfff8) {
      iVar4 = nwk_get_short_address();
      iVar4 = -iVar4;
    }
    else {
      iVar4 = -0xfffe;
    }
    iVar6 = aps_group_table_find(addr.src_addr);
    eVar2 = addr.src_addr;
    if (iVar6 == 0) {
      if (uVar5 + iVar4 == 0) {
        bVar1 = false;
        goto _L0;
      }
    }
    else {
      bVar1 = true;
_L0:
      msg_00 = (zmsg_t *)zmsg_clone(msg);
      if (msg_00 != (zmsg_t *)0x0) {
        aps_hdr.addr_info.cluster_id = 0;
        aps_hdr.addr_info.profile_id = 0;
        aps_hdr.fcf = '\0';
        aps_hdr.aps_cntr = '\0';
        aps_hdr.cmd_id = '\0';
        aps_hdr.lqi = '\0';
        memcpy(&addr.cluster_id,&uStack_5c,0xc);
        aps_hdr.fcf = '\x7f';
        aps_handle_data((aps_header_t *)&addr.cluster_id,msg_00);
      }
      if (eVar2 == 0) {
        aps_send_data_confirm(msg,(uint)(msg_00 == (zmsg_t *)0x0));
      }
      if (!bVar1) goto _L0;
    }
    if ((req._20_4_ & 2) == 0) {
      error = aps_send_frame(uStack_5e,(aps_apsde_data_req_t *)&aps_hdr.rssi);
    }
    else {
      error = aps_retrans_send_msg(uVar7 & 0xff,&aps_hdr.rssi);
    }
    if (error == 0) goto _L0;
  }
  aps_send_data_confirm(msg,error);
_L0:
  tasklet_post(ctx);
  return;
}

