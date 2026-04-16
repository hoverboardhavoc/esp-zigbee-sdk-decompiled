/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> nwk_mesh_routing.o -> nwk_mesh_send_rreq
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
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined3 in_register_00002031;
  char cStack_31;
  undefined4 uStack_30;
  nwk_rreq_cmd_t rreq;
  
  iVar1 = zmsg_alloc(0x27);
  if (iVar1 != 0) {
    zmsg_set_offset(0);
    uVar2 = nwk_get_short_address();
    nwk_frame_write_hdr(iVar1,uVar2,0xfffc,CONCAT31(in_register_00002031,radius),1,0);
    iVar3 = core_globals_get();
    cStack_31 = *(char *)(iVar3 + 0x9d9);
    *(char *)(iVar3 + 0x9d9) = cStack_31 + '\x01';
    zmsg_write_bytes(iVar1,7,1,&cStack_31);
    rreq.cmd_opt = '\0';
    rreq.rreq_id = '\0';
    rreq.dst_addr = 0;
    rreq._4_4_ = 0;
    rreq.dst_ieee_addr.field_0.u8[3] = '\0';
    uStack_30 = (rreq_type & 0x1f) << 3;
    uStack_30 = CONCAT22(dst_addr,CONCAT11(rreq_id,(undefined1)uStack_30));
    iVar3 = nwk_address_extended_by_short(CONCAT22(in_register_0000202a,dst_addr),&rreq.rreq_id);
    if (iVar3 == 0) {
      uStack_30 = uStack_30 | 0x20;
    }
    cStack_31 = '\x01';
    zmsg_append_bytes(iVar1,&cStack_31);
    if ((uStack_30 & 0x20) == 0) {
      uVar2 = 5;
    }
    else {
      uVar2 = 0xd;
    }
    zmsg_append_bytes(iVar1,uVar2,&uStack_30);
    nwk_fwd_send_msg(iVar1);
  }
  return;
}

