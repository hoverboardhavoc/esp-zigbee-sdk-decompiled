/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_leave_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_mgmt_leave_req
          (zdo_packet_payload_t *payload,zdp_nwk_mgmt_leave_req_field_t *req,_Bool is_write)

{
  _Bool _Var1;
  _Bool _Var2;
  int iVar3;
  uint uVar4;
  undefined3 in_register_00002031;
  byte bStack_23;
  uint16_t uStack_22;
  uint8_t leave_control;
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (req == (zdp_nwk_mgmt_leave_req_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0xce,
                  "zdo_op_nwk_mgmt_leave_req","payload && req");
  }
  else if (CONCAT31(in_register_00002031,is_write) != 0) {
    _Var1 = req->remove_children;
    _Var2 = req->rejoin;
    iVar3 = zmsg_append_bytes(8,req);
    if (iVar3 == 0) {
      uStack_22 = CONCAT11(uStack_22._1_1_,(byte)((_Var1 & 1) << 6) | _Var2 << 7);
      iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
      if (iVar3 != 0) {
        iVar3 = 0x8a;
      }
    }
    else {
      iVar3 = 0x8a;
    }
    goto _L0;
  }
  uStack_22 = 0;
  bStack_23 = 0;
  uVar4 = zmsg_get_length();
  af_read_bytes(payload,&uStack_22,8,(uint8_t *)req);
  af_read_le8(payload,&uStack_22,&bStack_23);
  if (uVar4 < uStack_22) {
    iVar3 = 0xfe;
  }
  else {
    req->remove_children = (_Bool)((byte)((int)(uint)bStack_23 >> 6) & 1);
    req->rejoin = (_Bool)(bStack_23 >> 7);
    iVar3 = 0;
  }
_L0:
  return (zdp_status_t)iVar3;
}

