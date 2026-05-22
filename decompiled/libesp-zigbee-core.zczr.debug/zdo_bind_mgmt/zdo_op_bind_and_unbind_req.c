/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_bind_mgmt.o -> zdo_op_bind_and_unbind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_bind_and_unbind_req(zdo_packet_payload_t *payload,zdp_bind_req_field_t *req,_Bool is_write)

{
  int iVar1;
  uint uVar2;
  undefined3 in_register_00002031;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (req == (zdp_bind_req_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_bind_mgmt.c",0x3b,
                  "zdo_op_bind_and_unbind_req","payload && req");
  }
  else {
    if (CONCAT31(in_register_00002031,is_write) == 0) {
      auStack_22[0] = 0;
      uVar2 = zmsg_get_length();
      af_read_bytes(payload,auStack_22,8,(uint8_t *)req);
      af_read_le8(payload,auStack_22,&req->src_ep);
      af_read_le16(payload,auStack_22,&req->cluster_id);
      af_read_le8(payload,auStack_22,&req->dst_addr_mode);
      if (auStack_22[0] <= uVar2) {
        if (req->dst_addr_mode == '\x03') {
          af_read_bytes(payload,auStack_22,8,(uint8_t *)&(req->dst_addr).short_addr);
          af_read_le8(payload,auStack_22,&req->dst_ep);
          iVar1 = 0;
        }
        else if (req->dst_addr_mode == '\x01') {
          af_read_le16(payload,auStack_22,&(req->dst_addr).short_addr);
          iVar1 = 0;
        }
        else {
          iVar1 = 0x80;
        }
        if (auStack_22[0] <= uVar2) goto _L0;
      }
      iVar1 = 0xfe;
      goto _L0;
    }
    iVar1 = zmsg_append_bytes(8,req);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
      goto _L0;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,req->src_ep);
    iVar1 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
      goto _L0;
    }
    auStack_22[0] = req->cluster_id;
    iVar1 = zmsg_append_bytes(payload,2,auStack_22);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
      goto _L0;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,req->dst_addr_mode);
    iVar1 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
      goto _L0;
    }
    if (req->dst_addr_mode != '\x03') {
      if (req->dst_addr_mode == '\x01') {
        auStack_22[0] = (req->dst_addr).short_addr;
        iVar1 = zmsg_append_bytes(payload,2,auStack_22);
        if (iVar1 != 0) {
          iVar1 = 0x8a;
        }
      }
      else {
        iVar1 = 0;
      }
      goto _L0;
    }
  }
  iVar1 = zmsg_append_bytes(payload,8,&req->dst_addr);
  if (iVar1 == 0) {
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,req->dst_ep);
    iVar1 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
    }
  }
  else {
    iVar1 = 0x8a;
  }
_L0:
  return (zdp_status_t)iVar1;
}

