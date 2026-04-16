/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_match_desc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_match_desc_rsp(zdo_packet_payload_t *payload,zdp_match_desc_rsp_field_t *rsp,_Bool is_write)

{
  byte bVar1;
  zdp_status_t zVar2;
  int iVar3;
  uint uVar4;
  uint8_t *value;
  undefined3 in_register_00002031;
  uint16_t auStack_22 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (rsp == (zdp_match_desc_rsp_field_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x21b,"zdo_op_match_desc_rsp"
                  ,"payload && rsp");
  }
  else if (CONCAT31(in_register_00002031,is_write) != 0) {
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->status);
    iVar3 = zmsg_append_bytes(1,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    auStack_22[0] = rsp->nwk_addr_of_interest;
    iVar3 = zmsg_append_bytes(payload,2,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    auStack_22[0] = CONCAT11(auStack_22[0]._1_1_,rsp->match_length);
    iVar3 = zmsg_append_bytes(payload,1,auStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    if (rsp->status == '\0') {
      if (rsp->match_length == '\0') {
        return '\0';
      }
      iVar3 = zmsg_append_bytes(payload,rsp->match_length,rsp->match_list);
      if (iVar3 == 0) {
        return '\0';
      }
      return 0x8a;
    }
    return '\0';
  }
  auStack_22[0] = 0;
  uVar4 = zmsg_get_length();
  af_read_le8(payload,auStack_22,&rsp->status);
  af_read_le16(payload,auStack_22,&rsp->nwk_addr_of_interest);
  af_read_le8(payload,auStack_22,&rsp->match_length);
  if (uVar4 < auStack_22[0]) {
    return 0xfe;
  }
  if (rsp->status == '\0') {
    bVar1 = rsp->match_length;
    if (bVar1 != 0) {
      value = (uint8_t *)calloc((uint)bVar1,1);
      rsp->match_list = value;
      if (value == (uint8_t *)0x0) {
        return 0x8a;
      }
      af_read_bytes(payload,auStack_22,(ushort)bVar1,value);
      goto _L0;
    }
  }
  rsp->match_list = (uint8_t *)0x0;
_L0:
  if (uVar4 < auStack_22[0]) {
    zVar2 = 0xfe;
  }
  else {
    zVar2 = '\0';
  }
  return zVar2;
}

