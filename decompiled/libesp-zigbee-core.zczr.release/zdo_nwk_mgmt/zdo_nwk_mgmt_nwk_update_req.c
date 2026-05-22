/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_nwk_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_nwk_mgmt_nwk_update_req(zdo_nwk_mgmt_nwk_update_req_t *req)

{
  int iVar1;
  int iVar2;
  ezb_err_t eVar3;
  uint32_t uStack_2c;
  undefined1 auStack_28 [4];
  zdo_packet_t packet;
  
  memset(auStack_28,0,0x18);
  if (req == (zdo_nwk_mgmt_nwk_update_req_t *)0x0) {
    iVar1 = 2;
    goto _L0;
  }
  iVar2 = zdo_packet_init(auStack_28,0x38,req->dst_nwk_addr,req->cb,req->user_ctx);
  iVar1 = -1;
  if (iVar2 != 0) goto _L0;
  if (packet.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
    __assert_func(0,0,0);
_L0:
    eVar3 = zmsg_append_u8((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).scan_duration);
    if ((eVar3 == 0) &&
       ((5 < (req->field).scan_duration ||
        (eVar3 = zmsg_append_u8((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).scan_count),
        eVar3 == 0)))) {
      if (0xfd < (req->field).scan_duration) {
        eVar3 = zmsg_append_u8((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).nwk_update_id);
        if (eVar3 != 0) goto _L0;
        if ((req->field).scan_duration == 0xff) {
          uStack_2c = CONCAT22(uStack_2c._2_2_,(req->field).nwk_mgmt_addr);
          iVar1 = zmsg_append_bytes(packet.ctx.req_ctx.arg,2,&uStack_2c);
          if (iVar1 != 0) goto _L0;
        }
      }
      zdo_packet_send(auStack_28);
      iVar1 = zdp_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
      goto _L0;
    }
  }
  else {
    uStack_2c = (req->field).scan_channels;
    iVar1 = zmsg_append_bytes(packet.ctx.req_ctx.arg,4,&uStack_2c);
    if (iVar1 == 0) goto _L0;
  }
_L0:
  iVar1 = 1;
_L0:
  zdo_packet_free(auStack_28);
  return iVar1;
}

