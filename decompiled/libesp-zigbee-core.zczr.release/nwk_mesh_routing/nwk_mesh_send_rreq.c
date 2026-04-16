/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> nwk_mesh_routing.o -> nwk_mesh_send_rreq
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void nwk_mesh_send_rreq(ezb_shortaddr_t dst_addr,uint8_t rreq_id,uint8_t radius,
                       nwk_rreq_type_t rreq_type)

{
  undefined2 in_register_0000202a;
  zmsg_t *msg;
  undefined4 uVar1;
  int iVar2;
  undefined3 in_register_00002031;
  byte local_30;
  uint8_t uStack_2f;
  ezb_shortaddr_t eStack_2e;
  nwk_rreq_cmd_t rreq;
  
  msg = (zmsg_t *)zmsg_alloc(0x27);
  if (msg != (zmsg_t *)0x0) {
    zmsg_set_offset(0);
    uVar1 = nwk_get_short_address();
    nwk_frame_write_hdr(msg,uVar1,0xfffc,CONCAT31(in_register_00002031,radius),1,0);
    iVar2 = core_globals_get();
    local_30 = *(byte *)(iVar2 + 0x9d9);
    *(byte *)(iVar2 + 0x9d9) = local_30 + 1;
    zmsg_write_bytes(msg,7,1,&local_30);
    local_30 = rreq_type << 3;
    rreq.cmd_opt = '\0';
    rreq.rreq_id = '\0';
    rreq.dst_addr = 0;
    rreq._4_4_ = 0;
    rreq.dst_ieee_addr.field_0.u8[3] = '\0';
    uStack_2f = rreq_id;
    eStack_2e = dst_addr;
    iVar2 = nwk_address_extended_by_short(CONCAT22(in_register_0000202a,dst_addr),&rreq.rreq_id);
    if (iVar2 == 0) {
      local_30 = local_30 | 0x20;
    }
    zmsg_append_u8(msg,'\x01');
    zmsg_append_bytes(msg,(-(uint)((local_30 & 0x20) == 0) & 0xfffffff8) + 0xd,&local_30);
    nwk_fwd_send_msg(msg);
  }
  return;
}

