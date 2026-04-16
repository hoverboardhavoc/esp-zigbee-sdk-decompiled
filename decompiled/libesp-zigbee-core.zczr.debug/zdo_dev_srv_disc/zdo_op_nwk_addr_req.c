/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_nwk_addr_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_addr_req(zdo_packet_payload_t *payload,zdp_nwk_addr_req_field_t *req,_Bool is_write)

{
  int iVar1;
  uint uVar2;
  undefined3 in_register_00002031;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (req == (zdp_nwk_addr_req_field_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x45,"zdo_op_nwk_addr_req",
                  "payload && req");
  }
  else if (CONCAT31(in_register_00002031,is_write) != 0) {
    iVar1 = zmsg_append_bytes(8,req);
    if (iVar1 == 0) {
      auStack_22[0]._0_1_ = req->request_type;
      iVar1 = zmsg_append_bytes(payload,1,auStack_22);
      if (iVar1 == 0) {
        auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,req->start_index);
        iVar1 = zmsg_append_bytes(payload,1,auStack_22);
        if (iVar1 != 0) {
          iVar1 = 0x8a;
        }
      }
      else {
        iVar1 = 0x8a;
      }
    }
    else {
      iVar1 = 0x8a;
    }
    goto _L0;
  }
  auStack_22[0] = 0;
  uVar2 = zmsg_get_length();
  af_read_bytes(payload,auStack_22,8,(uint8_t *)req);
  af_read_le8(payload,auStack_22,&req->request_type);
  af_read_le8(payload,auStack_22,&req->start_index);
  if (uVar2 < auStack_22[0]) {
    iVar1 = 0xfe;
  }
  else {
    iVar1 = 0;
  }
_L0:
  return (zdp_status_t)iVar1;
}

