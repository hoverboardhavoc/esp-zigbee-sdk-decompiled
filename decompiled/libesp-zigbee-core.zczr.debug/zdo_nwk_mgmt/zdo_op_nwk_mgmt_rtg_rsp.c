/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_nwk_mgmt.o -> zdo_op_nwk_mgmt_rtg_rsp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: status_info */
/* WARNING: Unknown calling convention */

zdp_status_t
zdo_op_nwk_mgmt_rtg_rsp
          (zdo_packet_payload_t *payload,zdp_nwk_mgmt_rtg_rsp_field_t *rsp,_Bool is_write)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  ezb_zdp_nwk_mgmt_routing_table_entry_t *peVar4;
  undefined3 in_register_00002031;
  uint uVar5;
  uint unaff_s3;
  uint uVar6;
  byte bStack_23;
  uint16_t uStack_22;
  uint8_t status_info;
  uint16_t offset;
  
  if ((payload == (zdo_packet_payload_t *)0x0) || (rsp == (zdp_nwk_mgmt_rtg_rsp_field_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_nwk_mgmt.c",0xf6,
                  "zdo_op_nwk_mgmt_rtg_rsp","payload && rsp");
  }
  else {
    if (CONCAT31(in_register_00002031,is_write) == 0) {
      uStack_22 = 0;
      uVar3 = zmsg_get_length();
      af_read_le8(payload,&uStack_22,&rsp->status);
      if (rsp->status == '\0') {
        af_read_le8(payload,&uStack_22,&rsp->routing_table_entries);
        af_read_le8(payload,&uStack_22,&rsp->start_index);
        af_read_le8(payload,&uStack_22,&rsp->routing_table_list_count);
        if (uVar3 < uStack_22) {
          unaff_s3 = 0xfe;
        }
        else {
          unaff_s3 = 0;
          if (rsp->routing_table_list_count != 0) {
            peVar4 = (ezb_zdp_nwk_mgmt_routing_table_entry_t *)
                     calloc((uint)rsp->routing_table_list_count,6);
            rsp->routing_table_list = peVar4;
            if (peVar4 == (ezb_zdp_nwk_mgmt_routing_table_entry_t *)0x0) {
              unaff_s3 = 0xfe;
            }
            else {
              for (uVar6 = 0; uVar6 < rsp->routing_table_list_count; uVar6 = uVar6 + 1 & 0xff) {
                bStack_23 = 0;
                af_read_le16(payload,&uStack_22,&rsp->routing_table_list[uVar6].dst_addr);
                af_read_le8(payload,&uStack_22,&bStack_23);
                af_read_le16(payload,&uStack_22,&rsp->routing_table_list[uVar6].next_hop_addr);
                if (uVar3 < uStack_22) {
                  unaff_s3 = 0xfe;
                  break;
                }
                uVar5 = (uint)bStack_23;
                rsp->routing_table_list[uVar6].field_0x2 =
                     rsp->routing_table_list[uVar6].field_0x2 & 0xf8 | bStack_23 & 7;
                rsp->routing_table_list[uVar6].field_0x2 =
                     rsp->routing_table_list[uVar6].field_0x2 & 0xf7 |
                     (byte)(((int)uVar5 >> 3 & 1U) << 3);
                rsp->routing_table_list[uVar6].field_0x2 =
                     rsp->routing_table_list[uVar6].field_0x2 & 0xef |
                     (byte)(((int)uVar5 >> 4 & 1U) << 4);
                rsp->routing_table_list[uVar6].field_0x2 =
                     (byte)(((int)uVar5 >> 5 & 1U) << 5) |
                     rsp->routing_table_list[uVar6].field_0x2 & 0xdf;
              }
            }
          }
        }
      }
      else {
        unaff_s3 = 0;
      }
      goto _L0;
    }
    uStack_22 = CONCAT11(uStack_22._1_1_,rsp->status);
    iVar2 = zmsg_append_bytes(1,&uStack_22);
    if (iVar2 != 0) {
      unaff_s3 = 0x8a;
      goto _L0;
    }
    unaff_s3 = (uint)rsp->status;
    if (unaff_s3 != 0) {
      unaff_s3 = 0;
      goto _L0;
    }
  }
  uStack_22._0_1_ = rsp->routing_table_entries;
  iVar2 = zmsg_append_bytes(payload,1,&uStack_22);
  if (iVar2 == 0) {
    uStack_22._0_1_ = rsp->start_index;
    iVar2 = zmsg_append_bytes(payload,1,&uStack_22);
    if (iVar2 == 0) {
      uStack_22 = CONCAT11(uStack_22._1_1_,rsp->routing_table_list_count);
      iVar2 = zmsg_append_bytes(payload,1,&uStack_22);
      if (iVar2 == 0) {
        if (rsp->routing_table_list != (ezb_zdp_nwk_mgmt_routing_table_entry_t *)0x0) {
          uVar3 = unaff_s3;
          if (rsp->routing_table_list_count == '\0') {
            unaff_s3 = 0;
          }
          else {
            for (; uVar3 < rsp->routing_table_list_count; uVar3 = uVar3 + 1 & 0xff) {
              uVar1 = *(ushort *)&rsp->routing_table_list[uVar3].field_0x2;
              uStack_22 = rsp->routing_table_list[uVar3].dst_addr;
              iVar2 = zmsg_append_bytes(payload,2,&uStack_22);
              if (iVar2 != 0) {
                unaff_s3 = 0x8a;
                break;
              }
              uStack_22 = CONCAT11(uStack_22._1_1_,
                                   (byte)uVar1 & 7 | (byte)((uVar1 >> 3 & 1) << 3) |
                                   (byte)((uVar1 >> 4 & 1) << 4) | (byte)((uVar1 >> 5 & 1) << 5));
              iVar2 = zmsg_append_bytes(payload,1,&uStack_22);
              if (iVar2 != 0) {
                unaff_s3 = 0x8a;
                break;
              }
              uStack_22 = rsp->routing_table_list[uVar3].next_hop_addr;
              iVar2 = zmsg_append_bytes(payload,2,&uStack_22);
              if (iVar2 != 0) {
                unaff_s3 = 0x8a;
                break;
              }
            }
          }
        }
      }
      else {
        unaff_s3 = 0x8a;
      }
    }
    else {
      unaff_s3 = 0x8a;
    }
  }
  else {
    unaff_s3 = 0x8a;
  }
_L0:
  return (zdp_status_t)unaff_s3;
}

