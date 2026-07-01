/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_lqi_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: dev_info */
/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_mgmt_lqi_rsp
          (zdo_packet_payload_t *payload,zdp_nwk_mgmt_lqi_rsp_field_t *rsp,_Bool is_write)

{
  ushort uVar1;
  zdp_status_t zVar2;
  int iVar3;
  ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *peVar4;
  undefined3 in_register_00002031;
  zdp_status_t unaff_s4;
  uint uVar5;
  uint uVar6;
  byte bStack_24;
  byte bStack_23;
  uint16_t uStack_22;
  uint8_t dev_info;
  uint8_t state_info;
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (rsp == (zdp_nwk_mgmt_lqi_rsp_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0x9c,
                  "zdo_op_nwk_mgmt_lqi_rsp","payload && rsp");
    return unaff_s4;
  }
  if (CONCAT31(in_register_00002031,is_write) != 0) {
    uStack_22._0_1_ = rsp->status;
    iVar3 = zmsg_append_bytes(1,&uStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    uStack_22._0_1_ = rsp->neighbor_table_entries;
    iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    uStack_22._0_1_ = rsp->start_index;
    iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    uStack_22 = CONCAT11(uStack_22._1_1_,rsp->neighbor_table_list_count);
    iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
    if (iVar3 != 0) {
      return 0x8a;
    }
    if (rsp->status != '\0') {
      return '\0';
    }
    if (rsp->neighbor_table_list == (ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *)0x0) {
      return '\0';
    }
    if (rsp->neighbor_table_list_count == '\0') {
      return '\0';
    }
    uVar6 = 0;
    while( true ) {
      if (rsp->neighbor_table_list_count <= uVar6) {
        return '\0';
      }
      uVar1 = *(ushort *)&rsp->neighbor_table_list[uVar6].field_0x12;
      iVar3 = zmsg_append_bytes(payload,8);
      if (iVar3 != 0) {
        return 0x8a;
      }
      iVar3 = zmsg_append_bytes(payload,8,&rsp->neighbor_table_list[uVar6].extended_addr);
      if (iVar3 != 0) {
        return 0x8a;
      }
      uStack_22 = rsp->neighbor_table_list[uVar6].nwk_addr;
      iVar3 = zmsg_append_bytes(payload,2,&uStack_22);
      if (iVar3 != 0) {
        return 0x8a;
      }
      uStack_22._0_1_ =
           (byte)uVar1 & 3 | (byte)((uVar1 >> 2 & 3) << 2) | (byte)((uVar1 >> 4 & 7) << 4);
      iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
      if (iVar3 != 0) {
        return 0x8a;
      }
      uStack_22._0_1_ = (byte)(uVar1 >> 8) & 3;
      iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
      if (iVar3 != 0) {
        return 0x8a;
      }
      uStack_22._0_1_ = rsp->neighbor_table_list[uVar6].device_depth;
      iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
      if (iVar3 != 0) {
        return 0x8a;
      }
      uStack_22 = CONCAT11(uStack_22._1_1_,rsp->neighbor_table_list[uVar6].lqa);
      iVar3 = zmsg_append_bytes(payload,1,&uStack_22);
      if (iVar3 != 0) break;
      uVar6 = uVar6 + 1 & 0xff;
    }
    return 0x8a;
  }
  uStack_22 = 0;
  uVar6 = zmsg_get_length();
  af_read_le8(payload,&uStack_22,&rsp->status);
  af_read_le8(payload,&uStack_22,&rsp->neighbor_table_entries);
  af_read_le8(payload,&uStack_22,&rsp->start_index);
  af_read_le8(payload,&uStack_22,&rsp->neighbor_table_list_count);
  if (uVar6 < uStack_22) {
_L0:
    zVar2 = 0xfe;
  }
  else {
    if ((rsp->status == '\0') && (rsp->neighbor_table_list_count != 0)) {
      peVar4 = (ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *)
               calloc((uint)rsp->neighbor_table_list_count,0x16);
      rsp->neighbor_table_list = peVar4;
      uVar5 = 0;
      if (peVar4 == (ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *)0x0) goto _L0;
      for (; uVar5 < rsp->neighbor_table_list_count; uVar5 = uVar5 + 1 & 0xff) {
        bStack_24 = 0;
        bStack_23 = 0;
        af_read_bytes(payload,&uStack_22,8,(uint8_t *)(rsp->neighbor_table_list + uVar5));
        af_read_bytes(payload,&uStack_22,8,(uint8_t *)&rsp->neighbor_table_list[uVar5].extended_addr
                     );
        af_read_le16(payload,&uStack_22,&rsp->neighbor_table_list[uVar5].nwk_addr);
        af_read_le8(payload,&uStack_22,&bStack_24);
        af_read_le8(payload,&uStack_22,&bStack_23);
        af_read_le8(payload,&uStack_22,&rsp->neighbor_table_list[uVar5].device_depth);
        af_read_le8(payload,&uStack_22,&rsp->neighbor_table_list[uVar5].lqa);
        if (uVar6 < uStack_22) goto _L0;
        *(ushort *)&rsp->neighbor_table_list[uVar5].field_0x12 =
             *(ushort *)&rsp->neighbor_table_list[uVar5].field_0x12 & 0xfffc | bStack_24 & 3;
        *(ushort *)&rsp->neighbor_table_list[uVar5].field_0x12 =
             *(ushort *)&rsp->neighbor_table_list[uVar5].field_0x12 & 0xfff3 |
             (ushort)(((int)(uint)bStack_24 >> 2 & 3U) << 2);
        *(ushort *)&rsp->neighbor_table_list[uVar5].field_0x12 =
             (ushort)(((int)(uint)bStack_24 >> 4 & 7U) << 4) |
             *(ushort *)&rsp->neighbor_table_list[uVar5].field_0x12 & 0xff8f;
        *(ushort *)&rsp->neighbor_table_list[uVar5].field_0x12 =
             *(ushort *)&rsp->neighbor_table_list[uVar5].field_0x12 & 0xfcff |
             (ushort)((bStack_23 & 3) << 8);
      }
    }
    zVar2 = '\0';
  }
  return zVar2;
}

