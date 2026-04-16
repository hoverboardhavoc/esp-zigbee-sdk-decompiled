/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_bind_mgmt.o -> zdo_bind_and_unbind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_bind_and_unbind_req(uint8_t cmd_id,zdo_bind_req_t *req)

{
  uint8_t uVar1;
  int iVar2;
  undefined3 in_register_00002029;
  int iVar3;
  undefined4 uVar4;
  uint16_t uStack_2a;
  undefined1 auStack_28 [4];
  zdo_packet_t packet;
  
  memset(auStack_28,0,0x18);
  if (req == (zdo_bind_req_t *)0x0) {
    iVar2 = 2;
    goto _L0;
  }
  iVar3 = zdo_packet_init(auStack_28,CONCAT31(in_register_00002029,cmd_id),req->dst_nwk_addr,req->cb
                          ,req->user_ctx);
  iVar2 = -1;
  if (iVar3 != 0) goto _L0;
  if (packet.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
    __assert_func(0,0,0);
_L0:
    uStack_2a = CONCAT11(uStack_2a._1_1_,(req->field).src_ep);
    iVar2 = zmsg_append_bytes(packet.ctx.req_ctx.arg,1,&uStack_2a);
    if (iVar2 == 0) {
      uStack_2a = (req->field).cluster_id;
      iVar2 = zmsg_append_bytes(packet.ctx.req_ctx.arg,2,&uStack_2a);
      if (iVar2 == 0) {
        uStack_2a = CONCAT11(uStack_2a._1_1_,(req->field).dst_addr_mode);
        iVar2 = zmsg_append_bytes(packet.ctx.req_ctx.arg,1,&uStack_2a);
        if (iVar2 == 0) {
          uVar1 = (req->field).dst_addr_mode;
          if (uVar1 != '\x03') {
            if (uVar1 == '\x01') {
              uStack_2a = (req->field).dst_addr.short_addr;
              uVar4 = 2;
              goto _L0;
            }
_L0:
            zdo_packet_send(auStack_28);
            iVar2 = zdp_status_to_err();
            if (iVar2 == 0) {
              return 0;
            }
            goto _L0;
          }
          iVar2 = zmsg_append_bytes(packet.ctx.req_ctx.arg,8,&(req->field).dst_addr);
          if (iVar2 == 0) {
            uVar4 = 1;
            uStack_2a = CONCAT11(uStack_2a._1_1_,(req->field).dst_ep);
_L0:
            iVar2 = zmsg_append_bytes(packet.ctx.req_ctx.arg,uVar4,&uStack_2a);
            if (iVar2 == 0) goto _L0;
          }
        }
      }
    }
  }
  else {
    iVar2 = zmsg_append_bytes(packet.ctx.req_ctx.arg,8,&req->field);
    if (iVar2 == 0) goto _L0;
  }
  iVar2 = 1;
_L0:
  zdo_packet_free(auStack_28);
  return iVar2;
}

