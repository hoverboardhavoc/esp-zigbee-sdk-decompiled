/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_bind_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_mgmt_bind_req
          (zdo_packet_payload_t *payload,zdp_nwk_mgmt_bind_req_field_t *req,_Bool is_write)

{
  int iVar1;
  uint uVar2;
  undefined3 in_register_00002031;
  uint16_t auStack_12 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (req == (zdp_nwk_mgmt_bind_req_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",300,
                  "zdo_op_nwk_mgmt_bind_req","payload && req");
  }
  else if (CONCAT31(in_register_00002031,is_write) != 0) {
    auStack_12[0] = CONCAT11(auStack_12[0]._1_1_,req->start_index);
    iVar1 = zmsg_append_bytes(1,auStack_12);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
    }
    goto _L0;
  }
  auStack_12[0] = 0;
  uVar2 = zmsg_get_length();
  af_read_le8(payload,auStack_12,&req->start_index);
  if (uVar2 < auStack_12[0]) {
    iVar1 = 0xfe;
  }
  else {
    iVar1 = 0;
  }
_L0:
  return (zdp_status_t)iVar1;
}

