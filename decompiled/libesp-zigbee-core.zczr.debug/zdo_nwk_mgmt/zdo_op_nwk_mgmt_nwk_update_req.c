/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_nwk_update_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_mgmt_nwk_update_req
          (zdo_packet_payload_t *payload,zdp_nwk_mgmt_nwk_update_req_field_t *req,_Bool is_write)

{
  int iVar1;
  uint uVar2;
  undefined3 in_register_00002031;
  uint uStack_24;
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) ||
     (req == (zdp_nwk_mgmt_nwk_update_req_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x186,
                  "zdo_op_nwk_mgmt_nwk_update_req","payload && req");
_L0:
    uStack_24 = CONCAT31(uStack_24._1_3_,req->scan_count);
    iVar1 = zmsg_append_bytes(payload,1,&uStack_24);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
      goto _L0;
    }
  }
  else {
    if (CONCAT31(in_register_00002031,is_write) == 0) {
      uStack_24 = uStack_24 & 0xffff0000;
      uVar2 = zmsg_get_length();
      af_read_le32(payload,(uint16_t *)&uStack_24,&req->scan_channels);
      af_read_le8(payload,(uint16_t *)&uStack_24,&req->scan_duration);
      if (req->scan_duration < 6) {
        af_read_le8(payload,(uint16_t *)&uStack_24,&req->scan_count);
      }
      if (0xfd < req->scan_duration) {
        af_read_le8(payload,(uint16_t *)&uStack_24,&req->nwk_update_id);
      }
      if (req->scan_duration == 0xff) {
        af_read_le16(payload,(uint16_t *)&uStack_24,&req->nwk_mgmt_addr);
      }
      if (uVar2 < (uStack_24 & 0xffff)) {
        iVar1 = 0xfe;
      }
      else {
        iVar1 = 0;
      }
      goto _L0;
    }
    uStack_24 = req->scan_channels;
    iVar1 = zmsg_append_bytes(4,&uStack_24);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
      goto _L0;
    }
    uStack_24 = CONCAT31(uStack_24._1_3_,req->scan_duration);
    iVar1 = zmsg_append_bytes(payload,1,&uStack_24);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
      goto _L0;
    }
    if (req->scan_duration < 6) goto _L0;
  }
  if (0xfd < req->scan_duration) {
    uStack_24 = CONCAT31(uStack_24._1_3_,req->nwk_update_id);
    iVar1 = zmsg_append_bytes(payload,1,&uStack_24);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
      goto _L0;
    }
  }
  if (req->scan_duration == 0xff) {
    uStack_24 = CONCAT22(uStack_24._2_2_,req->nwk_mgmt_addr);
    iVar1 = zmsg_append_bytes(payload,2,&uStack_24);
    if (iVar1 != 0) {
      iVar1 = 0x8a;
    }
  }
  else {
    iVar1 = 0;
  }
_L0:
  return (zdp_status_t)iVar1;
}

