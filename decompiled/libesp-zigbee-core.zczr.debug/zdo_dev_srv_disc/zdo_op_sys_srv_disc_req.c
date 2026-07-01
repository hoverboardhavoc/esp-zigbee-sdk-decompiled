/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_sys_srv_disc_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: offset */
/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_sys_srv_disc_req
          (zdo_packet_payload_t *payload,zdp_sys_srv_disc_req_field_t *req,_Bool is_write)

{
  int iVar1;
  uint uVar2;
  undefined3 in_register_00002031;
  uint16_t auStack_12 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (req == (zdp_sys_srv_disc_req_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x68d,
                  "zdo_op_sys_srv_disc_req","payload && req");
  }
  else if (CONCAT31(in_register_00002031,is_write) != 0) {
    auStack_12[0] = req->server_mask;
    iVar1 = zmsg_append_bytes(2,auStack_12);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
    }
    goto _L0;
  }
  auStack_12[0] = 0;
  uVar2 = zmsg_get_length();
  af_read_le16(payload,auStack_12,&req->server_mask);
  if (uVar2 < auStack_12[0]) {
    iVar1 = 0xfe;
  }
  else {
    iVar1 = 0;
  }
_L0:
  return (zdp_status_t)iVar1;
}

