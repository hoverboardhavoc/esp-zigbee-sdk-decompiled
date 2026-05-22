/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_op_power_desc_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_power_desc_rsp(zdo_packet_payload_t *payload,zdp_power_desc_rsp_field_t *rsp,_Bool is_write)

{
  int iVar1;
  uint uVar2;
  undefined3 in_register_00002031;
  zdp_status_t unaff_s2;
  ezb_af_node_power_desc_t aeStack_22 [2];
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (rsp == (zdp_power_desc_rsp_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",0x2d6,
                  "zdo_op_power_desc_rsp","payload && rsp");
  }
  else {
    if (CONCAT31(in_register_00002031,is_write) == 0) {
      aeStack_22[0].u16 = 0;
      uVar2 = zmsg_get_length();
      af_read_le8(payload,&aeStack_22[0].u16,&rsp->status);
      af_read_le16(payload,&aeStack_22[0].u16,&rsp->nwk_addr_of_interest);
      if (aeStack_22[0].u16 <= uVar2) {
        if (rsp->status == '\0') {
          af_read_le16(payload,&aeStack_22[0].u16,&(rsp->power_desc).u16);
        }
        else {
          (rsp->power_desc).u16 = 0;
        }
        if (aeStack_22[0].u16 <= uVar2) {
          return '\0';
        }
      }
      return 0xfe;
    }
    aeStack_22[0].u16._0_1_ = rsp->status;
    iVar1 = zmsg_append_bytes(1,aeStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    aeStack_22[0] = (ezb_af_node_power_desc_t)rsp->nwk_addr_of_interest;
    iVar1 = zmsg_append_bytes(payload,2,aeStack_22);
    if (iVar1 != 0) {
      return 0x8a;
    }
    unaff_s2 = rsp->status;
    if (unaff_s2 != '\0') {
      return '\0';
    }
  }
  aeStack_22[0] = rsp->power_desc;
  iVar1 = zmsg_append_bytes(payload,2,aeStack_22);
  if (iVar1 != 0) {
    unaff_s2 = 0x8a;
  }
  return unaff_s2;
}

