/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_sys_srv_disc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zdo_sys_srv_disc_req(zdo_sys_srv_disc_req_t *req)

{
  int iVar1;
  int iVar2;
  ezb_err_t eVar3;
  undefined1 auStack_28 [4];
  zdo_packet_t packet;
  
  memset(auStack_28,0,0x18);
  if (req == (zdo_sys_srv_disc_req_t *)0x0) {
    iVar1 = 2;
  }
  else {
    iVar2 = zdo_packet_init(auStack_28,0x15,0xfffd,req->cb,req->user_ctx);
    iVar1 = -1;
    if (iVar2 == 0) {
      if (packet.ctx.req_ctx.arg == (zdo_packet_user_ctx_t)0x0) {
        __assert_func(0,0,0);
      }
      else {
        eVar3 = zmsg_append_le16((zmsg_t *)packet.ctx.req_ctx.arg,(req->field).server_mask);
        if (eVar3 != 0) {
          iVar1 = 1;
          goto _L0;
        }
      }
      zdo_packet_send(auStack_28);
      iVar1 = zdp_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
_L0:
  zdo_packet_free(auStack_28);
  return iVar1;
}

